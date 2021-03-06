#include "MWD3D9RenderSystemPlugin.h"

Myway::D3D9RenderSystemPlugin _render;

bool APIENTRY DllMain(HANDLE hModule,DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch( ul_reason_for_call ) 
    {
    case DLL_PROCESS_ATTACH:
        Myway::PluginManager::Instance()->AddPlugin(&_render);
        break;

    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        ;
    }

    return TRUE;
}
