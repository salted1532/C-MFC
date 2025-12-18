// SettingDlg.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplication2.h"
#include "SettingDlg.h"
#include "afxdialogex.h"


// SettingDlg 대화 상자

IMPLEMENT_DYNAMIC(SettingDlg, CDialog)

SettingDlg::SettingDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, vnum(0)
{

}

SettingDlg::~SettingDlg()
{
}

void SettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, vnum);
}


BEGIN_MESSAGE_MAP(SettingDlg, CDialog)
END_MESSAGE_MAP()


// SettingDlg 메시지 처리기
