//#include<iostream>
//#include<cmath> 
//
//using namespace std;
//
//int main()
//{
//	int m,b;
//	cin >>m  >>b;
//
//	int x,y,num=0;
//	x=0.5+b/2.0;   //因为b是整数，可以直接5入。也可ceil()向上取整
//	double a=-1*x/m+b;
//	y=floor(a);   //向下取整
//
//	for(int a=x;a>=0;a--)
//		for(int b=y;b>=0;b--)
//			 num += a+b;
//
//	cout << num <<endl;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
////以Y=0,1,2..为矩形上限，开始循环比较面积大小
//int main()
//{
//    long long m,b,i,j,x,y;
//    long long sum=0,max=0,sum1=0,sum2=0;
//     cin>>m>>b;
//    for(i=0,j=b;j>=0;i+=m,j--)
//    {
//        x=i;y=j;sum1=0;sum2=0;sum=0;           
//        sum1=(((1+y)*y)/2)*(x+1);					
//        sum2=(((1+x)*x)/2)*(y+1);					
//        sum=sum1+sum2;
//        if(sum>max)max=sum;
//    }
//    cout<<max;
//
//    return 0;
//}

#include <iostream>
#include <stdio.h>
using namespace std;
 
 
int main()
{
    int n,A=0,B=0,C=0,tot=0,tol=0;
 
    while( cin>>n && n!= -1 )
    {
        tol++;
         if(n==1)
             A++;
         if(n==2)
             B++;
         if(n==3)
             C++;
         if( n==1 || n==2 || n==3 )
            tot++;
    }
    cout << "A=" << A << endl;
    cout << "B=" << B << endl;
    cout << "C=" << C << endl;
    cout << "Tot=" << tot << endl;
    if(A>= tol/2.0) cout << "A-yes" << endl;
    else if(B>= tol/2.0) cout << "B-yes" << endl;
    else if(C>= tol/2.0) cout << "C-yes" << endl;
    else cout << "all-NO" << endl;
 
    return 0;
}

 
//
//using namespace std;
//
//int main()
//{
//	int n;
//	int T=0;
//	int A,B,C; 
//	A = B = C = 0;
//	while (scanf("%d", &n) )
//	{
//		T++;
//		if (n == -1)
//			break;
//		if (n == 1)
//			A++;
//		if (n == 2)
//			B++;
//		if (n == 3)
//			C++;
//
//	}
//
//	cout << "A=" << A << endl << "B=" << B << endl << "C=" << C<<endl<<"Tot="<<A+B+C<<endl;
//
//	if (A >=( T-1) / 2.0)
//		cout << "A-yes" << endl;
//	if (B >=(T - 1) / 2.0)
//		cout << "B-yes" << endl;
//	if (C >=(T - 1) / 2.0)
//		cout << "C-yes" << endl;
//	else
//		cout << "all-NO";
//
//	return 0;
//}
