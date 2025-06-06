//========================================================
//
//    Copyright (c) 2008,欢乐连线工作室
//    All rights reserved.
//
//    文件名称：
//    摘    要：装备武器合成逻辑判断
//    
//    当前版本：1.00
//    作    者：赖滔
//    完成日期：2008-3-20
//
//========================================================
#ifndef _EQUIPFORGE_H_
#define _EQUIPFORGE_H_

#include "Item.h"
#include "..\ErrorMessage.h"

struct EquipForgeBase
{
	EquipForgeBase():Probability(-1),NextID(-1),MaterialType(-1){}
	int	NextID;
	int BadID;
	int Probability;            //成功概率
	int MaterialType;
	vector<int> BaseProyAdd;	//基础属性提升成功率
	vector<int> AppendProyAdd;	//附加属性提升成功率
	int         MaterialProyAdd;//成功率加成

	vector<int> Amoney;
	vector<int> Bmoney;
	vector<int> Cmoney;
};

struct EquipForgeAppend 
{
	EquipForgeAppend():Probability(-1),MaterialCharacter(-1){}
	int Probability;
	int MaterialCharacter;
};

class EquipForge
{
public:

	EquipForge();
	~EquipForge();

	/* --------------------------------------------------------------------
	功能：清除合成的缓存数据对象
	参数：
	返回：
	备注：
	------------------------------------------------------------------------ */
	void Clear();

	/* --------------------------------------------------------------------
	功能：合成对象(打造,宝石合成,装备合成)
	参数：type 区分合成类型
	返回：
	备注：
	------------------------------------------------------------------------ */
	eError Forge(int type);

	/* --------------------------------------------------------------------
	功能：设置合成对象数据(宝石类,装备类)
	参数：index 第几号包 
	num   包的第几个位置
	type  应用第几号数据对象
	返回：
	备注：
	------------------------------------------------------------------------ */
	eError SetEquip(Item* equip , int index , int num,int type);
	eError SetMaterial(Item* material , int index , int num,int type);

	/* --------------------------------------------------------------------
	功能：清除缓存数据对象
	参数：
	返回：
	备注：
	------------------------------------------------------------------------ */
	eError ClearEquip();
	eError ClearMaterial();
	eError ClearForge();

	void Init(CPlayer* player);

protected:
private:

	/* --------------------------------------------------------------------
	功能：打造升级新ID装备
	参数：
	返回：
	备注：
	------------------------------------------------------------------------ */
	void ForgeBase();

	/* --------------------------------------------------------------------
	功能：打造升级装备基本属性
	参数：
	返回：
	备注：
	------------------------------------------------------------------------ */
	void ForgeBaseData();

	/* --------------------------------------------------------------------
	功能：打造升级装备附加属性
	参数：
	返回：
	备注：
	------------------------------------------------------------------------ */
	void ForgeAppend();

	/* --------------------------------------------------------------------
	功能：合成装备新属性
	参数：
	返回：
	备注：
	------------------------------------------------------------------------ */
	void ForgeEquip();

	/* --------------------------------------------------------------------
	功能：合成新宝石
	参数：
	返回：
	备注：
	------------------------------------------------------------------------ */
	void ForgeMaterial();

	Item* m_Equip[6];		//主副合成装备
	Item* m_Material[6];	//abc类宝石

	CPlayer* m_Player;
};

#endif
