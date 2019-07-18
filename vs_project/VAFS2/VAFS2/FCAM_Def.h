//FCAM_Def.h
/*
* Copyright (c) 2007, 西安方诚科技有限责任公司
* All rights reserved.
* 
* 文件名称：FCAM_Def.h
* 文件标识：FCAM_Def.h
* 摘    要：FCAM.dll数据类型定义头文件
*
* 开发环境：Microsoft Win32 SDK, Visual C++ 6.00
* 
* 当前版本：V2.0.7.1116
* 作    者：赵星梅
* 完成日期：2007年11月16日
*
*第二版本，不兼容以前版本
*/
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
#ifndef __FCAM_DEF_H__
#define __FCAM_DEF_H__
//////////////////////////////////////////////////////////////////////////
#include <windows.h>
///////////////////////////////////////////////////////////////////////////
//相机类型 
typedef enum enumCAMERATYPE
{
    CAMERA_1394 = 0x00000000,      //1394接口相机，IK系列
    CAMERA_USB  = 0x00000001       //USB接口相机，ID、IE系列

}FCAM_CAMERA_TYPE;
//////////////////////////////////////////////////////////////////////////
//参数信息类型
typedef enum enumPARAMINFO_TYPE
{
    FEATURE_INFO    = 0x00000000,   //特性参数信息，对应信息结构体FCAM_FEATURE_INFO
    IMAGE_INFO      = 0x00000001,   //视频参数信息，对应信息结构体FCAM_IMAGE_INFO
    DATATRANS_INFO  = 0x00000002,   //数据传输信息，对应信息结构体FCAM_DATATRANS_INFO
    HARDWARE_INFO   = 0x00000003,   //硬件信息，对应信息结构体FCAM_HARDWARE_INFO
    TRIGGER_INFO    = 0x00000004,   //触发信息，对应信息结构体FCAM_TRIGGER_INFO
    STROBE_INFO     = 0x00000005,   //频闪灯信息，对应信息结构体FCAM_STROBE_INFO

    INTERFACE_INFO	= 0x00000006    //相机接口信息，对应信息结构体FCAM_INTERFACE_INFO

}FCAM_PARAMINFO_TYPE;

//for CAMERA_FEATURE_INFO---------
//相机特性类型
typedef enum enumCAMERAFEATURETYPE
{
    BRIGHTNESS              = 0x00000000,   //亮度
    AUTO_EXPOSURE           = 0x00000001,   //自动曝光
    SHARPNESS               = 0x00000002,   //锐化
    WHITE_BALANCE           = 0x00000003,	//白平衡,B、R增益
    HUE                     = 0x00000004,   //色度
    SATURATION              = 0x00000005,   //饱和度
    GAMMA                   = 0x00000006,   //伽玛校正
	SHUTTER                 = 0x00000007,   //曝光时间，1：32.944us
	ANG_GAIN                = 0x00000008,	//模拟增益
	IRIS                    = 0x00000009,   //IRIS调节
	FOCUS                   = 0x0000000a,   //对焦
	TEMPERATURE             = 0x0000000b,   //温度
	TRIG_DELAY              = 0x0000000c,   //触发延迟
	WHITE_SHADING           = 0x0000000d,   //通道亮度,R、G、B通道值
	FRAME_RATE_PRIORITYS    = 0x0000000e,   //帧频优先
	ZOOM                    = 0x0000000f,   //变焦
	PAN                     = 0x00000010,   //遥摄
	TILT                    = 0x00000011,   //相机倾斜度
	OPTICAL_FILTER          = 0x00000012,   //光学滤波
	CAPTURE_SIZE_FORMAT6    = 0x00000013,   //F6M0_EXIF_FORMAT视频格式对应的特性属性：捕获大小
	CAPTURE_QUALITY_FORMAT6 = 0x00000014,   //F6M0_EXIF_FORMAT视频格式对应的特性属性：图像质量
	DIGITAL_SHIFT           = 0x00000015,	//数字位移
	BIT_INVERSE             = 0x00000016,	//位反转
	PROCESS_SPEED			= 0x00000017,	//相机内部处理数据速度
	CLOCK					= 0x00000018	//相机的时钟频率
}FCAM_FEATURE_TYPE;

//特性参数调节方式
typedef enum enumAdjustMode
{
	AUTO      = 0x00000000,   //相机自动调节
	MANUAL    = 0x00000001,   //手动调节（用户调节）
	ONE_PUSH  = 0x00000002    //相机一次调节模式

}FCAM_ADJUST_MODE;

//参数值类型
typedef enum enumValueType
{
	FLOAT_VALUE = 0x00000000,   //浮点型
    LONG_VALUE  = 0x00000001    //整型    

}FCAM_VALUE_TYPE;

//FCAM_PARAMINFO_TYPE的FEATURE_INFO对应的结构体
typedef struct __CAMERA_FEATURE__
{	

	FCAM_FEATURE_TYPE featureType;   //相机特性类型，为输入参数

	BOOL    bAvaliable;              //该特性当前是否可用，TRUE为可用，FALSE为不可用
	BOOL    bCanOnePush;             //该特性是否支持one push调节模式，TRUE支持，FALSE不支持
	BOOL    bCanOnOff;               //该特性是否支持使能和不使能的切换操作，TRUE支持，FALSE不支持
	BOOL    bCanReadOut;             //该特性的参数值是否可读，TRUE支持，FALSE不支持
	BOOL    bCanAuto;                //该特性是否支持自动调节模式，TRUE支持，FALSE不支持
	BOOL    bCanManual;              //该特性是否支持手动调节模式，TRUE支持，FALSE不支持

	struct
	{
		
		BOOL       bLongValueValid;     //整型信息是否有效，若为TRUE，lMax_Value、lMin_Value、lStep有效，反之无效

		LONG       lMax_Value;          //整型参数值的最大值
		LONG       lMin_Value;          //整型参数值的最小值
		LONG       lStep;               //整型参数值的单位步进值

		BOOL       bFloatValueValid;    //浮点型信息是否有效，若为TRUE，fMax_Value、fMin_Value、fStep有效，反之无效

		float      fMax_Value;          //浮点型参数值的最大值
		float      fMin_Value;          //浮点型参数值的最小值
		float      fStep;               //浮点型参数值的单位步进值

	}FeatureInfoValue;

}FCAM_FEATURE_INFO, *PFCAM_FEATURE_INFO;

typedef struct __FCAM_INTERFACE__
{
	FCAM_CAMERA_TYPE CameraType;  //相机类型，若为CAMERA_USB，SUsbSpec结构体信息有效

	struct
	{
		BOOL		bIsUsb20;     //相机连接的USB接口是否是USB2.0接口，若不是，相机无法正常工作

	}SUsbSpec;
		
}FCAM_INTERFACE_INFO, *PFCAM_INTERFACE_INFO;

//end CAMERA_FEATURE--------------------

//for HARDWARE_INFO---------------------
//HARDWARE_INFO对应的结构体
typedef struct __HARDWARE_INFO__
{
	char     VendorName[100];    //厂商名
	char     ModelName[100];     //型号名
	ULONG    ulCameraID[2];      //相机ID
	BYTE     byHdEdition[4];     //硬件版本号
    BYTE     byHdUpdateTime[4];  //硬件更新日期

}FCAM_HARDWARE_INFO, *PFCAM_HARDWARE_INFO;
//end HARDWARE_INFO-----------------------

//for IMAGE_INFO--------------------------
//像素格式信息
typedef enum enumPixel_Format
{
	Raw8       = 0x00000000,        //彩色传感器输出的8位原始数据
	Raw16      = 0x00000001,        //彩色传感器输出的16位原始数据
	YMono8     = 0x00000002,        //8位亮度信息数据
	YMono16    = 0x00000003,        //16位亮度信息数据,无符号
	S_YMono16  = 0x00000004,        //16位亮度信息数据,有符号  
	RGB8       = 0x00000005,        //R=B=G=8bit  R-G-B-R-G-B
	RGB16      = 0x00000006,        //R=B=G=16bit R-G-B-R-G-B
	S_RGB16    = 0x00000007,        //R=B=G=16bit,有符号整型

	YUV444     = 0x00000008,        //U-Y-V-U-Y-V排列，均占8bit，pixel bit = 24 
	YUV422     = 0x00000009,        //U-Y-V-Y-U-Y-V-Y排列，均占8bit,pixel bit = 16
	YUV411     = 0x0000000a         //U-Y-Y-V-Y-Y-U排列，均占8bit, pixel bit = 12    

}FCAM_PIXEL_FORMAT;

//视频格式类型
typedef enum enumVideoFM
{
	F0M0_160_120YUV444  = 0x00000000,  //图像分辨率为160 * 120，像素格式为YUV444
	F0M1_320_240YUV422  = 0x00000001,  //图像分辨率为320 * 240，像素格式为YUV422
	F0M2_640_480YUV411  = 0x00000002,  //图像分辨率为640 * 480，像素格式为YUV411
	F0M3_640_480YUV422  = 0x00000003,  //图像分辨率为640 * 480，像素格式为YUV422
	F0M4_640_480RGB8    = 0x00000004,  //图像分辨率为640 * 480，像素格式为RGB8
	F0M5_640_480YMono8  = 0x00000005,  //图像分辨率为640 * 480，像素格式为YMono8
	F0M6_640_480YMono16 = 0x00000006,  //图像分辨率为640 * 480，像素格式为YMono16


	F1M0_800_600YUV422   = 0x00000007, //图像分辨率为800 * 600，像素格式为YUV422
	F1M1_800_600RGB8     = 0x00000008, //图像分辨率为800 * 600，像素格式为RGB8
	F1M2_800_600YMono8   = 0x00000009, //图像分辨率为800 * 600，像素格式为YMono8
	F1M3_1024_768YUV422  = 0x0000000a, //图像分辨率为1024 * 768，像素格式为YUV422
	F1M4_1024_768RGB8    = 0x0000000b, //图像分辨率为1024 * 768，像素格式为RGB8
	F1M5_1024_768YMono8  = 0x0000000c, //图像分辨率为1024 * 768，像素格式为YMono8
	F1M6_800_600YMono16  = 0x0000000d, //图像分辨率为800 * 600，像素格式为YMono16
	F1M7_1024_768YMono16 = 0x0000000e, //图像分辨率为1024 * 768，像素格式为YMono16

	F2M0_1280_960YUV422   = 0x0000000f, //图像分辨率为1280 * 960，像素格式为YUV422
	F2M1_1280_960RGB8     = 0x00000010, //图像分辨率为1280 * 960，像素格式为RGB8
	F2M2_1280_960YMono8   = 0x00000011, //图像分辨率为1280 * 960，像素格式为YMono8
	F2M3_1600_1200YUV422  = 0x00000012, //图像分辨率为1600 * 1200，像素格式为YUV422
	F2M4_1600_1200RGB8    = 0x00000013, //图像分辨率为1600 * 1200，像素格式为RGB8
	F2M5_1600_1200YMono8  = 0x00000014, //图像分辨率为1600 * 1200，像素格式为YMono8
	F2M6_1280_960YMono16  = 0x00000015, //图像分辨率为1280 * 960，像素格式为YMono16
	F2M7_1600_1200YMono16 = 0x00000016, //图像分辨率为1600 * 1200，像素格式为YMono16

	F6M0_EXIF_FORMAT      = 0x00000017, //静止图像格式

	//厂商自定义格式
    F7M0_CUSTOM           = 0x00000018, //厂商自定义格式0
	F7M1_CUSTOM           = 0x00000019, //厂商自定义格式1
	F7M2_CUSTOM           = 0x0000001a, //厂商自定义格式2
	F7M3_CUSTOM           = 0x0000001b, //厂商自定义格式3
	F7M4_CUSTOM           = 0x0000001c, //厂商自定义格式4
	F7M5_CUSTOM           = 0x0000001d, //厂商自定义格式5
	F7M6_CUSTOM           = 0x0000001e, //厂商自定义格式6
	F7M7_CUSTOM           = 0x0000001f  //厂商自定义格式7

}FCAM_VIDEO_FORMAT;

//帧频格式
typedef enum enumFRAME_RATE
{
	RATE_1_875    = 0x00000000,    //1.875帧每秒
	RATE_3_75     = 0x00000001,    //3.75帧每秒
	RATE_7_5      = 0x00000002,    //7.5帧每秒
	RATE_15       = 0x00000003,    //15帧每秒
	RATE_30       = 0x00000004,    //30帧每秒
	RATE_60       = 0x00000005,    //60帧每秒
	RATE_120      = 0x00000006,    //120帧每秒
	RATE_240      = 0x00000007,    //240帧每秒
	RATE_ANY      = 0x00000008,     //帧频不受限，可能为任何值，由相机硬件厂商决定
}FCAM_FRAME_RATE;

//滤光片阵列格式
typedef enum enumColorFilterArray
{
	NONE  = 0x00000000,    //非Bayer阵列
	RG_GB = 0x00000001,    //Bayer阵列，排列方式为：第一行：R G R G…… 第二行：G B G B……
	GB_RG = 0X00000002,    //Bayer阵列，排列方式为：第一行：G B G B…… 第二行：R G R G……
	GR_BG = 0x00000003,    //Bayer阵列，排列方式为：第一行：G R G R…… 第二行：B G B G……
	BG_GR = 0x00000004     //Bayer阵列，排列方式为：第一行：B G B G…… 第二行：G R G R……

}FCAM_COLORFILTER_PATTERN;

typedef struct __Image_Info__
{
	FCAM_VIDEO_FORMAT   FormatMode;       //FCAM_VIDEO_FORMAT视频格式类型，输入参数

	BOOL                bSupport;         //相机是否支持该视频格式，TRUE支持，FALSE不支持

	BOOL                bAOI;             //该视频格式是否支持开窗操作，TRUE支持，FALSE不支持
	ULONG               ulMaxWidthSize;   //该视频格式支持的图像宽度的最大分辨率
	ULONG               ulMaxHeightSize;  //该视频格式支持的图像高度的最大分辨率
	ULONG               ulLeftPosUnit;    //开窗起始列步进单位，bAOI为FALSE时该参数无效，忽略
	ULONG               ulTopPosUnit;     //开窗起始行步进单位，bAOI为FALSE时该参数无效，忽略
	ULONG               ulWidthSizeUnit;  //开窗宽度步进单位，bAOI为FALSE时该参数无效，忽略
	ULONG               ulHeightSizeUnit; //开窗高度步进单位，bAOI为FALSE时该参数无效，忽略

	FCAM_COLORFILTER_PATTERN  ColorFilterPattern;      //该视频格式的彩色滤光片阵列模式
	BOOL                      bSupportFrameRate[9];    //对FCAM_1394_FRAME_RATE帧频的支持
	BOOL                      bSupportPixelFormat[11]; //对FCAM_PIXEL_FORMAT像素格式的支持
 
	
	FCAM_CAMERA_TYPE    CameraType;   //当前的相机类型，若为CAMERA_1394，S1394Spec结构体有效
     
	struct
	{
		float   fFrameInterval;       //帧间隔,为0值，忽略

	}S1394Spec;

}FCAM_IMAGE_INFO, *PFCAM_IMAGE_INFO;
//end IMAGE_INFO----------------------

//for STROBE_INFO---------------------
typedef struct __CAMERA_STROBE_INFO__
{	
	ULONG      ulStrobeIndex;        //频闪灯通道选择，输入参数，从0~3

	BOOL       bAvaliable;           //相机是否支持该路频闪灯操作，TRUE表示支持，FALSE为不支持
	BOOL       bCanOnOff;            //该通道是否支持使能或者不使能的切换操作，TRUE支持，FALSE不支持
	BOOL       bCanReadOut;          //该通道的参数值是否可读，TRUE可读，FALSE不可读
	BOOL       bCanChangePolarity;   //频闪灯极性是否可改变，TRUE表示可以改变，FALSE不可改变

	struct
	{	
		BOOL       bLongValueValid;  //频闪灯参数是否可以以整型值来设置
		LONG       lMax_Value;       //整型值最大值
		LONG       lMin_Value;       //整型值最小值
		LONG	   lStep;		     //整型调节步进值

	
		BOOL       bFloatValueValid;  //频闪灯参数是否可以以浮点值来设置
		float      fMax_Value;        //浮点型值最大值
		float      fMin_Value;        //浮点型值最小值
		float	   fStep;	          //浮点型值调节步进值

	}StrobeInfoValue; 

}FCAM_STROBE_INFO, *PFCAM_STROBE_INFO;
//--end STROBE_INFO---------------------------------

//for TRIGGER_INFO-----------------------------------
//触发源类型
typedef enum enumTriggerSource
{
	TRIGGER_SOR0     = 0x00000000,     //硬件0触发源
	TRIGGER_SOR1     = 0x00000001,     //硬件1触发源
	TRIGGER_SOR2     = 0x00000002,     //硬件2触发源
	TRIGGER_SOR3     = 0x00000003,     //硬件3触发源
	TRIGGER_SOR4     = 0x00000004,     //硬件4触发源
	TRIGGER_SOR5     = 0x00000005,     //硬件5触发源
	TRIGGER_SOR6     = 0x00000006,     //硬件6触发源
	TRIGGER_SOFT     = 0x00000007      //软件触发

}FCAM_TRIGGER_SOURCE;

typedef struct __CAMERA_TRIGGER_INFO__
{	
	BOOL    bAvaliable;               //该相机是否支持触发功能，TRUE表示支持，FALSE为不支持
	BOOL    bCanOnOff;                //触发功能是否支持使能或者不使能的切换操作，TRUE为支持，FALSE不支持
	BOOL    bCanReadOut;              //触发参数值是否可读，TRUE可读，FALSE不可读         
	BOOL    bCanChangePolarity;       //触发极性是否可改变，TRUE表示可以改变，FALSE不可改变
	BOOL    bCanReadRawTrgInput;      //原始触发输入信号值是否可读，若bCanReadOut为FALSE，该值忽略

	BOOL    bHdTriggerSor[7];         //相机对FCAM_TRIGGER_SOURCE定义的TRIGGER_SOR0到TRIGGER_SOR6七种触发通道的支持
	BOOL    bSoftWareTrigger;         //相机是否支持软件触发功能，TRUE为支持，FALSE为不支持
	BOOL    bTriggerMode[16];         //相机对16种触发模式的支持，TRUE为支持，否则不支持	
	
}FCAM_TRIGGER_INFO, *PFCAM_TRIGGER_INFO;

//end TRIGGER_INFO------------------------------------

//for DATASTREAM_INFO---------------------------------
//数据传输模式
typedef enum enumTransType
{
	IDLE            = 0x00000000,     //当前相机不传输数据
	ONE_SHOT        = 0x00000001,     //当前相机的传输任务为传输一帧图像数据后，转为IDLE模式
	MUTI_SHOT       = 0x00000002,     //当前相机的传输任务为传输多帧图像数据后，转为IDLE模式
	CONTINUOUS_SHOT = 0x00000003      //当前相机的传输任务为连续传输

}FCAM_TRANSTYPE;

//1394相机的传输速度
typedef enum enum1394Speed
{
	SPEED_100M  = 0x00000000,       //100M bps/s
	SPEED_200M  = 0x00000001,       //200M bps/s
	SPEED_400M  = 0x00000002,       //400M bps/s
	SPEED_800M  = 0x00000003,       //800M bps/s
	SPEED_1_6G  = 0x00000004,       //1600M bps/s
	SPEED_3_2G  = 0x00000005        //3200M bps/s

}FCAM_1394SPEED;

typedef struct __STREAM_INFO__
{
	
	BOOL bCanMutiShot;              //相机是否支持连续采集传输模式，TRUE为支持，FALSE为不支持
	BOOL bCanContinusShot;          //相机是否支持多帧采集传输模式，TRUE支持，FALSE不支持
	BOOL bCanOneShot;               //相机是否支持单帧采集传输模式，TRUE支持，FALSE不支持

	ULONG    ulMaxStreamBufferCount;     //数据缓冲区可设的最大个数
	ULONG    ulMaxFrameCountOfBuffer;    //传输缓冲区包含的最大帧数

	FCAM_CAMERA_TYPE CameraType;         //相机类型，若为CAMERA_1394，S1394Spec结构体信息有效

	struct  
	{
		BOOL       bSpeedSupport[6];      //对FCAM_1394SPEED定义的6种速度的支持，TRUE为支持，FALSE为不支持
		ULONG      ulMaxChannelNumber;    //相机支持的最大可用通道值,从0开始
		
	}S1394Spec;

}FCAM_DATATRANS_INFO, *PFCAM_DATATRANS_INFO;

/////////////////////Get/Set参数设置和获取类型//////////////////////////////////////////

typedef enum enumGSP_Parameter
{
	GSP_FEATURE                = 0x00000000,   //特性参数类型，对应FCAM_GSP_FEATURE结构体

	GSP_IMAGE                  = 0x00000001,   //图像参数类型，对应FCAM_GSP_IMAGE结构体
	GSP_TRANS                  = 0x00000002,   //传输参数类型，对应FCAM_GSP_TRANS结构体            

	GSP_STROBE                 = 0x00000003,   //频闪灯参数类型，对应FCAM_GSP_STROBE结构体
	GSP_TRIGGER                = 0x00000004    //触发参数类型，对应FCAM_GSP_TRIGGER结构体

}FCAM_GSP_PARAME_TYPE;

//for GSP_FEATURE------------------------------------------
typedef struct __GSP_FEATURE__
{
	FCAM_FEATURE_TYPE FeatureType; //FCAM_FEATURE_TYPE定义的特性类型，输入参数

	BOOL             bAvaliable;   //相机是否支持该特性设置，同于FCAM_FEATURE_INFO中的bAvaliable,只读

	BOOL             bPresentOn;   //若为TRUE，该特性使能，否则不使能，
	                               //若FCAM_FEATURE_INFO中的bCanOnOff为FALSE，则该参数为只读，不可改变

	FCAM_ADJUST_MODE  AdjustMode;  //FCAM_ADJUST_MODE类型定义的调节模式

	BOOL              bValueValid; //参数值是否有效，若为TRUE，则ValueType和FeatureValue中的值有效，反之无效

	FCAM_VALUE_TYPE   ValueType;    //当前参数值类型，见FCAM_VALUE_TYPE定义。若为FLOAT_VALUE，
	                                //则FloatValue结构体有效，若为LONG_VALUE，则LongValue结构体有效

	struct
	{
		ULONG      ulValueCnt;     //当前整型参数值个数，最大为3
		long       lValue[3];      //若ValueType为LONG_VALUE，前uValueCnt个值为对应的参数值

	}LongValue;

	struct
	{
		ULONG      ulValueCnt;      //当前浮点参数值个数，最大为3
		float      fValue[3];       //若ValueType为FLOAT_VALUE，前uValueCnt个值为对应的参数值

	}FloatValue;

}FCAM_GSP_FEATURE, *PFCAM_GSP_FEATURE;

//-for GSP_VIDEO_FORMAT----------------
typedef struct __GSP_IMAGE__
{
	FCAM_VIDEO_FORMAT   FormatMode;    //当前视频格式
	FCAM_FRAME_RATE     FrameRate;     //当前帧频模式

	FCAM_PIXEL_FORMAT   PixelFormat;   //当前的像素格式
	ULONG               ulPixelBits;   //像素位数,read only,设置时忽略该值
	
	ULONG               ulLeft;        //显示图像的起始列，当获得的FCAM_IMAGE_INFO信息结构体中的bAOI为TRUE时，该值可按照ulLeftPosUnit设置，否则只读
	ULONG               ulTop;         //显示图像的起始行。当获得的FCAM_IMAGE_INFO信息结构体中的bAOI为TRUE时，该值可按照ulTopPosUnit设置，否则只读
	ULONG               ulWidth;       //显示图像的宽度，当获得的FCAM_IMAGE_INFO信息结构体中的bAOI为TRUE时，该值可按照ulWidthSizeUnit设置，否则只读
	ULONG               ulHeight;      //显示图像的高度，当获得的FCAM_IMAGE_INFO信息结构体中的bAOI为TRUE时，该值可按照ulHeightSizeUnit设置，否则只读

	FCAM_CAMERA_TYPE    CameraType;    //相机类型，若该值为CAMERA_1394,S1394Spec结构体有效，否则S1394Spec无效
	
	struct
	{
		BOOL        bDataVerify;                  //是否对数据进行校验，该值在当前版本忽略

		BOOL        bPacketSetable;               /*只读参数，表示当前包大小是否可设，TRUE为可设，且ulUnitBytePerPacket
						                            ulMaxBytePerPacket、ulRecBytePerPacket有效，反之无效，且ulPacketSize为只读参数*/

        ULONG       ulUnitBytePerPacket;          //包大小设置单位，也为包大小可设的最小值，只读 
		ULONG       ulMaxBytePerPacket;           //包大小可设的最大值，只读
		ULONG       ulRecBytePerPacket;           //相机推荐的包大小，为0表示忽略，只读 

		ULONG       ulPacketSize;                 //当前包大小，若包大小不可设，该值只读。若报大小可设且该值为0，则包大小设置忽略

		ULONG       ulPacketPerFrame;             //当前一帧图像数据的包个数，只读
	
	}S1394Spec;
}FCAM_GSP_IMAGE, *PFCAM_GSP_IMAGE;

//for GSP_STROBE-----------------------------
typedef struct __GSP_STROBE__
{

	ULONG             ulStrobeIndex;  //频闪灯通道值，从0-3,输入参数

	BOOL              bAvaliable;     //相机是否支持频闪灯通道设置，同于同样通道FCAM_STROBE_INFO信息中的
                                      //bAvaliable。该参数为只读参数，即只能获取不能设置。若该参数为FALSE，
                                      //以下所有参数值无效

	BOOL              bPresentOn;     //若为TRUE，该特性设置使能，否则不使能，若FCAM_STROBE_INFO中的bCanOnOff为FALSE，则该参数为只读，不可设置

	ULONG             ulPolarity;     //频闪灯极性，若FCAM_STROBE_INFO中的bCanChangePolarity为TRUE，则该参数可读可设，否则该参数只读

	BOOL              bValueValid;    //参数值是否有效，若为TRUE，则ValueType和StrobeValue中的值有效，反之无效

	FCAM_VALUE_TYPE   ValueType;      //当前参数值类型，见FCAM_VALUE_TYPE定义。若为FLOAT_VALUE，则FloatValue结构体有效，
	                                  //若为LONG_VALUE，则LongValue结构体有效
	
	struct 
	{
		LONG       lDelayValue;      //若ValueType为LONG_VALUE，该值有效，为频闪灯延迟时间，整型
		LONG       lDurationValue;   //若ValueType为LONG_VALUE，该值有效，为频闪灯持续时间，整型

	}LongValue;

	struct 
	{
		float      fDelayValue;      //若ValueType为FLOAT_VALUE，该值有效，为频闪灯延迟时间，浮点型
		float      fDurationValue;   //若ValueType为FLOAT_VALUE，该值有效，为频闪灯持续时间，浮点型
		
	}FloatValue;

	

}FCAM_GSP_STROBE, *PFCAM_GSP_STROBE;

//-for GSP_TRIGGER-------------------
typedef struct __GSP_TRIGGER__
{

	BOOL                bAvaliable;       //相机是否支持触发设置，同于FCAM_TRIGGER_INFO信息中的bAvaliable。
	                                      //该参数为只读参数，即只能获取不能设置。若该参数为FALSE，以下所有参数值无效
	
	BOOL                bPresentOn;       //若为TRUE，该特性设置使能，否则不使能，若对应的FCAM_TRIGGER_INFO信息中的bCanOnOff为FALSE，则该参数为只读，不可设置
 
	ULONG               ulTrgPolarity;    //触发极性，若FCAM_TRIGGER_INFO中的bCanChangePolarity为TRUE，则该参数可读可设，否则该参数只读
	FCAM_TRIGGER_SOURCE TrgSorce;         //触发源
	ULONG               ulTrgleMode;      //触发模式

	BOOL                bValueValid;      //触发信号值是否有效
	ULONG               ulTrgInputValue;  //触发信号，只读


}FCAM_GSP_TRIGGER, *PFCAM_GSP_TRIGGER;

//for GSP_TRANS-----------------------
typedef struct __GSP_TRANS__
{
	FCAM_TRANSTYPE   TransMode;            //当前传输模式
	ULONG            ulTransFrameCnt;      //多帧传输模式的传输帧数，当传输模式为MUTI_SHOT时，该值有效，否则忽略
	  
	ULONG            ulStreamBufferCnt;    //流传输的数据缓冲区个数，最大值对应FCAM_DATATRANS_INFO中的uMaxStreamBufferCount

	ULONG            ulFrameCntOfOneBuffer; //一个数据缓冲区存储的帧数。在ONE_SHOT传输模式下，该值必须为1，在MUTI_SHOT模式下，
	                                        //该值应能整除uTransFrameCnt，最大值对应FCAM_DATATRANS_INFO中的uMaxFrameCountOfBuffer
	
	ULONG            ulStreamBufferSize;    //流传输的数据缓冲区大小，以字节为单位，只读

	FCAM_CAMERA_TYPE CameraType;            //相机类型，当该值为CAMERA_1394时，S1394Spec有效，否则无效
        
	struct
	{
		ULONG            ulChannel;         //传输通道值，最大值对应FCAM_DATATRANS_INFO中的uMaxChannelNumber
		FCAM_1394SPEED  TransSpeed;         //传输速度，对各速度类型的支持见FCAM_DATATRANS_INFO中的bSpeedSupport[6]


	}S1394Spec;

}FCAM_GSP_TRANS, *PFCAM_GSP_TRANS;

//value of DIGITAL_SHIFT------------------9/26/2007
//DIGITAL_SHIFT特性值对应的类型
typedef enum tagVAL_DIGITAL_SHIFT
{
	DS_HIGH_8BITS	= 0,     //高八位
	DS_MID_8BITS	= 1,     //中八位
	DS_LOW_8BITS	= 2      //低八位
}VAL_DIGITAL_SHIFT;

//vale of polarity---------------------------26/2007
//触发或者频闪灯极性值对应的类型
typedef enum tagVAL_POLARITY
{
	POL_LOW_ACTIVE	= 0,     //低电平有效
	POL_HIGH_ACTIVE = 1      //高电平有效
}VAL_POLARITY;

/////////////////////////返回值定义//////////////////////////////////////
#define FCAM_SUCCESS                 0x20000000    //操作成功

#define FCAM_UNSUCCESSFUL            0xE0000000    //操作失败
#define FCAM_NO_SUCH_DEVICE          0xE0000001    //找不到指定的设备
#define FCAM_DEVICE_INIT_FAIL        0xE0000002    //设备初始化失败
#define FCAM_DEVICE_NOT_MATCH        0xE0000003    //设备不匹配
#define FCAM_DEVICE_TRANS_FAILED     0xE0000004    //设备传输失败，在获得该类型的返回值后，应尝试重新启动数据传输
#define FCAM_CONFIGFILE_NOT_MATCH    0xE0000005    //配置文件不匹配

#define FCAM_INVALID_PARAMETER       0xE0000020    //无效参数
#define FCAM_INVALID_TRIGGER_SOURCE  0xE0000021    //无效的触发源
#define FCAM_INVALID_TRIGGER_MODE    0xE0000022    //无效的触发模式
#define FCAM_INVALID_HANDLE_VALUE    0xE0000023    //无效的句柄值

#define FCAM_INSUFFICIENT_RESOURCE   0xE0000040    //资源不足
#define FCAM_REASONLESS_PARAMETER    0xE0000041    //不合理的参数
#define FCAM_RESONLESS_PACKETSIZE    0xE0000042    //不合理的包大小

#define FCAM_FEATURE_NOT_SUPPORT     0xE0000050    //特性属性不支持
#define FCAM_VIDEOFORMAT_NOT_SUPPORT 0xE0000051    //视频格式不支持
#define FCAM_TRIGGER_NOT_SUPPORT     0xE0000052    //触发不支持
#define FCAM_STROBE_NOT_SUPPORT      0xE0000053    //频闪灯通道不支持
#define FCAM_FRAMERATE_NOT_SUPPORT   0xE0000054    //帧频不支持
#define FCAM_PIXELFORMAT_NOT_SUPPORT 0xE0000055    //像素格式不支持
#define FCAM_AOI_NOT_SUPPORT         0xE0000056    //开窗不支持
#define FCAM_REGISTER_RW_NOT_SUPPORT 0xE0000057    //某地址的寄存器读写不支持
#define FCAM_AUTOWHB_NOT_SUPPORT     0xE0000058    //自动白平衡不支持

//add on 2007-11-27 by zxm
#define FCAM_TRANSMODE_NOT_SUPPORT   0xE0000059    //传输模式不支持
#define FCAM_TRANSSPEED_NOT_SUPPORT  0xE0000060    //传输速度不支持

#define FCAM_SOFTTRIGGER_BUSY        0xE0000070    //上一帧软件触发没有结束    
//////////////////////////////////////////////////////////////////////////////////////
typedef struct __COMMU_INFO__
{
	PVOID              pDataBuffer;             //当前数据缓冲区的地址
	ULONG              ulDataSizes;             //数据缓冲区的大小，字节为单位
	ULONG              ulFrameCountOfData;      //该数据缓冲区包含的帧数

	ULONG              ulFrameLeft;             //每帧数据图像的开窗起始列数
	ULONG              ulFrameTop;              //每帧数据图像的开窗起始行数
	ULONG              ulFrameWidth;            //每帧数据图像的宽度
	ULONG              ulFrameHeight;           //每帧数据图像的高度
	ULONG              ulFrameSizes;            //一帧图像数据的大小，字节为单位
	ULONG              ulFrameAvaliableSizes;   //一帧图像数据的有效字节数

	FCAM_PIXEL_FORMAT  PixelFormat;             //像素格式
	ULONG              ulFramePixelBits;        //像素位数

	ULONG              ulDeviceIndex;           //当前相机序号
	FCAM_CAMERA_TYPE   CameraType;              //当前相机类型
	
	PVOID              pUserParam;              //用户自定义数据类型指针

}FCAM_COMMU_INFO, *PFCAM_COMMU_INFO;

//回调函数
typedef int(CALLBACK* PFCAM_CALLBACK)(PFCAM_COMMU_INFO pCommuParam);
//自动调节回调函数
typedef void(CALLBACK* PFCAM_AUTOSET_CALLBACK)(PVOID pParam, PVOID pContext);
//////////////////////////////////////////////////////////////////////////
//消息定义
#define WM_FCAM_MESSAGE     WM_USER + 500         //主消息
#define WM_FCAM_ONE_RSVD    WM_FCAM_MESSAGE + 1   //收到图像缓冲区大小的图像数据
#define WM_FCAM_ONE_FAILED  WM_FCAM_MESSAGE + 2	  //获取图像数据失败  
//////////////////////////////////////////////////////////////////////////

#endif