#include <iostream>
#include <functional>

using namespace std;

template <typename ...Args>
std::function<void(Args...)> wrapLog(std::function<void(Args...)> f) {

	return [f](Args... args) {                                            //捕获函数对象f
		std::cout << "start" << std::endl;
		f(args...);
		std::cout << "finish" << std::endl;
	};
}

template <typename Function>
struct function_traits : public function_traits<decltype(&Function::operator())> {

};

//lambda 转换为 std::function<void(Args...)> 需要知道 传入参数类型和返回值类型 ，这里进行萃取 
template <typename ClassType, typename ReturnType, typename... Args>
struct function_traits<ReturnType(ClassType::*)(Args...) const>		 //Args...可变模板参数 ，因为不知道lambda将传入几个参数
{
	//typedef ReturnType (*pointer)(Args...);
	typedef std::function<ReturnType(Args...)> function;			
};


template <typename Function>
typename function_traits<Function>::function	//返回值类型 function_traits<Function>::function
to_function(Function& lambda)					//函数名to_function，传入参数lambda
{
	return typename function_traits<Function>::function(lambda);	//将lambda传入function_traits<Function>::function 
}

//auto plus = [](int a, int b) { cout << a + b << endl; };			//error，Plus不明确

int main(int argc, char *argv[]) {
	//这是简单的lambda，其中包含琐碎的计算：
	auto plus = [](int a, int b) { cout << a + b << endl; };

	//lambda和 std :: function 无法完成转换
	//auto loggedPlus = wrapLog(plus);												//test1

	//强制转换，OK，该行可以编译，但是很难看
	auto loggedPlus  = wrapLog(static_cast<std::function<void(int, int)>>(plus));   //test2
	loggedPlus(2, 3);

	//暂时最佳解决方案
	auto loggedPluss = wrapLog(to_function(plus));			//通过调用to_function函数 将 lambda表达式plus 转换为std::function<void(Args...)> 形式
	loggedPluss(2, 3);

	return 0;
}



//#include <iostream>
//#include <functional>
//
//using namespace std;
//
//
//template <typename ...Args>
//std::function<void(Args...)> wrapLog(std::function<void(Args...)> f)
//{
//	return [f](Args... args) {
//		cout << "start" << endl;
//		f(args...);
//		cout << "finish" << endl;
//	};
//}
//
//int a = 10, b = 15;
//int add(int i, int j) {
//	return i + j;
//}
//
////auto plus = [](int a, int b) { cout << a + b << endl; };            //error Plus不明确
//
//std::function<double(int,int)> addPlus = [v1 = 1, v2 = 2](int x, int y) -> double{
//	return x + y + v1 + v2;
//};
//
//int main(int argc, char *argv[]) {
//	int a = 15, b = 15;
//	cout << add(a, b) << endl;
//	cout << addPlus(a, b) << endl;
//
//	auto plus = [](int a, int b) { cout << a + b << endl; };
//	//auto loggedPlus = wrapLog(plus);                                                
//	auto loggedPlus = wrapLog(static_cast<std::function<void(int, int)>>(plus));
//
//	return 0;
//}