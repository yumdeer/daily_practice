#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>

int main() {

	// 两组结构按同样的顺序初始化
	std::unordered_map<int, std::string> umap = {
		{1, "1"},
		{3, "3"},
		{2, "2"}
	};
	std::map<int, std::string> map = {
		{1, "1"},
		{3, "3"},
		{2, "2"}
	};

	// 分别对两种容器进行遍历
	std::cout << "std::unordered_map" << std::endl;
	for (const auto &n : umap)
		std::cout  << &n <<" "<< "Key:[" << n.first << "] Value:[" << n.second << "]\n";

	std::cout << std::endl;
	std::cout << "std::map" << std::endl;
	for (const auto & n : map)
		std::cout << &n << " " << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
}