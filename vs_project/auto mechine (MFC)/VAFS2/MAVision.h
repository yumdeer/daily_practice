
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the MAVISION_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// MAVISION_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef MAVISION_EXPORTS
#define MAVISIONAPI extern "C" __declspec(dllexport)
#else
#define MAVISIONAPI extern "C" __declspec(dllimport)
#endif

// 颜色格式
#define CLFM_Y8		1
#define CLFM_RGB16	2
#define CLFM_RGB24	3
#define CLFM_RGB32	4

// 视频格式
#define VIFM_NTSC	0
#define VIFM_PAL	1

// 通道选择
#define CHANNEL_0	 1
#define CHANNEL_1	 2
#define CHANNEL_2	 4
#define CHANNEL_3	 8

typedef void (CALLBACK * GRABPROCESS )( DWORD, WORD );

/**************系统*****************/

// 初始化图像卡
MAVISIONAPI short MAInitial( WORD Port );
// 关闭图像卡
MAVISIONAPI short MAClose( WORD Port );
// 重启
MAVISIONAPI short MAReset( WORD Port );

/***************配置****************/

// 设置颜色格式
MAVISIONAPI short MASetColorFormat( WORD Port, BYTE ColorFormat );
// 获取颜色格式
MAVISIONAPI short MAGetColorFormat( WORD Port, BYTE *ColorFormat );
// 设置视频格式
MAVISIONAPI short MASetVideoFormat( WORD Port, BYTE VideoFormat );
// 获取视频格式
MAVISIONAPI short MAGetVideoFormat( WORD Port, BYTE *VideoFormat );
// 设置亮度、对比度……
MAVISIONAPI short MASetImageConfig( WORD Port, BYTE Index, BYTE Value );
// 获取亮度、对比度……
MAVISIONAPI short MAGetImageConfig( WORD Port, BYTE Index, BYTE* Value );
// 设置图像……
MAVISIONAPI short MASetImageGeometric( WORD Port, DWORD X_Offset, DWORD Y_Offset, DWORD X_Active, DWORD Y_Active, double X_Scale,double Y_Scale );

// 获取图像信息……
MAVISIONAPI VOID MAGetImageInfo( WORD Port, DWORD* BitCount, DWORD* Width, DWORD* Height );

/***************操作****************/

// 开始采集
MAVISIONAPI short MAStart( WORD Port, DWORD Capture );
// 停止采集
MAVISIONAPI short MAStop( WORD Port );
// 设置通道
MAVISIONAPI short MASelectChannel( WORD Port, WORD Channel );
// 设置操作
MAVISIONAPI short MACaptureConfig( WORD Port, WORD StartField );
// 同步
MAVISIONAPI short MASyncGrab( WORD Port, BYTE *pBuffer, DWORD* Width, DWORD* Height, DWORD* BufferSize );
// CALLBACK
MAVISIONAPI short MASetCallBack( WORD Port, GRABPROCESS GrabProc );

MAVISIONAPI short MASetIntEvent( WORD Port, HANDLE* hEvent );

MAVISIONAPI short MAGetIntStatus( WORD Port, DWORD* IntStatus );

/***************IO****************/

// 设置IO
MAVISIONAPI short MASetGPIOStatus( WORD Port, BYTE Status );
// 获取IO
MAVISIONAPI short MAGetGPIOStatus( WORD Port, BYTE* Status );

MAVISIONAPI short MAWriteEEPROM( WORD Port, BYTE Address, BYTE Value );

MAVISIONAPI short MAReadEEPROM( WORD Port, BYTE Address, BYTE* Value );
//
MAVISIONAPI short MASetLEDSts( WORD Port, BYTE Status );
//
MAVISIONAPI short MASetWDT( WORD Port, WORD Enable, WORD Interval );
// Category: Software Trigger
MAVISIONAPI short MATriggerConfig( WORD Port, WORD Interval );
//
MAVISIONAPI short MATriggerStart( WORD Port, WORD Multiplex );

/***************??****************/

// 获取一帧图像
MAVISIONAPI short MAGetFrameData( WORD Port, BYTE *pBuffer, DWORD *Width, DWORD *Height, DWORD *BufferSize );
//
MAVISIONAPI short MACopyFrameData( WORD Port, BYTE *pBuffer, DWORD *BufferSize );
// 
MAVISIONAPI short MASaveToFile( WORD Port, char* FileName, BYTE FileFormat, int nQuality );