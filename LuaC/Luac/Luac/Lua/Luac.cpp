/**===File Commentary=======================================*/
/**
 *	@file	Luac.cpp
 *
 *	@brief	Lua���W���[��
 *
 *	@author	KORYUOH
 *
 *	@date	2013/09/15
 */
/**===File Include=========================================*/
#include	<Lua/Luac.h>
#include	<iostream>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	<�v��>
 *	@param[in]	<����>
 *	@attention	<���ӏ���>
 *	@note	<��������>
 *	@author	<��Җ�>
 *	@return	<�߂�l>
 */
/**========================================================*/
Luac::Luac(const std::string& luaPath)
	:mLuaPath(luaPath)
	,mLua(luaL_newstate())
{
	luainit();
}
/**========================================================*/
/**
 *	@brief	<�v��>
 *	@param[in]	<����>
 *	@attention	<���ӏ���>
 *	@note	<��������>
 *	@author	<��Җ�>
 *	@return	<�߂�l>
 */
/**========================================================*/
Luac::~Luac(){
	lua_close(mLua);
}
void Luac::luainit(){
	// Lua�W���֐����g��
	luaL_openlibs(mLua);
	if(luaL_loadfile(mLua, mLuaPath.c_str())){
		std::string error = lua_tostring(mLua,-1);
		perror(("init:"+error).c_str());
	}
}
void Luac::run(){
//	luaL_openlibs(mLua);
	if(luaL_loadfile(mLua, mLuaPath.c_str())||lua_pcall(mLua,0,0,0)){
		std::string error = lua_tostring(mLua,-1);
		perror(("init:"+error).c_str());
	}
}

//template<typename Ty>
void Luac::CallFunc(const std::string& funcName){
	lua_getglobal(mLua, funcName.c_str());
	 if(lua_pcall(mLua, 0, 0, 0)) {
		std::string error = lua_tostring(mLua,-1);
		perror((funcName+" EXEC:"+error).c_str());
    }
}
/**===End Of File==========================================*/