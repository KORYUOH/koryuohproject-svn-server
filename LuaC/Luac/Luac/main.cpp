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
	return 1;//�߂�l�̓X�^�b�N�ŕԂ���
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
		// Lua���J��
	lua_State* L	= luaL_newstate();

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