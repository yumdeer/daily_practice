// ModelEditDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ModelEditDlg.h"
#include "externs.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CModelEditDlg dialog


CModelEditDlg::CModelEditDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CModelEditDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CModelEditDlg)
	m_contrast = 0;
	m_contrastin = 0;
	//}}AFX_DATA_INIT
    

	model11=0;
	model12=0;
	model21=0;
	model22=0;
	model31=0;
	model32=0;
	model41=0;
	model42=0;

	m_EditModel		= FALSE;
	m_PenWidth		= 10;
	m_PointState	= 0;



}


void CModelEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CModelEditDlg)
	DDX_Control(pDX, IDC_SLIDERcontrast, m_contrastctr);
	DDX_Slider(pDX, IDC_SLIDERcontrast, m_contrast);
	DDX_Text(pDX, IDC_EDIT1contrast, m_contrastin);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CModelEditDlg, CDialog)
	//{{AFX_MSG_MAP(CModelEditDlg)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_ADD_EDGE, OnAddEdge)
	ON_BN_CLICKED(IDC_DEL_EDGE, OnDelEdge)
	ON_BN_CLICKED(IDC_softkey4, Onsoftkey4)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
		ON_BN_CLICKED(IDC_up1, Onup1)
	ON_BN_CLICKED(IDC_center, Oncenter)
	ON_BN_CLICKED(IDC_rightup2, Onrightup2)
	ON_BN_CLICKED(IDC_right3, Onright3)
	ON_BN_CLICKED(IDC_rightdown4, Onrightdown4)
	ON_BN_CLICKED(IDC_down5, Ondown5)
	ON_BN_CLICKED(IDC_leftdown6, Onleftdown6)
	ON_BN_CLICKED(IDC_left7, Onleft7)
		ON_BN_CLICKED(IDC_leftup8, Onleftup8)
	//}}AFX_MSG_MAP
	//ON_BN_CLICKED(IDOK, &CModelEditDlg::OnBnClickedOk)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDERcontrast, &CModelEditDlg::OnNMCustomdrawSlidercontrast)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CModelEditDlg message handlers

void CModelEditDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		//dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
						

}

BOOL CModelEditDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//GetDlgItem( IDC_STATIC_img )->GetWindowRect( &m_ViewRect );
	//ScreenToClient(&m_ViewRect );
	m_contrastctr.SetRange(1,255,true);

	CheckDlgButton( IDC_ADD_EDGE, m_PointState );
	CheckDlgButton( IDC_DEL_EDGE, !m_PointState );


	
	
	SetDlgItemInt( IDC_EDIT8, m_PenWidth );
	
	SetDlgItemInt(IDC_modalxorg,0);
	SetDlgItemInt(IDC_modalyorg,0);
	ShowWindow(SW_SHOWMAXIMIZED);
	messageout=false;


	EnableAll();

	
	HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{
		::SendMessage(h,WM_CLOSE,0,0);
		SetDlgItemText(IDC_softkey4,"开键盘");
	}

    Hlong m_WindowRow, m_WindowColumn, m_WindowWidth, m_WindowHeight;
			
	set_window_attr("border_width",HTuple(0));
	set_window_attr("window_title",HTuple("Camera0"));
	set_check("~father");
//	SetSystem("int_zooming","false");

	gen_empty_region(&modelrect);

	CRect rtWindow;	
	HWND hWnd = GetDlgItem(IDC_STATIC_img)->m_hWnd;
	Hlong lWWindowID = (Hlong)hWnd;
	
	GetDlgItem(IDC_STATIC_img)->EnableWindow(true);//ModifyStyle(0,SS_NOTIFY); 

	GetDlgItem(IDC_STATIC_img)->GetClientRect(&rtWindow);
	m_WindowRow = rtWindow.top;
	m_WindowColumn = rtWindow.left;
	m_WindowWidth = rtWindow.Width();
	m_WindowHeight = rtWindow.Height();

   open_window(m_WindowRow,m_WindowColumn,m_WindowWidth,m_WindowHeight,
				lWWindowID,"visible","",&m_Windoweditid);
	//set_part(m_Windoweditid,0,0,camera1width,camera1height);
   //	if(cameraselect==0)
	{
		set_part(m_Windoweditid,0,0,camera1width,camera1height);
		
	}
/*	if(cameraselect==1)
	{
		set_part(m_Windoweditid,0,0,camera2width,camera2height);
		
	}*/
		if(cameraselect==0)
	{
	   if(modalselect==0)
	   {
		   m_modalorg=modalorg11;
		  
	   }
	   if(modalselect==1)
	   {
		   m_modalorg=modalorg12;
	
	   }
	   if(modalselect==2)
	   {m_modalorg=modalorg21;}
	   if(modalselect==3)
	   {m_modalorg=modalorg22;}
	   
	}
	//if(cameraselect==1)
	//{
	//   if(modalselect==0)
	//   {m_modalorg=modalorg21;}
	//   if(modalselect==1)
	//   {m_modalorg=modalorg22;}
	//   
	//}
	    CheckDlgButton( IDC_center, 0 );
	CheckDlgButton( IDC_up1, 0 );
	CheckDlgButton( IDC_rightup2, 0 );
	CheckDlgButton( IDC_right3, 0 );
	CheckDlgButton( IDC_rightdown4, 0 );
	CheckDlgButton( IDC_down5, 0 );
	CheckDlgButton( IDC_leftdown6, 0 );
	CheckDlgButton( IDC_left7, 0 );
	CheckDlgButton( IDC_leftup8, 0 );
	if(m_modalorg==0)
	{
    CheckDlgButton( IDC_center, 1);
	}
	if(m_modalorg==1)
	{
    CheckDlgButton( IDC_up1, 1 );
	}
	if(m_modalorg==2)
	{
    	
	CheckDlgButton( IDC_rightup2, 1 );
	}
	if(m_modalorg==3)
	{
     
	CheckDlgButton( IDC_right3, 1 );
	}
	if(m_modalorg==4)
	{
     
	CheckDlgButton( IDC_rightdown4, 1 );
	}
	if(m_modalorg==5)
	{
     
	CheckDlgButton( IDC_down5, 1 );
	}
	if(m_modalorg==6)
	{
     
	CheckDlgButton( IDC_leftdown6, 1 );
	}
	if(m_modalorg==7)
	{
 
	CheckDlgButton( IDC_left7, 1 );
	}
	if(m_modalorg==8)
	{
   
	CheckDlgButton( IDC_leftup8, 1 );
	}
	set_part_style(m_Windoweditid,2);
	set_check("father");
    

	{
		try
		{
		HTuple NumLevels,AngleStart,  AngleExtent, AngleStep,ScaleMin,  ScaleMax, ScaleStep;
		HTuple Metric;
		HTuple MinContrast;
		get_shape_model_params(ShapeModeledit,&NumLevels,& AngleStart, & AngleExtent,& AngleStep,&ScaleMin, & ScaleMax,& ScaleStep, & Metric,& MinContrast);
	    m_contrastin=MinContrast[0].L();
		}
		catch (HException &except)
		{;}

		UpdateData(false);
	    m_contrastctr.SetPos(m_contrastin);
		
	}


	if( m_EditModel == FALSE )
	{
	//	m_ShapeModelContoursxld=m_ShapeModelContours.GenContourRegionXld("border");
		set_draw(m_Windoweditid,"margin");
		
		disp_obj(Imageedit,m_Windoweditid);
		  set_color(m_Windoweditid,"red");

    	disp_cross(m_Windoweditid,keypasteytemp,keypastextemp,80,0);

	}
	if( m_EditModel == TRUE)
	{   
		set_draw(m_Windoweditid,"margin");
	    set_part(m_Windoweditid,-800,-800,800,800);
		//ShapeModeledit.SetShapeModelOrigin(shapemodel11orgx,shapemodel11orgy);
        try
		{
		get_shape_model_contours(&m_ShapeModelContoursxld,ShapeModeledit,1);
		get_shape_model_contours(&m_ShapeModelContours,ShapeModeledit,1);
			 
	
        segment_contours_xld(m_ShapeModelContoursxld,&m_ShapeModelContoursxld,"lines", 5, 4, 2);
		
		disp_obj(m_ShapeModelContoursxld,m_Windoweditid);
		m_ShapeModelContoursxldold=m_ShapeModelContoursxld;
        double Row,Column;
		get_shape_model_origin(ShapeModeledit,&Row, &Column);

		HTuple    NumLevelstest,AngleStarttest, AngleExtenttest;
        HTuple  AngleSteptest, ScaleMintest, ScaleMaxtest, ScaleSteptest, Metrictest;
        HTuple  MinContrasttest;


        get_shape_model_params(ShapeModeledit, &NumLevelstest, &AngleStarttest, &AngleExtenttest, &AngleSteptest, 
        &ScaleMintest, &ScaleMaxtest, &ScaleSteptest, &Metrictest, &MinContrasttest);
		NumLevels=NumLevelstest[0].D();
		

		SetDlgItemInt(IDC_modalxorg,Column);
	    SetDlgItemInt(IDC_modalyorg,Row);
		}
		catch (HException &except)
		{;}
		
	}


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}






void CModelEditDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{


	CDialog::OnLButtonDown(nFlags, point);
}


BOOL CModelEditDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class

	//show positon of mouse on the screen
	{
		HTuple button;
        Herror error_num;
	          try
		   {
				HTuple pointxtemp,pointytemp;
				double pointx,pointy;
		
			 HTuple endpointxtemp,endpointytemp;
			 get_mposition_sub_pix(m_Windoweditid, &pointxtemp, &pointytemp,&button);
			
				pointx=pointxtemp[0].D();
				pointy=pointytemp[0].D();
				SetDlgItemInt( IDC_mousepointx, pointx );
				SetDlgItemInt( IDC_mousepointy, pointy );
			
		   }
         catch (HException &except)
		 {
           error_num = except.err;
		   
		  
		 }


	}

 if (pMsg->hwnd == ::GetDlgItem(m_hWnd, IDC_STATIC_img) && pMsg->message == WM_LBUTTONDOWN)
 {
	 	
     HTuple button;
       Herror error_num;
	          try
		   {
				  HTuple startpointxtemp,startpointytemp;
				 
         		get_mposition(m_Windoweditid,&startpointxtemp, &startpointytemp,&button) ;//point.x;	
				startpointx=startpointxtemp[0].D();
					startpointy=startpointytemp[0].D();

			
		   }
         catch (HException &except)
		 {
           error_num = except.err;
		   
		  	 	   
           return  CDialog::PreTranslateMessage(pMsg);
		 }
	 return  CDialog::PreTranslateMessage(pMsg);

 }
 if (pMsg->hwnd == ::GetDlgItem(m_hWnd, IDC_STATIC_img) && pMsg->message == WM_MOUSEMOVE)
  {
	 
    //添加你自己的代码
	 if( m_EditModel == FALSE ) 
	{
		
	if( pMsg->wParam == MK_LBUTTON ) 
		{
		 HTuple button;
	
		 Herror error_num;
	     try
		   {
			 HTuple endpointxtemp,endpointytemp;
			 get_mposition_sub_pix(m_Windoweditid,&endpointxtemp ,&endpointytemp ,&button);
			 endpointx=endpointxtemp[0].D();
			  endpointy=endpointytemp[0].D();


		 }
         catch (HException &except)
		 {
           error_num = except.err;;
		   return  CDialog::PreTranslateMessage(pMsg);
		 }
	
		
		    disp_obj(Imageedit,m_Windoweditid);
		 	set_draw(m_Windoweditid,"margin");
            set_color(m_Windoweditid,"red");
		 
	     try
		 {
			gen_rectangle1(&modelrect,startpointx,startpointy,endpointx,endpointy);
		 	disp_obj(modelrect,m_Windoweditid);
			modelhalfx=(endpointx-startpointx)/2;
			modelhalfy=(endpointy-startpointy)/2;
			visionx=(endpointx+startpointx)/2;
			visiony=(endpointy+startpointy)/2;
		   // if(visionx<2592/2)
			{
				revisionx=visionx;
				revisiony=2592-visiony;
			}
		

		 }
         catch (HException &except)
		 {
           error_num = except.err;;
		   return  CDialog::PreTranslateMessage(pMsg);
		 }
	
		
		


		}
     return  CDialog::PreTranslateMessage(pMsg);
  }
 }
	
 if (pMsg->hwnd == ::GetDlgItem(m_hWnd, IDC_STATIC_img) && pMsg->message == WM_MOUSEMOVE)
  {
	 
    //添加你自己的代码
	 if( m_EditModel == true) 
	{

		 HRegion delrect;
	
		 Hlong button;
	
		 Herror error_num;
		 clear_window(m_Windoweditid);
		 set_color(m_Windoweditid,"green");
		  //m_Windowedit.SetWindowParam("interactive_plot" ,"false");
		  //SetWindowType("WIN32-Window");


		 disp_obj(m_ShapeModelContoursxld,m_Windoweditid);

	     try
		   {
			  HTuple endpointxtemp,endpointytemp,button;
			 get_mposition_sub_pix(m_Windoweditid, &endpointxtemp, &endpointytemp,&button);
			 	 endpointx=endpointxtemp[0].D();
			  endpointy=endpointytemp[0].D();
		 }
         catch (HException &except)
		 {
           error_num = except.err;;
		   return  CDialog::PreTranslateMessage(pMsg);
		 }
		 // m_Windowedit.SetColor("red");
		 // m_Windowedit.SetMshape("cross");
	//	m_Windowedit.DispRectangle1(endpointx-m_PenWidth ,endpointy-m_PenWidth ,endpointx+m_PenWidth ,endpointy+m_PenWidth );

		if( pMsg->wParam == MK_LBUTTON ) 
		{
		// m_Windowedit.DispObj(Image);
		 Herror error_num;
		
		 m_PenWidth = GetDlgItemInt( IDC_EDIT8 );
	     try
		 {delrect.GenRectangle1(endpointx-m_PenWidth ,endpointy-m_PenWidth ,endpointx+m_PenWidth ,endpointy+m_PenWidth );}
         catch (HException &except)
		 {
           error_num = except.err;
		   return  CDialog::PreTranslateMessage(pMsg);
		 }
        	set_color(m_Windoweditid,"red");
		
			disp_rectangle1(m_Windoweditid,endpointx-m_PenWidth ,endpointy-m_PenWidth ,endpointx+m_PenWidth ,endpointy+m_PenWidth );
	
			set_draw(m_Windoweditid,"margin");
            set_color(m_Windoweditid,"green");
            Hobject cliped,clipedout;
     
	        HTuple Row, Column;
	
				HTuple Num;
				Hobject pickxld;
				int i;
				count_obj(m_ShapeModelContoursxldold,&Num);
				try
						{
				for (i=1; i<=Num; i++)
				{
				   double x,y,areatemp;
				   select_obj(m_ShapeModelContoursxldold,&pickxld,i);
				   area_center_points_xld(pickxld,&areatemp,&x, &y);

					if((abs(x-endpointx)<m_PenWidth)&&(abs(y-endpointy)<m_PenWidth))
					{
						HTuple isequal;
						test_equal_obj(pickxld,m_ShapeModelContoursxldold,&isequal);
						if(isequal[0].L()!=1)
						{cliped=pickxld;}
					
				
							if(m_PointState==0)
							{obj_diff(m_ShapeModelContoursxld,cliped,&clipedout);}
							if(m_PointState==1)
							{concat_obj(m_ShapeModelContoursxld,cliped,&clipedout);}
						

					m_ShapeModelContoursxld=clipedout;
					}
             
				}
}
									catch (HException &except)
						{
							error_num = except.err;
							return  CDialog::PreTranslateMessage(pMsg);
						}
		//IntersectionCircleContourXld(	m_ShapeModelContours, endpointx, endpointy, m_PenWidth, 0, 6.29, "positive", &Row, &Column); 
			//cliped=m_ShapeModelContoursxldold.SelectXldPoint(endpointx,endpointy);//,"false");//Hlong Top, Hlong Bottom, Hlong Left, Hlong Right) 
		
		
			
			clear_window(m_Windoweditid);
			disp_obj(m_ShapeModelContoursxld,m_Windoweditid);
			
		


		}
     return  CDialog::PreTranslateMessage(pMsg);
  }
 }
	return  CDialog::PreTranslateMessage(pMsg);

}






void CModelEditDlg::OnAddEdge() 
{
	// TODO: Add your control notification handler code here
	
	m_PointState = 1;
	
	CheckDlgButton( IDC_DEL_EDGE, 0 );

}

void CModelEditDlg::OnDelEdge() 
{
	// TODO: Add your control notification handler code here
	
	m_PointState = 0;
	
   	CheckDlgButton( IDC_ADD_EDGE, 0 );

}

void CModelEditDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	if( m_EditModel == FALSE )
	{
			
			

                HTuple xarea,yarea;
				HTuple areatemp;
				area_center(modelrect,&areatemp,&xarea,&yarea);
    			if(areatemp[0].L()==0)
				{
					AfxMessageBox("请选择区域");
					return;
				}
			if(m_contrastin==0)
				{
					AfxMessageBox("调节对比度");
					return;
				}



			
	            Herror error_num;
			try
			  {	
					reduce_domain(Imageedit,modelrect,&m_ImageReduced );
			  }
		    catch (HException &except)
			 {
				error_num = except.err;
				AfxMessageBox(error_num);

			
	  			return;
			}
				
			//	m_ShapeModelImage = m_ImageReduced.InspectShapeModel(&m_ShapeModelContours,1,10);
				set_color(m_Windoweditid,"red");
		//	m_Windowedit.DispObj(m_ImageReduced);

					
				
	          try
			  {	
				  //SetSystem("pregenerate_shape_models","true");
				  
				 
         		/*create_shape_model(m_ImageReduced, NumLevels,  -0.2, 0.4, "auto", "auto", "ignore_local_polarity", 

                m_contrastin+1, m_contrastin,&ShapeModeledit);*/
				  create_shape_model(m_ImageReduced, NumLevels,  -0.5, 1.0, "auto", "auto", "ignore_local_polarity", 

                m_contrastin+1, m_contrastin,&ShapeModeledit);
			
			
			   }
		    catch (HException &except)
			 {
				error_num = except.err;
				//AfxMessageBox(error_num);

				AfxMessageBox( "学习失败！" );
				//m_Windowedit.DispObj(Image);
	  			CDialog::OnOK();
				return;
			}



		
		    HTuple x,y;
	
		   area_center(modelrect,&areatemp,&x,&y);
		
			xi=startpointx-x[0].D();
			yi=startpointy-y[0].D();
		
			//ShapeModeledit.SetShapeModelOrigin(xi,yi);
			get_shape_model_contours(&m_ShapeModelContours,ShapeModeledit,1);
			get_shape_model_contours(&m_ShapeModelContoursxld,ShapeModeledit,1);
			//m_ShapeModelContoursxld=m_ShapeModelContours.GenContourXld("center");
					 
		segment_contours_xld(m_ShapeModelContoursxld,&m_ShapeModelContoursxld,"lines", 5, 4, 2);
		

		m_ShapeModelContoursxldold=m_ShapeModelContoursxld;
	    
	//	m_Windowedit.SetPart(xi,yi,600,600);	
		disp_obj(Imageedit,m_Windoweditid);
	    HTuple	Transformation;
		Hobject		ContourTrans;
	

       try
		{vector_angle_to_rigid(0,0,0,startpointx,startpointy,0,&Transformation);}
         catch (HException &except)
		 {
           error_num = except.err;
		   if(error_num!=2)
			   {return ;}
		 }
	
   

		affine_trans_contour_xld(m_ShapeModelContours,&ContourTrans,Transformation);//,"false");
		set_color(m_Windoweditid,"red");
	//	m_Windowedit.SetPart(xi,yi,-2*xi,-2*yi);
		disp_obj(ContourTrans,m_Windoweditid);

		disp_obj(modelrect,m_Windoweditid);
	
		if((modalselect==0)&&(cameraselect==0))
		{
		ShapeModel11=ShapeModeledit;
		model11halfx=modelhalfx;
		model11halfy=modelhalfy;

		HTuple	Transformation;
		HTuple NumLevels,AngleStart,  AngleExtent, AngleStep,ScaleMin,  ScaleMax, ScaleStep;
		HTuple Metric;
		HTuple MinContrast;
		Hobject m_ShapeModelContours1,ContourTrans1;
		
		try
		{
	    get_shape_model_params(ShapeModeledit,&NumLevels,& AngleStart, & AngleExtent,& AngleStep,&ScaleMin, & ScaleMax,& ScaleStep, & Metric,& MinContrast);
		get_shape_model_contours(&m_ShapeModelContours1,ShapeModeledit,1);
		vector_angle_to_rigid(0,0,0,0,0,3.1415926,&Transformation);
		affine_trans_contour_xld(m_ShapeModelContours1,&ContourTrans1 ,Transformation);

		create_shape_model_xld(ContourTrans1,NumLevels,-0.5,1.0,"auto","auto","ignore_local_polarity", m_contrastin,&ShapeModel22);
	
		}
		catch (HException &except)
			 {
				error_num = except.err;
				AfxMessageBox( "学习失败！" );
				disp_obj(Imageedit,m_Windoweditid);
	  			return;
			}
		//create_shape_model_xld(ContourTrans1,NumLevels,-0.5,1.0,"auto","auto","ignore_local_polarity", m_contrastin,&ShapeModel22);
		//create_shape_model_xld(m_ShapeModelContoursxld,NumLevels,-0.5,1.0,"auto","auto","ignore_local_polarity", m_contrastin,&ShapeModeledit);
		}
		if((modalselect==1)&&(cameraselect==0))
		{
		ShapeModel12=ShapeModeledit;
		model12halfx=modelhalfx;
		model12halfy=modelhalfy;

		HTuple	Transformation;
		HTuple NumLevels,AngleStart,  AngleExtent, AngleStep,ScaleMin,  ScaleMax, ScaleStep;
		HTuple Metric;
		HTuple MinContrast;
		Hobject m_ShapeModelContours1,ContourTrans1;
		
		try
		{
	    get_shape_model_params(ShapeModeledit,&NumLevels,& AngleStart, & AngleExtent,& AngleStep,&ScaleMin, & ScaleMax,& ScaleStep, & Metric,& MinContrast);
		get_shape_model_contours(&m_ShapeModelContours1,ShapeModeledit,1);
		vector_angle_to_rigid(0,0,0,0,0,3.1415926,&Transformation);
		affine_trans_contour_xld(m_ShapeModelContours1,&ContourTrans1 ,Transformation);

		create_shape_model_xld(ContourTrans1,NumLevels,-0.5,1.0,"auto","auto","ignore_local_polarity", m_contrastin,&ShapeModel21);
		//ShapeModel22=ShapeModeledit;
		}
		catch (HException &except)
			 {
				error_num = except.err;
				AfxMessageBox( "学习失败！" );
				disp_obj(Imageedit,m_Windoweditid);
	  			return;
			}
		}
		if((modalselect==2)&&(cameraselect==0))
		{
		ShapeModel21=ShapeModeledit;
		model21halfx=modelhalfx;
		model21halfy=modelhalfy;
		}
		if((modalselect==3)&&(cameraselect==0))
		{
		ShapeModel22=ShapeModeledit;
		model22halfx=modelhalfx;
		model22halfy=modelhalfy;
		}


			m_EditModel	= TRUE;
			EnableAll();
		   
		   CDialog::OnOK();

		
	} 

	
	if( m_EditModel == TRUE )
	{
	
		
						
			Herror error_num;
	        //ClearShapeModel(ShapeModeledit);
			try
			{
								
                set_system("pregenerate_shape_models","true");
				   // if(m_modalorg==0)
				  //{create_shape_model_xld(m_ShapeModelContoursxld,NumLevels,0,0,"auto","auto","ignore_local_polarity", m_contrastin,&ShapeModeledit);}
				  //else
			/*create_shape_model_xld(m_ShapeModelContoursxld,NumLevels,-0.2,0.4,"auto","auto","ignore_local_polarity", m_contrastin,&ShapeModeledit);*/
			   create_shape_model_xld(m_ShapeModelContoursxld,NumLevels,-0.5,1.0,"auto","auto","ignore_local_polarity", m_contrastin,&ShapeModeledit);

            set_shape_model_origin(ShapeModeledit,0,0);
			get_shape_model_contours(&m_ShapeModelContoursxld,ShapeModeledit,1);

			

			HTuple  y, x, length, distanceold, Index, xselect;
            HTuple  yselect, distance,number;
			 HTuple minx, miny;


			// HTuple Rowrect,Columnrect,Phirect,Length1rect,Length2rect,PointOrderrect;
			Hobject select,Rectangle ;

			
			
	        /*Hobject m_ShapeModelContoursxldnew;
				HTuple Num ;
				Hobject pickxld;
			
				count_obj(m_ShapeModelContoursxld,&Num);
				
				
				for (int i=1; i<=Num; i++)
				{
				   double x,y,areatemp;
				   select_obj(m_ShapeModelContoursxld,&pickxld,i);
				   if(i==1)
				   {
					   m_ShapeModelContoursxldnew=pickxld;
				   }
				   else
				   {
					   concat_obj(m_ShapeModelContoursxldnew,pickxld,&m_ShapeModelContoursxldnew);
				   }
							

					
					}*/
             
				
		    /*smallest_rectangle2_xld (m_ShapeModelContoursxldnew, &Rowrect, &Columnrect, &Phirect, &Length1rect, &Length2rect);
		    
			gen_rectangle2_contour_xld( &Rectangle ,Rowrect, Columnrect, Phirect, Length1rect, Length2rect ) ;
			set_color(m_Windoweditid,"blue");
			disp_obj(Rectangle,m_Windoweditid);
			set_color(m_Windoweditid,"green");*/
			if(m_modalorg!=0)
			{
				distanceold = 5000;
				
				 count_obj(m_ShapeModelContoursxld, &number);
				 int i;

				for (i=1; i<=number; i++)
				 {

				
					 
					select_obj(m_ShapeModelContoursxld, &select, i);
						get_contour_xld(select, &y, &x);
			tuple_length(x, &length);
				for (Index=0; Index<=length-1; Index+=1)
				{
					tuple_select(x, Index, &xselect);
					tuple_select(y, Index, &yselect);
					switch(m_modalorg)
					{
				    	case 1:
							  distance_pl(yselect, xselect, -1000, 0, -1000, 1000, &distance);
						break;
						case 2:
							  distance_pl(yselect, xselect, -1000, 0, 0, 1000, &distance);
						break;
						case 3:
							  distance_pl(yselect, xselect, 0, 1000, 1000, 1000, &distance);
						break;
						case 4:
							  distance_pl(yselect, xselect, 0, 1000, 1000, 0, &distance);
						break;
						case 5:
							  distance_pl(yselect, xselect, 1000, 0, 1000, 1000, &distance);
						break;
						case 6:
							  distance_pl(yselect, xselect, 0,-1000, 1000, 0, &distance);
						break;
						case 7:
							  distance_pl(yselect, xselect, 0, -1000, -1000, -1000, &distance);
						break;
						case 8:
							  distance_pl(yselect, xselect, -1000, 0, 0, -1000, &distance);
						break;
					}
					if (0 != (distance<distanceold))
						{
							distanceold = distance;
							minx = xselect;
							miny = yselect;
						}

				}
				}
			}
		//	gen_circle(&circle, miny, minx, 20);

			   

			  /* if(m_originstate==1)
                 {set_shape_model_origin(ShapeModeledit,ya,xa);}
				  if(m_originstate==2)
                 {set_shape_model_origin(ShapeModeledit,yb,xb);}
				   if(m_originstate==3)
                 {set_shape_model_origin(ShapeModeledit,yd,xd);}
				    if(m_originstate==4)
                 {set_shape_model_origin(ShapeModeledit,yc,xc);}*/
				/*int Row,Column;*/
				//SetDlgItemInt( IDC_modalyorg, int(miny[0].D()));
				//SetDlgItemInt(  IDC_modalxorg,int(minx[0].D()));
			   if(m_modalorg!=0)
			   {set_shape_model_origin(ShapeModeledit,miny,minx);}
			}
		    catch (HException &except)
			 {
				error_num = except.err;
				AfxMessageBox( "学习失败！" );
				disp_obj(Imageedit,m_Windoweditid);
	  			return;
			}
		
			if((modalselect==0)&&(cameraselect==0))
		{
			ShapeModel11=ShapeModeledit;
			modalorg11=m_modalorg;
		}
		if((modalselect==1)&&(cameraselect==0))
		{
		ShapeModel12=ShapeModeledit;
		modalorg12=m_modalorg;
		}
		if((modalselect==2)&&(cameraselect==0))
		{
		ShapeModel21=ShapeModeledit;
		modalorg21=m_modalorg;
		}
		if((modalselect==3)&&(cameraselect==0))
		{
		ShapeModel22=ShapeModeledit;
		modalorg22=m_modalorg;
		}
        
		
	

		CDialog::OnOK();
	}


}

void CModelEditDlg::OnCancel() 
{

	CDialog::OnCancel();
}



void CModelEditDlg::EditModel(BOOL IsEdit)
{
	m_EditModel = IsEdit;
}

void CModelEditDlg::EnableAll()
{
	if( m_EditModel )
	{
		SetWindowText( "编辑模板" );
		SetDlgItemText( IDOK, "确定" );
	    m_contrastctr.EnableWindow( FALSE );
		
		GetDlgItem( IDC_ADD_EDGE )->EnableWindow( TRUE );
		GetDlgItem( IDC_DEL_EDGE )->EnableWindow( TRUE );
	
	} else 
	{
		SetWindowText( "创建模板" );
		SetDlgItemText( IDOK, "学习" );
		m_contrastctr.EnableWindow( TRUE );
	
		GetDlgItem( IDC_ADD_EDGE )->EnableWindow( FALSE );
		GetDlgItem( IDC_DEL_EDGE )->EnableWindow( FALSE );

	}
}


void CModelEditDlg::Onsoftkey4() 
{
	// TODO: Add your control notification handler code here
		HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{
		::SendMessage(h,WM_CLOSE,0,0);
		SetDlgItemText(IDC_softkey4,"开键盘");
	}
	else
	{
		WinExec("c:\\windows\\system32\\osk.exe",SW_SHOWNORMAL);
		SetDlgItemText(IDC_softkey4,"关键盘");
	}
	
}




void CModelEditDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	m_contrastin=m_contrastctr.GetPos();
	UpdateData(false);
	m_contrastctr.SetPos(m_contrastin);
	HTuple areaarea, xarea,yarea;
    area_center(modelrect,&areaarea,&xarea,&yarea);
    if(areaarea[0].D()==0)
				{
		           if(messageout==false)
				   {
					messageout=true;
					AfxMessageBox("请选择区域");
					

				   }
					return;
				}

      

	  Herror error_num;
			try
			  {	
				
					 reduce_domain(Imageedit,modelrect,&m_ImageReduced );
			  }
		    catch (HException &except)
			 {
				error_num = except.err;
				
	
	  			return;
			}
     
   	Hobject ModelRegions,modelimagein;
	try
		{ inspect_shape_model(m_ImageReduced,&modelimagein,&ModelRegions, 8, m_contrastin);}
    catch (HException &except)
			 {
				error_num = except.err;
				AfxMessageBox(error_num);

			
	  			return;
			}
	HTuple AreaModelRegions,RowModelRegions, ColumnModelRegions;
    area_center(ModelRegions,&AreaModelRegions,&RowModelRegions, &ColumnModelRegions);
	int i;
	Hlong obj;
    count_obj(ModelRegions,&obj);
    for(i=1;i<obj;i++)
	{
		try
	{
	if (AreaModelRegions[i-1].L()>=15)
      
	  {NumLevels = i;}
    
	}
	  catch (HException &except)
			 {
				error_num = except.err;
				
	
	  			return;
			}
	}
	clear_window(m_Windoweditid);
	set_part(m_Windoweditid,0,0,3000-NumLevels*350,3000-NumLevels*350);
	//m_Windowedit.SetDraw("margin");

	set_color(m_Windoweditid,"green");
	disp_obj(ModelRegions,m_Windoweditid);
	set_color(m_Windoweditid,"red");
	try
	{

		Hobject temp;
		select_obj(ModelRegions,&temp,NumLevels-1);
	    disp_obj(temp,m_Windoweditid);
	}
	catch (HException &except)
	{
		error_num = except.err;
				
	
	  			return;
	}

	CString   level; 
    level.Format( "%d ",NumLevels);


	write_string(m_Windoweditid,"           金字塔级别"+(HTuple)level);
 
     


	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CModelEditDlg::Onup1() 
{
	// TODO: Add your control notification handler code here
	m_modalorg=1;
    CheckDlgButton( IDC_center, 0 );

	CheckDlgButton( IDC_rightup2, 0 );
	CheckDlgButton( IDC_right3, 0 );
	CheckDlgButton( IDC_rightdown4, 0 );
	CheckDlgButton( IDC_down5, 0 );
	CheckDlgButton( IDC_leftdown6, 0 );
	CheckDlgButton( IDC_left7, 0 );
	CheckDlgButton( IDC_leftup8, 0 );
	
}

void CModelEditDlg::Oncenter() 
{
	// TODO: Add your control notification handler code here
		m_modalorg=0;
	   
	CheckDlgButton( IDC_up1, 0 );
	CheckDlgButton( IDC_rightup2, 0 );
	CheckDlgButton( IDC_right3, 0 );
	CheckDlgButton( IDC_rightdown4, 0 );
	CheckDlgButton( IDC_down5, 0 );
	CheckDlgButton( IDC_leftdown6, 0 );
	CheckDlgButton( IDC_left7, 0 );
	CheckDlgButton( IDC_leftup8, 0 );
	
}

void CModelEditDlg::Onrightup2() 
{
	// TODO: Add your control notification handler code here
		m_modalorg=2;
	    CheckDlgButton( IDC_center, 0 );
	CheckDlgButton( IDC_up1, 0 );

	CheckDlgButton( IDC_right3, 0 );
	CheckDlgButton( IDC_rightdown4, 0 );
	CheckDlgButton( IDC_down5, 0 );
	CheckDlgButton( IDC_leftdown6, 0 );
	CheckDlgButton( IDC_left7, 0 );
	CheckDlgButton( IDC_leftup8, 0 );
	
}

void CModelEditDlg::Onright3() 
{
	// TODO: Add your control notification handler code here
		m_modalorg=3;
	    CheckDlgButton( IDC_center, 0 );
	CheckDlgButton( IDC_up1, 0 );
	CheckDlgButton( IDC_rightup2, 0 );

	CheckDlgButton( IDC_rightdown4, 0 );
	CheckDlgButton( IDC_down5, 0 );
	CheckDlgButton( IDC_leftdown6, 0 );
	CheckDlgButton( IDC_left7, 0 );
	CheckDlgButton( IDC_leftup8, 0 );
	
}

void CModelEditDlg::Onrightdown4() 
{
	// TODO: Add your control notification handler code here
		m_modalorg=4;
	CheckDlgButton( IDC_center, 0 );
	CheckDlgButton( IDC_up1, 0 );
	CheckDlgButton( IDC_rightup2, 0 );
	CheckDlgButton( IDC_right3, 0 );

	CheckDlgButton( IDC_down5, 0 );
	CheckDlgButton( IDC_leftdown6, 0 );
	CheckDlgButton( IDC_left7, 0 );
	CheckDlgButton( IDC_leftup8, 0 );
	
}

void CModelEditDlg::Ondown5() 
{
	// TODO: Add your control notification handler code here
		m_modalorg=5;
	    CheckDlgButton( IDC_center, 0 );
	CheckDlgButton( IDC_up1, 0 );
	CheckDlgButton( IDC_rightup2, 0 );
	CheckDlgButton( IDC_right3, 0 );
	CheckDlgButton( IDC_rightdown4, 0 );

	CheckDlgButton( IDC_leftdown6, 0 );
	CheckDlgButton( IDC_left7, 0 );
	CheckDlgButton( IDC_leftup8, 0 );
	
}

void CModelEditDlg::Onleftdown6() 
{
	// TODO: Add your control notification handler code here
		m_modalorg=6;
	    CheckDlgButton( IDC_center, 0 );
	CheckDlgButton( IDC_up1, 0 );
	CheckDlgButton( IDC_rightup2, 0 );
	CheckDlgButton( IDC_right3, 0 );
	CheckDlgButton( IDC_rightdown4, 0 );
	CheckDlgButton( IDC_down5, 0 );

	CheckDlgButton( IDC_left7, 0 );
	CheckDlgButton( IDC_leftup8, 0 );
	
}

void CModelEditDlg::Onleft7() 
{
	// TODO: Add your control notification handler code here
		m_modalorg=7;
	    CheckDlgButton( IDC_center, 0 );
	CheckDlgButton( IDC_up1, 0 );
	CheckDlgButton( IDC_rightup2, 0 );
	CheckDlgButton( IDC_right3, 0 );
	CheckDlgButton( IDC_rightdown4, 0 );
	CheckDlgButton( IDC_down5, 0 );
	CheckDlgButton( IDC_leftdown6, 0 );

	CheckDlgButton( IDC_leftup8, 0 );
}

void CModelEditDlg::Onleftup8() 
{
	// TODO: Add your control notification handler code here
		m_modalorg=8;
	    CheckDlgButton( IDC_center, 0 );
	CheckDlgButton( IDC_up1, 0 );
	CheckDlgButton( IDC_rightup2, 0 );
	CheckDlgButton( IDC_right3, 0 );
	CheckDlgButton( IDC_rightdown4, 0 );
	CheckDlgButton( IDC_down5, 0 );
	CheckDlgButton( IDC_leftdown6, 0 );
	CheckDlgButton( IDC_left7, 0 );

	
}



//void CModelEditDlg::OnBnClickedOk()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	CDialog::OnOK();
//}


void CModelEditDlg::OnNMCustomdrawSlidercontrast(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}
