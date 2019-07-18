//DrawUtil.h
/*
* Copyright (c) 2006, 西安方诚科技有限责任公司
* All rights reserved.
* 
* 文件名称：DrawUtil.h
* 文件标识：DrawUtil.h
* 摘    要：DrawUtil.hl输出函数声明
*
* 开发环境：Microsoft Win32 SDK, Visual C++ 6.00
* 
* 当前版本：1.0.0.1
* 作    者：何珊
* 完成日期：2006年6月2日
*
* 取代版本：1.1.7.1102
* 原 作 者：star
* 完成日期：2007年11月2日
*
* 修改记录：

* 版本:    版本1.1.7.1102
* 时间:    07-11-02
* 修改项:  增加函数: FD_StretchDrawImage和FD_DrawActualImage

*/
//////////////////////////////////////////////////////////////////////
#ifndef _DRAW_UTIL_H
#define _DRAW_UTIL_H

#ifdef DRAWUTIL_API
#define DRAWUTIL_API __declspec(dllexport)
#else
#define DRAWUTIL_API __declspec(dllimport)
#endif

typedef enum tagFD_FILE_TYPE
{
	FILE_BITMAP = 0,
	FILE_JPEG	= 1,
	FILE_RAW	= 2
}FD_FILE_TYPE;

////////////////////////////////////////////////////////////////////////////////////////////////
//GDI绘图函数，此组数用GDI方式在窗体上绘图，适用于续列图像在同一窗体上绘制。

/* By C++ language compiler */
#ifdef __cplusplus
extern "C"{
#endif

/*
*函数说明：创建绘图对象，必须使用FD_ReleaseDraw释放对象
*输入参数：hDisp：显示窗口句柄
*          nWidth：显示的图像宽度
*          nHeight：显示的图像高度
*          nBitCnt：显示图像位深，支持RGB24格式位图和8位灰度图，对应的值分别为24和8
*          bTopToDown：图像数据是否是倒位图，即位图第一个扫描行是否在图像数据矩阵的最后一行
*          bDwordAligned：图像数据块是否四字节边界对齐
*输出参数：无
*返 回 值：位图对象句柄，创建失败则返回NULL
*/
DRAWUTIL_API
HANDLE __stdcall FD_CreateDraw(HWND hDisp, int nWidth, int nHeight, 
				int nBitCnt, bool bTopToDown, bool bDwordAligned);

/*
*函数说明：释放已创建的绘图对象
*输入参数：hDraw：绘图对象句柄
*输出参数：无
*返 回 值：无
*/
DRAWUTIL_API 
void __stdcall FD_ReleaseDraw(HANDLE hDraw);

////////////////可缩放显示的函数///////////////////////////////////////////////
/*
*函数说明：在指定的窗体上绘图。若拉伸显示的宽度或高度为0，则按原大小显示
*输入参数：hDraw：绘图对象句柄
*          pBits：图像数据缓冲区地址
*          nSize：图像数据缓冲区大小
*          nLeft：图像在窗体显示时，左上角相对于窗体客户区的横坐标
*          nTop：图像在窗体显示时，左上角相对于窗体客户区的纵坐标
*          nPlayWidth：拉伸显示时的宽度
*          nPlayHeight：拉伸显示时的高度
*输出参数：无
*返 回 值：无
*/
DRAWUTIL_API
void __stdcall FD_DrawImage(HANDLE hDraw, PVOID pBits, UINT nSize,  int nLeft, 
								int nTop, UINT nPlayWidth, UINT nPlayHeight);

/*
*函数说明：在指定的窗体窗口区域显示源图像中指定矩形区域的图像。
*输入参数：hDraw：绘图对象句柄
*          pBits：图像数据缓冲区地址
*          nSize：图像数据缓冲区大小
*		   rcInput：将显示的源图像矩形区域
*          rcOutput：窗体中的显示矩形区域，若输出区域与源图像区域大小不一致，则自动缩放显示
*输出参数：无
*返 回 值：无
*/
DRAWUTIL_API
void __stdcall FD_DrawImageEx(HANDLE hDraw, PVOID pBits, UINT nSize,  RECT &rcInput, RECT &rcOutput);

////////////////////////////////////////////////////////////////////////////////////////////
/*
*函数说明：重画最近一次调用FD_DrawImageEx或FD_DrawImage函数所画的图像，
*		   图像输入输出矩形可以根据需要调整。
*输入参数：hDraw：绘图对象句柄
*		   rcInput：将显示的源图像矩形区域
*          rcOutput：在窗体中显示时的输出图像的矩形区域
*输出参数：无
*返 回 值：无
*/
DRAWUTIL_API
void __stdcall FD_RedrawImage(HANDLE hDraw, RECT &rcInput, RECT &rcOutput);

/////////////////////////////////////////////////////////////////////////////////////////////
/*
*函数说明：在指定的窗口绘图，该函数可以缩放, 局部显示，且效率高于FD_DrawImage和FD_DrawImageEx函数。
*输入参数：
*hDraw：    绘图对象句柄。
*pBits：    图像数据缓冲区地址。
*ulSize     图像数据缓冲区大小。
*rtSorRect：源图像矩形区域。
*rtDesRect：显示矩形区域。若源图像矩形区域与显示矩形区域大小不一致，则自动缩放显示。
*输出参数： 无
*/
DRAWUTIL_API
void __stdcall FD_StretchDrawImage(HANDLE hDraw, PVOID pBits, ULONG nSize, RECT rtSorRect, RECT rtDesRect);

///////////////////////////////////////////////////////////////////////////////////////////////////////
/*
*函数说明：在指定的窗口绘图，该函数不支持缩放，但效率高，CPU占用率小
*输入参数：
*hDraw：    绘图对象句柄。
*pBits：    图像数据缓冲区地址。
*nSize      图像数据缓冲区大小。
*nLeft：    图像在窗体显示时，左上角相对于窗体客户区的横坐标
*nTop：     图像在窗体显示时，左上角相对于窗体客户区的纵坐标
*输出参数： 无
*/
DRAWUTIL_API
void __stdcall FD_DrawActualImage(HANDLE hDraw, PVOID pBits, UINT nSize, int nLeft, int nTop);

///////////////////////////////////////////////////////////////////////////////////////////////
/*
*函数说明：保存当前帧图像，保存图像为FD_DrawImage函数显示的整幅图像，在FD_DrawImage后调用
*输入参数：
*		   hDraw：绘图对象句柄
*          szSaveName：保存的图像名
*          FileType：保存文件类型，FILE_BITMAP：保存为BMP图，FILE_JPEG：保存为JPEG图，
*					 FILE_RAW：保存为原始数据文件。
*输出参数：无
*返 回 值：无
*/
DRAWUTIL_API
void __stdcall FD_SaveImage(HANDLE hDraw, const char *szSaveName, FD_FILE_TYPE FileType);

/* extren "C" { */
#ifdef __cplusplus
}
#endif

#endif