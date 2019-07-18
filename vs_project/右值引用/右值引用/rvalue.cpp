#include <iostream>
#include <string>

void reference(std::string& str) {
	std::cout << "左值" << std::endl;
}
void reference(std::string&& str) {
	std::cout << "右值" << std::endl;
}

int main()
{
	std::string  lv1 = "string,";			 // lv1 是一个左值
	//std::string&& rv2 = lv1 ;				// 非法,lv1 是一个左值
	// std::string&& r1 = s1;				// 非法, s1 在全局上下文中没有声明
	reference(std::move(lv1));				// std::move 可以将左值转移为右值
	std::string&& rv1 = std::move(lv1);		// 合法, std::move 可以将左值转移为右值
	std::cout << "rv1 = " << rv1 << std::endl;      // string,

	const std::string& lv2 = lv1 + lv1;		// 合法, 常量左值引用能够延长临时变量的生命周期
	// lv2 += "Test";						// 非法, 引用的右值无法被修改
	std::cout << "lv2 = " << lv2 << std::endl;      // string,string

	//std::string&& rv2 = lv1 + lv1;		// 合法，lv1 + lv1生成一个临时对象
	std::string&& rv2 = lv1 + lv2;			// 合法, 右值引用延长临时对象的生命周期
	rv2 += "string";					    // 合法, 非常量引用能够修改临时变量
	std::cout << "rv2 = " << rv2 << std::endl;      // string,string,string,

	reference(rv2);							// 输出左值,rv2 虽然引用了一个右值，但由于它是一个引用，所以 rv2 依然是一个左值。
}