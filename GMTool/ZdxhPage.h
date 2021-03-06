/////////////////////////////////////////////////////////////////////////////
// Name:        ZdxhPage.h
// Created:     2009-02-04
// Info:		自动循环公告页面
/////////////////////////////////////////////////////////////////////////////

#ifndef ZDXHPAGE_H_
#define ZDXHPAGE_H_
#include "UserFrame.h"
#include "../ServerDefine/gm_tool_define.h"

class MyListCtrl;
class ZdxhPage : public wxPanel, public UserFrame
{
public:
	ZdxhPage(wxBookCtrlBase *book, const wxString& label);

	const wxString& GetLabel() { return m_label; }

	void InsertShowItem(tstring, tstring, tstring, EColorType, tagDWORDTime, tstring, tstring, tstring);
	void ClearShowItem();
	void ZdxhOperationStatus(BOOL);

	void SetMyFrame(MyFrame* frame) { m_pMyFrame = frame; }

	void IssueZdxhPage(wxCommandEvent& event);
	void CancelZdxh(wxCommandEvent& event);

	//DWORD OnZdxhPageEvent(tagUserEvent* pGameEvent);

	void OnColorType(wxCommandEvent& event);

	void ClearCtrlText();
private:
	wxString		m_label;
	wxButton*		m_btnAdd_zdxh;			//添加自动循环公告
	wxComboBox*		m_combobox_color_zdxh;	//自动循环公告颜色
	MyListCtrl*     m_lctrl_zdxh;			//自动循环公告状态
	wxTextCtrl*		m_text_zdxh;			//自动循环公告内容
	wxTextCtrl*		m_text_IssueTimeYear;
	wxTextCtrl*		m_text_month;
	wxTextCtrl*		m_text_day;
	wxTextCtrl*		m_text_hour;
	wxTextCtrl*		m_text_min;
	wxTextCtrl*		m_text_interval;		//发布间隔
	wxTextCtrl*		m_text_loop;			//循环时间
	wxTextCtrl*		m_text_num;				//循环次数
	wxButton*		m_btnAdd_cancelzdxh;	//取消已设定的跑马灯
	MyFrame*		m_pMyFrame;

	DECLARE_EVENT_TABLE()
};



#endif /* ZDXHPAGE_H_ */