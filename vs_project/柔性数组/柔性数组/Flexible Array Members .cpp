#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>

struct test
{
	int a = 10;			    //  4+4(补)，因为double型需要从8的整数倍开始
	double  b = 20.0;		//  8+8
	char c = 'a';			//  8+8+1+3(补)，因为Int型需要从4的整数倍开始
	int d = 30;				//  8+8+4+4 = 24
	char e = 'e';			//  24+1+7(补)
	char f = 'f';			//  最后第二个元素地址
	char buf[];				//  等于最后第二个元素地址+其字节长+1
};


int main(int *argc, int **argv)
{
	char ch[] = "hello world!";
	std::cout << sizeof(ch) << std::endl;

	//struct test tst;
	//tst.buf = ch;		   // 不可指定数组类型“char []”, 表达式必须是可修改的左值

	struct test* p = (struct test*)malloc(sizeof(struct test) + sizeof(ch) + 1);
	strcpy_s(p->buf, sizeof(ch) + 1, ch);
	std::cout << "结构体大小" <<sizeof(*p) << std::endl;
	std::cout << "结构体首地址" << p << " 结构体尾地址 " << (p + 1) << std::endl;

	std::cout  << &p->a << std::endl;
	std::cout  << &p->b << std::endl;
	std::cout  << (void *) &p->c << std::endl;
	std::cout  << &p->d << std::endl;
	std::cout  << (void *) &(p->e) << std::endl;
	std::cout  << (void *) &(p->f) << std::endl;
	std::cout  << "柔性数组地址/值 " << &p->buf << " " << p->buf << std::endl;
	free(p);

	return 0;
}