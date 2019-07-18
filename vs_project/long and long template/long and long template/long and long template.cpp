//#include <iostream>
//#include <string>

/*计算参数的个数
template<typename... Args>
void magic(Args... args) {
	std::cout << sizeof...(args) << std::endl;
}
int main()
{
	magic();        // 输出0
	magic(1);       // 输出1
	magic(1, "");   // 输出2

}
*/

/********************************************************************************/
/*******************								 ****************************/
/*##################对参数进行解包,两种经典的处理手法###########################*/
/*******************								 ****************************/
/********************************************************************************/


/********************************************************************************/
//一、递归模板函数
//递归模板函数是一种标准的做法，但缺点显而易见的在于必须定义一个终止递归的函数。
//下例会输出每一个参数，直到为空时输出empty。
//展开参数包的函数有两个，一个是递归函数，另外一个是递归终止函数，参数包Args...在展开的过程中递归
//调用自己，每调用一次参数包中的参数就会少一个，直到所有的参数都展开为止，当没有参数时，
//则调用非模板函数print终止递归过程。
//递归调用的过程是这样的:
//print(1,2,3,4);
//print(2, 3, 4);
//print(3, 4);
//print(4);
//print();

//#include <iostream>
//using namespace std;
////递归终止函数
//void print()
//{
//	cout << "empty" << endl;
//}
////展开函数
//template <class T, class ...Args>
//void print(T head, Args... rest)
//{
//	cout << "parameter " << head << endl;
//	print(rest...);
//}
//
//
//int main(void)
//{
//	print(1, 2, 3, 4);
//	return 0;
//}


/**************************************************************************************************/
//上面的递归终止函数还可以写成这样
//修改递归终止函数后，上例中的调用过程是这样的
//print(1, 2, 3, 4);
//print(2, 3, 4);
//print(3, 4);
//print(4);

//#include <iostream>
//
//template<typename T>
//void printf(T value) {
//	std::cout << value << std::endl;
//}
//
//template<typename T, typename... Args>
//void printf(T value, Args... args) {        //该函数不接受0个参数
//	std::cout << value << std::endl;
//	printf(args...);                        //迭代printf(T value, Args... args)本身，当参数剩下一个将调用printf(T value) 
//}
//
//
//int main() {
//	printf(1, 2, "123", 1.1);		//递归模板函数
//	return 0;
//}



/******************************************************************************************************/
//二、不使用递归版本，借助逗号表达式和初始化列表

//printarg不是一个递归终止函数，只是一个处理参数包中每一个参数的函数。
//逗号表达式：这种就地展开参数包的方式实现的关键是逗号表达式，逗号表达式会按顺序执行逗号前面的表达式。
//            逗号表达式会按顺序执行逗号前面的表达式，比如：d = (a = b, a+c); 
//            这个表达式会按顺序执行：b会先赋值给a，接着括号中的逗号表达式返回a+c的值，因此d将等于a+c。
//初始化列表：通过初始化列表来初始化一个变长数组, { (printarg(args), 0)... }将会展开成
//            ((printarg(arg1), 0), (printarg(arg2), 0), (printarg(arg3), 0), etc...)，
//            最终会创建一个元素值都为0的数组int arr[sizeof...(Args)]。

//#include <iostream>
//
//template <class T>
//void printarg(T t)
//{
//	std::cout << t << std::endl;
//}
//
//template <class ...Args>
//void expand(Args... args)
//{
//	int arr[] = { (printarg(args), 0)... };
//}
//
//int main() {
//	expand(1, 2, 3, 4);
//
//	return 0;
//}


//我们可以把上面的例子再进一步改进一下，将函数作为参数，就可以支持lambda表达式了，
//从而可以少写一个递归终止函数了，具体代码如下：


//#include <iostream>
//
//template<class F, class... Args>void expand(const F& f, Args&&...args)
//{
//	//这里用到了完美转发
//	std::initializer_list<int>{(f(std::forward<Args>(args)), 0)...};
//}
//
//int main() {
//	expand([](int i) {std::cout << i << std::endl; }, 1, 2, 3);
//	//expand([](auto i) {std::cout << i << std::endl; }, 1, 2.0, ”test”);
//
//	return 0;
//}


//通过初始化列表，(lambda 表达式, value)... 将会被展开。
//由于逗号表达式的出现，首先会执行前面的 lambda 表达式，完成参数的输出。
//唯一不美观的地方在于如果不使用 return 编译器会给出未使用的变量作为警告。
//C++14的新特性泛型lambda表达式.更泛化的lambda表达式,适配auto.
//编译这个代码需要开启 -std=c++14

////lambda表达式：定义[](){}，声明并调用[](){}(). 
//
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	[](){
//		cout << "Hello,World\n";
//	}();
//}

#include <iostream>

template<typename T, typename... Args>
auto print(T value, Args... args) {
	std::cout << value << std::endl;
	return std::initializer_list<T>{([&](){
		std::cout << args << std::endl;
	}(), value)...};
}
int main() {
	print(1, 2.1, "test");			//使用初始化列表
	return 0;
}

