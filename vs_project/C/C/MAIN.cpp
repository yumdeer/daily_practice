#include <iostream>
//#include"TestTemplate.h"
//
//template <typename node>
//void TestTemplate<node>::print(){
//    std::cout << "TestTemplate " << data << std::endl;
//}
//
////template class TestTemplate<int>;
//
//void main()
//{
//	TestTemplate<int>print();
//
//}

using namespace std;

//int main()
//{
//    int a,b,c,ans;
//    cin>>a>>b>>c;
//    ans=c+1-a;
//     int num=0.5+(ans*1.0/b*1.0);
//     cout << num+3 <<endl ;
// 
//    return 0;
//}

int main()
{
    int a,b,c,ans;
    cin>>a>>b>>c;
    if(3*b>=a)
    {
        int u,q,p;
        u=c%a;
        q=c/a;
        p=u/b;
        ans=3*q+p;
    }
    else
    {
        int y,o;
        y=c-a;
        o=y/b;
        ans=3+o;
    }
    cout<<ans<<endl;
    return 0;
}