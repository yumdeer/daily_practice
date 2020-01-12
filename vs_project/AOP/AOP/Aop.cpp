//#include <iostream>
//#include <functional>
//
////using namespace std;
//
///*
// *
// *  使用类型特征将匿名lambda转换为相同类型的std :: function
// *  原文地址：http://vitiy.info/c11-functional-decomposition-easy-way-to-do-aop/
// *
//*/
//
//template <typename ...Args>
//std::function<void(Args...)> wrapLog(std::function<void(Args...)> f) {
//
//	return [f](Args... args) {                                            //捕获函数对象f
//		std::cout << "start" << std::endl;
//		f(args...);
//		std::cout << "finish" << std::endl;
//	};
//}
//
//它是前向声明，声明这个 function_traits_base 结构 是一个 可变参数模板结构
//template <typename> struct function_traits_base;										// 通例， 没有 后面的 特例 则会报错 主模板的声明中不允许使用模板参数列表
//
//template <typename Function>
//struct function_traits : public function_traits_base<decltype(&Function::operator())> {		
//																						// https://segmentfault.com/q/1010000021360347/a-1020000021365367
//};																						// 借助 function_traits 的辅助来获得其对应得 std::function 特化。
//
//// lambda 转换为 std::function<void(Args...)> 需要知道 传入参数类型和返回值类型 ，这里进行萃取 
//template <typename ClassType, typename ReturnType, typename... Args>		 // https://www.cnblogs.com/qicosmos/p/4325949.html
//struct function_traits_base<ReturnType(ClassType::*)(Args...) const>		 // 特例化 ：Args...可变模板参数 ，因为不知道lambda将传入几个参数
//{																			 
//	typedef ReturnType (*pointer)(Args...);									 // 暂时没有作用，可注释
//	typedef std::function<ReturnType(Args...)> function;			
//};
//
////template <typename> struct function_traits;
////
////template  <typename ClassType, typename ReturnType, typename... Args>
////struct function_traits<ReturnType(ClassType::*)(Args...) const>										//Args...可变模板参数 ，因为不知道lambda将传入几个参数
////{
////	typedef std::function<ReturnType(Args...)> function;
////};
//
//template <typename Function>
//typename function_traits<Function>::function	// 返回值类型 - function_traits<Function>::function ， 作为 wrapLog 的 参数类型 std::function<void(Args...)> 
//to_function(Function& lambda)					// 函数名 - to_function，传入参数 - lambda，参数类型 Function& = std::function<void( xx , xx )>
//{
//	return typename function_traits<Function>::function(lambda);	//将lambda传入function_traits<Function>::function,第24行
//}
//
////functional里面有定义了个std::plus。如果把plus定义为global的，访问时在global查找定义就会和std::plus冲突，产生二义。
////auto plus = [](int a, int b) { std::cout << a + b << std::endl; };			//error，Plus不明确
//std::function<void(int, int)> plus = [](int a, int b) { std::cout << a + b << std::endl; };
//
//int main(int argc, char *argv[]) {
//	//这是简单的lambda，其中包含琐碎的计算：
//	//auto plus = [](int a, int b) { cout << a + b << endl; };
//
//	//lambda和 std :: function 无法完成转换
//	//auto loggedPlus = wrapLog(plus);												//test1
//
//	//强制转换，OK，该行可以编译，但是很难看
//	auto loggedPlus  = wrapLog(static_cast<std::function<void(int, int)>>(plus));   //test2
//	loggedPlus(2, 3);
//
//	//暂时最佳解决方案
//	auto loggedPluss = wrapLog(to_function(plus));			//通过调用to_function函数 将 lambda表达式plus 转换为std::function<void(Args...)> 形式
//	loggedPluss(2, 3);
//
//	return 0;
//}






/*
*
*  以下为测试内容
*
*
*/


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


//#include <stdio.h>
//#include <iostream>
//
//void main() {
//	char arr1[] = "abc";
//	char arr2[] = { 'a','b','c','\0' };
//	std::cout << strlen(arr1) << std::endl;
//	printf("%d\n", strlen(arr1));
//	std::cout << strlen(arr2) << std::endl;
//	printf("%d\n", strlen(arr2));
//
//	int a = 4, b = 0, c = 0;
//	b = a << 2;
//	c = a >> 2;
//	std::cout << "a= " << a << " b= " << b << " c= " << c << std::endl;
//
//}



#include <iostream>
#include <functional>

template<typename T1, typename T2, int i, template<typename, int> class CP>
class TMP {                                           // 通例 ， 没有则会 报错 主模板的声明中不允许使用模板参数列表

};

template<typename T1, typename T2, int i, template<typename, int> class CP>
struct TMP<const T1, T2, i, CP> {                    // 特例化

};


template <typename> struct function_traits_base;

																			
template <typename ClassType, typename ReturnType, typename... Args>
struct function_traits_base<ReturnType(ClassType::*)(Args...) const>		
{
	typedef ReturnType (*pointer)(Args...);									
	typedef std::function<ReturnType(Args...)> function;			
};

template <typename Function>
struct function_traits : public function_traits_base<decltype(&Function::operator())> {

};	


int main() {



	return 0;
}