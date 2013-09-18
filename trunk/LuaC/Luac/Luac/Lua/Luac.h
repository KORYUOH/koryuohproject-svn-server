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
/**===File Include=========================================*/
#include	<string>
#include	<lua.hpp>
#pragma comment(lib, "lua52.lib")
/**===Class Definition=====================================*/
class Luac{
public:
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	lua�t�@�C��
	 */
	Luac(const std::string& luaPath);
	/**
	 *	@brief	Lua�t�@�C�����s
	 */
	void run();
	/**
	 *	@brief	�֐��Ăяo��
	 *	@note	�e���v���[�g
	 *	@return	�w��^�C�v
	 */
//	template<typename Ty>
	void CallFunc(const std::string& funcName);
	/**
	 *	@brief	���z�f�X�g���N�^
	 */
	virtual ~Luac();
private:
	void luainit();
private:
	/**	�����o�[�ϐ�*/
	const std::string	mLuaPath;
	lua_State*	mLua;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/