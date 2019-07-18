// VisionSetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "VAFS2.h"
#include "VisionSetDlg.h"
#include "externs.h"
#include "dmc1000.h"  //包含1000B库头文件

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif





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
ON_EN_SETFOCUS(IDC_EDIT_SHUTTER, OnSetfocusEditShutter)
ON_EN_KILLFOCUS(IDC_EDIT_SHUTTER, OnKillfocusEditShutter)
ON_EN_KILLFOCUS(IDC_EDIT_GAIN, OnKillfocusEditGain)
ON_EN_KILLFOCUS(IDC_EDIT_contrast, OnKillfocusEDITcontrast)
ON_EN_SETFOCUS(IDC_EDIT_contrast, OnSetfocusEDITcontrast)
ON_EN_SETFOCUS(IDC_keypastex, OnSetfocuskeypastex)
ON_EN_KILLFOCUS(IDC_keypastex, OnKillfocuskeypastex)
ON_EN_SETFOCUS(IDC_keypastey, OnSetfocuskeypastey)
ON_EN_KILLFOCUS(IDC_keypastey, OnKillfocuskeypastey)
ON_WM_SYSCOMMAND()
ON_EN_SETFOCUS(IDC_EDIT_GAIN, OnSetfocusEditGain)
    //}}AFX_MSG_MAP
ON_EN_CHANGE(IDC_EDIT_GAIN, &CVisionSetDlg::OnEnChangeEditGain)
ON_EN_CHANGE(IDC_EDIT_contrast, &CVisionSetDlg::OnEnChangeEditcontrast)
ON_EN_CHANGE(IDC_EDIT_SHUTTER, &CVisionSetDlg::OnEnChangeEditShutter)
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

    if((modalselect==0)&&(cameraselect==0))
    {
        m_gain=gain;
        m_shutter = (float)shutter;
        m_contrast=contrast1;
    }

    if((modalselect==1)&&(cameraselect==0))
    {
        m_shutter =(float) shutter;
        m_contrast=contrast1;
        m_gain=gain;
    }
    if((modalselect==2)&&(cameraselect==0))
    {	m_shutter = (float)shutter;
        m_contrast=contrast1;
        m_gain=gain;
    }
    if((modalselect==3)&&(cameraselect==0))
    {	m_shutter =(float) shutter;
        m_contrast=contrast1;
        m_gain=gain;
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
    return TRUE;  // return TRUE  unless you set the focus to a control
}


//初始化设备，给设备指定任务
BOOL CVisionSetDlg::InitDeviceFunction()
{
    CameraSetAeState(camera1, FALSE);
    CameraSetExposureTime(camera1, shutter*10000);

    CameraSetAnalogGain(camera1,gain);

    // 	CameraSetAeState(camera2, FALSE);
    //      CameraSetExposureTime(camera2, shutter3*10000);
    // 	
    //CameraSetAnalogGain(camera2,gain2);
    CameraSetContrast(camera1, contrast1);
    //CameraSetContrast(camera2, contrast2);
    return true;
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
    HWND h=::FindWindow(NULL,"屏幕键盘");
    if(h!=NULL)
    {::SendMessage(h,WM_CLOSE,0,0);}



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
    //       if(cameraselect==0)
    //{
    imagephotoover=false;

    CameraPlay(camera1);
    while(imagephotoover!=true)
    {

        ;

    }
    disp_obj(Image1,m_Windowvisionid);
    imagephotoover=false;



    //		}
    //   if(cameraselect==1)
    //{
    //	imagephotoover2=false;
    //	
    //	CameraPlay(camera2);
    //       while(imagephotoover2!=true)
    //	{
    //	
    //		;
    //  
    //	}
    //	disp_obj(Image2,m_Windowvisionid);
    //	imagephotoover2=false;

    //
    //}



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
    //if(cameraselect==0)
    {m_ModelEditDlg.Imageedit=Image1;}
    //if(cameraselect==1)
    //{m_ModelEditDlg.Imageedit=Image2;}

    if(modalselect==0)
    {m_ModelEditDlg.ShapeModeledit=ShapeModel11;}
    if(modalselect==1)
    {m_ModelEditDlg.ShapeModeledit=ShapeModel12;}
    if(modalselect==2)
    {m_ModelEditDlg.ShapeModeledit=ShapeModel21;}
    if(modalselect==3)
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
    {m_ModelEditDlg.ShapeModeledit=ShapeModel21;}
    if((cameraselect==0)&&(modalselect==3))
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
    HTuple Countregion,imagesArea, imagesRow, imagesColumn;
    Hobject roiimages,sortroiimages;

    //BeginTime();	// 开始测试时间


    {


        if((modalselect==0)&&(cameraselect==0))

        {
            Herror error_num ;

            double row,column;
            {
                try
                {
                    set_shape_model_param(ShapeModel11,"timeout",8000);
                    Hobject modelroi,roiimage;
                    {gen_rectangle1(&modelroi,visionx-model11halfx-searchrange,visiony-model11halfy-searchrange,visionx+model11halfx+searchrange,visiony+model11halfy+searchrange);}
                    reduce_domain(Image1,modelroi,&roiimage);
                    find_shape_model(roiimage,ShapeModel11, -0.5, 1.0, minscore11, 1, 0,"interpolation",
                            0,0.9,&htRowCheck,&htColumnCheck,&htAngleCheck,&htScore);
                    disp_obj(Image1,m_Windowvisionid);
                    HTuple	Transformation;
                    Hobject m_ShapeModelContoursxld,ContourTrans;
                    set_color(m_Windowvisionid,"red");
                    set_draw(m_Windowvisionid,"margin");
                    int i;
                    /*for(i=0;i<3;i++)
                      {*/
                    if(	htScore[0].D()<minscore11)

                    {

                        AfxMessageBox( "查找失败！" );


                    }

                    get_shape_model_contours(&m_ShapeModelContoursxld,ShapeModel11,1);

                    {vector_angle_to_rigid(0,0,0,htRowCheck[0].D(),htColumnCheck[0].D(),htAngleCheck[0].D(),&Transformation);}
                    affine_trans_contour_xld(m_ShapeModelContoursxld,&ContourTrans,Transformation);//,"false");					
                    disp_obj(ContourTrans,m_Windowvisionid);						
                    model11xtemp=htColumnCheck[0].D();
                    model11ytemp=htRowCheck[0].D();
                    set_color(m_Windowvisionid,"green");
                    disp_cross(m_Windowvisionid,model11ytemp,model11xtemp,40,0);
                    disp_obj(modelroi,m_Windowvisionid);


                }
                catch (HException &except)
                {
                    error_num = except.err;
                    AfxMessageBox( "查找失败！" );
                    return ;

                }
                }
            }

            if((modalselect==1)&&(cameraselect==0))
            {
                Herror error_num ;

                double row,column;
                {
                    try
                    {
                        set_shape_model_param(ShapeModel12,"timeout",8000);
                        Hobject modelroi;
                        Hobject roiimage;

                        {gen_rectangle1(&modelroi,visionx-model12halfx-searchrange,visiony-model12halfy-searchrange,visionx+model12halfx+searchrange,visiony+model12halfy+searchrange);}


                        reduce_domain(Image1,modelroi,&roiimage);
                        {

                            find_shape_model(roiimage,ShapeModel12,-0.5, 1.0, minscore11, 1, 0,"least_squares",
                                    0,0.9,&htRowCheck,&htColumnCheck,&htAngleCheck,&htScore);
                        }




                        disp_obj(Image1,m_Windowvisionid);;
                        HTuple	Transformation;
                        Hobject m_ShapeModelContoursxld,ContourTrans;


                        set_color(m_Windowvisionid,"red");
                        set_draw(m_Windowvisionid,"margin");

                        if(	htScore[0].D()<minscore11)

                        {

                            AfxMessageBox( "查找失败！" );


                        }

                        get_shape_model_contours(&m_ShapeModelContoursxld,ShapeModel12,1);

                        {vector_angle_to_rigid(0,0,0,htRowCheck[0].D(),htColumnCheck[0].D(),htAngleCheck[0].D(),&Transformation);}
                        affine_trans_contour_xld(m_ShapeModelContoursxld,&ContourTrans,Transformation);//,"false");

                        disp_obj(ContourTrans,m_Windowvisionid);

                        model12xtemp=htColumnCheck[0].D();
                        model12ytemp=htRowCheck[0].D();
                        set_color(m_Windowvisionid,"green");
                        disp_obj(modelroi,m_Windowvisionid);
                        disp_cross(m_Windowvisionid,model12xtemp,model12ytemp,40,0);


                    }
                    catch (HException &except)
                    {
                        error_num = except.err;
                        AfxMessageBox( "查找失败！" );
                        return ;

                    }
                }

            }

            if((modalselect==2)&&(cameraselect==0))

            {
                Herror error_num ;

                double row,column;


                try
                {
                    set_shape_model_param( ShapeModel21,"timeout",3000);
                    Hobject modelroi;
                    Hobject roiimage;
                    roiimage=Image1;

                    find_shape_model(roiimage, ShapeModel21,-0.5, 1.0, minscore11, 0, 0,"interpolation",
                            0,0.9,&htRowCheck,&htColumnCheck,&htAngleCheck,&htScore);

                    tuple_length(htRowCheck,&Countregion);  

                    disp_obj(Image1,m_Windowvisionid);
                    HTuple	Transformation;
                    Hobject m_ShapeModelContoursxld,ContourTrans;

                    set_color(m_Windowvisionid,"red");
                    set_draw(m_Windowvisionid,"margin");

                    for(int i=0;i<Countregion[0].D();i++)

                    {
                        if(	htScore[i].D()<minscore21)

                        {

                            AfxMessageBox( "查找失败！" );


                        }

                        get_shape_model_contours(&m_ShapeModelContoursxld,ShapeModel21,1);

                        {vector_angle_to_rigid(0,0,0,htRowCheck[i].D(),htColumnCheck[i].D(),htAngleCheck[i].D(),&Transformation);}
                        affine_trans_contour_xld(m_ShapeModelContoursxld,&ContourTrans,Transformation);//,"false");

                        disp_obj(ContourTrans,m_Windowvisionid);

                        remodel1xtemp[i]=htColumnCheck[i].D();
                        remodel1ytemp[i]=htRowCheck[i].D();

                        set_color(m_Windowvisionid,"green");
                        //disp_line(m_Windowvisionid,model21ytemp,model21xtemp,model22y,model22x);
                        disp_obj(modelroi,m_Windowvisionid);
                        disp_cross(m_Windowvisionid,remodel1ytemp[i],remodel1xtemp[i],40,0);
                    }
                    for(int i=0;i<Countregion[0].D();i++) 
                    {
                        if(i<1)
                        {
                            {gen_rectangle1(&modelroi,htRowCheck[i].D()-model21halfx-searchrange,htColumnCheck[i].D()-model21halfy-searchrange,htRowCheck[i].D()+model21halfx+searchrange,htColumnCheck[i].D()+model21halfy+searchrange);}
                            reduce_domain(Image1,modelroi,&roiimages);
                        }
                        if(i>=1)
                        {
                            {gen_rectangle1(&modelroi,htRowCheck[i].D()-model21halfx-searchrange,htColumnCheck[i].D()-model21halfy-searchrange,htRowCheck[i].D()+model21halfx+searchrange,htColumnCheck[i].D()+model21halfy+searchrange);}
                            reduce_domain(Image1,modelroi,&roiimage);
                            concat_obj(roiimage,roiimages,&roiimages);
                        }

                    }

                    sort_region(roiimages, &sortroiimages, "character", "true", "row");
                    Regiontemp=sortroiimages;
                    area_center(sortroiimages, &imagesArea, &imagesRow, &imagesColumn);
                    for(int i=0;i<Countregion[0].D();i++)
                    {
                        remodel1xtemp[i]=imagesColumn[i].D();
                        remodel1ytemp[i]=imagesRow[i].D();
                    }
                    modelcounttemp=Countregion[0].D();

                    for(int i=0;i<Countregion[0].D();i++) 
                    {						
                        {gen_rectangle1(&modelroi,imagesRow[i].D()-model21halfx-searchrange,imagesColumn[i].D()-model21halfy-searchrange,imagesRow[i].D()+model21halfx+searchrange,imagesColumn[i].D()+model21halfy+searchrange);}
                        disp_obj(modelroi,m_Windowvisionid);					
                    }
                }
                catch (HException &except)
                {
                    error_num = except.err;
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
                    set_shape_model_param(ShapeModel22,"timeout",3000);
                    Hobject modelroi;
                    Hobject roiimage;

                    /*gen_rectangle1(&modelroi,visionx-model22halfx-searchrange2,0,visionx+model22halfx+searchrange2,2592);
                      reduce_domain(Image1,modelroi,&roiimage);*/
                    roiimage=Image1;
                    find_shape_model(roiimage,ShapeModel22 ,-0.5, 1.0, minscore11, 0, 0,"interpolation",
                            0,0.9,&htRowCheck,&htColumnCheck,&htAngleCheck,&htScore);

                    tuple_length(htRowCheck,&Countregion);

                    disp_obj(Image1,m_Windowvisionid);
                    HTuple	Transformation;
                    Hobject m_ShapeModelContoursxld,ContourTrans;

                    set_color(m_Windowvisionid,"red");
                    set_draw(m_Windowvisionid,"margin");

                    for(int i=0;i<Countregion[0].D();i++)

                    {
                        if(	htScore[i].D()<minscore21)

                        {

                            AfxMessageBox( "查找失败！" );


                        }

                        get_shape_model_contours(&m_ShapeModelContoursxld,ShapeModel22,1);

                        {vector_angle_to_rigid(0,0,0,htRowCheck[i].D(),htColumnCheck[i].D(),htAngleCheck[i].D(),&Transformation);}
                        affine_trans_contour_xld(m_ShapeModelContoursxld,&ContourTrans,Transformation);//,"false");

                        disp_obj(ContourTrans,m_Windowvisionid);

                        remodel2xtemp[i]=htColumnCheck[i].D();
                        remodel2ytemp[i]=htRowCheck[i].D();


                        set_color(m_Windowvisionid,"green");
                        disp_obj(modelroi,m_Windowvisionid);
                        disp_cross(m_Windowvisionid,remodel2ytemp[i],remodel2xtemp[i],40,0);						
                    }

                    for(int i=0;i<Countregion[0].D();i++) 
                    {
                        if(i<1)
                        {
                            {gen_rectangle1(&modelroi,htRowCheck[i].D()-model22halfx-searchrange,htColumnCheck[i].D()-model22halfy-searchrange,htRowCheck[i].D()+model22halfx+searchrange,htColumnCheck[i].D()+model22halfy+searchrange);}
                            reduce_domain(Image1,modelroi,&roiimages);
                        }
                        if(i>=1)
                        {
                            {gen_rectangle1(&modelroi,htRowCheck[i].D()-model22halfx-searchrange,htColumnCheck[i].D()-model22halfy-searchrange,htRowCheck[i].D()+model22halfx+searchrange,htColumnCheck[i].D()+model22halfy+searchrange);}
                            reduce_domain(Image1,modelroi,&roiimage);
                            concat_obj(roiimage,roiimages,&roiimages);
                        }

                    }

                    sort_region(roiimages, &sortroiimages, "character", "true", "row");
                    Regiontemp=sortroiimages;
                    area_center(sortroiimages, &imagesArea, &imagesRow, &imagesColumn);
                    for(int i=0;i<Countregion[0].D();i++)
                    {
                        remodel2xtemp[i]=imagesColumn[i].D();
                        remodel2ytemp[i]=imagesRow[i].D();
                    }
                    modelcounttemp=Countregion[0].D();
                    for(int i=0;i<Countregion[0].D();i++) 
                    {						
                        {gen_rectangle1(&modelroi,imagesRow[i].D()-model22halfx-searchrange,imagesColumn[i].D()-model22halfy-searchrange,imagesRow[i].D()+model22halfx+searchrange,imagesColumn[i].D()+model22halfy+searchrange);}
                        disp_obj(modelroi,m_Windowvisionid);					
                    }
                }

                catch (HException &except)
                {
                    error_num = except.err;
                    AfxMessageBox( "查找失败！" );
                    return ;

                }
            }      





        }  

        //EndTime();		// 结束测试时间
        //   if(repeat==1)
        //{
        //   m_list1.DeleteAllItems();
        //if( htScore[0].D() >0 ) 
        //{
        //	char s[100];
        //	int i, item;
        //	for( i = 0; i < 3; i ++ ) 
        //	{
        //		item = m_list1.InsertItem( i, "" );
        //		sprintf( s, "%d", i + 1 );
        //		m_list1.SetItemText( item, 0, s );
        //		sprintf( s, "%0.3f", htScore[i].D() );
        //		m_list1.SetItemText( item, 1, s );
        //		sprintf( s, "%f", htAngleCheck[i].D() );
        //		m_list1.SetItemText( item, 2, s );
        //	//	sprintf( s, "%0.2f", pMatchArray[i].Scale );
        //	//	m_list1.SetItemText( item, 3, s );
        //		sprintf( s, "%0.2f", htRowCheck[i].D() );
        //		m_list1.SetItemText( item, 3, s );
        //		sprintf( s, "%0.2f",htColumnCheck[i].D());
        //		m_list1.SetItemText( item, 4, s );
        //	}
        //} 
        //}
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
            if(model1xtemp[0]!=0)
            {
                if(nRes == IDNO)
                {
                    {
                        model11x=model11xtemp;
                        model11y=model11ytemp;
                    }
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

            CFileDialog fdR( FALSE, "reg",currentregionsname1, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"*.reg");
            fdR.m_ofn.lpstrTitle = "保存Region文件";
            //	if( fd.DoModal() == IDOK ) 
            {
                //if( m_ModelEditDlg.model11 ) 

                //	currentmodelname=fd.GetPathName();
                CString writepathname=fdR.GetPathName();
                //HTuple nametemp;
                //nametemp=writepathname;
                Herror error_num;

                try
                { write_region(Regiontemp,(HTuple)writepathname);}
                catch (HException &except)
                {
                    error_num = except.err;
                    AfxMessageBox("保存Region失败！");
                    return;
                }
                Regions1=Regiontemp;
            }


        }
        if((modalselect==1)&&(cameraselect==0))
        {
            if(model2xtemp[0]!=0)
            {
                /*if(nRes == IDNO)
                  {
                  for( int i = 0; i < 3; i ++ ) 
                  {
                  model2x[i]=model2xtemp[i];
                  model2y[i]=model2ytemp[i];

                  }
                  }*/

                if(nRes == IDNO)
                {
                    {
                        model12x=model12xtemp;
                        model12y=model12ytemp;
                    }
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

            CFileDialog fdR( FALSE, "reg",currentregionsname2, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"*.reg");
            fdR.m_ofn.lpstrTitle = "保存Region文件";
            //	if( fd.DoModal() == IDOK ) 
            {
                //if( m_ModelEditDlg.model11 ) 

                //	currentmodelname=fd.GetPathName();
                CString writepathname=fdR.GetPathName();
                //HTuple nametemp;
                //nametemp=writepathname;
                Herror error_num;

                try
                { write_region(Regiontemp,(HTuple)writepathname);}
                catch (HException &except)
                {
                    error_num = except.err;
                    AfxMessageBox("保存Region失败！");
                    return;
                }
                Regions2=Regiontemp;
            }

        }


        if((modalselect==2)&&(cameraselect==0))
        {
            if(remodel1xtemp[0]!=0)
            {
                if(nRes == IDNO)
                {
                    for( int i = 0; i < modelcounttemp; i ++ ) 
                    {
                        remodel1x[i]=remodel1xtemp[i];
                        remodel1y[i]=remodel1ytemp[i];
                        comno=modelcounttemp;

                    }
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

            CFileDialog fdR( FALSE, "reg",currentregionsname3, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"*.reg");
            fdR.m_ofn.lpstrTitle = "保存Region文件";
            //	if( fd.DoModal() == IDOK ) 
            {
                //if( m_ModelEditDlg.model11 ) 

                //	currentmodelname=fd.GetPathName();
                CString writepathname=fdR.GetPathName();
                //HTuple nametemp;
                //nametemp=writepathname;
                Herror error_num;

                try
                { write_region(Regiontemp,(HTuple)writepathname);}
                catch (HException &except)
                {
                    error_num = except.err;
                    AfxMessageBox("保存Region失败！");
                    return;
                }
                Regions3=Regiontemp;
            }
        }


        if((modalselect==3)&&(cameraselect==0))
        {
            if(remodel2xtemp[0]!=0)
            {
                if(nRes == IDNO)
                {
                    for( int i = 0; i < modelcounttemp; i ++ ) 
                    {
                        remodel2x[i]=remodel2xtemp[i];
                        remodel2y[i]=remodel2ytemp[i];
                        comno=modelcounttemp;

                    }
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
            CFileDialog fdR( FALSE, "reg",currentregionsname4, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"*.reg");
            fdR.m_ofn.lpstrTitle = "保存Region文件";
            //	if( fd.DoModal() == IDOK ) 
            {
                //if( m_ModelEditDlg.model11 ) 

                //	currentmodelname=fd.GetPathName();
                CString writepathname=fdR.GetPathName();
                //HTuple nametemp;
                //nametemp=writepathname;
                Herror error_num;

                try
                { write_region(Regiontemp,(HTuple)writepathname);}
                catch (HException &except)
                {
                    error_num = except.err;
                    AfxMessageBox("保存Region失败！");
                    return;
                }
                Regions4=Regiontemp;
            }
        }

        AfxMessageBox("确认用当前料片学习另一模版！");

    }





    BOOL CVisionSetDlg::DestroyWindow() 
    {
        // TODO: Add your specialized code here and/or call the base class
        //	ReleaseDevice();
        // KillTimer(1);
        InitDeviceFunction();



        visionphoto=false;

        m_bStartCapture=FALSE;


        CFile currentphotonew;
        currentphotonew.Open(currentphotoname,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
        CArchive currentphotoarnew(&currentphotonew,CArchive::store);


        currentphotoarnew<<shutter<<bright<<gain<<shutter2<<shutter3<<shutter4<<shutter5<<gain2<<contrast1<<contrast2<<model1x[0]<<model1x[1]<<model1x[2]<<model1x[3]<<model1x[4]<<model1x[5]<<model1y[0]<<model1y[1]<<model1y[2]<<model1y[3]<<model1y[4]<<model1y[5]<<model2x[0]<<model2x[1]<<model2x[2]<<model2x[3]<<model2x[4]<<model2x[5]<<model2y[0]<<model2y[1]<<model2y[2]<<model2y[3]<<model2y[4]<<model2y[5]
            <<model11halfx<<model11halfy<<model12halfx<<model12halfy<<model21halfx<<model21halfy<<model22halfx<<model22halfy<<modalorg11<<modalorg12<<modalorg21<<modalorg22
            <<remodel1x[0]<<remodel1x[1]<<remodel1x[2]<<remodel1x[3]<<remodel1x[4]<<remodel1x[5]<<remodel1y[0]<<remodel1y[1]<<remodel1y[2]<<remodel1y[3]<<remodel1y[4]<<remodel1y[5]<<remodel2x[0]<<remodel2x[1]<<remodel2x[2]<<remodel2x[3]<<remodel2x[4]<<remodel2x[5]<<remodel2y[0]<<remodel2y[1]<<remodel2y[2]<<remodel2y[3]<<remodel2y[4]<<remodel2y[5];

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


    void CVisionSetDlg::OnSetfocusEditShutter() 
    {
        // TODO: Add your control notification handler code here
        CWnd * cwnd=GetDlgItem(IDC_EDIT_SHUTTER);
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
        GetDlgItem(IDC_EDIT_SHUTTER)->PostMessage(EM_SETSEL,0,-1);

    }

    void CVisionSetDlg::OnKillfocusEditShutter() 
    {
        // TODO: Add your control notification handler code here
        HWND h=::FindWindow(NULL,"屏幕键盘");
        if(h!=NULL)
        {::SendMessage(h,WM_CLOSE,0,0);}
        UpdateData(true);
        if((m_shutter>3000)||(m_shutter<0))
        {
            MessageBox("输入数值在0和3000之间");
            if(m_shutter>3000)
            {
                m_shutter=3000;
            }
            if(m_shutter<0)
            {
                m_shutter=0;
            }
            UpdateData(false);

        }
        if((modalselect==0)&&(cameraselect==0))
        {
            shutter=m_shutter;

        }
        if((modalselect==1)&&(cameraselect==0))

        {
            shutter=m_shutter;

        }
        if((modalselect==2)&&(cameraselect==0))
        {
            shutter=m_shutter;

        }
        if((modalselect==3)&&(cameraselect==0))

        {
            shutter=m_shutter;

        }



        // TODO: Add your control notification handler code here
        //获取当前设备所有支持的属性

        // Get supported property items.
        if(cameraselect==0)
        {
            CameraSetAeState(camera1,false);
            CameraSetExposureTime(camera1, shutter*10000);


        }

        if(cameraselect==1)
        {
            CameraSetAeState(camera2, false);
            CameraSetExposureTime(camera2, shutter3*10000);
        }





    }

    void CVisionSetDlg::OnKillfocusEditGain() 
    {
        // TODO: Add your control notification handler code here
        HWND h=::FindWindow(NULL,"屏幕键盘");
        if(h!=NULL)
        {::SendMessage(h,WM_CLOSE,0,0);}
        UpdateData(true);
        if((m_gain>8)||(m_gain<1))
        {
            MessageBox("输入数值在1和8之间");
            if(m_gain>8)
            {
                m_gain=8;
            }
            if(m_gain<1)
            {
                m_gain=1;
            }
            UpdateData(false);
        }


        // TODO: Add your control notification handler code here
        //获取当前设备所有支持的属性

        // Get supported property items.
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

    }

    void CVisionSetDlg::OnKillfocusEDITcontrast() 
    {
        HWND h=::FindWindow(NULL,"屏幕键盘");
        if(h!=NULL)
        {::SendMessage(h,WM_CLOSE,0,0);}
        UpdateData(true);
        if((m_contrast>200)||(m_contrast<0))
        {
            MessageBox("输入数值在0和200之间");
            if(m_contrast<0)
                m_contrast=0;
            if(m_contrast>200)
                m_contrast=200;
            UpdateData(false);
        }

        UpdateData(false);

        if((modalselect==0)&&(cameraselect==0))
        {
            contrast1=m_contrast;

        }
        if((modalselect==1)&&(cameraselect==0))

        {
            contrast1=m_contrast;

        }
        if((modalselect==2)&&(cameraselect==0))
        {
            contrast2=m_contrast;

        }
        if((modalselect==3)&&(cameraselect==0))

        {
            contrast2=m_contrast;

        }

        CameraSetContrast(camera1, contrast1);
        CameraSetContrast(camera2, contrast2);



    }

    void CVisionSetDlg::OnSetfocusEDITcontrast() 
    {


        // TODO: Add your control notification handler code here
        CWnd * cwnd=GetDlgItem(IDC_EDIT_contrast);
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
        GetDlgItem(IDC_EDIT_contrast)->PostMessage(EM_SETSEL,0,-1);

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

    void CVisionSetDlg::OnSetfocusEditGain() 
    {
        // TODO: Add your control notification handler code here
        CWnd * cwnd=GetDlgItem(IDC_EDIT_contrast);
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
        GetDlgItem(IDC_EDIT_contrast)->PostMessage(EM_SETSEL,0,-1);

    }


    void CVisionSetDlg::OnEnChangeEditGain()
    {
        // TODO:  如果该控件是 RICHEDIT 控件，它将不
        // 发送此通知，除非重写 CDialog::OnInitDialog()
        // 函数并调用 CRichEditCtrl().SetEventMask()，
        // 同时将 ENM_CHANGE 标志“或”运算到掩码中。

        // TODO:  在此添加控件通知处理程序代码
    }


    void CVisionSetDlg::OnEnChangeEditcontrast()
    {
        // TODO:  如果该控件是 RICHEDIT 控件，它将不
        // 发送此通知，除非重写 CDialog::OnInitDialog()
        // 函数并调用 CRichEditCtrl().SetEventMask()，
        // 同时将 ENM_CHANGE 标志“或”运算到掩码中。

        // TODO:  在此添加控件通知处理程序代码
    }


    void CVisionSetDlg::OnEnChangeEditShutter()
    {
        // TODO:  如果该控件是 RICHEDIT 控件，它将不
        // 发送此通知，除非重写 CDialog::OnInitDialog()
        // 函数并调用 CRichEditCtrl().SetEventMask()，
        // 同时将 ENM_CHANGE 标志“或”运算到掩码中。

        // TODO:  在此添加控件通知处理程序代码
    }
