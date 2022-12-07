#include "17_04_filesystem.h"

/* How to search file using <filesystem> library */
#include <filesystem>
#include <iostream>

namespace FileSystemSimple {
	void test() {
		std::filesystem::path p("./17_04_some_file");

		std::cout << "Does " << p << " exists? : "
			<< std::boolalpha << std::filesystem::exists(p) << std::endl;

		std::cout << "Is " << p << " a file? : "
			<< std::boolalpha << std::filesystem::is_regular_file(p) << std::endl;

		std::cout << "Is " << p << " a directory? : "
			<< std::boolalpha << std::filesystem::is_directory(p) << std::endl;
	}
}

void filesystem_simple_test() {
	FileSystemSimple::test();
}



namespace fs = std::filesystem;

namespace FileSystemMiscTest {

	void test() {
		fs::path p("./17_04_some_file");

		std::cout << "Curr Path : " << fs::current_path() << std::endl;
		std::cout << "Relative Path : " << p.relative_path() << std::endl;
		std::cout << "Absolute Path : " << fs::absolute(p) << std::endl;
		std::cout << "Canonical Absolute Path : " << fs::canonical(p) << std::endl;

	}
}

void filesystem_path_related_functions() {
	FileSystemMiscTest::test();
}


/* Tech.) Directory Iteration */
namespace FileSystemDirectoryIteration {

	void simple_test() {
		fs::directory_iterator dir_itr(fs::current_path() / "images");	// '/' operator is defined in path module
		while (dir_itr != fs::end(dir_itr)) {
			const fs::directory_entry& entry = *dir_itr;
			std::cout << entry.path() << std::endl;
			dir_itr++;
		}
	}

	void recursive_iteration_test() {
		for (const fs::directory_entry& e
			: fs::recursive_directory_iterator(fs::current_path() / "images")) {
			std::cout << e.path() << std::endl;
		}
	}
}

void filesystem_directory_iteration_test() {
	FileSystemDirectoryIteration::simple_test();
}

void filesystem_recursive_directory_iteration_test() {
	FileSystemDirectoryIteration::recursive_iteration_test();
}


/* Tech.) Directory Creation
	- Recall that <ofstream> can create ONLY files, NOT directories.
	- Instead, we should use "create_directory" function in <filesystem>
*/


namespace FileSystemCreateDir {
	void test() {
		fs::path p("./images/17_04_creation_test");
		std::cout << "Does " << p << " exists? : "
			<< std::boolalpha << fs::exists(p) << std::endl;

		fs::create_directory(p);
		std::cout << "Does " << p << " exists? : "
			<< std::boolalpha << fs::exists(p) << std::endl;
	}

	void parent_directory_creation_test() {
		fs::path p("./images/17_04_creation_test1/a/b/c");
		std::cout << "Does " << p << " exists? : "
			<< std::boolalpha << fs::exists(p) << std::endl;

		fs::create_directories(p);
		std::cout << "Does " << p << " exists? : "
			<< std::boolalpha << fs::exists(p) << std::endl;
		if (fs::exists(p)) {
			for (const fs::directory_entry& e
				: fs::recursive_directory_iterator(fs::current_path() / "images")) {
				std::cout << e.path() << std::endl;
			}
		}
	}
}

void filesystem_directory_creation_test() {
	FileSystemCreateDir::test();
}

void filesystem_directories_creation_test() {
	FileSystemCreateDir::parent_directory_creation_test();
}


/* Tech.) Directory copy and removal 
	- <ofstream> allows only the copy and the removal of a single file.
	- <filesystem> allows the copy and the removal for an entire directory.
*/

namespace FileSystemCpRm {
	void copy_test() {
		fs::path from("./images/17_04_creation_test1");
		fs::path to("./images/17_04_creation_test");

		fs::copy(from, to, fs::copy_options::recursive);
	}

	void remove_test() {
		fs::path p("./images/17_04_creation_test1/a/b/c");
		std::cout << "Does " << p << " exists? : "
			<< std::boolalpha << fs::exists(p) << std::endl;

		if (fs::exists(p)) {
			fs::remove(p);
		}
		std::cout << "Does " << p << " exists? : "
			<< std::boolalpha << fs::exists(p) << std::endl;
	}
}

void filesystem_copy_test() {
	FileSystemCpRm::copy_test();
}

void filesystem_remove_test() {
	FileSystemCpRm::remove_test();
}


/* Tech.) Caution for Directory Removal Using Iteration
	 - When certain directory is removed, directory_iterator becomes invalid!!!!
	 - Thus, if we iterate and remove directory, we should add logic that initiates iterator whenever a directory is removed!
*/