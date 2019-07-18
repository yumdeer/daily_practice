//#include <iostream>

//struct stc {
//	int a = 10;
//};
//
//int main()
//{
//	stc aa;
//	std::cout << aa.a << std::endl;
//
//}

//示例1
#include <iostream>

//枚举类型后面使用了冒号及类型关键字来指定枚举中枚举值的类型，这使得我们能够为枚举赋值（未指定时将默认使用 int）
enum class new_enum : unsigned int {
	value1,
	value2 = 100,
	value3 = 200,
	value4 = 200
};

//通用方案
//template<typename T>
//std::ostream& operator<<(typename std::enable_if<std::is_enum<T>::value, std::ostream>::type& stream, const T& e)
//{
//	return stream << static_cast<typename std::underlying_type<T>::type>(e);
//}

//自己写的重载方案
std::ostream& operator<<(std::ostream& os, new_enum al)
{
	return os << static_cast<unsigned int>(al);
}

int main()
{
	//相同枚举值之间如果指定的值相同，那么可以进行比较
	if (new_enum::value3 == new_enum::value4) {
		std::cout << "new_enum::value3 == new_enum::value4" << std::endl;
	}
	
	//而我们希望获得枚举值的值时，将必须显式的进行类型转换，不过我们可以通过重载 << 这个算符来进行输出
	//std::cout << new_enum::value3 << std::endl;

	new_enum n_enum;
	n_enum = new_enum::value2;
	std::cout << n_enum<< std::endl;
	
	return 0;
}

//示例2
//#include <iostream>
//
//// 采用 16 位的 enum
//enum smallenum : int16_t
//{
//	a,
//	b,
//	c
//};
//
//
//// color 可为 red（值 0）、yellow（值 1）、green（值 20）或 blue（值 21）
//enum color
//{
//	red,
//	yellow,
//	green = 20,
//	blue
//};
//
//// altitude 可为 altitude::high 或 altitude::low
//enum class altitude : char
//{
//	high = 'h',
//	low = 'l', // C++11 允许尾随逗号
//};
//
//// 常量 d 为 0，常量 e 为 1，常量 f 为 3
//enum
//{
//	d,
//	e,
//	f = e + 2
//};
//
//// 枚举类型（有作用域和无作用域）能拥有重载的运算符
//std::ostream& operator<<(std::ostream& os, color c)
//{
//	switch (c)
//	{
//	case red: os << "red";    break;
//	case yellow: os << "yellow"; break;
//	case green: os << "green";  break;
//	case blue: os << "blue";   break;
//	default: os.setstate(std::ios_base::failbit);
//	}
//	return os;
//}
//
//std::ostream& operator<<(std::ostream& os, altitude al)
//{
//	return os << static_cast<char>(al);
//}
//
//int main()
//{
//	color col = red;
//	altitude a;
//	a = altitude::low;
//
//	std::cout << "col = " << col << '\n'
//		<< "a = " << a << '\n'
//		<< "f = " << f << '\n';
//}
