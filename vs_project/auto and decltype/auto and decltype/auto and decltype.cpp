#include <iostream>

using namespace std;

class Person
{
public:
	enum PersonType { ADULT, CHILD, SENIOR };
	void setPersonType(PersonType person_type);
	PersonType getPersonType();
private:
	PersonType _person_type;
};

//第一个函数，设置器，没什么好说的，你可以直接使用枚举类型PersonType，没任何问题：
void Person::setPersonType(PersonType person_type)
{
	_person_type = person_type;
}

//但是，第二个函数就有点问题了。最漂亮的代码却无法通过编译
// 编译器不知道 PersonType 是什么，因为 PersonType 在 Person 类的外面使用
//PersonType Person::getPersonType()
//{
//	return _person_type;
//}

//Person::PersonType Person::getPersonType()
//{
//	return _person_type;
//}

auto Person::getPersonType() -> PersonType
{
	return _person_type;
}

//error a\b can`t find  
//template <typename T1, typename T2>
//decltype(a + b) compose(T1 a, T2 b) {
//	
//		return a + b;;
//}

//template <typename T1, typename T2>
//decltype(std::declval<T1>() + std::declval<T2>())
//compose(T1 a, T2 b)
//{
//	return a + b;
//}

template <typename T1, typename T2>
auto compose(T1 a, T2 b) -> decltype(a + b) {
	return a + b;
}

int main() {
	int i=0, j=10;
	cout << compose(i,j)<< endl;

	return 0;
}




