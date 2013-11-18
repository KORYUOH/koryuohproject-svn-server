/**===File Commentary=======================================*/
/**
 *	@file	Luabin.cpp
 *
 *	@brief	Luaバイナリ化モジュール
 *
 *	@author	KORYUOH
 *
 *	@date	2013/11/18
 */
/**===File Include=========================================*/
#include	<Luabin/Luabin.h>
#include	<cstdio>
/**===Class Implementation=================================*/
const int Luabin::BUF_SIZE = LUA_BIN_BUF_SIZE;
Luabin* Luabin::mInstance = nullptr;
Luabin::Luabin(const std::string& luaPath)
	:mLuaPath(luaPath)
	,mLua(luaL_newstate())
{
	mInstance = this;
}
/*
void make_bin_lua(const char *bin_filename, const char *text_filename) {
	FILE *fin = fopen(lua_filename, "r");
	FILE *fout = fopen(bin_filename, "wb");
	lua_State *ls = luaL_newstate();
	lua_load(ls, (lua_Reader)reader, fin, "", NULL);
	lua_dump(ls, (lua_Writer)writer, fout);
	lua_close(ls);
	fclose(fout);
	fclose(fin);
}
*/
void Luabin::convert(){
	FILE *fin = fopen(mLuaPath.c_str(), "r");
	FILE *fout = fopen(std::string("test.lub").c_str(), "wb");
	lua_load(mLua, (lua_Reader)reader, fin, "", NULL);
	lua_dump(mLua, (lua_Writer)writer, fout);
	lua_close(mLua);
	fclose(fout);
	fclose(fin);
}

const char * Luabin::reader(FILE *fp, size_t *size) {
	if (feof(fp)) {
		*size = 0;
		return NULL;
	} else {
		*size = std::fread(mInstance->m_buf, 1, sizeof(mInstance->m_buf), fp);
		return mInstance->m_buf;
	}
}
int Luabin::writer(const void *data, size_t size, FILE *fp) {
	fwrite(data, size, 1, fp);
	return 0; // no error
}

/**===End Of File==========================================*/