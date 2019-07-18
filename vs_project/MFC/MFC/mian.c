#include <Windows.h> //底层实现窗口的头文件 ， 底层是没有CPP的 ，需要使用c文件的形式 

//6.处理窗口过程

//CALLBACK 是一个宏，代表_stdcall 参数的传递顺序：从右到左 从此入栈，并且在函数返回前 清空堆栈
LRESULT CALLBACK WindowProc(
	HWND hwnd,				//消息所属的窗口句柄
	UINT uMsg,				//消息具体名称 WM_XXXX消息名
	WPARAM wParam,			//键盘附加消息
	LPARAM lParam           //鼠标附加消息
	)
{
	switch(uMsg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);	//DestroyWindow发送另一个消息WM_DESTROY
		break;
	case WM_DESTROY:
		PostQuitMessage(0);     //点击X号，退出进程
		break; 
	}


	//返回值用默认处理方式
	return DefWindowProc(hwnd,uMsg, wParam, lParam);
}						 
						 
						 
程序入口函数 main函数

WINAPI 是一个宏，代表_stdcall 参数的传递顺序：从右到左 从此入栈，并且在函数返回前 清空堆栈
int WINAPI WinMain(
	HINSTANCE hInstance,              //应用程序实例句柄
	HINSTANCE hPrevInstance,          //上一个应用程序句柄，在Win32环境下，参数一般为NULL，不起作用了
	LPSTR lpCmdLine,                  //char *argv[]
	int nShowCmd )					  //显示命令 最大化 最小化 正常
{
	1.设计窗口
	2.注册窗口
	3.创建窗口
	4.显示和更新
	5.通过循环取消息
	6.处理消息（窗口过程）
	HWND hwnd;

	1.设计窗口
	WNDCLASS wc;
	wc.cbClsExtra = 0;				         //类的额外的内存
	wc.cbWndExtra = 0;						 //窗口的额外的内存
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	 //设置背景,并强制转换为wc.hbrBackground的返回值类型(HBRUSH)
	wc.hCursor = LoadCursor(NULL , IDC_HAND);			 //设置光标,如果第一个参数为NULL,则使用系统提供的光标
	wc.hIcon = LoadIcon(NULL , IDC_ICON);				//设置图标
	wc.hInstance = hInstance;                           //应用程序实例句柄
	wc.lpfnWndProc = WindowProc;						//回调函数，窗口过程
	wc.lpszClassName = TEXT("WIN");						//指定窗口类名称
	wc.lpszMenuName = NULL ;							//菜单名称
	wc.style = 0;										//显示风格，0代表默认风格

	2.注册窗口
	RegisterClass(&wc);

	3.创建窗口
	/*
	 lpClassName  类名
	 lpWindowName 标题名
	 dwStyle, WS_OVERPLAPPEDWINDOW 默认值
	 x,y		  显示坐标
	 nwidth,nHeight			宽高
	 hWndParent    父窗口 NULL
	 hMenu         菜单 NULL
	 hInstance     实例句柄 hInstance
	 lpParam       附加值，鼠标附加值
	 */

	HWND hwnd = CreateWindow(wc.lpszClassName, TEXT("WINDOWS"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	

	4.显示和更新
	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);

	5.通过循环取消息
	/*
	HWND        hwnd;    主窗口句柄
    UINT        message; 具体消息名称
    WPARAM      wParam;  附加消息，键盘消息
    LPARAM      lParam;  附加消息，鼠标消息
    DWORD       time;    消息产生时间
    POINT       pt;      附加消息  鼠标消息 x y
	*/
	MSG msg;

	while(1)
	{   
		/*
		  __out LPMSG lpMsg,         消息
		  __in_opt HWND hWnd,        捕获消息，填NULL代表捕获所有的窗口
		  __in UINT wMsgFilterMin,   最小的过滤额的消息，一般填0，代表捕获所有窗口
		  __in UINT wMsgFilterMax);  最大的过滤额的消息，一般填0，代表捕获所有消息
		 */
		if(GetMessage(&msg, NULL, 0, 0) == FALSE)
		{
			break;
		}

		翻译消息
		TranslateMessage(&msg);

		不为false
		分发消息
		DispatchMessage(&msg);

	}

	return 0;
}

