#include <iostream>
#include <utility>

void learn_lambda_func_3() {
	auto important = std::make_unique<int>( 1 );
	auto add = [v1 = 1, v2 = std::move(important)](int x, int y) -> int {
		return x + y + v1 + (*v2);
	};
	std::cout << "add(3, 4) = " << add(3, 4) << std::endl;
}

int main()
{
	learn_lambda_func_3();

	return 0;
}

//void learn_lambda_func_4() {
//	auto generic = [](auto x, auto y) {
//		return x + y;
//	};
//
//	std::cout << "generic(1,2) = " << generic(1, 2) << std::endl;
//	std::cout << "generic(1.1,2.2) = " << generic(1.1, 2.2) << std::endl;
//}
//
//int main()
//{
//	learn_lambda_func_4();
//
//	return 0;
//}