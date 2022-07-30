#pragma once
#include "01_02_namespace.h"

// How to call elements in namespaces : namespaces are defined in "01_02_namespace.h"
void call_namespaces() {
	header1::foo(); // foo() from header1
	header2::bar(); // bar() from header2
}

using namespace header3;
void call_namespaces2() {
	foo3();
	bar3();
}

// Thus, the syntax std::cout means calling cout from the namespace std.


// Function that can only be used within the file case!
namespace {

	int func_only_in_this_file() { return 0; };
	int var_only_in_this_file = 0;

}

void only_in_this_file() {
	func_only_in_this_file();
}