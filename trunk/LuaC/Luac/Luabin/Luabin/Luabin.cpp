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
const int Luabin::BUF_SIZE = 1024;
Luabin::Luabin(const std::string& luaPath)
	:mLuaPath(luaPath)
	,mLua(luaL_newstate())
{
	luainit();
}

const char * Luabin::reader(FILE *fp, size_t *size) {
	if (feof(fp)) {
		*size = 0;
		return NULL;
	} else {
		*size = std::fread(m_buf, 1, sizeof(m_buf), fp);
		return m_buf;
	}
}
int Luabin::writer(const void *data, size_t size, FILE *fp) {
	fwrite(data, size, 1, fp);
	return 0; // no error
}

/**===End Of File==========================================*/