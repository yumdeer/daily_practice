//std::shared_ptr 就会发现依然存在着资源无法释放的问题

//#include <iostream>
//#include <memory>
//
//class A;
//class B;
//
//class A {
//public:
//	std::shared_ptr<B> pointer;
//	~A() {
//		std::cout << "A 被销毁" << std::endl;
//	}
//};
//class B {
//public:
//	std::shared_ptr<A> pointer;
//	~B() {
//		std::cout << "B 被销毁" << std::endl;
//	}
//};
//int main() {
//	std::shared_ptr<A> a = std::make_shared<A>();
//	std::shared_ptr<B> b = std::make_shared<B>();
//	a->pointer = b;
//	b->pointer = a;
//
//	return 0;
//}




//解决这个问题的办法就是使用弱引用指针 std::weak_ptr，std::weak_ptr是一种弱引用（相比较而言 std::shared_ptr 就是一种强引用）
//弱引用不会引起引用计数增加.
//std::weak_ptr 没有 * 运算符和 -> 运算符，所以不能够对资源进行操作，它的唯一作用就是用于检查 std::shared_ptr 是否存在，
//expired() 方法在资源未被释放时，会返回 true，否则返回 false。
#include <iostream>
#include <memory>

class A;
class B;

class A {
public:
	// A 或 B 中至少有一个使用 weak_ptr
	std::weak_ptr<B> pointer;
	~A() {
		std::cout << "A 被销毁" << std::endl;
	}
};
class B {
public:
	std::shared_ptr<A> pointer;
	~B() {
		std::cout << "B 被销毁" << std::endl;
	}
};
int main() {
	std::shared_ptr<A> a = std::make_shared<A>();
	std::shared_ptr<B> b = std::make_shared<B>();
	a->pointer = b;
	b->pointer = a;

	return 0;
}

//shared_ptr 和 weak_ptr 是一个强引用和弱引用的关系：
//一个强引用当被引用的对象活着的话，这个引用也存在（就是说，当至少有一个强引用，那么这个对象就不能被释放）。
//相对而言，弱引用当引用的对象活着的时候不一定存在, 仅仅是当它存在的时候的一个引用。
//弱引用并不修改该对象的引用计数，这意味这弱引用它并不对对象的内存进行管理，在功能上类似于普通指针.一个比较大的区别是，
//弱引用能检测到所管理的对象是否已经被释放，从而避免访问非法内存。