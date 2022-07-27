#include <stdio.h>
#include "pragma.h"

void pragma_packed_simulator() {
	auto_packed_test();
	pragma_packed_test();
}

typedef struct AutoPacked {
	char arr[2];
	int i;
} AutoPacked;

void auto_packed_test() {
	AutoPacked ap;
	printf("AutoPacked size : %d\n", (int)sizeof(ap));  // Double Word Allignment : 4Byte forced to each variables in the struct.
}

#pragma pack(1)
typedef struct PragmaPacked {
	char arr[2];
	int i;
} PragmaPacked;

void pragma_packed_test() {
	PragmaPacked pp;
	printf("PragmaPacked size : %d\n", (int)sizeof(pp));  // Forced 1Byte as the minimum unit of each variables.
}



// Deliberately duplicated definition of ForPragmaOnce
struct ForPragmaOnce {
	int num;
};

void pragma_once_test() {
	struct ForPragmaOnce fpo;

	fpo.num = 1;
	printf("%d", fpo.num);

}