#include <iostream>
#include <thread>
void foo() {
	std::cout << "hello world" << std::endl;
}
int main() {
	std::thread t(foo);
	t.join();
	return 0;
}