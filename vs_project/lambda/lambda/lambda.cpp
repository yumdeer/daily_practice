//值捕获，引用捕获
#include <iostream>
using namespace std;

void learn_lambda_func_3() {
	auto add = [v1 = 1.2, v2 = 2](int x, int y) -> double {
		return x + y + v1 + v2;
	};
	std::cout << "add(3, 4) = " << add(3, 4) << std::endl;
}

int main()
{
	learn_lambda_func_3();

	return 0;
}


//#include <iostream>
//using namespace std;
//
//void learn_lambda_func_1() {
//	int value_1 = 1;
//	auto copy_value_1 = [value_1] {
//		return value_1;
//	};
//	value_1 = 100;
//	auto stored_value_1 = copy_value_1();
//	// 这时, stored_value_1 == 1, 而 value_1 == 100.
//	// 因为 copy_value_1 在创建时就保存了一份 value_1 的拷贝
//	cout << "value_1 = " << value_1 << endl;
//	cout << "stored_value_1 = " << stored_value_1 << endl;
//}
//
//void learn_lambda_func_2() {
//	int value_2 = 1;
//	auto copy_value_2 = [&value_2] {
//		return value_2;
//	};
//	value_2 = 100;
//	auto stored_value_2 = copy_value_2();
//	// 这时, stored_value_2 == 100, value_1 == 100.
//	// 因为 copy_value_2 保存的是引用
//	cout << "value_2 = " << value_2 << endl;
//	cout << "stored_value_2 = " << stored_value_2 << endl;
//}
//
//int main()
//{
//	learn_lambda_func_1();
//	learn_lambda_func_2();
//
//	return 0;
//}


////[] 不捕获任何变量
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int i = 1024;
//	//auto func = []{ cout << i; };			//①
//	//auto func = []() { cout << i; };		//②
//	auto func = [](int i){ cout << i; };	//③
//	
//	//func();								//①②error C3493: 无法隐式捕获“i”，因为尚未指定默认捕获模式
//											//①②error C2064 : 项不会计算为接受 0 个参数的函数
//	
//	func(i);								//①②error C3493: 无法隐式捕获“i”，因为尚未指定默认捕获模式
//											//①②error C2064: 项不会计算为接受 1 个参数的函数
//}


