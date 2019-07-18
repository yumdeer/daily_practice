#include <iostream>
#include <iterator>
#include <algorithm>
#include <cmath>

using namespace std;

/*枚举法*/
//int main()
//{
//	int n;
//	cin>>n;
//
//	for(int i=1;i<=n/2;i++)
//	{
//		int j;
//		int sum=0;
//		for(j=i;j<n;j++)
//		{
//			sum+=j;
//			if(sum>=n)
//				break;
//		}
//
//		if(sum==n)
//			cout<<i<<" "<<j<<endl;
//	}
//
//	return 0;
//}

/*枚举左端和右端*/
//int main()
//{
//	long long n,s=1,sum=0;
//	scanf("%lld",&n); 
//	for(int i=1;i<n;i++)
//	{
//		sum+=i;
//		while(sum>n)
//			sum-=s++;
//		if(sum==n)
//			cout<<s<<" "<<i<<endl;
//
//	}
//	return 0;
//} 

/*迭代法，利用等差数列和的公式求解*/
//int main()
//{
//	long long n,i,j,sum=0;
//	cin>>n;
//	for(i=1;i<n;i++)
//		for(j=i+1;j<n;j++)
//			if((i+j)*(j-i+1)/2==n)
//				cout<<i<<" "<<j<<endl;
//			else if((i+j)*(j-i+1)/2>n)
//				break;
//	return 0;
//} 

/*利用数组提前计算并储存前n项数之和，然后进行对比*/
//int main()
//{
//	long long d[2000005];
//	long long s=0;
//	d[0]=0;
//	for(int i=1;i<=2000000;i++)
//	{
//		s+=i;
//		d[i]=s;
//	}
//
//	long long n;
//	while(cin>>n)
//	{
//		int j=0;
//		for(int i=1;i<n;i++)
//		{
//			for(;j<n;j++)   //这样的复杂度其实为O(n);
//			{
//				long long x=d[i]-d[j];
//				if(x==n)
//				{
//					cout<<j+1<<' '<<i<<endl;
//
//				}
//				else if(x<n) break;
//			}
//		}
//
//	}
//}


/*
	题目可以转化为，等差数列n个数之和为Sn。
	等差公式：Sn=n(a1+an)/2=n[2a1+(n-1)d]/2，项数n,首项a1,公差d。
	           k=√(2*Sn)=√n(a1+an)=√n[2a1+(n-1)d]
	Sn=na1+0.5*(n^2-n)=0.5n^2+(a1-0.5)n   
	n^2+(2a1-1)n-2Sn=0    一元二次方程ax^2+bx+c=0     解x=(-b+Δ)/2a
 */
//int main()
//{
//	LL m;
//	cin>>m;
//	LL n,a1,i;
//	double r;
//	LL b,c,d;
//	for(i=0;i<=m;i++)
//	{   
//		a1=i;
//		b=(2*a1-1);
//		c=-2*m;
//		d=b*b-4*c;//delta判别式
//		r=-b+sqrt(d);//求根公式分号上面那一堆东西Δ
//		if(r==(int)r&&r>0)//某些时候-b会大于sqrt(d)，导致r为负，很明显这种情况不存在
//		{
//			n=r/2;            //Δ/2a，即x的解，即n，答案的两个数之间有n个项
//			if(a1==a1+n-1)
//				continue;//避免只有一项的情况
//			cout<<a1<<' '<<a1+n-1<<' '<<endl;    
//		}
//	}
//	return 0;
//} 


//思路：等差数列，因为从1开始，项数等于尾项-首项+1，所以项数一定和对应项数两者奇偶不同。
//若项数为奇数，对应两个项的和则为偶数。
//例如：1 4 两个数，其中包含4个项（1，2，3，4）为偶数，但1+4=5为奇数。
//既然是一个连续的数列，那么它们的和等于他们的平均数×项数，平均数可能为0.5，将其整体扩大2倍，平均数则为整数。
//若项数为奇数，其对应首位项和必为偶数，若项数为偶数，其对应首位项和必为奇数。
//项数和对应首位项和不可能同为奇，即(x+2*m/x)%2一定为奇数。
int main(){
	int m;		
	cin>>m;											
	for( int x=sqrt((double)(2*m)) ; x>1 ; x-- )    //x是连续自然段的个数(项数)，即x为首项数和尾项数的差+1
		if( (2*m)%x==0 && (x+2*m/x)%2 )				//2m是x的倍数，x+y是奇数
		{
			int y=2*m/x;							//2倍的平均数,即y是符合条件的首项和尾项的和，防止平均数是小数？   
			cout<<(y-x+1)/2<<" "<<(y+x-1)/2<<endl;  //平均数-项数*0.5，平均数+项数*0.5。将之前扩大的两倍缩小     验证：(y+x-1)/2-(y-x+1)/2=x-1，共x项,。
		}
		return 0;
}


/*
     高斯法
     给出M，有等差数列求和公式得：设区间[x,y]上M=（x+y）*（x-y+1）/2,顺便提一下 x-y+1 为自然数个数
	  y^2-y=x^2+x-2*M；进一步两边同时加一个1/4 可得 （y-1/2)^2=（x+1/2)^2-2*M;
	  y=√(x^2+x-2M+1/4)-1/2=√((x+1/2)^2-2M）+1/2
 */
/*
	n^2+(2a1-1)n-2Sn=0    一元二次方程ax^2+bx+c=0      a=1,b=(2a1-1),c=-2Sn=-2m
	x^2+(2a1-1)x-2Sn=0;  （y-1/2）^2=（x+1/2)^2-2*M;   对称，只需要一半，另外的一半就是x,y值对调
	((x + y) * (y - x + 1) / 2 == Sn) ; y^2+y=2Sn+X^2-x 
//*/
//int main()
//{
//	int x = 1, y = 0, Sn;
//
//	scanf("%d", &Sn);
//	for (; y < Sn / 2; x++, y = (int)(sqrt(Sn * 2 - x+ x * x + 0.25) - 0.5))
//		if ((x + y) * (y - x + 1) / 2 == Sn) printf("%d %d\n", x,y);                      //42分，有错误
//
//	return 0;
//}



//https://www.luogu.org/blog/boshi/solution-p1147
//#include <iostream>
//#include <algorithm>
//#include <cstring>
//#include <cstdio>
//#include <vector>
//using namespace std;
//int M;
//typedef struct node_t
//{
//	int l,r;
//	inline bool operator < (const node_t t) const
//	{
//		return l<t.l;
//	}
//}node;
//vector<node>ans;
//
//inline void work()
//{
//	node t;
//	for(register int i=M;i>=2;i--)
//		if((i&1)&&(M%i==0))
//		{
//			t=(node){M/i-i/2,M/i+i/2};
//			if(t.l==0)t.l++;
//			else if(t.l<0)t.l=-t.l+1;
//			if(t.l>t.r)swap(t.l,t.r);
//			ans.push_back(t);
//		}
//		sort(ans.begin(),ans.end());
//		for(register int i=0;i<ans.size();i++)printf("%d %d\n",ans[i].l,ans[i].r);
//}
//int main()
//{
//	scanf("%d",&M);
//	work();
//	return 0;
//}

//#include <iostream>
//#include <algorithm>
//#include <cstring>
//#include <cstdio>
//#include <vector>
//using namespace std;
//
//int M;
//typedef struct node_t
//{
//	int l,r;
//	inline bool operator < (const node_t t)const{return l<t.l;}
//}node;
//vector<node>ans;
//inline void work()
//{
//	node t;
//	for(register int i=2;i*i<=M;++i)
//		if((i&1)&&(M%i==0))
//		{
//			//node a={M/i-i/2,M/i+i/2};
//			//t=a;
//			t= node {M/i-i/2,M/i+i/2};
//			if(t.l==0)t.l++;
//			else if(t.l<0)t.l=-t.l+1;
//			if(t.l>t.r)swap(t.l,t.r);
//			ans.push_back(t);
//		}
//		for(register int i=1;i*i<M;++i)
//			if(((M/i)&1)&&(M%i==0))
//			{
//				//node b={i-(M/i)/2,i+(M/i)/2};    
//				//t=b;
//				t=node {i-(M/i)/2,i+(M/i)/2}        //c++13支持隐性赋值
//				if(t.l==0)t.l++;
//				else if(t.l<0)t.l=-t.l+1;
//				if(t.l>t.r)swap(t.l,t.r);
//				ans.push_back(t);
//			}
//			sort(ans.begin(),ans.end());
//			for(register int i=0;i<ans.size();i++)printf("%d %d\n",ans[i].l,ans[i].r);
//}
//
//int main()
//{
//	scanf("%d",&M);
//	work();
//	return 0;
//}