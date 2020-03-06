#include <functional>
#include <iostream> 

std::function<int(int)> make_adder(int add_by) { 
	return [=](int ival) { return ival + add_by; };  //没有捕获（=）将报错
} 
std::function<int(int,int)> make_adder_1(int add_by) {
	return [](int ival, int add_by) { return ival + add_by; };   // make_adder_1 的参数与 add_by_14 无关
}

int main() {
	auto add_by_12 = make_adder(12); 
	std::cout << add_by_12(30) << std::endl; 

	int b = 40;
	std::cout << add_by_12(b) << std::endl;

	auto add_by_14 = make_adder_1(60);
	std::cout << add_by_14(30,20) << std::endl;

	return 0;
}
