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
#include	<iomanip>
/**===Class Implementation=================================*/
/**
static const struct luaL_Reg myMathLib [] = {
	{"add", l_add},
		{"mul", l_mul},
		{NULL, NULL} //�Ō�͕K��NULL�̃y�A
}
���̌��
	luaL_register(L, "myMath", myMathLib);���ēo�^�����
	lua�̂Ȃ���
	myMath.add(1,2)
	�Ƃ��Ŏg����悤�ɂȂ�
**/
/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	Lua�t�@�C���p�X
 */
/**========================================================*/
Luac::Luac(const std::string& luaPath)
	: mLuaPath(luaPath)
	, mLua(luaL_newstate())
	, mInitialized(true)
	, mArgCnt(0)
{
	luainit();
}
/**========================================================*/
/**
*	@brief	�R���X�g���N�^
*	@param[in]	Lua�t�@�C���p�X
*/
/**========================================================*/
Luac::Luac()
	: mLuaPath("")
	, mLua(nullptr)
	, mInitialized(false)
	, mArgCnt(0)
{
}
/**========================================================*/
/**
*	@brief	������
*	@param[in]	Lua�t�@�C���p�X
*	@note	�{���̓R���X�g���N�^�ŌĂ΂��
*/
/**========================================================*/
void Luac::Initialize(const std::string& luapath)
{
	if (mInitialized)
	{
		lua_close(mLua);
		mInitialized = false;
	}

	mLuaPath = luapath;
	mLua = luaL_newstate();
	mInitialized = true;
	mArgCnt = 0;

	luainit();

}
/**========================================================*/
/**
 *	@brief	Lua�Ɋ֐���ǉ�
 *	@param[in]	�ǉ��֐���
 *	@param[in]	�R�[���o�b�N�֐�
 *	@note	�ǉ��̊֐��͊���̌^�̂�
 */
/**========================================================*/
//*template<typename Ty>
void Luac::setFunction(const std::string& funcName,void* function){
	lua_register(mLua,funcName.c_str(),static_cast<lua_CFunction>(function));
}
/**========================================================*/
/**
*	@brief	Lua�Ɋ֐���ǉ�
*	@param[in]	�ǉ��֐���
*	@param[in]	�R�[���o�b�N�֐�
*	@note	�ǉ��̊֐��͊���̌^�̂�
*/
/**========================================================*/
void Luac::addClass(const std::string& className , const static struct luaL_Reg *classdef)
{
	luaL_newlib(mLua, classdef);
	lua_setglobal(mLua, className.c_str());
}
/**========================================================*/
/**
 *	@brief	Lua�_���v�̐���
 *	@param[in]	Lua�X�e�[�g
 */
/**========================================================*/
void Luac::Dump(LUA_STATE lua){
	int max_stack = lua_gettop(lua);
	std::cout <<"=== Lua Dump ========================================="<<"\n";
	std::cout << "LUA_MAX_STACK : " << max_stack<<"\n";
	for(int i = 0; i < max_stack;i++){
		int stack =	max_stack - i;
		int type = lua_type(lua,stack);
		std::cout <<"Stack["<<std::setw(2)<<stack<< " : "<<std::setw(10)<< lua_typename(lua,type) <<"]\t";
		switch(type){
		case LUA_TNUMBER:
			//number�^
			std::cout << lua_tonumber(lua, stack);
			break;
		case LUA_TBOOLEAN:
			//boolean�^
			if( lua_toboolean(lua, stack) ) {
				std::cout << "true";
			}else{
				std::cout <<"false";
			}
			break;
		case LUA_TSTRING:
			//string�^
			std::cout << lua_tostring(lua,stack);
			break;
		case LUA_TNIL:
			//nil
			break;
		default:
			//���̑��̌^
			std::cout <<lua_typename(lua, stack);
			break;
		}
			std::cout<<"\n";
	}
	std::cout <<"======================================================"<<"\n";
}
void Luac::Dump(){
	Dump(mLua);
}

/**========================================================*/
/**
 *	@brief	�f�X�g���N�^
 */
/**========================================================*/
Luac::~Luac(){
	if (mInitialized)
		lua_close(mLua);
}
/**========================================================*/
/**
 *	@brief	Lua�̏�����
 */
/**========================================================*/
void Luac::luainit(){
	// Lua�W���֐����g��
	luaL_openlibs(mLua);
	if(luaL_loadfile(mLua, mLuaPath.c_str())){
		std::string error = lua_tostring(mLua,-1);
		perror(("init ERROR:"+error).c_str());
	}
}
/**========================================================*/
/**
 *	@brief	Lua�t�@�C���̎��s
 */
/**========================================================*/
void Luac::run(){

	if (!isInitialized())
	{
		return;
	}
//	luaL_openlibs(mLua);
	if(luaL_loadfile(mLua, mLuaPath.c_str())||lua_pcall(mLua,0,0,0)){
		std::string error = lua_tostring(mLua,-1);
		perror(("Run ERROR:"+error).c_str());
	}
}
/**========================================================*/
/**
 *	@brief	Lua�̊֐����Ăяo��
 */
/**========================================================*/
//template<typename Ty>
void Luac::CallFunc(const std::string& funcName){
	lua_getglobal(mLua, funcName.c_str());
	 if(lua_pcall(mLua, 0, 0, 0)) {
		std::string error = lua_tostring(mLua,-1);
		perror((funcName+" EXEC ERROR:"+error).c_str());
	}
}
/**========================================================*/
/**
*	@brief	Lua�̊֐����Ăяo������
*	@param[in] �֐���
*/
/**========================================================*/

void Luac::ReadyFunc(const std::string& funcName)
{
	lua_getglobal(mLua, funcName.c_str());
}

/**========================================================*/
/**
*	@brief	Lua�̊֐����Ăяo��
*	@param[in]	Lua�̈����̐�
*/
/**========================================================*/
void Luac::CallFunc()
{
	if (lua_pcall(mLua, mArgCnt, 0, 0))
	{
		std::string error = lua_tostring(mLua, -1);
		perror((" EXEC ERROR:" + error).c_str());
	}
	mArgCnt = 0;
}
/**========================================================*/
/**
*	@brief	Lua�̊֐��̈�����ݒ�
*	@param[in]	����
*/
/**========================================================*/

void Luac::SetInt(int arg)
{
	lua_pushinteger(mLua, arg);
	++mArgCnt;
}

void Luac::SetFloat(float arg)
{
	lua_pushnumber(mLua, arg);
	++mArgCnt;
}

void Luac::SetPtr(void* p)
{
	lua_pushlightuserdata(mLua, p);
	++mArgCnt;
}

void Luac::SetStr(const char* str)
{
	lua_pushstring(mLua, str);
	++mArgCnt;
}

void Luac::SetStr(const std::string& str)
{
	SetStr(str.c_str());
	++mArgCnt;
}

void Luac::SetNil()
{
	lua_pushnil(mLua);
	++mArgCnt;
}


/**===End Of File==========================================*/