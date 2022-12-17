#include "15_05_threadpool.h"

#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>


namespace ThreadPoolMk1{
	class ThreadPool {
	public:
		ThreadPool(size_t num_threads);
		~ThreadPool();

		void EnqueueJob(std::function<void()> job);

	private:
		size_t num_threads;
		std::vector<std::thread> workers_thread;
		std::queue<std::function<void()>> jobs;
		std::condition_variable cv_job_queue;
		std::mutex mutex_job_queue;

		bool stop_all;
		void WorkerThread();
	};

	ThreadPool::ThreadPool(size_t num_threads) : num_threads(num_threads), stop_all(false) {
		workers_thread.reserve(num_threads);
		for (size_t i = 0; i < num_threads; i++) {
			workers_thread.emplace_back([this]() {this->WorkerThread(); });
		}
	}

	void ThreadPool::WorkerThread() {
		while (true) {
			std::unique_lock<std::mutex> lock(mutex_job_queue);
			cv_job_queue.wait(lock, [this]() {return !this->jobs.empty() || stop_all; });
			if (stop_all && this->jobs.empty()) {
				return;
			}

			// Get the first job in the Queue
			std::function<void()> job = std::move(jobs.front());
			jobs.pop();
			lock.unlock();

			// Execute the job!
			job();
		}
	}

	ThreadPool::~ThreadPool() {
		stop_all = true;
		cv_job_queue.notify_all();

		for (auto& t : workers_thread) {
			t.join();
		}
	}

	void ThreadPool::EnqueueJob(std::function<void()> job) {
		if (stop_all) {
			throw std::runtime_error("ThreadPool NOT available!");
		}

		{
			std::lock_guard<std::mutex> lock(mutex_job_queue);
			jobs.push(std::move(job));
		}

		cv_job_queue.notify_one();
	}

	void work(int t, int id) {
		printf("%d start \n", id);
		std::this_thread::sleep_for(std::chrono::seconds(t));
		printf("%d ends after %d second(s).\n", id, t);
	}

	void test() {
		ThreadPool pool(3);

		for (int i = 0; i < 10; i++) {
			pool.EnqueueJob([i]() { work(i % 3 + 1, i + 1); });
		}
	}
}

void threadpool_mk1_test() {
	ThreadPoolMk1::test();
}


/* Limit and Improvement 1
	- Above ThreadPool supports only for the jobs that return voids.
	- Let's improve it by allowing the return of an arbitrary datatype.
		- How?)
			- Use template for the EnqueueJob() method!
*/


#include <future>
#include <iostream>

namespace ThreadPoolMk2 {
	class ThreadPool {
	public:
		ThreadPool(size_t num_threads);
		~ThreadPool();

		// Use template to get an arbitrary input datatype. std::result_of denotes the result of the class F with the input parameters Args...
		template <class F, class... Args>
		std::future<typename std::result_of<F(Args...)>::type> EnqueueJob(
			F f, Args... args);

	protected:
		size_t num_threads;
		std::vector<std::thread> worker_threads;
		std::queue<std::function<void()>> jobs_queue;
		std::condition_variable cv_job_queue;
		std::mutex mutex_job_queue;
		bool stop_all;
		void WorkerThread();
	};

	ThreadPool::ThreadPool(size_t num_threads) : num_threads(num_threads), stop_all(false) {
		worker_threads.reserve(num_threads);
		for (size_t i = 0; i < num_threads; i++) {
			worker_threads.emplace_back([this]() { this->WorkerThread(); });
		}
	}

	void ThreadPool::WorkerThread() {
		while (true) {
			std::unique_lock<std::mutex> lock(mutex_job_queue);
			cv_job_queue.wait(lock, [this]() { return !this->jobs_queue.empty() || stop_all; });
			if (stop_all && this->jobs_queue.empty()) {
				return;
			}

			std::function<void()> job = std::move(jobs_queue.front());
			jobs_queue.pop();
			lock.unlock();

			job();
		}
	}

	ThreadPool::~ThreadPool() {
		stop_all = true;
		cv_job_queue.notify_all();

		for (auto& t : worker_threads) {
			t.join();
		}
	}
	
	// Implement the NEW EnqueueJob() that returns future asynchronously.
	template <class F, class... Args>
	std::future<typename std::result_of<F(Args...)>::type> ThreadPool::EnqueueJob(
		F f, Args... args) {
		
		//std::cout << "EnqueueJob" << std::endl;

		if (stop_all){
			throw std::runtime_error("ThreadPool NOT avaiable.");
		}

		// Use "packaged_type" to get the return value of the asynchronous function!
		// Use a cumstomized return_type for the reult of F(Args...) for packaged_type bellow.
		//		- Why?) packaged_task receives only function as input parameter! Use bind!
		using return_type = typename std::result_of<F(Args...)>::type;
		//std::packaged_task<return_type()> job(std::bind(f, args...));

		// Use shared_ptr for job.
		//	- Why?) Job is destructed when EnqueueJob() is finished.
		//			Then, we cannot use the result of the job()!
		//			Thus, use shared_ptr so that job will be maintained until other procedures pointing at job is finished!!!
		auto job = std::make_shared<std::packaged_task<return_type()>>(std::bind(f, args...));

		// Now get_future() from the packaged_task, job.
		std::future<return_type> job_result_future = job->get_future();
		{
			std::lock_guard<std::mutex> lock(mutex_job_queue);
			this->jobs_queue.push([job]() { (*job)(); });	// The object of the shared_ptr which is the returned value of job() delivered to jobs!
		}
		cv_job_queue.notify_one();

		return job_result_future;	// Here's the result of job()!
	}


	// Now the work returns the integer value!!!
	int work(int t, int id) {
		printf("%d start \n", id);
		std::this_thread::sleep_for(std::chrono::seconds(t));
		printf("%d end after %d second(s).\n", id, t);
		return t + id;
	}

	void test() {
		ThreadPool pool(3);

		std::vector<std::future<int>> futures;
		for (int i = 0; i < 10; i++) {
			futures.emplace_back(pool.EnqueueJob(work, i % 3 + 1, i + 1));
		}

		for (auto& f : futures) {
			printf("result : %d \n", f.get());	// Gets the returned value of the jobs.
		}
	}
}


void threadpool_mk2_test() {
	ThreadPoolMk2::test();
}


/* Again, Limit and Improvement
	- Consider that above program delivers the copy of result of EnqueueJob().
		- Copy results in redundant memory loss.
	- Solution : Use perfect forwarding!!!
*/

namespace ThreadPoolMk3 {
	class ThreadPool : ThreadPoolMk2::ThreadPool {
	public:
		ThreadPool(size_t num_threads) : ThreadPoolMk2::ThreadPool(num_threads) {};
		~ThreadPool() {};

		template <class F, class... Args>
		std::future<typename std::result_of<F(Args...)>::type> EnqueueJob(
			F&& f, Args&&... args);
	};

	template <class F, class... Args>
	std::future<typename std::result_of<F(Args...)>::type> ThreadPool::EnqueueJob(
		F&& f, Args&&... args) {

		if (stop_all) {
			throw std::runtime_error("ThreadPool NOT avaiable.");
		}

		using return_type = typename std::result_of<F(Args...)>::type;
		auto job = std::make_shared<std::packaged_task<return_type()>>(
			std::bind(std::forward<F>(f), std::forward<Args>(args)...));	// forward!

		std::future<return_type> job_result_future = job->get_future();
		{
			std::lock_guard<std::mutex> lock(mutex_job_queue);
			jobs_queue.push([job]() { (*job)(); });	// The object of the shared_ptr which is the returned value of job() delivered to jobs!
		}
		cv_job_queue.notify_one();

		return job_result_future;
	}


	int work(int t, int id) {
		printf("%d start \n", id);
		std::this_thread::sleep_for(std::chrono::seconds(t));
		printf("%d end after %ds\n", id, t);
		return t + id;
	}

	void test() {
		ThreadPool pool(3);

		std::vector<std::future<int>> futures;
		for (int i = 0; i < 10; i++) {
			futures.emplace_back(pool.EnqueueJob(work, i % 3 + 1, i));
		}
		for (auto& f : futures) {
			printf("result : %d \n", f.get());
		}
	}
}


void threadpool_mk3_test() {
	ThreadPoolMk3::test();
}