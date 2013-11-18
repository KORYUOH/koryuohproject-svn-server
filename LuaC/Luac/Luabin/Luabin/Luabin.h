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
class Luabun{
public:
	typedef lua_State* LUA_STATE;
	Luabin();
	virtual ~Luabin(){};

private:
	void luainit();
	const char * reader(lua_State *L, FILE *fp, size_t *size);
	int writer(lua_State *ls, const void *data, size_t size, FILE *fp);
private:
	LUA_STATE mLua;
	const std::string	mLuaPath;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/