/**===File Commentary=======================================*/
/**
 *	@file	Luabin.h
 *
 *	@brief	Luaバイナリ化モジュール
 *
 *	@author	KORYUOH
 *
 *	@date	2013/11/18
 */
/**===Include Guard========================================*/
#ifndef	_LUABIN_H_
#define	_LUABIN_H_
/**===File Include=========================================*/
#include	<string>
#include	<lua.hpp>
#pragma comment(lib, "lua52.lib")
/**===Class Definition=====================================*/
class Luabin{
public:
	typedef lua_State* LUA_STATE;
	Luabin(const std::string& luaPath);
	virtual ~Luabin(){};

private:
	void luainit();
	static const char * reader(FILE *fp, size_t *size);
	static int writer(const void *data, size_t size, FILE *fp);
private:
	const static int BUF_SIZE;
	LUA_STATE mLua;
	const std::string	mLuaPath;
	static char m_buf[BUF_SIZE];
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/