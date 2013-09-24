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
    // Luaを開く
	lua_State* L  = luaL_newstate();

    // Lua標準関数を使う
    luaL_openlibs(L);

    // Luaファイルを読み込む
    if(luaL_loadfile(L, "test.lua") || lua_pcall(L, 0, 0, 0)) {
        perror(lua_tostring(L, -1));
    }

    // 関数を読み込む
    lua_getglobal(L, "speech");
    if(lua_pcall(L, 0, 0, 0)) {
        perror(lua_tostring(L, -1));
    }
    // グローバル変数を読む
    lua_getglobal(L, "Name");
    if(lua_isstring(L, -1)) {
        printf("My name is %s.\n", lua_tostring(L, -1));
    }

    // Luaを閉じる
    lua_close(L);
//*/
    getchar();
    return 0;
}