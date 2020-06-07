# Microsoft Developer Studio Project File - Name="VAFS2" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=VAFS2 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "VAFS2.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "VAFS2.mak" CFG="VAFS2 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "VAFS2 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "VAFS2 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/VAFS2/VAFS2", DAAAAAAA"
# PROP Scc_LocalPath ".."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "VAFS2 - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "C:\Program Files\MVTec\HALCON-10.0\include" /I "C:\Program Files\MVTec\HALCON-10.0\include\cpp" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 halconcpp.lib /nologo /subsystem:windows /machine:I386 /libpath:"C:\Program Files\MVTec\HALCON-10.0\lib\x86sse2-win32"

!ELSEIF  "$(CFG)" == "VAFS2 - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /I "C:\Program Files\MVTec\HALCON-10.0\include\cpp" /I "C:\Program Files\MVTec\HALCON-10.0\include\\" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_DEVELOP" /D "STRSAFE_NO_DEPRECATE" /D "_AFXDLL" /Fr /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 halconcpp.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept /libpath:"C:\Program Files\The Imaging Source Europe GmbH\IC Imaging Control 3.0\classlib\debug\  C:\Program Files\MVTec\HALCON-10.0\lib\x86sse2-win32" /libpath:"C:\Program Files\MVTec\HALCON-10.0\lib\x86sse2-win32"
# SUBTRACT LINK32 /pdb:none /map /nodefaultlib

!ENDIF 

# Begin Target

# Name "VAFS2 - Win32 Release"
# Name "VAFS2 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\DebugDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DELETERCP.cpp
# End Source File
# Begin Source File

SOURCE=.\IOMonitor.cpp
# End Source File
# Begin Source File

SOURCE=.\login.cpp
# End Source File
# Begin Source File

SOURCE=.\ModelEditDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\mscomm.cpp
# End Source File
# Begin Source File

SOURCE=.\MyButton.cpp
# End Source File
# Begin Source File

SOURCE=.\PARAMETERSET.cpp
# End Source File
# Begin Source File

SOURCE=.\paraproduce.cpp
# End Source File
# Begin Source File

SOURCE=.\RcpSave.cpp
# End Source File
# Begin Source File

SOURCE=.\SmallKey.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\VAFS2.cpp
# End Source File
# Begin Source File

SOURCE=.\hlp\VAFS2.hpj

!IF  "$(CFG)" == "VAFS2 - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Making help file...
OutDir=.\Release
InputPath=.\hlp\VAFS2.hpj
InputName=VAFS2

"$(OutDir)\$(InputName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	start /wait hcw /C /E /M "hlp\$(InputName).hpj" 
	if errorlevel 1 goto :Error 
	if not exist "hlp\$(InputName).hlp" goto :Error 
	copy "hlp\$(InputName).hlp" $(OutDir) 
	goto :done 
	:Error 
	echo hlp\$(InputName).hpj(1) : error: 
	type "hlp\$(InputName).log" 
	:done 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "VAFS2 - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Making help file...
OutDir=.\Debug
InputPath=.\hlp\VAFS2.hpj
InputName=VAFS2

"$(OutDir)\$(InputName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	start /wait hcw /C /E /M "hlp\$(InputName).hpj" 
	if errorlevel 1 goto :Error 
	if not exist "hlp\$(InputName).hlp" goto :Error 
	copy "hlp\$(InputName).hlp" $(OutDir) 
	goto :done 
	:Error 
	echo hlp\$(InputName).hpj(1) : error: 
	type "hlp\$(InputName).log" 
	:done 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\VAFS2.idl
# ADD MTL /h "VAFS2_i.h" /iid "VAFS2_i.c" /Oicf
# End Source File
# Begin Source File

SOURCE=.\VAFS2.rc
# End Source File
# Begin Source File

SOURCE=.\VAFS2Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\VisionSetDlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AAFStage.h
# End Source File
# Begin Source File

SOURCE=.\ckvision.h
# End Source File
# Begin Source File

SOURCE=.\DebugDlg.h
# End Source File
# Begin Source File

SOURCE=.\DELETERCP.h
# End Source File
# Begin Source File

SOURCE=.\Dmc1000.h
# End Source File
# Begin Source File

SOURCE=.\DrawUtil.h
# End Source File
# Begin Source File

SOURCE=.\externs.h
# End Source File
# Begin Source File

SOURCE=.\FCAM.h
# End Source File
# Begin Source File

SOURCE=.\FCAM_Def.h
# End Source File
# Begin Source File

SOURCE=.\glbs.h
# End Source File
# Begin Source File

SOURCE=.\IOMonitor.h
# End Source File
# Begin Source File

SOURCE=.\ISIDll.h
# End Source File
# Begin Source File

SOURCE=.\login.h
# End Source File
# Begin Source File

SOURCE=.\MAVision.h
# End Source File
# Begin Source File

SOURCE=.\ModelEditDlg.h
# End Source File
# Begin Source File

SOURCE=.\mscomm.h
# End Source File
# Begin Source File

SOURCE=.\MyButton.h
# End Source File
# Begin Source File

SOURCE=.\PARAMETERSET.h
# End Source File
# Begin Source File

SOURCE=.\paraproduce.h
# End Source File
# Begin Source File

SOURCE=.\RcpSave.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h

!IF  "$(CFG)" == "VAFS2 - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Making help include file...
TargetName=VAFS2
InputPath=.\Resource.h

"hlp\$(TargetName).hm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo. >"hlp\$(TargetName).hm" 
	echo // Commands (ID_* and IDM_*) >>"hlp\$(TargetName).hm" 
	makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Prompts (IDP_*) >>"hlp\$(TargetName).hm" 
	makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Resources (IDR_*) >>"hlp\$(TargetName).hm" 
	makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Dialogs (IDD_*) >>"hlp\$(TargetName).hm" 
	makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Frame Controls (IDW_*) >>"hlp\$(TargetName).hm" 
	makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\$(TargetName).hm" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "VAFS2 - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Making help include file...
TargetName=VAFS2
InputPath=.\Resource.h

"hlp\$(TargetName).hm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo. >"hlp\$(TargetName).hm" 
	echo // Commands (ID_* and IDM_*) >>"hlp\$(TargetName).hm" 
	makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Prompts (IDP_*) >>"hlp\$(TargetName).hm" 
	makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Resources (IDR_*) >>"hlp\$(TargetName).hm" 
	makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Dialogs (IDD_*) >>"hlp\$(TargetName).hm" 
	makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Frame Controls (IDW_*) >>"hlp\$(TargetName).hm" 
	makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\$(TargetName).hm" 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\SmallKey.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\VAFS2.h
# End Source File
# Begin Source File

SOURCE=.\VAFS2Dlg.h
# End Source File
# Begin Source File

SOURCE=.\VisionSetDlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\FCAM.dll
# End Source File
# Begin Source File

SOURCE=.\res\film.bmp
# End Source File
# Begin Source File

SOURCE=.\res\gray.bmp
# End Source File
# Begin Source File

SOURCE=.\res\green.bmp
# End Source File
# Begin Source File

SOURCE=.\I2C.dll
# End Source File
# Begin Source File

SOURCE=.\I2CCTL.sys
# End Source File
# Begin Source File

SOURCE=.\ISIDll.dll
# End Source File
# Begin Source File

SOURCE=.\res\VAFS2.ico
# End Source File
# Begin Source File

SOURCE=.\res\VAFS2.rc2
# End Source File
# Begin Source File

SOURCE=.\VAFS2.rgs
# End Source File
# Begin Source File

SOURCE=".\res\开机画面.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\开机画面2.bmp"
# End Source File
# Begin Source File

SOURCE=.\FCAM.lib
# End Source File
# Begin Source File

SOURCE=.\Dmc1000.lib
# End Source File
# End Group
# Begin Group "Help Files"

# PROP Default_Filter "cnt;rtf"
# Begin Source File

SOURCE=.\hlp\AfxDlg.rtf
# End Source File
# Begin Source File

SOURCE=.\hlp\VAFS2.cnt

!IF  "$(CFG)" == "VAFS2 - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Copying contents file...
OutDir=.\Release
InputPath=.\hlp\VAFS2.cnt
InputName=VAFS2

"$(OutDir)\$(InputName).cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "hlp\$(InputName).cnt" $(OutDir)

# End Custom Build

!ELSEIF  "$(CFG)" == "VAFS2 - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Copying contents file...
OutDir=.\Debug
InputPath=.\hlp\VAFS2.cnt
InputName=VAFS2

"$(OutDir)\$(InputName).cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "hlp\$(InputName).cnt" $(OutDir)

# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\vafs2.exe.manifest
# End Source File
# End Target
# End Project
# Section VAFS2 : {000001BE-01BE-0000-BE01-0000BE010000}
# 	1:9:IDR_VAFS2:104
# End Section
# Section VAFS2 : {E6E17E90-DF38-11CF-8E74-00A0C90F26F8}
# 	2:5:Class:CMSComm
# 	2:10:HeaderFile:mscomm.h
# 	2:8:ImplFile:mscomm.cpp
# End Section
# Section VAFS2 : {648A5600-2C6E-101B-82B6-000000000014}
# 	2:21:DefaultSinkHeaderFile:mscomm.h
# 	2:16:DefaultSinkClass:CMSComm
# End Section
