#include<iostream>
using namespace std;

class machine
{
private:
	int m25;
	int m50;
	int set;                   //±êÖ¾Î»
	//int m100;
public:
	machine(): m25(0),m50(0),set(0){};
	void init();
	void save(int *arr,int num);
	void push(int *arr,int num);
	void pay_pal();
};

void machine::init()
{
	m25=0;
	m50=0;
	set=0;
}

void machine::save(int *arr,int num)
{
	if( *(arr+num) == 25)
		m25++;
	if( *(arr+num) == 50)
		m50++;

}

void machine::push(int *arr,int num)
{
	if( *(arr+num) == 50)
		m25--;
	if( *(arr+num) == 100)
	{
		m25--; m50--;
	}
	if(m25<0 || m50<0 )
		set++;
}

void machine::pay_pal()
{

	if( m25<0 || m50<0 || set>0)
		cout << "NO"<<endl;
	else
		cout << "YES"<<endl;

}



int main()
{
	machine s;
	int n;
	int a[100000];

	while(cin >> n)
	{	
		s.init();
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
				s.save(a,i);
			if(a[i]>25)
				s.push(a,i);
		}
		s.pay_pal();
	}

	return 0;
}