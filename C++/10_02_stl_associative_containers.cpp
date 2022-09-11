#include "10_02_stl_associative_containers.h"

/* Set : contains only keys. */

template <typename T>
void print_set(std::set<T>& s) {
	std::cout << "[";
	for (typename std::set<T>::iterator itr = s.begin(); itr != s.end(); ++itr) {
		std::cout << *itr << " ";
	}
	std::cout << "]\n";
}

/* Set containing pre-defined data types */
void stl_set_test() {
	std::set<int> s;
	for (int i = 0; i < 5; i++) s.insert(i);

	// iteration test : sequential
	print_set(s);

	// find method -> returns s.end() if not found!
	auto itr1 = s.find(3);
	std::cout << "find method test : ";
	if (itr1 != s.end()) std::cout << *itr1 << std::endl;
	else std::cout << "Fail." << std::endl;
	auto itr2 = s.find(6);
	std::cout << "find method test : ";
	if (itr2 != s.end()) std::cout << *itr2 << std::endl;
	else std::cout << "Fail" << std::endl;
}



/* Set containing custom data types */
/*  - Must define "<" operator, i.e. comparison between keys */


//bool CustomKeyValSet::operator<(const CustomKeyValSet& c) const {		// Use comparison struct instead
//	if (key == c.key) return value < c.value;
//	return key < c.key;
//}
std::ostream& operator<<(std::ostream& o, const CustomKeyValSet& c) {
	o << "<Key : " << c.key << " / Value : " << c.value << ">";
	return o;
}

// comparison struct
bool CustomKeyValSetCmp::operator()(const CustomKeyValSet& c1, const CustomKeyValSet& c2) const {
	if (c1.key == c2.key) return c1.value < c2.value;
	return c1.key < c2.key;
}

// Method overloading for comparison struct usage.
template <typename T, typename C>
void print_set(std::set<T, C>& s) {
	std::cout << "[";
	for (typename std::set<T>::iterator itr = s.begin(); itr != s.end(); ++itr) {
		std::cout << *itr << " ";
	}
	std::cout << "]\n";
}

void stl_set_custom_object_insertion_test() {
	std::set<CustomKeyValSet, CustomKeyValSetCmp> custom_class_set;
	for (int i = 0; i < 10; i++) {
		custom_class_set.insert(CustomKeyValSet(i, i));
	}

	print_set(custom_class_set);
}



///////////////////////////////////////////////////////////
/* Map : contains keys and values. */
template <typename K, typename V>
void print_map(std::map<K, V> map) {
	std::cout << "{";
	/*for (auto itr = map.begin(); itr != map.end(); ++itr) {
		std::cout << "<Key:" << itr->first << " - Value:" << itr->second << "> ";
	}*/
	for (const auto& kv : map) {
		std::cout << "<Key:" << kv.first << " - Value:" << kv.second << "> ";
	}
	std::cout << "}" << std::endl;
}

void stl_map_insertion_test() {
	std::map<int, int> m1;

	// insert method of map class gets std::pair object as input.
	for (int i = 0; i < 5; i++) m1.insert(std::pair<int, int>(i, i+1));
	print_map(m1);

	// or use std::make_pair function
	for (int i = 0; i < 5; i++) m1.insert(std::make_pair((i + 1) * 10, (i + 1) * 100));
	print_map(m1);

	// or use operator[]
	for (int i = 0; i < 5; i++) m1[(i + 1) * (-1)] = (i + 1) * (-10);
	print_map(m1);
}

void stl_map_search_test() {
	std::map<int, int> m;
	for (int i = 0; i < 5; i++) m[i] = i;

	print_map(m);

	auto itr1 = m.find(3);
	std::cout << "Search result : ";
	if (itr1 != m.end()) std::cout << m[3];
	else std::cout << "Fail";
	std::cout << std::endl;

	auto itr2 = m.find(10);
	std::cout << "Search result : ";
	if (itr2 != m.end()) std::cout << m[10];
	else std::cout << "Fail";
	std::cout << std::endl;
}



///////////////////////////////////////////////////////////
/* MultiSet / MultiMap : allow repeated keys */
template <typename T>
void print_set(std::multiset<T>& ms) {
	std::cout << "[";
	for (const auto& element : ms) std::cout << element << " ";
	std::cout << "]" << std::endl;
}

template <typename K, typename V>
void print_map(std::multimap<K, V>& mm) {
	std::cout << "{";
	for (const auto& kv : mm) {
		std::cout << "Key:" << kv.first << "-Value:" << kv.second << " ";
	}
	std::cout << "}" << std::endl;
}

void stl_multset_multimap_test() {
	std::multiset<int> ms;
	ms.insert(1);
	ms.insert(1);
	ms.insert(2);
	print_set(ms);

	std::multimap<int, int> mm;
	for (int i = 0; i < 3; i++) mm.insert(std::make_pair(0, i));
	print_map(mm);

	// return values that share a same key.
	auto range = mm.equal_range(0);
	std::cout << "equal range : [";
	for (auto itr = range.first; itr != range.second; ++itr) {
		std::cout << itr->first << " : " << itr->second << ", ";
	}
	std::cout << "]\n";
}



///////////////////////////////////////////////////////////
/* unordered_set / unordered_map : Use hash function and enables O(1) search/insert/delete in average */
template <typename T>
void print_set(std::unordered_set<T>& us) {
	std::cout << "[";
	for (const auto& k : us) std::cout << k << " ";
	std::cout << "]\n";
}

template <typename K, typename V>
void print_map(std::unordered_map<K, V>& um) {
	std::cout << "{";
	for (const auto& kv : um) std::cout << "Key:" << kv.first << "-Value:" << kv.second << ", ";
	std::cout << "}\n";
}

void unordered_set_unordered_map_test() {
	std::unordered_set<int> us;
	for (int i = 0; i < 10; i++) us.insert(i % 3);
	print_set(us);


	std::unordered_map<int, int> um;
	for (int i = 0; i < 10; i++) um.insert(std::make_pair(i % 3, i));
	print_map(um);
}


// Custom object containing : Use Hash function!
bool CustomForHash::operator==(const CustomForHash& other) const {
	return (key == other.key && value == other.value);
}
std::ostream& operator<<(std::ostream& o, const CustomForHash& c) {
	return operator<<(o, (CustomKeyValSet)c);
}


void custom_hash_test() {
	std::unordered_set<CustomForHash> us;

	CustomForHash c1(1, 1);
	std::cout << c1 << std::endl;

	us.insert(CustomForHash(1, 1));
	us.insert(CustomForHash(2, 2));
	
	print_set(us);
	
}