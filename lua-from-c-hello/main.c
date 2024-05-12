#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int main()
{

    lua_State *L = luaL_newstate();

    luaL_openlibs(L);

    int result = luaL_dofile( L, "script.lua" );

    if ( result != 0 )
    {
        printf( "ERROR: luaL_dofile failed: %s\n", lua_tostring( L, -1 ) );
        lua_close(L);
        return 1;
    }

    lua_close(L);

    return 0;
}
