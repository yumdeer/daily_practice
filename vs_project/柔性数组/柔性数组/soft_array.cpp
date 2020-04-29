//#include <iostream>
//#include <cstdio>
//#include <vector>
//#include <string>
//
//struct test
//{
//	int a = 10;
//	double b = 20.0;
//	char *buf = nullptr ;  
//};
//
//struct test2
//{
//	int a = 10;
//	double b = 20.0;
//	char buf[];
//};
//
//struct test3
//{
//	int a = 10;
//	double b = 20.0;
//	std::string buf;
//};
//
//struct test4
//{ 
//	int a = 10 ;			//  4+4(补)，因为double型需要从8的整数倍开始
//	double  b = 20.0;		//  8+8
//	char c = 'a';			//  8+8+1+3(补)，因为Int型需要从4的整数倍开始
//	int d = 30;				//  8+8+4+4 = 24
//	char e = 'e';			//  24+1+7(补)
//	char f = 'f';			//  
//	char buf[];				//  等于最后一个元素地址+其字节长+1
//};
//
//int main(int *argc, int **argv)
//{
//	char ch[] = "hello world!";
//	std::cout << sizeof(ch) << std::endl;
//
//	std::cout << "test : " << std::endl;
//	struct test t;
//	std::cout << t.a << " " << t.b << std::endl;
//
//
//	std::cout << "test1 : " << std::endl;
//	//struct test p; p.buf = ch;
//	//std::cout << p.a << p.b << p.buf << std::endl;
//	struct test* p = (struct test*)malloc(sizeof(struct test) + sizeof(ch) + 1);
//	p->buf = ch;
//	//std::cout << (char*)(p + 1) << std::endl;
//	std::cout << &p->a <<" "<<  &p->b << " " << &p->buf << " " << p->buf << std::endl;
//
//	std::cout << "test2 : " << std::endl;
//	struct test2* p2 = (struct test2*)malloc(sizeof(struct test2) + sizeof(ch) + 1);
//	strcpy_s(p2->buf, sizeof(ch)+1, ch);
//	//strcpy_s((char*)(p2 + 1), sizeof(ch) + 1, ch);
//	std::cout << (char*)(p2 + 1) << std::endl;
//	std::cout << p2->buf << std::endl;
//
//	std::cout << "test3 : " << std::endl;
//	struct test3* p3 = (struct test3*)malloc(sizeof(struct test3) + sizeof(ch) + 1);
//	//p3->buf = ch;
//	//std::cout << p3->buf << std::endl;
//
//
//	std::cout << "test4 : " << std::endl;
//	struct test4* p4 = (struct test4*)malloc(sizeof(struct test4) + sizeof(ch) + 1);
//	strcpy_s(p4->buf, sizeof(ch) + 1, ch);
//	p4->e = 'e';
//	std::cout << (char*)(p4 + 1) << std::endl;
//	std::cout << sizeof(*p4) << std::endl;
//	std::cout << p4 << " " << (p4 + 1) << " " << &p4->a << " " << &(p4->e) << " " << &p4->buf << " " << p4->buf << std::endl;
//	//std::cout << p4->buf << std::endl;
//	
//
//	free(p);
//	free(p2);
//	free(p3);
//	free(p4);
//
//	return 0;
//}