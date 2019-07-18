#include <iostream>
#include <string>

int main ()
{
	std::string str;
	std::string str2="Writing ";
	std::string str3="print 10 and then 5 more";

	// used in the same order as described above:
	str.append(str2);                       // "Writing "
	str.append(str3,6,3);                   // "10 "
	str.append("dots are cool",5);          // "dots "
	str.append("here: ");                   // "here: "
	str.append(10u,'.');                    // ".........."
	str.append(str3.begin()+8,str3.end());  // " and then 5 more"
	str.append<int>(5,0x2E);                // "....."

	std::cout << str << '\n';
	return 0;
}