/**===File Commentary=======================================*/
/**
 *	@file	Luac.h
 *
 *	@brief	Luaモジュール
 *
 *	@author	KORYUOH
 *
 *	@date	2013/09/15
 */
/**===Include Guard========================================*/
#ifndef	_LUAC_H_
#define	_LUAC_H_

#ifdef _WIN32
#pragma once
#endif
/**===File Include=========================================*/
#include	<string>
#include	<lua.hpp>
#pragma comment(lib, "lua52.lib")
/**===Class Definition=====================================*/
class Luac{
public:
	typedef lua_State* LUA_STATE;
	typedef luaL_Reg LUA_LIBTABLE;
	typedef int LUA_TYPES;
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	luaファイル
	 */
	Luac(const std::string& luaPath);
	/**
	 *	@brief	Luaファイル実行
	 */
	void run();
	/**
	 *	@brief	関数呼び出し
	 *	@note	テンプレート
	 *	@return	指定タイプ
	 */
//	template<typename Ty>
	void CallFunc(const std::string& funcName);
	/**
	 *	@brief	Luaのダンプコールバック
	 *	@note	テンプレート
	 */
	static void Dump(LUA_STATE lua);
	/**
	 *	@brief	Luaのダンプ
	 */
	void Dump();
	/**
	 *	@brief	関数を設定する
	 *	@param[in]	Luaでの関数名
	 *	@param[in]	追加する関数のポインタ
	 */
	void setFunction(const std::string& funcName,void* func);
	/**
	 *	@brief	Luaにクラス追加
	 *	@note	テンプレート
	 */
	void addClass(const std::string&className, const static struct luaL_Reg *classdef);
	/**
	 *	@brief	仮想デストラクタ
	 */
	virtual ~Luac();
private:
	/**
	 *	@brief	Luaの初期化
	 */
	void luainit();
private:
	/**	メンバー変数*/
	const std::string	mLuaPath;
	LUA_STATE	mLua;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/