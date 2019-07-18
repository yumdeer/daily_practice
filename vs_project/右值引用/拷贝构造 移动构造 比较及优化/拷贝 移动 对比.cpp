#include <iostream>
#include <vector>
using namespace std;


//拷贝构造函数 
class TextFile {
public:
	TextFile() {};
	TextFile(const TextFile& tf) { cout << "copy" << endl; };
	TextFile& operator=(TextFile& tf) { cout << "operator=" << endl;      return *this; };
};

int main() {
	vector<TextFile> text_files;
	text_files.push_back(TextFile());             //调用 copy
	TextFile text_file_a;
	//TextFile text_file_b = text_file_a;		  //调用 copy

	TextFile text_file_b;
	text_file_b = text_file_a;                   //调用 operator=
}

// 移动构造函数
class TextFile {
public:
	TextFile() {};
	TextFile(TextFile && tf) { cout << "move" << endl; };
};

int main() {
	vector<TextFile> text_files;
	text_files.push_back(TextFile());     //该行构造了两个一模一样的 TextFile 对象，
										 //一次是在 TextFile 临时对象构造时，
										 //一次是向量在 push_back 时将临时对象又拷贝一份，而第二次构造明显是可以避免的。

}

//返回值优化
class TextFile {
public:
	TextFile() {};
	TextFile(const TextFile& tf) { cout << "copy" << endl; };
	TextFile& operator=(TextFile& tf) { cout << "operator=" << endl; return *this; };
};
TextFile get_tmp_text_file() { TextFile tf; return tf; }

int main()
{
	TextFile tf = get_tmp_text_file();
}