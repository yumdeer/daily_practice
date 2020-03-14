#include <iostream>
#include <cstdio>
#include <bitset>

using namespace std;

union Test
{
	char a[4];
	short b;
};

int isLittleEndian()
{
	{
		union w
		{
			int a;
			char b;
		} c;
		c.a = 1;
		return(c.b == 1);
	}
}

typedef union
{
	char c[10];
	int i;
}u22;

typedef union
{
	char c[10];
	double d;
}u33;

typedef union un {
	short  i;
	char ch[2];
} un;

typedef struct  AA
{
	int b1 : 5;
	int b2 : 2;
}AA;

int main() {
	int i = 1;
	char *p = (char *)&i;
	if (*p == 1)
		printf("Little Endian\n");
	else
		printf("Big Endian\n");

	cout << sizeof(u22) << endl;
	cout << sizeof(u33) << endl;

	Test test;
	test.a[0] = 256;
	test.a[1] = 255;
	test.a[2] = 254;
	test.a[3] = 253;
	printf("%d\n", test.b);

	un u;
	u.ch[0] = 10;
	u.ch[1] = 1;

	printf("%d\n", u.i);

	AA aa;
	char cc[100];
	strcpy_s(cc, "0123456789abcdefghijklmnopqrstuvwxyz");
	memcpy(&aa, cc, sizeof(AA));
	cout << bitset<8>(aa.b1)  << endl;
	cout << aa.b1 << endl;
	cout << bitset<8>(aa.b2) << endl;
	cout << aa.b2 << endl;
}
