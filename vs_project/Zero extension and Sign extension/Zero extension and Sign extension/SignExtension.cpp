#include <iostream> 
#include <string>
#include <algorithm>
#include <bitset>       

int main()
{

	int i = 129;
	char chA = (char)i;
	int c = (int)(unsigned char)chA;
	int b = (int)chA;

	std::cout << "sign extension: " << b << std::endl;
	std::cout << "zero extension: " << c << std::endl;

    char d = -127;
	std::bitset <sizeof(int) * 8> x(d);   
	std::cout << "sign extension: " << x << std::endl;
	unsigned char e = (d & 0XFF);
	std::bitset <sizeof(int) * 8> y(e);
	std::cout << "sign extension: " << y << std::endl;
	
	return 0;
}