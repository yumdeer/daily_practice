//FCAM.h
/*
* Copyright (c) 2006, 西安方诚科技有限责任公司
* All rights reserved.
* 
* 文件名称：FCAM.h
* 文件标识：FCAM.h
* 摘    要：FCAM.dll输出函数声明
*
* 开发环境：Microsoft Win32 SDK, Visual C++ 6.00
* 
* 当前版本：V2.0.7.1116
* 作    者：赵星梅
* 完成日期：2007年11月16日
*
*/
//////////////////////////////////////////////////////////////////////

#ifndef __FCAM_H__
#define __FCAM_H__

#include "FCAM_Def.h"

#ifdef FCAM_EXPORTS
#define FCAM_API __declspec(dllexport)
#else
#define FCAM_API __declspec(dllimport)
#endif

//////////////////////////////////////////////////////////////////////////
/*
*函数说明: 获得指定序列号和相机类型的相机句柄。
*输入参数: uDeviceIndex:  相机序列号，从1开始。
           CameraType:    相机类型,见FCAM_Def.h文件，FCAM_CAMERA_TYPE类型定义。
*输出参数: 无。 
*返 回 值: 成功返回代表该相机的设备句柄，否则返回NULL。
*/
FCAM_API HANDLE __stdcall FCAM_GetDevice(UINT uDeviceIndex, FCAM_CAMERA_TYPE CameraType);

/*

*函数说明: 释放获取的设备句柄。
*输入参数: hDev:  待释放的设备句柄。
*输出参数: 无。 
*返 回 值: 成功返回FCAM_SUCCESS，否则返回相应的错误代码。

注: FCAM_GetDevice必须与FCAM_ReleaseDevice配对使用，即使用n次FCAM_GetDevice，
    相应的要调用n次FCAM_ReleaseDevice函数，才能正确释放设备句柄。

*/
FCAM_API HRESULT __stdcall FCAM_ReleaseDevice(HANDLE hDev);

/*
*函数说明: 获得设备句柄的引用计数，即调用FCAM_GetDevice成功的次数。必须调用引用计
           数次的FCAM_ReleaseDevice才能最终销毁设备对象。

*输入参数: hDev:   已获取的设备句柄。
*输出参数: 无。 
*返 回 值: 返回设备句柄的引用计数。
*/
FCAM_API int __stdcall FCAM_GetDeviceReferenceCount(HANDLE hDev);

/*
*函数说明: 启动相机数据传输任务
*输入参数: hDev: 获取的设备句柄
*输出参数: 无
*返回值:   成功返回FCAM_SUCCESS,否则返回相应的错误代码
*/
FCAM_API HRESULT __stdcall FCAM_StartCapture(HANDLE hDev);

/*
*函数说明: 取消(停止)相机的数据传输
*输入参数: hDev: 获取的设备句柄
*输出参数: 无
*返回值:   成功返回FCAM_SUCCESS,否则返回相应的错误代码
*/
FCAM_API HRESULT __stdcall FCAM_StopCapture(HANDLE hDev);

/*
*函数说明: 设置相机各类型参数的当前值
*输入参数: hDev:          获取的设备句柄
*          uType:         FCAM_GSP_PARAME_TYPE枚举类型，详见FCAM_Def.h文件
*          pParamStruct:  uType所对应的结构体指针，用来存储设置的参数值
*输出参数: 无
*返回值:   成功返回FCAM_SUCCESS,否则返回相应的错误代码
*/
FCAM_API HRESULT __stdcall FCAM_SetParameter(HANDLE hDev, FCAM_GSP_PARAME_TYPE uType, PVOID pParamStruct);

/*
*函数说明: 获取相机各类型参数的当前值
*输入参数: hDev:          获取的设备句柄
*          uType:         FCAM_GSP_PARAME_TYPE枚举类型，详见FCAM_Def.h文件
*          pParamStruct:  uType所对应的结构体指针，用来存储获取到的参数的当前值
*输出参数: 无
*返回值:   成功返回FCAM_SUCCESS,否则返回相应的错误代码
*/
FCAM_API HRESULT __stdcall FCAM_GetParameter(HANDLE hDev, FCAM_GSP_PARAME_TYPE uType, PVOID pParamStruct);

/*
*函数说明: 获取相机各参数的信息
*输入参数: hDev:               获取的设备句柄
*          uType:              FCAM_PARAMINFO_TYPE信息参数类型，详FCAM_Def.h文件
*          pParamInfoStruct:   uType所对应的存储参数信息的结构体指针 
*输出参数: 无
*返回值:   成功返回FCAM_SUCCESS,否则返回相应的错误代码 
*/
FCAM_API HRESULT __stdcall FCAM_GetParameterInfo(HANDLE hDev, FCAM_PARAMINFO_TYPE uType, PVOID pParamInfoStruct);
//////////////////////////////////////////////////////////////////////////
//数据获取
/*
*函数说明: 获取一个图像数据缓冲区指针，必须与FCAM_PutInFrameBuffer成对使用
*输入参数: hDev:              获取的设备句柄。
           pBuffer:           存储图像数据指针的缓冲区地址。
           pulBufferSizes:    存储buffer大小的缓冲区地址,大小以字节为单位。
           dwWaitMillTime:    获取操作的等待时间。
*输出参数: 无
*返回值:   成功返回FCAM_SUCCESS,否则返回相应的错误代码 
*/
FCAM_API HRESULT __stdcall FCAM_GetOutFrameBuffer(HANDLE hDev, PVOID &pBuffer, ULONG &ulBufferSizes, DWORD dwWaitMillTime);

/*
*函数说明: 归还获取的图像数据缓冲区指针
*输入参数: hDev:         获取的设备句柄
*          pBuffer:      获取的图像数据指针
*输出参数: 无
*返回值:   成功返回FCAM_SUCCESS,否则返回相应的错误代码 
*/
FCAM_API HRESULT __stdcall FCAM_PutInFrameBuffer(HANDLE hDev, PVOID pBuffer);
/////////////////////////////////////////////////////////////////////////////////////////////////
//软件触发
/*
*函数说明：当前设备状态为软件触发时，给一个软件触发信号，相机接到信号后开始曝光，一帧图像曝光完毕后，
*		   停止曝光，等待下一个触发信号。
*输入参数：hDev：获取的设备句柄
*输出参数：无。
*返 回 值：操作成功则返回FCAM_SUCCESS，否则返为相应的错误码。
*/
FCAM_API HRESULT __stdcall FCAM_SoftWareTrigger(HANDLE hDev);
/////////////////////////////////////////////////////////////////////////////////////////////////
//相机配置
/*
*函数说明: 保存当前的相机配置到指定文件
*输入参数: hDev:          获取的设备句柄
		   pFileName:     指定文件名
*输出参数: 无
*返回值:   成功返回FCAM_SUCCESS,否则返回相应的错误代码
*/
FCAM_API HRESULT __stdcall FCAM_SaveCameraConfiguration(HANDLE hDev, const char *pFileName);

/*
*函数说明: 从指定文件中读取相机的配置信息并加载到相机中，若当前传输已建立，请停止传输后再调用该函数
*输入参数: hDev:          获取的设备句柄
		   pFileName:     指定文件名
*输出参数: 无
*返回值:   成功返回FCAM_SUCCESS,否则返回相应的错误代码
*/
FCAM_API HRESULT __stdcall FCAM_LoadCameraConfiguration(HANDLE hDev, const char *pFileName);

//////////////////////////////////////////////////////////////////////////
//寄存器读写
/*
*函数说明: 指定地址寄存器读
*输入参数: hDev:          获取的设备句柄
		   ucRegAddr:     寄存器地址
		   ucValue:       存取读取到的数据的数组，4字节
*输出参数: 无
*返回值:   成功返回FCAM_SUCCESS,否则返回相应的错误代码
*/
FCAM_API HRESULT __stdcall FCAM_ReadRegister(HANDLE hDev, UCHAR ucRegAddr[4], UCHAR ucValue[4]);

/*
*函数说明: 指定地址寄存器写
*输入参数: hDev:          获取的设备句柄
		   ucRegAddr:     寄存器地址
		   ucValue:       存取写入的数据的数组，4字节
*输出参数: 无
*返回值:   成功返回FCAM_SUCCESS,否则返回相应的错误代码
*/
FCAM_API HRESULT __stdcall FCAM_WriteRegister(HANDLE hDev, UCHAR ucRegAddr[4], UCHAR ucValue[4]);

//////////////////////////////////////////////////////////////////////////
//设备事件处理
/*
*函数说明: 设置流传输的回调函数，该函数在每传满一个数据缓冲区后，该函数被调用一次
*输入参数: hDev:         获取的设备句柄
           pCallBack:    回调例程函数地址
           pUserParam:   用户自定义结构体指针, 详见FCAM_Def.h文件
*返回值:   成功返回FCAM_SUCCESS,否则返回相应的错误代码
*/
FCAM_API HRESULT __stdcall FCAM_SetStreamCallBackRoutine(HANDLE hDev, PFCAM_CALLBACK pCallBack, PVOID pUserParam);

/*
*函数说明: 设置流传输的事件通知窗口句柄, 在每传输满一个buffer，该窗口将会收到WM_FCAM_MESSAGE类型的消息
           消息详见FCAM_Def.h文件
*输入参数: hDev:         获取的设备句柄
           hMsgWnd:      消息接收窗口句柄
		   pUserParam:   用户自定义结构体指针, 详见FCAM_Def.h文件
*返回值:   成功返回FCAM_SUCCESS,否则返回相应的错误代码
*/
FCAM_API HRESULT __stdcall FCAM_SetMessageNotifyWindow(HANDLE hDev, HWND hMsgWnd, PVOID pUserParam);
//////////////////////////////////////////////////////////////////////////
//相机自动调节，目前只针对FUNCTION-TECH的130万像素相机
/*
*函数说明: 启动相机的自动白平衡调节，调节区域为图像中心区域480*360, 若图像大小不足，则全图调节
*输入参数: hDev:               获取的设备句柄
           pAutoCallBack:      回调函数，当自动白平衡调节完毕后，该函数被调用
           pAutoContext:       用户传入的在pAutoCallBack函数中用到的数据指针
*返回值:   成功返回FCAM_SUCCESS,否则返回相应的错误代码
*/
FCAM_API HRESULT __stdcall FCAM_SetDoAutoWHB(HANDLE hDev, PFCAM_AUTOSET_CALLBACK pAutoCallBack, PVOID pAutoContext);

//////////////////////////////////////////////////////////////////////////


#endif
