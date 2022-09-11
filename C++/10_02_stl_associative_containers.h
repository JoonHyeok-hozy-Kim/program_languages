#include <iostream>
#include <set>
#include <string>

///////////////////////////////////////////////
/* Sets */
template <typename T>
void print_set(std::set<T>& s);
void stl_set_test();

// Custom key-value set class definition for the set-insertion test.
class CustomKeyValSet {
protected:
	int key;
	int value;

public:
	CustomKeyValSet(int key, int value) : key(key), value(value) {};
	//bool operator<(const CustomKeyValSet& c) const;	// key value comparison		// use comparison struct instead!
	friend std::ostream& operator<<(std::ostream& o, const CustomKeyValSet& c);
	friend struct CustomKeyValSetCmp;	// comparison struct
};

// comparison struct
struct CustomKeyValSetCmp {
	bool operator()(const CustomKeyValSet& c1, const CustomKeyValSet& c2) const;
};

template <typename T, typename C>
void print_set(std::set<T, C>& s);

void stl_set_custom_object_insertion_test();



///////////////////////////////////////////////
/* Maps */
#include <map>
template <typename K, typename V>
void print_map(std::map<K, V> map);

void stl_map_insertion_test();
void stl_map_search_test();


///////////////////////////////////////////////
/* Multiset / Multimap */
template <typename T>
void print_set(std::multiset<T>& ms);

template <typename K, typename V>
void print_map(std::multimap<K, V>& mm);

void stl_multset_multimap_test();



///////////////////////////////////////////////
/* unordered_set / unordered_map */
#include <unordered_set>
#include <unordered_map>
void unordered_set_unordered_map_test();


#include <functional>	// included for the hash function!
// Custom object containing : Use Hash function!
class CustomForHash : CustomKeyValSet {
public:
	CustomForHash(int key, int val) : CustomKeyValSet(key, val) {};
	bool operator==(const CustomForHash& other) const;
	friend std::ostream& operator<<(std::ostream& o, const CustomForHash& c);
	friend struct std::hash<CustomForHash>;		// hash function for CustomForHash class!
};

// hash function for CustomForHash class!
namespace std {
	template <>
	struct hash<CustomForHash> {
		size_t operator()(const CustomForHash& cfh) const {
			hash<int> hash_func;
			std::cout << "In hash, hash_func(cfh.value) = " << hash_func(cfh.value) << std::endl;
			return cfh.key ^ (hash_func(cfh.value));
		}
	};
}

void custom_hash_test();