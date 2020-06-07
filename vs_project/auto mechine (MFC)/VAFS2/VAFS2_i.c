/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sat Oct 06 20:34:15 2018
 */
/* Compiler settings for C:\Documents and Settings\Administrator\桌面\东莞自动线\RTU AF3-R DS 500 485 Z two autoload\AF3R\VAFS2\VAFS2\VAFS2.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID LIBID_VAFS2Lib = {0x833CF565,0xB57F,0x4560,{0xA9,0x29,0x5F,0xE1,0xD0,0x5D,0x90,0x53}};


#ifdef __cplusplus
}
#endif

