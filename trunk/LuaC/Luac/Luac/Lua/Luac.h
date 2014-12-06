/**===File Commentary=======================================*/
/**
 *	@file	Luac.h
 *
 *	@brief	Lua���W���[��
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
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	lua�t�@�C��
	 */
	Luac(const std::string& luaPath);
	/**
	*	@brief	�R���X�g���N�^
	*/
	Luac();
	/**
	 *	@brief ���������J�n
	 *	@param[in]	Lua�t�@�C���p�X
	 *	@note �񐄏��A�R���X�g���N�^���g���Ăق���
	 */
	void Initialize(const std::string& luapath);
	/**
	 *	@brief	Lua�t�@�C�����s
	 */
	void run();
	/**
	 *	@brief	�֐��Ăяo��
	 */
//	template<typename Ty>
	void CallFunc(const std::string& funcName);
	/**
	 *	@brief	�֐��Ăяo������
	 *	@param[in]	�֐���
	 *	@note	���̌�ɗ^����������X�^�b�N�ɂ�
	 */
	void ReadyFunc(const std::string& funcName);
	/**
	*	@brief	�֐��Ăяo��
	*/
	void CallFunc();
	/**
	 *	@brief	Lua�̃_���v�R�[���o�b�N
	 *	@note	�e���v���[�g
	 */
	static void Dump(LUA_STATE lua);
	/**
	 *	@brief	Lua�̃_���v
	 */
	void Dump();
	/**
	 *	@brief	�֐���ݒ肷��
	 *	@param[in]	Lua�ł̊֐���
	 *	@param[in]	�ǉ�����֐��̃|�C���^
	 */
	void setFunction(const std::string& funcName,void* func);
	/**
	 *	@brief	Lua�ɃN���X�ǉ�
	 *	@note	�e���v���[�g
	 */
	void addClass(const std::string&className, const static struct luaL_Reg *classdef);
	/**
	 *	@brief	����������Ă��邩�H
	 *	@return	���������
	 */
	bool isInitialized()const{ return mInitialized;}


	void SetInt(int arg);
	void SetFloat(float arg);
	void SetPtr(void* p);
	void SetStr(const char* str);
	void SetStr(const std::string& str);
	void SetNil();
	
	/**
	 *	@brief	���z�f�X�g���N�^
	 */
	virtual ~Luac();
private:
	/**
	 *	@brief	Lua�̏�����
	 */
	void luainit();
private:
	/**	�����o�[�ϐ�*/
	std::string	mLuaPath;
	LUA_STATE	mLua;
	bool	mInitialized;
	int mArgCnt;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/