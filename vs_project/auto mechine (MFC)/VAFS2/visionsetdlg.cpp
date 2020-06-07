// VisionSetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "VAFS2.h"
#include "VisionSetDlg.h"
#include "externs.h"
#include "Dmc1000.h"
#include "externs.h"
#include "SmallKey.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



int IDnumv;
//////////////////////////////////////////colorvariable
HBRUSH vfixcolor;
HBRUSH vwhitecolor;
//////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// CVisionSetDlg dialog


CVisionSetDlg::CVisionSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVisionSetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CVisionSetDlg)
	m_bright = bright;
	m_digitalshift = 0;
	m_contrast = 0.0f;
	m_gain = 0;
	m_shutter = 0;
	m_keypastex = 0.0f;
	m_keypastey = 0.0f;
	//}}AFX_DATA_INIT
	m_bStartCapture  =FALSE;
	
}


void CVisionSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVisionSetDlg)
	DDX_Control(pDX, IDC_LIST1, m_list1);
	DDX_Text(pDX, IDC_EDIT_contrast, m_contrast);
	DDX_Text(pDX, IDC_EDIT_GAIN, m_gain);
	DDX_Text(pDX, IDC_EDIT_SHUTTER, m_shutter);
	DDX_Text(pDX, IDC_keypastex, m_keypastex);
	DDX_Text(pDX, IDC_keypastey, m_keypastey);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CVisionSetDlg, CDialog)
	//{{AFX_MSG_MAP(CVisionSetDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OpenImage, OnOpenImage)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_StartCollection, OnStartCollection)
	ON_BN_CLICKED(IDC_StopCollection, OnStopCollection)
	ON_BN_CLICKED(IDC_EditModel, OnEditModel)
	ON_BN_CLICKED(IDC_SearchObject, OnSearchObject)
	ON_BN_CLICKED(IDC_DRAW_RECT, OnDrawRect)
	ON_BN_CLICKED(IDC_SaveModel, OnSaveModel)
	ON_BN_CLICKED(IDC_CreateModel, OnCreateModel)
	ON_BN_CLICKED(IDC_OK, OnOk)
	ON_BN_CLICKED(IDC_softkey3, Onsoftkey3)
	ON_EN_SETFOCUS(IDC_keypastex, OnSetfocuskeypastex)
	ON_EN_KILLFOCUS(IDC_keypastex, OnKillfocuskeypastex)
	ON_EN_SETFOCUS(IDC_keypastey, OnSetfocuskeypastey)
	ON_EN_KILLFOCUS(IDC_keypastey, OnKillfocuskeypastey)
	ON_BN_CLICKED(IDC_EDIT_GAIN, OnEditGain)
	ON_BN_CLICKED(IDC_EDIT_SHUTTER, OnEditShutter)
	ON_BN_CLICKED(IDC_EDIT_contrast, OnEDITcontrast)
	ON_WM_SYSCOMMAND()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()





/////////////////////////////////////////////////////////////////////////////
// CVisionSetDlg message handlers
BOOL CVisionSetDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

                           

    visionphoto=true;
    
    if(cameraselect==0)
	{
		m_shutter = shutter;
	m_contrast=contrast1;
	m_gain=gain;
	}
	 if(cameraselect==1)
	 {	m_shutter = shutter3;
	 m_contrast=contrast2;
	 m_gain=gain2;
	 }

    UpdateData(false);
	
	m_list1.SetExtendedStyle( 0x22 );
	m_list1.InsertColumn( 0, "编号", LVCFMT_LEFT, 50 );
	m_list1.InsertColumn( 1, "相似度", LVCFMT_LEFT, 60 );
	m_list1.InsertColumn( 2, "角度", LVCFMT_LEFT, 100 );
//	m_list1.InsertColumn( 3, "比例", LVCFMT_LEFT, 60 );
	m_list1.InsertColumn( 4, "中心x", LVCFMT_LEFT, 100 );
	m_list1.InsertColumn( 5, "中心y", LVCFMT_LEFT, 100 );
   










	
	InitDeviceFunction();//test for count
	

		
	ShowWindow(SW_SHOWMAXIMIZED);
		HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{
		::SendMessage(h,WM_CLOSE,0,0);
		SetDlgItemText(IDC_softkey3,"开键盘");
	}
	   


	Hlong m_WindowRow, m_WindowColumn, m_WindowWidth, m_WindowHeight;
			
	set_window_attr("border_width",HTuple(0));
	set_window_attr("window_title",HTuple("Camera0"));
	set_check("~father");





	
	CRect rtWindow;	
	HWND hWnd = GetDlgItem(IDC_PORFILE_RECTvision)->m_hWnd;
	Hlong lWWindowID = (Hlong)hWnd;
	
	GetDlgItem(IDC_PORFILE_RECTvision)->EnableWindow(true);//ModifyStyle(0,SS_NOTIFY); 

	GetDlgItem(IDC_PORFILE_RECTvision)->GetClientRect(&rtWindow);
	m_WindowRow = rtWindow.left;
	m_WindowColumn = rtWindow.top;
	m_WindowWidth = rtWindow.Width();
	m_WindowHeight = rtWindow.Height();

   open_window(m_WindowRow,m_WindowColumn,m_WindowWidth,m_WindowHeight,
				lWWindowID,"visible","",&m_Windowvisionid);
	
	set_part_style(m_Windowvisionid,2);
	set_check("father");
	//if(cameraselect==0)
	{
		set_part(m_Windowvisionid,0,0,camera1width,camera1height);
	//	disp_image(Image1,m_Windowvisionid);
	}
/*	if(cameraselect==1)
	{
		set_part(m_Windowvisionid,0,0,camera2width,camera2height);
	    m_keypastex=keypastextemp;
		m_keypastey=keypasteytemp;
		UpdateData(false);
		
		//disp_image(Image2,m_Windowvisionid);
	}*/
	IDnumv=0;
	UpdateWindow();
	return TRUE;  // return TRUE  unless you set the focus to a control
}


//初始化设备，给设备指定任务
BOOL CVisionSetDlg::InitDeviceFunction()
{
	 	CameraSetAeState(camera1, FALSE);
        CameraSetExposureTime(camera1, shutter*10000);
	  	
		CameraSetAnalogGain(camera1,gain);

		 	CameraSetAeState(camera2, FALSE);
        CameraSetExposureTime(camera2, shutter3*10000);
	  	
		CameraSetAnalogGain(camera2,gain2);
			CameraSetContrast(camera1, contrast1);
	CameraSetContrast(camera2, contrast2);




	
	return TRUE;
}





// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CVisionSetDlg::OnPaint() 
{

	CPaintDC dc(this); // device context for painting

	if (IsIconic())
	{
	    
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//DrawObject(&dc);
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CVisionSetDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CVisionSetDlg::BeginTime()
{
	QueryPerformanceFrequency( &m_Frequency );
	QueryPerformanceCounter( &m_BeginTime );
}

void CVisionSetDlg::EndTime()
{
	QueryPerformanceCounter(&m_EndTime);
	double fTime = double(m_EndTime.LowPart-m_BeginTime.LowPart)/double(m_Frequency.LowPart);
	CString strTime;
	strTime.Format( "时间 %0.3f", fTime * 1000.0 );
	SetDlgItemText( IDC_TIMER, strTime );
}

void CVisionSetDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
		



	CDialog::OnLButtonDown(nFlags, point);
}

void CVisionSetDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	


	CDialog::OnMouseMove(nFlags, point);
}

BOOL CVisionSetDlg::PreTranslateMessage(MSG* pMsg) 
{
		if ((pMsg->hwnd == ::GetDlgItem(m_hWnd, IDC_PORFILE_RECTvision) && pMsg->message == WM_LBUTTONDOWN)&&(cameraselect==1))
	{
		{
		HTuple button;
        Herror error_num;
	          try
		   {
				/*HTuple pointxtemp,pointytemp;
				float pointx,pointy;
				get_mposition(m_Windowvisionid,&pointxtemp, &pointytemp,&button) ;//point.x;	
				pointy=pointxtemp[0].D();
				pointx=pointytemp[0].D();
			  int nRes = AfxMessageBox("修改装配点吗？",MB_YESNO|MB_ICONQUESTION);
	           if(nRes == IDYES)
			   {
    
			    m_keypastex=pointx;
				m_keypastey=pointy;
				UpdateData(false);
				set_color(m_Windowvisionid,"red");
				if(cameraselect==0)
				{
					disp_image(Image1,m_Windowvisionid);
					disp_cross(m_Windowvisionid,keypasteytemp,keypastextemp,80,0);
				}
				if(cameraselect==1)
				{disp_image(Image2,m_Windowvisionid);}

				disp_cross(m_Windowvisionid,pointy,pointx,80,0);
				

				keypastextemp=pointx;
				keypasteytemp=pointy;
					CFile currentpara;
					currentpara.Open(currentparametername,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

					CArchive currentparaar(&currentpara,CArchive::store);
					currentparaar<<PARAINPUT;
    
					currentparaar.Close();
					currentpara.Close();
			   }*/
			
		   }
         catch (HException &except)
		 {
           error_num = except.err;
		   
		  	  return  CDialog::PreTranslateMessage(pMsg);	   
         
		 }


	}
     return  CDialog::PreTranslateMessage(pMsg);
	}
	
	//show positon of mouse on the screen
		
	{
		HTuple button;
        Herror error_num;
	          try
		   {
				HTuple pointxtemp,pointytemp;
				int pointx,pointy;
				 
         		get_mposition(m_Windowvisionid,&pointxtemp, &pointytemp,&button) ;//point.x;	
				pointy=pointxtemp[0].D();
				pointx=pointytemp[0].D();
				SetDlgItemInt( IDC_mousex, pointx );
				SetDlgItemInt( IDC_mousey, pointy );
			
		   }
         catch (HException &except)
		 {
           error_num = except.err;
		   return  CDialog::PreTranslateMessage(pMsg);
		  	 	   
          
		 }

     
	}

		


 return  CDialog::PreTranslateMessage(pMsg);
}
void CVisionSetDlg::DrawObject(CDC *pDC)
{
	
;




}

void CVisionSetDlg::OnOpenImage() 
{
	;
}



void CVisionSetDlg::OnStartCollection() 
{
	// TODO: Add your control notification handler code here

	//触发一帧图像数据
		
    	Sleep(100);
       if(cameraselect==0)
		{
			imagephotoover=false;
			
			CameraPlay(camera1);
	        while(imagephotoover!=true)
			{
			
				;
	   
			}
			disp_obj(Image1,m_Windowvisionid);
			imagephotoover=false;
			

  
		}
	    if(cameraselect==1)
		{
			imagephotoover2=false;
			
			CameraPlay(camera2);
	        while(imagephotoover2!=true)
			{
			
				;
	   
			}
			disp_obj(Image2,m_Windowvisionid);
			imagephotoover2=false;

  
		}

	 


}


//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

void CVisionSetDlg::OnStopCollection() 
{
	// TODO: Add your control notification handler code here
	
	//MAStop( 0 );

}

void CVisionSetDlg::OnCreateModel() 
{
	if(cameraselect==0)
	{m_ModelEditDlg.Imageedit=Image1;}
	if(cameraselect==1)
	{m_ModelEditDlg.Imageedit=Image2;}

	if((cameraselect==0)&&(modalselect==0))
	{m_ModelEditDlg.ShapeModeledit=ShapeModel11;}
	if((cameraselect==0)&&(modalselect==1))
	{m_ModelEditDlg.ShapeModeledit=ShapeModel12;}
	if((cameraselect==0)&&(modalselect==2))
	{m_ModelEditDlg.ShapeModeledit=ShapeModel13;}
	if((cameraselect==0)&&(modalselect==3))
	{m_ModelEditDlg.ShapeModeledit=ShapeModel14;}
	if((cameraselect==1)&&(modalselect==0))
	{m_ModelEditDlg.ShapeModeledit=ShapeModel21;}
	if((cameraselect==1)&&(modalselect==1))
	{m_ModelEditDlg.ShapeModeledit=ShapeModel22;}
	m_ModelEditDlg.EditModel( FALSE );
	
	m_ModelEditDlg.DoModal();
	OnSearchObject();

	
}

void CVisionSetDlg::OnEditModel() 
{
	// TODO: Add your control notification handler code here
	if(cameraselect==0)
	{m_ModelEditDlg.Imageedit=Image1;}
	if(cameraselect==1)
	{m_ModelEditDlg.Imageedit=Image2;}

	if((cameraselect==0)&&(modalselect==0))
	{m_ModelEditDlg.ShapeModeledit=ShapeModel11;}
	if((cameraselect==0)&&(modalselect==1))
	{m_ModelEditDlg.ShapeModeledit=ShapeModel12;}
	if((cameraselect==0)&&(modalselect==2))
	{m_ModelEditDlg.ShapeModeledit=ShapeModel13;}
	if((cameraselect==0)&&(modalselect==3))
	{m_ModelEditDlg.ShapeModeledit=ShapeModel14;}
	if((cameraselect==1)&&(modalselect==0))
	{m_ModelEditDlg.ShapeModeledit=ShapeModel21;}
	if((cameraselect==1)&&(modalselect==1))
	{m_ModelEditDlg.ShapeModeledit=ShapeModel22;}
	try
	{
    //m_ModelEditDlg.ShapeModeledit.GetShapeModelContours(1);
	m_ModelEditDlg.EditModel( TRUE );
	m_ModelEditDlg.DoModal();
	}
	catch (HException &except)
	{AfxMessageBox("先学习模板");}

}

void CVisionSetDlg::OnSearchObject()
{
	
	// TODO: Add your control notification handler code here
	HTuple		htRowCheck, htColumnCheck, htAngleCheck, htScore;


	BeginTime();	// 开始测试时间


	{
	

       if((modalselect==0)&&(cameraselect==0))

	   {
			Herror error_num ;
				
			double row,column;

				
				try
					{
						  set_shape_model_param(ShapeModel11,"timeout",8000);
						 Hobject modelroi,roiimage;
						 
					    //if(repeat==1)
						//{gen_rectangle1(&modelroi,visionx-model11halfx-searchrange,0,visionx+model11halfx+searchrange,2592);}
						//else
						{gen_rectangle1(&modelroi,visionx-model11halfx-searchrange,visiony-model11halfy-searchrange,visionx+model11halfx+searchrange,visiony+model11halfy+searchrange);}
			            reduce_domain(Image1,modelroi,&roiimage);
					
				
						
					    //if(repeat==1) 
					//	{
					//	find_shape_model(roiimage,ShapeModel11, -0.1, 0.2, minscore11, 2, 0.5,"least_squares",
						//		0,0.9,&htRowCheck,&htColumnCheck,&htAngleCheck,&htScore);
					//	}
					//	else
						{
                        		find_shape_model(roiimage,ShapeModel11, -0.1, 0.2, minscore11, 1, 0.5,"least_squares",
								0,0.9,&htRowCheck,&htColumnCheck,&htAngleCheck,&htScore);
						}
	                 		
				        disp_obj(Image1,m_Windowvisionid);
						//	disp_obj(modelroi,m_Windowvisionid);
						HTuple	Transformation;
						Hobject m_ShapeModelContoursxld,ContourTrans;
							set_color(m_Windowvisionid,"red");
						set_draw(m_Windowvisionid,"margin");
					//	int i;
						
						//for(i=0;i<(repeat+1);i++)
						{
							if(	htScore[0].D()<minscore11)
				
					{
					
						AfxMessageBox( "查找失败！" );
				
						
					}

						get_shape_model_contours(&m_ShapeModelContoursxld,ShapeModel11,1);
				
						{vector_angle_to_rigid(0,0,0,htRowCheck[0].D(),htColumnCheck[0].D(),htAngleCheck[0].D(),&Transformation);}
						affine_trans_contour_xld(m_ShapeModelContoursxld,&ContourTrans,Transformation);//,"false");
					
						disp_obj(ContourTrans,m_Windowvisionid);
						}
						model11xtemp=htColumnCheck[0].D();
						model11ytemp=htRowCheck[0].D();
						//if(repeat==1)
						//{
						//remodel11xtemp=htColumnCheck[1].D();
						//remodel11ytemp=htRowCheck[1].D();
						//}
						set_color(m_Windowvisionid,"green");
						//	disp_line(m_Windowvisionid,model11ytemp,model11xtemp,model12y,model12x);
						disp_cross(m_Windowvisionid,model11ytemp,model11xtemp,40,0);
						//if(repeat==1)
						//{disp_cross(m_Windowvisionid,remodel11ytemp,remodel11xtemp,40,0);}

						//if(repeat==1)
					//	{
					//	float xtemp,ytemp;

						//if(model11xtemp<remodel11xtemp)
						//{
						//	xtemp=model11xtemp;
						//	ytemp=model11ytemp;
						//	model11xtemp=remodel11xtemp;
						//	model11ytemp=remodel11ytemp;
						//	remodel11xtemp=xtemp;
						//	remodel11ytemp=ytemp;

						//}
					//	}

						disp_obj(modelroi,m_Windowvisionid);
						
						//	disp_cross(m_Windowvisionid,model12y,model12x,40,0);
					}
					catch (HException &except)
					{
						error_num = except.err;;
						AfxMessageBox( "查找失败！" );
						return ;
						
					}
	   }
		
		if((modalselect==1)&&(cameraselect==0))
		{
		    Herror error_num ;
				
			double row,column;

				
				try
					{
					    set_shape_model_param(ShapeModel12,"timeout",8000);
					     Hobject modelroi;
						 Hobject roiimage;
						 //if(repeat==1)
						// {gen_rectangle1(&modelroi,visionx-model12halfx-searchrange,0,visionx+model12halfx+searchrange,2592);}
						 //else
						{gen_rectangle1(&modelroi,visionx-model12halfx-searchrange,visiony-model12halfy-searchrange,visionx+model12halfx+searchrange,visiony+model12halfy+searchrange);}

		       	        
			            reduce_domain(Image1,modelroi,&roiimage);
						//if(repeat==1)
						//{
         	
						//find_shape_model(roiimage,ShapeModel12,-0.1, 0.2, minscore11, 2, 0.5,"least_squares",
						//		0,0.9,&htRowCheck,&htColumnCheck,&htAngleCheck,&htScore);
						//}
						//else
						{
         	
						find_shape_model(roiimage,ShapeModel12,-0.1, 0.2, minscore11, 1, 0.5,"least_squares",
								0,0.9,&htRowCheck,&htColumnCheck,&htAngleCheck,&htScore);
						}
			
				
			
			
				disp_obj(Image1,m_Windowvisionid);;
				HTuple	Transformation;
				Hobject m_ShapeModelContoursxld,ContourTrans;
								

                    set_color(m_Windowvisionid,"red");
				set_draw(m_Windowvisionid,"margin");
				//int i;
					//for(i=0;i<(repeat+1);i++)
					
					{
							if(	htScore[0].D()<minscore11)
				
							{
					
						   AfxMessageBox( "查找失败！" );
				
						
							}

						get_shape_model_contours(&m_ShapeModelContoursxld,ShapeModel12,1);
				
						{vector_angle_to_rigid(0,0,0,htRowCheck[0].D(),htColumnCheck[0].D(),htAngleCheck[0].D(),&Transformation);}
						affine_trans_contour_xld(m_ShapeModelContoursxld,&ContourTrans,Transformation);//,"false");
					
						disp_obj(ContourTrans,m_Windowvisionid);
					}
				

			
					
				 model12xtemp=htColumnCheck[0].D();
				model12ytemp=htRowCheck[0].D();
				//if(repeat==1)
				//{
				//remodel12xtemp=htColumnCheck[1].D();
				//remodel12ytemp=htRowCheck[1].D();

						/*float xtemp,ytemp;
						if(model12xtemp<remodel12xtemp)
						{
							xtemp=model12xtemp;
							ytemp=model12ytemp;
							model12xtemp=remodel12xtemp;
							model12ytemp=remodel12ytemp;
							remodel12xtemp=xtemp;
							remodel12ytemp=ytemp;

						}*/
				//}
				 set_color(m_Windowvisionid,"green");
				//disp_line(m_Windowvisionid,model11y,model11x,model12ytemp,model12xtemp);
				 disp_obj(modelroi,m_Windowvisionid);
				disp_cross(m_Windowvisionid,model12ytemp,model12xtemp,40,0);
				//if(repeat==1)
				//{disp_cross(m_Windowvisionid,remodel12ytemp,remodel12xtemp,40,0);}
				//disp_cross(m_Windowvisionid,model11y,model11x,40,0);
				
				}
					catch (HException &except)
					{
						error_num = except.err;;
						AfxMessageBox( "查找失败！" );
						return ;
						
					}

		}

		if((modalselect==2)&&(cameraselect==0))

	   {
			Herror error_num ;
				
			double row,column;

				
				try
					{
						  set_shape_model_param(ShapeModel13,"timeout",8000);
						 Hobject modelroi,roiimage;
						 
					    //if(repeat==1)
					//	{gen_rectangle1(&modelroi,visionx-model11halfx-searchrange,0,visionx+model11halfx+searchrange,2592);}
						//else
						{gen_rectangle1(&modelroi,visionx-model13halfx-searchrange,visiony-model13halfy-searchrange,visionx+model13halfx+searchrange,visiony+model11halfy+searchrange);}
			            reduce_domain(Image1,modelroi,&roiimage);
					
				
						
					    //if(repeat==1) 
						//{
						//find_shape_model(roiimage,ShapeModel11, -0.1, 0.2, minscore11, 2, 0.5,"least_squares",
						//		0,0.9,&htRowCheck,&htColumnCheck,&htAngleCheck,&htScore);
						//}
						//else
						{
                        		find_shape_model(roiimage,ShapeModel13, -0.1, 0.2, minscore11, 1, 0.5,"least_squares",
								0,0.9,&htRowCheck,&htColumnCheck,&htAngleCheck,&htScore);
						}
	                 		
				        disp_obj(Image1,m_Windowvisionid);
						//	disp_obj(modelroi,m_Windowvisionid);
						HTuple	Transformation;
						Hobject m_ShapeModelContoursxld,ContourTrans;
							set_color(m_Windowvisionid,"red");
						set_draw(m_Windowvisionid,"margin");
						int i;
						
						//for(i=0;i<(repeat+1);i++)
						{
							if(	htScore[0].D()<minscore11)
				
					{
					
						AfxMessageBox( "查找失败！" );
				
						
					}

						get_shape_model_contours(&m_ShapeModelContoursxld,ShapeModel13,1);
				
						{vector_angle_to_rigid(0,0,0,htRowCheck[0].D(),htColumnCheck[0].D(),htAngleCheck[0].D(),&Transformation);}
						affine_trans_contour_xld(m_ShapeModelContoursxld,&ContourTrans,Transformation);//,"false");
					
						disp_obj(ContourTrans,m_Windowvisionid);
						}
						remodel11xtemp=htColumnCheck[0].D();
						remodel11ytemp=htRowCheck[0].D();
						//if(repeat==1)
						//{
						//remodel11xtemp=htColumnCheck[1].D();
						//remodel11ytemp=htRowCheck[1].D();
						//}
						set_color(m_Windowvisionid,"green");
						//	disp_line(m_Windowvisionid,model11ytemp,model11xtemp,model12y,model12x);
						disp_cross(m_Windowvisionid,remodel11ytemp,remodel11xtemp,40,0);
						//if(repeat==1)
						//{disp_cross(m_Windowvisionid,remodel11ytemp,remodel11xtemp,40,0);}

						//if(repeat==1)
						//{
						//float xtemp,ytemp;

						//if(model11xtemp<remodel11xtemp)
						//{
						//	xtemp=model11xtemp;
						//	ytemp=model11ytemp;
						//	model11xtemp=remodel11xtemp;
						//	model11ytemp=remodel11ytemp;
						//	remodel11xtemp=xtemp;
						//	remodel11ytemp=ytemp;

						//}
						//}

						disp_obj(modelroi,m_Windowvisionid);
						
						//	disp_cross(m_Windowvisionid,model12y,model12x,40,0);
					}
					catch (HException &except)
					{
						error_num = except.err;;
						AfxMessageBox( "查找失败！" );
						return ;
						
					}
	   }
		
		if((modalselect==3)&&(cameraselect==0))
		{
		    Herror error_num ;
				
			double row,column;

				
				try
					{
					    set_shape_model_param(ShapeModel14,"timeout",8000);
					     Hobject modelroi;
						 Hobject roiimage;
						 //if(repeat==1)
						 //{gen_rectangle1(&modelroi,visionx-model12halfx-searchrange,0,visionx+model12halfx+searchrange,2592);}
						 //else
						{gen_rectangle1(&modelroi,visionx-model14halfx-searchrange,visiony-model14halfy-searchrange,visionx+model14halfx+searchrange,visiony+model14halfy+searchrange);}

		       	        
			            reduce_domain(Image1,modelroi,&roiimage);
						//if(repeat==1)
						//{
         	
						//find_shape_model(roiimage,ShapeModel12,-0.1, 0.2, minscore11, 2, 0.5,"least_squares",
						//		0,0.9,&htRowCheck,&htColumnCheck,&htAngleCheck,&htScore);
						//}
						//else
						{
         	
						find_shape_model(roiimage,ShapeModel14,-0.1, 0.2, minscore11, 1, 0.5,"least_squares",
								0,0.9,&htRowCheck,&htColumnCheck,&htAngleCheck,&htScore);
						}
			
				
			
			
				disp_obj(Image1,m_Windowvisionid);;
				HTuple	Transformation;
				Hobject m_ShapeModelContoursxld,ContourTrans;
								

                    set_color(m_Windowvisionid,"red");
				set_draw(m_Windowvisionid,"margin");
				//int i;
					//for(i=0;i<(repeat+1);i++)
					
					{
							if(	htScore[0].D()<minscore11)
				
							{
					
						   AfxMessageBox( "查找失败！" );
				
						
							}

						get_shape_model_contours(&m_ShapeModelContoursxld,ShapeModel14,1);
				
						{vector_angle_to_rigid(0,0,0,htRowCheck[0].D(),htColumnCheck[0].D(),htAngleCheck[0].D(),&Transformation);}
						affine_trans_contour_xld(m_ShapeModelContoursxld,&ContourTrans,Transformation);//,"false");
					
						disp_obj(ContourTrans,m_Windowvisionid);
					}
				

			
					
				 remodel12xtemp=htColumnCheck[0].D();
				remodel12ytemp=htRowCheck[0].D();
				//if(repeat==1)
				//{
			//	remodel12xtemp=htColumnCheck[1].D();
			//	remodel12ytemp=htRowCheck[1].D();

				//		float xtemp,ytemp;
				//		if(model12xtemp<remodel12xtemp)
				//		{
				//			xtemp=model12xtemp;
				//			ytemp=model12ytemp;
				//			model12xtemp=remodel12xtemp;
				//			model12ytemp=remodel12ytemp;
				//			remodel12xtemp=xtemp;
				//			remodel12ytemp=ytemp;

				//		}
				//}
				 set_color(m_Windowvisionid,"green");
				//disp_line(m_Windowvisionid,model11y,model11x,model12ytemp,model12xtemp);
				 disp_obj(modelroi,m_Windowvisionid);
				disp_cross(m_Windowvisionid,remodel12ytemp,remodel12xtemp,40,0);
				//if(repeat==1)
				//{disp_cross(m_Windowvisionid,remodel12ytemp,remodel12xtemp,40,0);}
				//disp_cross(m_Windowvisionid,model11y,model11x,40,0);
				
				}
					catch (HException &except)
					{
						error_num = except.err;;
						AfxMessageBox( "查找失败！" );
						return ;
						
					}

		}
	   
	   if((modalselect==0)&&(cameraselect==1))

	   {
				Herror error_num ;
				
			double row,column;

				
				try
					{
					   set_shape_model_param( ShapeModel21,"timeout",3000);
					   	 Hobject modelroi;
						 Hobject roiimage;
						 if(repeat==1)
						 {gen_rectangle1(&modelroi,visionx-model21halfx-searchrange2,0,visionx+model21halfx+searchrange2,2592);}
						 else
						{gen_rectangle1(&modelroi,visionx-model21halfx-searchrange2,visiony-model21halfy-searchrange2,visionx+model21halfx+searchrange2,visiony+model21halfy+searchrange2);}


		       	         
			            reduce_domain(Image2,modelroi,&roiimage);
					 
				
         	            if(repeat==1)
						{
						find_shape_model(roiimage, ShapeModel21,0, 0, minscore21, 2, 0.5,"least_squares",
								0,0.9,&htRowCheck,&htColumnCheck,&htAngleCheck,&htScore);
						}
						else
						{
						find_shape_model(roiimage, ShapeModel21,0, 0, minscore21, 1, 0.5,"least_squares",
								0,0.9,&htRowCheck,&htColumnCheck,&htAngleCheck,&htScore);
						}
	                   
						
				disp_obj(Image2,m_Windowvisionid);
				HTuple	Transformation;
			Hobject m_ShapeModelContoursxld,ContourTrans;
			
			          set_color(m_Windowvisionid,"red");
				set_draw(m_Windowvisionid,"margin");
				int i;
					for(i=0;i<repeat+1;i++)
					
					{
							if(	htScore[i].D()<minscore21)
				
							{
					
						   AfxMessageBox( "查找失败！" );
				
						
							}

						get_shape_model_contours(&m_ShapeModelContoursxld,ShapeModel21,1);
				
						{vector_angle_to_rigid(0,0,0,htRowCheck[i].D(),htColumnCheck[i].D(),htAngleCheck[i].D(),&Transformation);}
						affine_trans_contour_xld(m_ShapeModelContoursxld,&ContourTrans,Transformation);//,"false");
					
						disp_obj(ContourTrans,m_Windowvisionid);
					}
				 model21xtemp=htColumnCheck[0].D();
				model21ytemp=htRowCheck[0].D();
				if(repeat==1)
				{
				remodel21xtemp=htColumnCheck[1].D();
				remodel21ytemp=htRowCheck[1].D();

						float xtemp,ytemp;
						if(model21xtemp>remodel21xtemp)
						{
							xtemp=model21xtemp;
							ytemp=model21ytemp;
							model21xtemp=remodel21xtemp;
							model21ytemp=remodel21ytemp;
							remodel21xtemp=xtemp;
							remodel21ytemp=ytemp;

						}
				}
				set_color(m_Windowvisionid,"green");
				//disp_line(m_Windowvisionid,model21ytemp,model21xtemp,model22y,model22x);
				disp_cross(m_Windowvisionid,model21ytemp,model21xtemp,40,0);
				
                if(repeat==1)
				{	disp_cross(m_Windowvisionid,remodel21ytemp,remodel21xtemp,40,0);}
				//disp_cross(m_Windowvisionid,model22y,model22x,40,0);
				set_color(m_Windowvisionid,"red");

		     	disp_cross(m_Windowvisionid,keypasteytemp,keypastextemp,80,0);
			  }
					catch (HException &except)
					{
						error_num = except.err;;
						AfxMessageBox( "查找失败！" );
						return ;
						
					}
				
		}
		
		if((modalselect==1)&&(cameraselect==1))
		{
		    Herror error_num ;
				
			double row,column;

				
				try
					{
					    set_shape_model_param(ShapeModel22,"timeout",3000);
							 Hobject modelroi;
						 Hobject roiimage;
						 if(repeat==1)
						 {
						 	 gen_rectangle1(&modelroi,visionx-model22halfx-searchrange2,0,visionx+model22halfx+searchrange2,2592);
						 }
					     else
						{gen_rectangle1(&modelroi,visionx-model22halfx-searchrange2,visiony-model22halfy-searchrange2,visionx+model22halfx+searchrange2,visiony+model22halfy+searchrange2);}


		       	        
			            reduce_domain(Image2,modelroi,&roiimage);
					 
				

         	           if(repeat==1)
					   {

						find_shape_model(roiimage,ShapeModel22 ,-0.2, 0.4, minscore21, 2, 0.5,"least_squares",
								0,0.9,&htRowCheck,&htColumnCheck,&htAngleCheck,&htScore);
					   }
					   else
						      {

						find_shape_model(roiimage,ShapeModel22 ,-0.2, 0.4, minscore21, 1, 0.5,"least_squares",
								0,0.9,&htRowCheck,&htColumnCheck,&htAngleCheck,&htScore);
					   }

	                   
			
				
		
			
				disp_obj(Image2,m_Windowvisionid);
				HTuple	Transformation;
			    Hobject m_ShapeModelContoursxld,ContourTrans;

		          set_color(m_Windowvisionid,"red");
				set_draw(m_Windowvisionid,"margin");
				int i;
					for(i=0;i<repeat+1;i++)
					
					{
							if(	htScore[i].D()<minscore21)
				
							{
					
						   AfxMessageBox( "查找失败！" );
				
						
							}

						get_shape_model_contours(&m_ShapeModelContoursxld,ShapeModel22,1);
				
						{vector_angle_to_rigid(0,0,0,htRowCheck[i].D(),htColumnCheck[i].D(),htAngleCheck[i].D(),&Transformation);}
						affine_trans_contour_xld(m_ShapeModelContoursxld,&ContourTrans,Transformation);//,"false");
					
						disp_obj(ContourTrans,m_Windowvisionid);
					}
				 model22xtemp=htColumnCheck[0].D();
				model22ytemp=htRowCheck[0].D();
				if(repeat==1)
				{
				remodel22xtemp=htColumnCheck[1].D();
				remodel22ytemp=htRowCheck[1].D();

						float xtemp,ytemp;
						if(model22xtemp>remodel22xtemp)
						{
							xtemp=model22xtemp;
							ytemp=model22ytemp;
							model22xtemp=remodel22xtemp;
							model22ytemp=remodel22ytemp;
							remodel22xtemp=xtemp;
							remodel22ytemp=ytemp;

						}
				}
			
				 set_color(m_Windowvisionid,"green");
				disp_line(m_Windowvisionid,model21y,model21x,model22ytemp,model22xtemp);
				disp_cross(m_Windowvisionid,model22ytemp,model22xtemp,40,0);
				if(repeat==1)
				{disp_cross(m_Windowvisionid,remodel22ytemp,remodel22xtemp,40,0);}
				disp_cross(m_Windowvisionid,model21y,model21x,40,0);
				set_color(m_Windowvisionid,"red");

		     	disp_cross(m_Windowvisionid,keypasteytemp,keypastextemp,80,0);
				}
					catch (HException &except)
					{
						error_num = except.err;
						AfxMessageBox( "查找失败！" );
						return ;
						
					}
		}      
	
      



	}  

  EndTime();		// 结束测试时间

    m_list1.DeleteAllItems();
    if(cameraselect==0)
	{
        if( htScore[0].D() >0 ) 
		{
			char s[100];
			int i, item;
			for( i = 0; i < 1; i ++ ) 
			{
				item = m_list1.InsertItem( i, "" );
				sprintf( s, "%d", i + 1 );
				m_list1.SetItemText( item, 0, s );
				sprintf( s, "%0.3f", htScore[i].D() );
				m_list1.SetItemText( item, 1, s );
				sprintf( s, "%f", htAngleCheck[i].D() );
				m_list1.SetItemText( item, 2, s );
			//	sprintf( s, "%0.2f", pMatchArray[i].Scale );
			//	m_list1.SetItemText( item, 3, s );
				sprintf( s, "%0.2f", htRowCheck[i].D() );
				m_list1.SetItemText( item, 3, s );
				sprintf( s, "%0.2f",htColumnCheck[i].D());
				m_list1.SetItemText( item, 4, s );
			}
		} 
	}
	else
	{
	if( htScore[0].D() >0 ) 
	{
		char s[100];
		int i, item;
		for( i = 0; i < repeat+1; i ++ ) 
		{
			item = m_list1.InsertItem( i, "" );
			sprintf( s, "%d", i + 1 );
			m_list1.SetItemText( item, 0, s );
			sprintf( s, "%0.3f", htScore[i].D() );
			m_list1.SetItemText( item, 1, s );
			sprintf( s, "%f", htAngleCheck[i].D() );
			m_list1.SetItemText( item, 2, s );
		//	sprintf( s, "%0.2f", pMatchArray[i].Scale );
		//	m_list1.SetItemText( item, 3, s );
			sprintf( s, "%0.2f", htRowCheck[i].D() );
			m_list1.SetItemText( item, 3, s );
			sprintf( s, "%0.2f",htColumnCheck[i].D());
			m_list1.SetItemText( item, 4, s );
		}
	} 
    }
	Invalidate( FALSE );

		
	
}

void CVisionSetDlg::OnDrawRect() 
{
	// TODO: Add your control notification handler code here

	Invalidate( FALSE );    //显示位置
}



void CVisionSetDlg::OnSaveModel() 
{

	// TODO: Add your control notification handler code here
		  int nRes = AfxMessageBox("YES仅修改形状，NO还修改位置",MB_YESNO|MB_ICONQUESTION);
	           
	OnSearchObject();

	if((modalselect==0)&&(cameraselect==0))
	{
     if(model11xtemp!=0)
	 {
		   if(nRes == IDNO)
			{
				model11x=model11xtemp;
				 model11y=model11ytemp;
				 	//remodel11x=remodel11xtemp;
				 //remodel11y=remodel11ytemp;
		   }
	 }
	
	CFileDialog fd( FALSE, "shm",currentmodelname, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"*.shm");
	fd.m_ofn.lpstrTitle = "保存模板文件";
//	if( fd.DoModal() == IDOK ) 
	{
		//if( m_ModelEditDlg.model11 ) 
		
		//	currentmodelname=fd.GetPathName();
			CString writepathname=fd.GetPathName();
			//HTuple nametemp;
			//nametemp=writepathname;
			Herror error_num;
	        
			try
			{ write_shape_model(ShapeModel11,(HTuple)writepathname);}
		    catch (HException &except)
			 {
				error_num = except.err;
				AfxMessageBox("保存模板失败！");
				return;
			}
		
	}
   
	
	}
	if((modalselect==1)&&(cameraselect==0))
	{
		if(model12xtemp!=0)
	 {
			if(nRes == IDNO)
			{
				model12x=model12xtemp;
				model12y=model12ytemp;
				//remodel12x=remodel12xtemp;
				//remodel12y=remodel12ytemp;
			}
	 }
	CFileDialog fd( FALSE, "shm",currentmodelname2, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"*.shm");
	fd.m_ofn.lpstrTitle = "保存模板文件";
	//if( fd.DoModal() == IDOK ) 
	{
		//if( m_ModelEditDlg.model11 ) 
		
		//	currentmodelname=fd.GetPathName();
			CString writepathname=fd.GetPathName();
			Herror error_num;
	        
			try
			{ write_shape_model(ShapeModel12,(HTuple)writepathname);}
		    catch (HException &except)
			 {
				error_num = except.err;
				AfxMessageBox("保存模板失败！");
				return;
			}
		
	}

	}


	if((modalselect==2)&&(cameraselect==0))
	{
     if(remodel11xtemp!=0)
	 {
		   if(nRes == IDNO)
			{
				//model11x=model11xtemp;
				 //model11y=model11ytemp;
				 	remodel11x=remodel11xtemp;
				 remodel11y=remodel11ytemp;
		   }
	 }
	
	CFileDialog fd( FALSE, "shm",currentmodelname3, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"*.shm");
	fd.m_ofn.lpstrTitle = "保存模板文件";
//	if( fd.DoModal() == IDOK ) 
	{
		//if( m_ModelEditDlg.model11 ) 
		
		//	currentmodelname=fd.GetPathName();
			CString writepathname=fd.GetPathName();
			//HTuple nametemp;
			//nametemp=writepathname;
			Herror error_num;
	        
			try
			{ write_shape_model(ShapeModel13,(HTuple)writepathname);}
		    catch (HException &except)
			 {
				error_num = except.err;
				AfxMessageBox("保存模板失败！");
				return;
			}
		
	}

	
	}
	if((modalselect==3)&&(cameraselect==0))
	{
		if(remodel12xtemp!=0)
	 {
			if(nRes == IDNO)
			{
				//model12x=model12xtemp;
				//model12y=model12ytemp;
				remodel12x=remodel12xtemp;
				remodel12y=remodel12ytemp;
			}
	 }
	CFileDialog fd( FALSE, "shm",currentmodelname4, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"*.shm");
	fd.m_ofn.lpstrTitle = "保存模板文件";
	//if( fd.DoModal() == IDOK ) 
	{
		//if( m_ModelEditDlg.model11 ) 
		
		//	currentmodelname=fd.GetPathName();
			CString writepathname=fd.GetPathName();
			Herror error_num;
	        
			try
			{ write_shape_model(ShapeModel14,(HTuple)writepathname);}
		    catch (HException &except)
			 {
				error_num = except.err;
				AfxMessageBox("保存模板失败！");
				return;
			}
		
	}

	}

	if((modalselect==0)&&(cameraselect==1))
	{
		if(model21xtemp!=0)
	 {
				   if(nRes == IDNO)
			{
		 model21x=model21xtemp;
		 model21y=model21ytemp;
		 remodel21x=remodel21xtemp;
		 remodel21y=remodel21ytemp;
				   }
	 }
		CFileDialog fd( FALSE, "shm",currentmodelname21, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"*.shm");
	fd.m_ofn.lpstrTitle = "保存模板文件";
	//if( fd.DoModal() == IDOK ) 
	{
		//if( m_ModelEditDlg.model11 ) 
		
		//	currentmodelname=fd.GetPathName();
			CString writepathname=fd.GetPathName();
			Herror error_num;
	        
			try
			{ write_shape_model(ShapeModel21,(HTuple)writepathname);}
		    catch (HException &except)
			 {
				error_num = except.err;
				AfxMessageBox("保存模板失败！");
				return;
			}
		
	}
	}
    

	if((modalselect==1)&&(cameraselect==1))
	{
	if(model22xtemp!=0)
	 {
		if(nRes == IDNO)
		 {
		 model22x=model22xtemp;
		 model22y=model22ytemp;
		 remodel22x=remodel22xtemp;
		 remodel22y=remodel22ytemp;
		 }
	 }
		CFileDialog fd( FALSE, "shm",currentmodelname22, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"*.shm");
	fd.m_ofn.lpstrTitle = "保存模板文件";
//	if( fd.DoModal() == IDOK ) 
	{
		//if( m_ModelEditDlg.model11 ) 
		
		//	currentmodelname=fd.GetPathName();
			CString writepathname=fd.GetPathName();
			Herror error_num;
	        
			try
			{ write_shape_model(ShapeModel22,(HTuple)writepathname);}
		    catch (HException &except)
			 {
				error_num = except.err;
				AfxMessageBox("保存模板失败！");
				return;
			}
		
	}
	}
	
   //AfxMessageBox("确认用当前料片学习另一模版！");

}





BOOL CVisionSetDlg::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
//	ReleaseDevice();
	// KillTimer(1);

	DeleteObject(vfixcolor);
	DeleteObject(vwhitecolor);

	close_window(m_Windowvisionid);


	InitDeviceFunction();



    visionphoto=false;

	m_bStartCapture=FALSE;
	

	CFile currentphotonew;
	currentphotonew.Open(currentphotoname,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
    CArchive currentphotoarnew(&currentphotonew,CArchive::store);
		
		 
    currentphotoarnew<<shutter<<bright<<gain<<shutter2<<shutter3<<shutter4<<shutter5<<gain2<<contrast1<<contrast2<<model11x<<model11y<<model12x<<model12y<<model21x<<model21y<<model22x<<model22y
			 <<model11halfx<<model11halfy<<model12halfx<<model12halfy<<model13halfx<<model13halfy<<model14halfx<<model14halfy<<model21halfx<<model21halfy<<model22halfx<<model22halfy<<modalorg11<<modalorg12<<modalorg13<<modalorg14<<modalorg21<<modalorg22
			 <<remodel11x<<remodel11y<<remodel12x<<remodel12y<<remodel21x<<remodel21y<<remodel22x<<remodel22y;
	
    currentphotoarnew.Close();
    currentphotonew.Close();

	return CDialog::DestroyWindow();

   


}









	


void CVisionSetDlg::OnChangeEditBright() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	UpdateData(true);

}





void CVisionSetDlg::OnOk() 
{
	// TODO: Add your control notification handler code here
		CDialog::OnOK();

	
}

void CVisionSetDlg::Onsoftkey3() 
{
		HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{
		::SendMessage(h,WM_CLOSE,0,0);
		SetDlgItemText(IDC_softkey3,"开键盘");
	}
	else
	{
		WinExec("c:\\windows\\system32\\osk.exe",SW_SHOWNORMAL);
		SetDlgItemText(IDC_softkey3,"关键盘");
	}
	
}

void CVisionSetDlg::OnChangeDigitalShift() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
		UpdateData(true);
//	SetFeature(m_hDevice,DIGITAL_SHIFT , m_digitalshift, m_digitalshift);
	
}









void CVisionSetDlg::OnSetfocuskeypastex() 
{
	// TODO: Add your control notification handler code here
		CWnd * cwnd=GetDlgItem(IDC_keypastex);
	  HWND handle;
	  handle=cwnd->GetSafeHwnd();
	  RECT r;
	  ::GetWindowRect(handle,&r);
	  HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	WinExec("c:\\windows\\system32\\osk.exe",SW_SHOWNORMAL);
    h=::FindWindow(NULL,"屏幕键盘");
	::MoveWindow(h,0,r.bottom,1024,400,true);
	GetDlgItem(IDC_keypastex)->PostMessage(EM_SETSEL,0,-1);
	
}

void CVisionSetDlg::OnKillfocuskeypastex() 
{
	// TODO: Add your control notification handler code here
	 HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	UpdateData(true);
	
	keypastextemp=m_keypastex;
		CFile currentpara;
					currentpara.Open(currentparametername,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

					CArchive currentparaar(&currentpara,CArchive::store);
					currentparaar<<PARAINPUT;
    
					currentparaar.Close();
					currentpara.Close();
	
}

void CVisionSetDlg::OnSetfocuskeypastey() 
{
	// TODO: Add your control notification handler code here
		CWnd * cwnd=GetDlgItem(IDC_keypastey);
	  HWND handle;
	  handle=cwnd->GetSafeHwnd();
	  RECT r;
	  ::GetWindowRect(handle,&r);
	  HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	WinExec("c:\\windows\\system32\\osk.exe",SW_SHOWNORMAL);
    h=::FindWindow(NULL,"屏幕键盘");
	::MoveWindow(h,0,r.bottom,1024,400,true);
	GetDlgItem(IDC_keypastey)->PostMessage(EM_SETSEL,0,-1);
	
}

void CVisionSetDlg::OnKillfocuskeypastey() 
{
	// TODO: Add your control notification handler code here
		 HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	UpdateData(true);
	
	keypasteytemp=m_keypastey;
		CFile currentpara;
					currentpara.Open(currentparametername,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

					CArchive currentparaar(&currentpara,CArchive::store);
					currentparaar<<PARAINPUT;
    
					currentparaar.Close();
					currentpara.Close();
	
	
}











void CVisionSetDlg::OnEditGain() 
{
	// TODO: Add your control notification handler code here
	inputshow(IDC_EDIT_GAIN);
	CRect rect;
	GetDlgItem(IDC_EDIT_GAIN)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_EDIT_GAIN,inlong ,m_gain, 8, 1, pos, &outf);
	m_gain = outf;
	UpdateData(false);
	inputshow(IDC_EDIT_GAIN);

	if(cameraselect==0)
	{
		gain=m_gain;
     CameraSetAnalogGain(camera1,gain);
	}
	if(cameraselect==1)
	{
		gain2=m_gain;
       CameraSetAnalogGain(camera2,gain2);
	
	}
    UpdateWindow();

}




void CVisionSetDlg::OnEditShutter() 
{
	// TODO: Add your control notification handler code here
	inputshow(IDC_EDIT_SHUTTER);
	CRect rect;
	GetDlgItem(IDC_EDIT_SHUTTER)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_EDIT_SHUTTER,inlong ,m_shutter, 200, 0, pos, &outf);
	m_shutter = outf;
	UpdateData(false);
	inputshow(IDC_EDIT_SHUTTER);

	if(cameraselect==0)
	{
		shutter=m_shutter;
     CameraSetAeState(camera1,false);
        CameraSetExposureTime(camera1, shutter*10000);
	}
	if(cameraselect==1)
	{
		shutter3=m_shutter;
       CameraSetAeState(camera2, false);
        CameraSetExposureTime(camera2, shutter3*10000);
	
	}
	UpdateWindow();
}




void CVisionSetDlg::OnEDITcontrast() 
{
	// TODO: Add your control notification handler code here
	inputshow(IDC_EDIT_contrast);
	CRect rect;
	GetDlgItem(IDC_EDIT_contrast)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_EDIT_contrast,inlong ,m_contrast, 200, 0, pos, &outf);
	m_contrast = outf;
	UpdateData(false);
	inputshow(IDC_EDIT_contrast);

	if(cameraselect==0)
	{
		contrast1=m_contrast;
        CameraSetContrast(camera1, contrast1);
	}
	if(cameraselect==1)
	{
		contrast2=m_contrast;
	    CameraSetContrast(camera2, contrast2);
	}
	UpdateWindow();
	
}

HBRUSH CVisionSetDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if ((nCtlColor==CTLCOLOR_STATIC)&&(pWnd-> GetDlgCtrlID()==IDnumv))
	{
		pDC->SetBkMode(TRANSPARENT);
		//HBRUSH B = CreateSolidBrush(RGB(3, 168, 158));
		//return (HBRUSH)B;
		DeleteObject(vfixcolor);
		vfixcolor=CreateSolidBrush(RGB(3, 168, 158));
		return (HBRUSH)vfixcolor;
	}
	if ((nCtlColor==CTLCOLOR_STATIC)&&(pWnd-> GetDlgCtrlID()!=IDC_STATIC)&&(pWnd-> GetDlgCtrlID()!=IDnumv))//&&(pWnd-> GetDlgCtrlID()!=IDC_TIMER)
	{
		pDC->SetBkMode(TRANSPARENT);
		//HBRUSH B = CreateSolidBrush(RGB(255, 255, 255));
		//return (HBRUSH)B;
		DeleteObject(vwhitecolor);
		vwhitecolor=CreateSolidBrush(RGB(255, 255, 255));
		return (HBRUSH)vwhitecolor;
	}
	// TODO: Return a different brush if the default is not desired
	return hbr;
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CVisionSetDlg::inputshow(UINT nID)
{
    CRect rect;
	GetDlgItem(nID)->GetWindowRect(&rect);
	ScreenToClient(&rect);
	InvalidateRect(rect);
	
}

bool CVisionSetDlg::GoSmallKey(int ctlID,intype intype, float invaluef , float Vlumax, float Vlumin,POINT point, float* outvaluef)
{

    IDnumv=ctlID;
	CSmallKey* smallkey;
	smallkey= new CSmallKey;
	smallkey->m_intype=intype;
	smallkey->ctlposL = point;
	smallkey->m_maximum = Vlumax;
	smallkey->m_minimum = Vlumin;
	
		smallkey->m_inputfloat = invaluef;
	
	//dlgkey->m_input = paravalue;
	smallkey->DoModal();
	
		*outvaluef = smallkey->m_inputfloat;
	//redraw=false;
		IDnumv=0;
	return true;
}