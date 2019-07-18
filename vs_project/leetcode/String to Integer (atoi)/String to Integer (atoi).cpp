#include <iostream>
using namespace std;

//class Solution {
//public:
//	int myAtoi(string str) {
//
//		if (str[0] >= '0'&& str[0] <= '9' || str[0] == ' ' || str[0] == '-' || str[0] == '+')
//		{
//			int result=0;
//			while (str[0] == ' ')
//			{
//				for (int i = 0; i < str.size(); i++)
//					str[i] = str[i + 1];
//			}
//
//			//if (str[0] == '-' || str[0] == '+')            //ÅÅ³ý "-+2"
//			//{
//			//	if ((str[1] <'0' || str[1] > '9'))
//			//		return 0;
//			//}
//
//			for (int i = 0; i < str.size(); i++)
//			{
//				if (str[0] == '-' || str[0] == '+')
//				{
//					if ((str[1] <'0' || str[1] > '9'))
//						return 0;
//					else         //ÅÅ³ý "-+2"
//					{
//						if (str[i] >= '0' && str[i] <= '9')
//						{
//							result = result * 10 + (str[i] - '0');
//						}
//					}
//				}
//				else if (str[i] >= '0' && str[i] <= '9')
//				{
//					result = result * 10 + (str[i] - '0');
//					if ((str[1] <'0' || str[1] > '9'))
//						break;
//				}
//			}
//
//			if (str[0] == '-')
//			{
//				if (result*-1 < INT_MIN / 10)
//					return INT_MIN;
//				else  return result*-1;
//			}
//			else
//			{
//				if (result > INT_MAX / 10)
//					return INT_MAX;
//				else return result;
//			}
//
//		}
//		else return 0;
//
//	}
//
//};

class Solution {
public:
	int myAtoi(string str) {
		long result = 0;
		int indicator = 1;
		for (int i = 0; i < str.size();)
		{
			i = str.find_first_not_of(' ');
			if (str[i] == '-' || str[i] == '+')
				indicator = (str[i++] == '-') ? -1 : 1;
			while ('0' <= str[i] && str[i] <= '9')
			{
				result = result * 10 + (str[i++] - '0');
				if (result*indicator >= INT_MAX) return INT_MAX;
				if (result*indicator <= INT_MIN) return INT_MIN;
			}
			return result * indicator;
		}
	}
};

//Best answer
//class Solution {
//public:
//	int myAtoi(string str) {
//		int i = 0, start = 0, end = 0, sign = 1;
//		const int int_min = -2147483648;
//		const int int_max = 2147483647;
//		//drop white space
//		while (i < str.size())
//		{
//			if (str[i] >= '0'&&str[i] <= '9')
//			{
//				start = i;
//				break;
//			}
//			if (str[i] != ' '&&str[i] != '-'&&str[i] != '+')
//			{
//				return 0;
//			}
//			else if (str[i] == '-' || str[i] == '+')
//			{
//				if (str[i] == '-') sign = -1;
//				start = i + 1;
//				break;
//			}
//			++i;
//		}
//		//    cout<<start<<' '<<str.size()<<endl;
//		if (i == str.size()) return 0;
//		//get the value 
//		int value = 0, dis = 0;
//		i = start;
//		while (i < str.size())
//		{
//			if (str[i]<'0' || str[i]>'9')
//				break;
//			if (value > 214748364)
//			{
//				if (sign == 1) return int_max;
//				else if (sign == -1) return int_min;
//			}
//			else if (value == 214748364)
//			{
//				if (sign == 1 && str[i] > '6') return int_max;
//				else if (sign == -1 && str[i] > '7') return int_min;
//			}
//			dis = str[i] - '0';
//			value = value * 10 + dis;
//			++i;
//		}
//		return sign * value;
//	}
//};


int main()
{
	Solution sol;
	//string s = "3.141592";                //  ´ð°¸3
	//string s = "    -42";					//  ´ð°¸-42
	//string s = "-+2";                     //  ´ð°¸0
	//string s = "  -0012a42";              //  ´ð°¸-12
	string s = "4193 with words";

	cout << sol.myAtoi(s);
	return 0;
}

