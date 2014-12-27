; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSpliterTreeView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "VipManage_Final.h"
LastPage=0

ClassCount=15
Class1=CVipManage_FinalApp
Class2=CVipManage_FinalDoc
Class3=CVipManage_FinalView
Class4=CMainFrame
Class7=CSpliterManageView
Class9=CSpliterChildFrame

ResourceCount=7
Resource1=IDD_ABOUTBOX
Resource2=IDD_DlgVipQuery
Resource3=IDR_MAINFRAME
Class10=CSpliterDoc
Resource4=IDD_Details
Class11=CSpliterTreeView
Class12=CSpliterView
Class5=CChildFrame
Class6=CAboutDlg
Class8=CSpliterDetailsView
Resource5=IDD_Manage
Class13=CQueryVip
Class14=VipRecord
Resource6=IDR_VIPMANTYPE
Class15=CChangeVip
Resource7=IDD_DlgChange

[CLS:CVipManage_FinalApp]
Type=0
HeaderFile=VipManage_Final.h
ImplementationFile=VipManage_Final.cpp
Filter=N

[CLS:CVipManage_FinalDoc]
Type=0
HeaderFile=VipManage_FinalDoc.h
ImplementationFile=VipManage_FinalDoc.cpp
Filter=N

[CLS:CVipManage_FinalView]
Type=0
HeaderFile=VipManage_FinalView.h
ImplementationFile=VipManage_FinalView.cpp
Filter=C
LastObject=CVipManage_FinalView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame
BaseClass=CMDIFrameWnd
VirtualFilter=fWC


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M
LastObject=CChildFrame


[CLS:CAboutDlg]
Type=0
HeaderFile=VipManage_Final.cpp
ImplementationFile=VipManage_Final.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_APP_ABOUT
CommandCount=8

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_VIPMANTYPE]
Type=1
Class=CVipManage_FinalView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_WINDOW_NEW
Command18=ID_WINDOW_CASCADE
Command19=ID_WINDOW_TILE_HORZ
Command20=ID_WINDOW_ARRANGE
Command21=ID_APP_ABOUT
Command22=ID_Menu_VipQuery
CommandCount=22

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_Manage]
Type=1
Class=CSpliterManageView
ControlCount=21
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_Edit_VipNumber,edit,1350631552
Control10=IDC_Edit_VipName,edit,1350631552
Control11=IDC_Edit_VipID,edit,1350631552
Control12=IDC_Combo_VipSex,combobox,1344340226
Control13=IDC_Datetimepick_VipJoin,SysDateTimePick32,1342242848
Control14=IDC_Edit_VipHobby,edit,1350631552
Control15=IDC_Combo_VipLevel,combobox,1344340226
Control16=IDC_Edit_VipRemarks,edit,1350631552
Control17=IDC_Btn_Add,button,1342242816
Control18=IDC_Btn_delete,button,1342242816
Control19=IDC_Btn_Change,button,1342242816
Control20=IDC_Pic_VipPic,static,1342177550
Control21=IDC_BtnShowAll,button,1342242816

[CLS:CSpliterManageView]
Type=0
HeaderFile=SpliterManageView.h
ImplementationFile=SpliterManageView.cpp
BaseClass=CFormView
Filter=D
LastObject=IDC_Pic_VipPic
VirtualFilter=VWC

[DLG:IDD_Details]
Type=1
Class=CSpliterDetailsView
ControlCount=1
Control1=IDC_List_VipList,SysListView32,1350631432

[CLS:CSpliterDetailsView]
Type=0
HeaderFile=SpliterDetailsView.h
ImplementationFile=SpliterDetailsView.cpp
BaseClass=CFormView
Filter=D
LastObject=CSpliterDetailsView
VirtualFilter=VWC

[CLS:CSpliterChildFrame]
Type=0
HeaderFile=SpliterChildFrame.h
ImplementationFile=SpliterChildFrame.cpp
BaseClass=CMDIChildWnd
Filter=M
LastObject=CSpliterChildFrame
VirtualFilter=mfWC

[CLS:CSpliterDoc]
Type=0
HeaderFile=SpliterDoc.h
ImplementationFile=SpliterDoc.cpp
BaseClass=CDocument
Filter=N

[CLS:CSpliterTreeView]
Type=0
HeaderFile=SpliterTreeView.h
ImplementationFile=SpliterTreeView.cpp
BaseClass=CTreeView
Filter=C
VirtualFilter=VWC
LastObject=CSpliterTreeView

[CLS:CSpliterView]
Type=0
HeaderFile=SpliterView.h
ImplementationFile=SpliterView.cpp
BaseClass=CView
Filter=C
LastObject=CSpliterView

[DLG:IDD_DlgVipQuery]
Type=1
Class=CQueryVip
ControlCount=23
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EditNumber,edit,1350631552
Control9=IDC_EditName,edit,1350631552
Control10=IDC_Edit_ID,edit,1350631552
Control11=IDC_ComboSex,combobox,1344340226
Control12=IDC_Datetimepick,SysDateTimePick32,1342242848
Control13=IDC_EditHobby,edit,1350631552
Control14=IDC_Combo_Level,combobox,1344340226
Control15=IDC_BtnQuery,button,1342242816
Control16=IDC_Btn_Cancel,button,1342242816
Control17=IDC_BtnSelectByNumber,button,1342242816
Control18=IDC_BtnSelectByName,button,1342242816
Control19=IDC_BtnSelectByID,button,1342242816
Control20=IDC_BtnSelectBySex,button,1342242816
Control21=IDC_BtnSelectByJoinTime,button,1342242816
Control22=IDC_BtnSelectByHobby,button,1342242816
Control23=IDC_BtnSelectByLevel,button,1342242816

[CLS:CQueryVip]
Type=0
HeaderFile=QueryVip.h
ImplementationFile=QueryVip.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CQueryVip

[CLS:VipRecord]
Type=0
HeaderFile=VipRecord.h
ImplementationFile=VipRecord.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=VipRecord

[DB:VipRecord]
DB=1
DBType=ODBC
ColumnCount=10
Column1=[id], 4, 4
Column2=[VipNumber], 4, 4
Column3=[VipName], -8, 20
Column4=[VipID], 4, 4
Column5=[VipSex], -8, 20
Column6=[VipJoinTime], 11, 16
Column7=[VipHobby], -8, 20
Column8=[VipLevel], -8, 20
Column9=[VipPicPath], -8, 100
Column10=[VipRemarks], -8, 100

[DLG:IDD_DlgChange]
Type=1
Class=CChangeVip
ControlCount=19
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_Edit_VipNumber_change,edit,1350631552
Control10=IDC_Edit_VipName_change,edit,1350631552
Control11=IDC_Edit_VipID_change,edit,1350633600
Control12=IDC_Combo_VipSex_change,combobox,1344340226
Control13=IDC_Datetimepick_VipJoin_change,SysDateTimePick32,1342242848
Control14=IDC_Edit_VipHobby_change,edit,1350631552
Control15=IDC_Edit_VipRemarks_change,edit,1350631552
Control16=IDC_Combo_VipLevel_change,combobox,1344340226
Control17=IDC_Btn_ChangeVip,button,1342242816
Control18=IDC_Pic_VipPicPath_change,static,1342177550
Control19=IDC_BtnCancel,button,1342242816

[CLS:CChangeVip]
Type=0
HeaderFile=ChangeVip.h
ImplementationFile=ChangeVip.cpp
BaseClass=CDialog
Filter=D
LastObject=CChangeVip
VirtualFilter=dWC

