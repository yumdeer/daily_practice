#ifndef _LEISAI_
#define _LEISAI_

//#ifdef __cplusplus
extern "C" {
//#endif

//这一段无需改动  //This segment should not be modified
#ifndef TRUE
#define TRUE  1
#endif

#ifndef FALSE
#define FALSE 0
#endif

typedef unsigned long       DWORD;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef float               FLOAT;

typedef unsigned char  INT8U;                   /* defined for unsigned 8-bits integer variable 	无符号8位整型变量  */
typedef signed   char  INT8S;                   /* defined for signed 8-bits integer variable		有符号8位整型变量  */
typedef unsigned short INT16U;                  /* defined for unsigned 16-bits integer variable 	无符号16位整型变量 */
typedef signed   short INT16S;                  /* defined for signed 16-bits integer variable 		有符号16位整型变量 */
typedef unsigned int   INT32U;                  /* defined for unsigned 32-bits integer variable 	无符号32位整型变量 */
typedef int			   INT32S;                  /* defined for signed 32-bits integer variable 		有符号32位整型变量 */
typedef float		   FP32;                    /* single precision floating point variable (32bits) 单精度浮点数（32位长度） */
typedef double		   FP64;                    /* double precision floating point variable (64bits) 双精度浮点数（64位长度） */


#define DMC1000_API __declspec(dllexport)


#define WINAPI __stdcall





///////////////////////////////////////////////////////////
/////////////////////DMC1380 V1.2函数列表//////////////////
///////////////////////////////////////////////////////////

//////////////////初始化函数////////////////////
//---------------------   板卡初始和配置函数  ----------------------
/********************************************************************************
** 函数名称: d1000_board_init
** 功能描述: 控制板初始化，设置初始化和速度等设置
** 输　  入: 无
** 返 回 值: 0：无卡； 1-8：成功(实际卡数) 
** 修    改:  
*********************************************************************************/
DMC1000_API DWORD WINAPI d1000_board_init(void);

DMC1000_API DWORD WINAPI d1000_board_close(void);
//DMC1000_API DWORD WINAPI d1000_get_base_addr(short CardNo);
//DMC1000_API DWORD WINAPI d1000_get_irq_channel(short CardNo);
//////////////////脉冲输出设置函数//////////////
DMC1000_API DWORD WINAPI d1000_set_pls_outmode(short axis,short pls_outmode);

//////////////////速度模式运动函数//////////////
DMC1000_API DWORD WINAPI d1000_start_tv_move(short axis,long StrVel,long MaxVel,double Tacc);

DMC1000_API DWORD WINAPI d1000_get_speed(short axis);
//DMC1000_API DWORD WINAPI d1000_change_speed(short axis,long NewVel,double Tadc);
DMC1000_API DWORD WINAPI d1000_change_speed(short axis,long NewVel);
DMC1000_API DWORD WINAPI d1000_decel_stop(short axis);
DMC1000_API DWORD WINAPI d1000_immediate_stop(short axis);

//////////////////单轴位置模式函数//////////////
DMC1000_API DWORD WINAPI d1000_start_t_move(short axis,long Dist, long StrVel,long MaxVel,double Tacc);
DMC1000_API DWORD WINAPI d1000_start_ta_move(short axis,long Pos, double StrVel,double MaxVel,double Tacc);

DMC1000_API DWORD WINAPI d1000_start_s_move(short axis,long Dist, long StrVel,long MaxVel,double Tacc);
DMC1000_API DWORD WINAPI d1000_start_sa_move(short axis,long Pos, long StrVel,long MaxVel,double Tacc);

DMC1000_API DWORD WINAPI d1000_start_sv_move(short axis,long StrVel,long MaxVel,double Tacc);

DMC1000_API DWORD WINAPI d1000_set_s_profile(short axis,double s_para);
DMC1000_API DWORD WINAPI d1000_get_s_profile(short axis,double* s_para);

//////////////////线性插补函数//////////////////
DMC1000_API DWORD WINAPI d1000_start_t_line(short TotalAxis,short *AxisArray,long *DistArray,long StrVel, long MaxVel, double Tacc);
DMC1000_API DWORD WINAPI d1000_start_ta_line(short TotalAxis,short *AxisArray,long *DistArray,long StrVel, long MaxVel, double Tacc);

//////////////////回原点函数////////////////////
DMC1000_API DWORD WINAPI d1000_home_move(short axis,long StrVel,long MaxVel,double Tacc);

//////////////////运动状态检测函数//////////////
DMC1000_API DWORD WINAPI d1000_check_done(short axis);

//////////////////位置设定和读取函数////////////
DMC1000_API long WINAPI d1000_get_command_pos(short axis);
DMC1000_API DWORD WINAPI d1000_set_command_pos(short axis,double Pos);

//////////////////通用I/O函数///////////////////
DMC1000_API DWORD WINAPI d1000_out_bit(short BitNo,short BitData);
DMC1000_API DWORD WINAPI d1000_in_bit(short BitNo);
DMC1000_API DWORD WINAPI d1000_get_outbit(short BitNo);
DMC1000_API void WINAPI d1000_in_enable(DWORD CardNo,DWORD InputEn);


//////////////////专用I/O接口函数///////////////
DMC1000_API DWORD WINAPI d1000_set_sd(short axis ,short SdMode);
DMC1000_API DWORD WINAPI d1000_get_axis_status(short axis);

DMC1000_API void  WINAPI d1000_WriteDWord(DWORD addr, DWORD data);
DMC1000_API DWORD WINAPI d1000_ReadDWord(DWORD addr);


//#ifdef __cplusplus
}
//#endif

#endif 
