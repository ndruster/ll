#pragma once
#include "Render2D.h"
#include "RoleQuestFlag.h"
#include "RoleTitleFlag.h"
#include "RoleTitleProtoData.h"
struct tagPKStateStartCountDownEvent;



struct tagHeadTip
{
	enum ECityWarState
	{
		ECWS_NULL, 
		ECWS_Attack,
		ECWS_Defence
	};

	DWORD		roleID;
	tstring		strNameTip;			//显示的玩家的姓名
	tstring		strTitleTip;		//显示的玩家的称号 added by hyu
	tstring		strGuildTip;		//显示的玩家的帮派 added by hqzhang
	tstring		strVipNetBarTip;	//显示的玩家的金牌网吧名称 added by yfwang
    tstring     strSpouse;          //夫妻称谓 added by hyu
    Color4ub    spouseColor;        //夫妻称谓的颜色 added by hyu
	Vector3		scrPos;				//角色头顶屏幕坐标位置
	Vector3		worldPos;			//角色头顶的世界坐标
	Color4ub	txtNameColor;		//显示姓名的颜色
	Color4ub	txtTitleColor;		//显示称号的颜色 added by hyu
    BOOL        bPicTitle;          //是否是图片式称号
	EQuestFlag	qeustFlag;
	tstring		strResTex;			//称号贴图
    RECT        rcTitle;            //称号贴图的位置
	float		scale;
	RECT		rectName;
	BOOL		bPKMode;			// PK模式
	ECityWarState eCityWarState;	// 城战状态
	INT			nVIPLevel;			// VIP等级
	tstring		strResGodTex;		// 神职图片
	RECT		rcGodJob;
	tstring     strFamilyNameTip;	// 显示玩家家族名
	RECT		rectFamilyName;


	tagHeadTip(): roleID(GT_INVALID), eCityWarState(ECWS_NULL), bPicTitle(FALSE) ,nVIPLevel(0)
	{
	}

	tagHeadTip(const tagHeadTip& other)
	{
		Copy(other);
	}

	const tagHeadTip& operator = (const tagHeadTip& other)
	{
		if(this!=&other)
			Copy(other);
		return *this;
	}

private:
	void Copy(const tagHeadTip& other)
	{
		roleID		= other.roleID;
	}

};

class Role;
class RoleHeadTipsFrame :
	public GameFrame
{

public:
	RoleHeadTipsFrame(void);
	~RoleHeadTipsFrame(void);

	virtual BOOL Init(GameFrameMgr* pMgr, GameFrame* pFather, DWORD dwParam);
	virtual BOOL Destroy();
	virtual VOID Render3D();
	virtual VOID OnEvent(tagGameEvent* pEvent);
	virtual VOID Update();

	void Create();

	void SetIsShowHeadTips(BOOL bVal) { m_bShowTips = bVal; }

private:
	void ClearAllTips();
	void DrawAllRoleHeadTips();
	void UpdateRoleHeadTips();
	Color4ub GetRoleTipsColor(Role* pRole);
    const tstring GetRoleTitleTips(Role* pRole);
    BOOL IsRolePicTitle(Role* pRole);
    Color4ub GetRoleTitleColor(Role* pRole);
	const tstring GetRoleTitleIcon(Role* pRole);
	const tstring GetRoleGuildTips(Role* pRole);
	const tstring GetRoleVipNetBarTips( Role* pRole );
	const DWORD GetRoleHostilityTips( Role* pRole );
	const BOOL GetRolePKMode( Role* pRole );
    const tstring GetRoleSpouse(Role* pRole);
    Color4ub GetRoleSpouseColor(Role* pRole);
	const INT GetRoleVIPLevel(Role* pRole);
	const tstring GetRoleGodJobIcon(Role* pRole);
	//计算血条和真气条
	void UpdateLocalHPorMPProgress();
	void UpdateOtherHPorMPProgress();

	//血条和真气条
	DWORD OnKey(DWORD dwID, BOOL bDown);

private:
	TSFPTrunk<RoleHeadTipsFrame>	m_Trunk;
	TObjRef<GUISystem>				m_pSystem;
	TObjRef<Util>					m_pUtil;
	TObjRef<GUIRender>				m_pRender;
	TObjRef<GameInputMap>			m_pKeyMap;

	IDepthFont*						m_pFont;
	IDepthFont*						m_pFontTitle;		//称号使用
	IDepthFont*						m_pFmFont;			//家族使用
	tagGUIFont*						m_pTempFont;

	vector<tagHeadTip*>				m_vecTipsList;
	RoleQuestFlag					m_questFlag;
	RoleTitleFlag					m_titleFlag;		//称号贴图
	ResTexture*						m_pResHP;
	ResTexture*						m_pResMP;

	BOOL							m_bShowTips;
	BOOL							m_bShowHPorMP;

	enum EHostilityValue
	{
		EHostility_Start = -1,
		EHostility_Zero,
		EHostility_One,
		EHostility_Two,
		EHostility_Three,
		EHostility_Four,
		EHostility_Five,
		EHostility_Six,
		EHostility_Seven,
		EHostility_Eight,
		EHostility_Nine,
		EHostility_End,
	};
};