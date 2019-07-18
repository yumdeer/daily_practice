#include <memory>
#include <iostream>
#include <string>

int main()
{
	std::allocator<int> a1;   // int 的默认分配器
	int* a = a1.allocate(1);  // 一个 int 的空间
	a1.construct(a, 7);       // 构造 int
	std::cout << a[0] << '\n';
	a1.deallocate(a, 1);      // 解分配一个 int 的空间

	// string 的默认分配器
	std::allocator<std::string> a2;

	// 同上，但以 a1 的重绑定获取
	decltype(a1)::rebind<std::string>::other a2_1;

	// 同上，但通过 allocator_traits 由类型 a1 的重绑定获取
	std::allocator_traits<decltype(a1)>::rebind_alloc<std::string> a2_2;

	std::string* s = a2.allocate(2); // 2 个 string 的空间

	a2.construct(s, "foo");
	a2.construct(s + 1, "bar");

	std::cout << s[0] << ' ' << s[1] << '\n';

	a2.destroy(s);
	a2.destroy(s + 1);
	a2.deallocate(s, 2);
}


