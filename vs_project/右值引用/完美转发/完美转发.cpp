//推导示例

//#include <iostream>
////using namespace std;
//
//void reference(int& v) {
//	std::cout << "左值" << std::endl;
//}
//
//void reference(int&& v) {													/*输出结果*/
//	std::cout << "右值" << std::endl;										//传递右值:
//}																			//普通传参:左值
//
//template <typename T>														//传递左值:
//void pass(T&& v) {														//普通传参:左值
//	std::cout << "普通传参:";
//	reference(v);   // 始终调用 reference(int& )
//}
//
//int main() {
//	std::cout << "传递右值:" << std::endl;
//	pass(1);        // 1是右值, 但输出左值: 进入移动语句，调用reference(v),但由于 v 是一个引用，所以同时也是左值。
//					// 因此 reference(v) 会调用 reference(int&)，输出『左值』。
//	std::cout << std::endl;
//	std::cout << "传递左值:" << std::endl;
//	int v = 1;
//	pass(v);        // v是左引用, 为什么会调用移动语句，输出左值？
//					// 这是基于引用坍缩规则的：在传统 C++ 中，我们不能够对一个引用类型继续进行引用，
//					// 但 C++ 由于右值引用的出现而放宽了这一做法，从而产生了引用坍缩规则，允许我们对引用进行引用，既能左引用，又能右引用。
//
//	return 0;
//}
//模板函数中使用 T&& 不一定能进行右值引用，当传入左值时，此函数的引用将被推导为左值。
//更准确的讲，无论模板参数是什么类型的引用，当且仅当实参类型为右引用时，模板参数才能被推导为右引用类型。
//所以才使得 v 作为左值的成功传递。

//完美转发
//所谓完美转发，就是为了让我们在传递参数的时候，保持原来的参数类型（左引用保持左引用，右引用保持右引用）。
//为了解决这个问题，我们应该使用 std::forward 来进行参数的转发（传递）：
#include <iostream>
#include <utility>

void reference(int& v) {
	std::cout << "左值引用" << std::endl;
}

void reference(int&& v) {
	std::cout << "右值引用" << std::endl;
}

//template <typename T>
//void pass(T& v) {
//	std::cout << "普通传参0:";
//	reference(v);
//	std::cout << "std::move 传参0:";
//	reference(std::move(v));
//	std::cout << "std::forward 传参0:";
//	reference(std::forward<T>(v));
//}

template <typename T>
void pass(T&& v) {
	std::cout << "普通传参:";
	reference(v);							   //引用折叠的类型
	std::cout << "std::move 传参:";
	reference(std::move(v));                   //强制转化为右值
	std::cout << "std::forward 传参:";
	reference(std::forward<T>(v));             //显示实际类型

}

int main() {
	std::cout << "传递右值:" << std::endl;
	pass(1);
	std::cout <<  std::endl;

	std::cout << "传递左值:" << std::endl;
	int v = 1;
	pass(v);

	return 0;
}