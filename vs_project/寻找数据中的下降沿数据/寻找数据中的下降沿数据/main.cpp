#include<iostream>

using namespace std;
int a[1001];
int b[1001];

int main()
{
    int n;
    int j;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(int i=1;i<=n;i++)
    {
        j=i;
        while(a[j]>=a[j-1 ]&& j>1)
        {
            b[i]++;
            j--;
        }
        j=i;
        while(a[j]>a[j+1] && j<n)
        {
            b[i]++;
            j++;
        }
        b[i]++;
    }

    int max=0;
    for(int i=1;i<=n;i++)
    {
        if(b[i]>max)
        max=b[i];
    }
    cout<<max<<endl;
    return 0;
}