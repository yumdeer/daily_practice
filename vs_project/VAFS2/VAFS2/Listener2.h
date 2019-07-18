// Listener2.h: interface for the Listener2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LISTENER2_H__418EDFAA_9258_4620_9003_40DC2522EDDC__INCLUDED_)
#define AFX_LISTENER2_H__418EDFAA_9258_4620_9003_40DC2522EDDC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class listener2 : public DShowLib::GrabberListener  
{
public:
	listener2();
	virtual ~listener2();
public:
	virtual void frameReady(DShowLib::Grabber& caller, smart_ptr<DShowLib::MemBuffer> pBuffer, DWORD FrameNumber);
  
};

#endif // !defined(AFX_LISTENER2_H__418EDFAA_9258_4620_9003_40DC2522EDDC__INCLUDED_)
