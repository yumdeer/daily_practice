//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int n,big=0,sum=0;
//	cin >> n;
//	int a[100000];
//	for(int i=0;i<n;i++)
//	{
//		cin>> a[i];
//		if(a[i]>big)
//			big=a[i];
//	}
//
//	for(int i=0;i<n;i++)
//		if(a[i]==big)
//			sum++;
//
//
//	if(sum%2==0) cout << "bob"<<endl;
//	else cout << "alice"<<endl;
//
//	return 0;
//}
//
////int a[100001];
////int b[100001];
////int main()
////{
////    int n,i,s=0;
////    cin>>n;
////    for(i=1;i<=n;i++)
////        b[i]=0;
////    for(i=1;i<=n;i++)
////    {
////        cin>>a[i];
////        b[a[i]]++;
////    }
////    for(i=1;i<=100000;i++)
////    {
////        if(b[i]%2==1&&b[i]!=0)
////        {
////            s=1;
////            break;
////        }
////    }
////    if(s==1)
////        cout<<"alice"<<endl;
////    else
////        cout<<"bob"<<endl;
////    return 0;
////}
//
//
//
//
//
//

//#include<iostream>
//using namespace std;
//
//template<typename T>
//struct double_d{
//      void operator()(T a, T b){cout<<a+b<<endl;}  
//};
//
//template<typename S>
//void set_1(S visit){
//     visit(1,2);
//}
//
//template<typename S>
//void set_2(S& visit){
//     visit(1,2);
//}
//
//int main(){
//    set_1<>( double_d<int> ());
//    //set_2(double_d<int>());
//    //if call set_2(),then cannot pass compiling process.while set_1() can.
//    system("pause");
//    return 0;
// }

