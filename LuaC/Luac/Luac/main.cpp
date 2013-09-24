#include <stdio.h>
#include <Lua/Luac.h>

int func(){
	printf("Called ...");
	return 0;
}

int main(int argc, char* argv[])
{
//*
	Luac lua("test.lua");
	lua.setFunction("Shout",func);
	lua.run();
	lua.CallFunc("speech");
	lua.CallFunc("say");
/*/
    // Lua���J��
	lua_State* L  = luaL_newstate();

    // Lua�W���֐����g��
    luaL_openlibs(L);

    // Lua�t�@�C����ǂݍ���
    if(luaL_loadfile(L, "test.lua") || lua_pcall(L, 0, 0, 0)) {
        perror(lua_tostring(L, -1));
    }

    // �֐���ǂݍ���
    lua_getglobal(L, "speech");
    if(lua_pcall(L, 0, 0, 0)) {
        perror(lua_tostring(L, -1));
    }
    // �O���[�o���ϐ���ǂ�
    lua_getglobal(L, "Name");
    if(lua_isstring(L, -1)) {
        printf("My name is %s.\n", lua_tostring(L, -1));
    }

    // Lua�����
    lua_close(L);
//*/
    getchar();
    return 0;
}