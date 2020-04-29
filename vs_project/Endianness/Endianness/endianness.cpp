#include <iostream>
#include <cstdio>
#include <string.h>

int main()
{
	//int i = 1;
	//char *p = (char *)&i;
	//if (*p == 1)
	//	printf("Little Endian");
	//else
	//	printf("Big Endian");


	int a = 0x01020304;

	unsigned char* a1 = (unsigned char*)(&a);
	unsigned char* a2 = (a1 + 1);
	unsigned char* a3 = (a1 + 2);
	unsigned char* a4 = (a1 + 3);


	printf("a:%x\n", a);
	printf("a1:%d\n", *a1);
	printf("a2:%d\n", *a2);
	printf("a3:%d\n", *a3);
	printf("a4:%d\n", *a4);


	return 0;
}
