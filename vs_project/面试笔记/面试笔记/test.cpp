#include <iostream>

static int  hello_init(void)
{
	//int a = 0;
	//int *p = &a;
	int *p = 0;
	*p = 1;

	return 0;
}

int main() {
	hello_init();

	return 0;
}