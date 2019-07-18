#include <iostream>
using namespace std;
int main()
{
	const char key[] ={ 'a','b','c','d','a'};
	const int NUM_QUES=5;
	char c;
	int ques =0, numCorrect=0;
	cout << " Enter the " << NUM_QUES << " question tests:" << endl ;
	while(cin.get(c))
	{
		if(c != '\n')
		{
			if(c == key[ques])
			{
				numCorrect++;
				cout << " ";
			}
			else 
			{
				cout << "*";
			}
			ques++;
		}
		 else
		  {
			cout << "Score" << static_cast<float>(numCorrect)/NUM_QUES*100 << "%";
			ques=0;numCorrect=0;															//注释掉将导致*号没有重置
			cout << endl;
		   }
	 }
	return 0;
}