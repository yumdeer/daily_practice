#include <iostream>
#include <string>
#include <memory>

template<typename T, typename ...Args>
std::unique_ptr<T> make_unique(Args&& ...args) {
	return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

struct Foo {
	Foo() { std::cout << "Foo::Foo" << std::endl; }
	~Foo() { std::cout << "Foo::~Foo" << std::endl; }
	void foo() { std::cout << "Foo::foo" << std::endl; }
};

void f(const Foo &) {
	std::cout << "f(const Foo&)" << std::endl;
}

int main()
{
	//std::unique_ptr 是一种独占的智能指针，它禁止其他智能指针与其共享同一个对象，从而保证了代码的安全
	std::unique_ptr<int> pointer = std::make_unique<int>(10);	 // make_unique 从 C++14 引入
	//std::unique_ptr<int> pointer2 = pointer;    // 非法

	std::unique_ptr<Foo> p1(std::make_unique<Foo>());       //输出:Foo::Foo
	// p1 不空, 输出
	if (p1) p1->foo();										//输出:Foo::foo
	{
		//既然是独占，换句话说就是不可复制。但是，我们可以利用 std::move 将其转移给其他的 unique_ptr
		std::unique_ptr<Foo> p2(std::move(p1));

		// p2 不空, 输出
		f(*p2);												//输出:f(const Foo&)

		// p2 不空, 输出
		if (p2) p2->foo();									//输出:Foo::foo

		// p1 为空, 无输出
		if (p1) p1->foo();									
		
		//将p2控制权还给p1
		p1 = std::move(p2);

		// p2 为空, 无输出
		if (p2) p2->foo();
		std::cout << "p2 被销毁" << std::endl;				//输出:p2 被销毁
	}
	// p1 不空, 输出
	if (p1) p1->foo();										//输出:Foo::foo

	// Foo 的实例会在离开作用域时被销毁

	return 0;												//输出:Foo::~Foo
}
