//-------------------------------------------------------------------------------
// Copyright (c) 2004 TENGWU Entertainment All rights reserved.
// filename: vip_netbar_define.h
// author: xlguo
// actor:
// data: 2009-8-3
// last:
// brief: 金牌网吧服务器定义
//-------------------------------------------------------------------------------
#pragma once
#pragma pack(push,1)

//-------------------------------------------------------------------------
// 数据库存储账号结构
//-------------------------------------------------------------------------
struct tagDBVNBPlayers
{
	INT		nHisPlayers;
	INT		nTodaysPlayers;
	DWORD	dwAccountIDs[1];
};

//-------------------------------------------------------------------------
// 金牌网吧礼品原型
//-------------------------------------------------------------------------
struct tagVNBGiftProto
{
	DWORD	dwID;
	DWORD	dwItemTypeID;
	INT		nNum;
};

//-------------------------------------------------------------------------
// 金牌网吧装备原型
//-------------------------------------------------------------------------
struct tagVNBEquipProto
{
	DWORD	dwID;
	DWORD	dwEquipTypeID;
	INT		nQuality;
};

//-------------------------------------------------------------------------
// 金牌网吧结构
//-------------------------------------------------------------------------
struct tagVipNetBar
{
	DWORD	dwID;
	TCHAR	szName[X_SHORT_NAME];
	INT		nPlayerNum;
	DWORD	dwBuffID;		// 金牌网吧登录，就有的持续时间8小时
	DWORD	dwInstBuffID;	// 进入副本才增加的buff

	VOID	OnPlayerLogin(){++nPlayerNum;}
	VOID	OnPlayerLogout(){--nPlayerNum;}

};

//-------------------------------------------------------------------------
// 网吧最大ip段数目
//-------------------------------------------------------------------------
const INT MAX_VNB_IP_NUM	= 5;

#pragma pack(pop)