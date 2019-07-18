#include <windows.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

DWORD WINAPI MyThreadProc1(LPVOID lpParameter);
DWORD WINAPI MyThreadProc2(LPVOID lpParameter);
int index = 0;
int i = 0 , y = 0;
int main()
{
    HANDLE handle1,handle2;
    handle1 = CreateThread(NULL,0,MyThreadProc1,NULL,0,NULL);
    handle2 = CreateThread(NULL,0,MyThreadProc2,NULL,0,NULL);

    if(NULL == handle1)
    {
        cout<<"Create Thread failed !"<<endl;
        return -1;
    }
    if(NULL == handle2)
    {
        cout<<"Create Thread failed !"<<endl;
        return -1;
    }

    CloseHandle(handle1);
    CloseHandle(handle2);

    cout<<"The Main Thread is Running !"<<endl;

    system("PAUSE");
    return 0;
}
DWORD WINAPI MyThreadProc1(LPVOID lpParameter)
{

    cout<<"The MyThreadProc1 is Running !"<<endl;

    return 0;
}
DWORD WINAPI MyThreadProc2(LPVOID lpParameter)
{
    
    cout<<"The MyThreadProc2 is Running ! "<<endl;
    return 0;
}