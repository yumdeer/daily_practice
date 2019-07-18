//C++11 提供的正则表达式库操作 std::string 对象，模式 std::regex(本质是 std::basic_regex)进行初始化，通过 std::regex_match 进行匹配，
//从而产生 std::smatch （本质是 std::match_results 对象）。

#include <iostream>
#include <string>
#include <regex>

int main() {

	// 简单正则表达式匹配
	std::string fnames[] = { "foo.txt", "bar.txt", "test", "a0.txt", "AAA.txt" };
	std::regex txt_regex("[a-z]+\\.txt");		//是否匹配a-z.txt
	for (const auto &fname : fnames)
		std::cout << fname << ": " << std::regex_match(fname, txt_regex) << std::endl;	//匹配 输出1 否则 输出 0
	std::cout << std::endl;
	// 提取子匹配
	std::regex base_regex("([a-z]+)\\.txt");
	std::smatch base_match;
	for (const auto &fname : fnames) {
		if (std::regex_match(fname, base_match, base_regex)) {
			// 首个 sub_match 是整个字符串；下个sub_match 是首个有括号表达式。
			if (base_match.size() == 2) {
				std::ssub_match base_sub_match = base_match[1];
				std::string base = base_sub_match.str();
				std::cout << fname << " has a base of " << base << '\n';
			}
		}
	}
	std::cout << std::endl;
	// 提取几个子匹配
	std::regex pieces_regex("([a-z]+)\\.([a-z]+)");
	std::smatch pieces_match;
	for (const auto &fname : fnames) {
		if (std::regex_match(fname, pieces_match, pieces_regex)) {
			std::cout << fname << '\n';
			for (size_t i = 0; i < pieces_match.size(); ++i) {
				std::ssub_match sub_match = pieces_match[i];
				std::string piece = sub_match.str();
				std::cout << "  submatch " << i << ": " << piece << '\n';
			}
		}
	}

}