#include <stdio.h>
#include <Lua/Luac.h>

int func(){
	printf("Called ...\n");
	return 0;
}

class Value{
public:
	static int destroy(Luac::LUA_STATE lua){
		printf(" THIS IS DESTROY FUNCTION\n"); 
		return 0;
	};
};

int add(Luac::LUA_STATE lua){
	int a = luaL_checkint(lua,-2);
	int b = luaL_checkint(lua,-1);
	Luac::Dump(lua);
	lua_pushnumber(lua,a+b);
	Luac::Dump(lua);
	return 1;//戻り値はスタックで返す個数
}

int main(int argc, char* argv[])
{
//*
	Luac lua("test.lub");
	lua.setFunction("Shout",&func);
	lua.setFunction("add",&add);
	lua.setFunction("Destroyer",&Value::destroy);
	lua.run();
	lua.CallFunc("speech");
	lua.CallFunc("say");

	lua.Dump();
/*/
		// Luaを開く
	lua_State* L	= luaL_newstate();

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