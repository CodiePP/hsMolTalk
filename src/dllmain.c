#ifdef _WINDOWS
BOOL APIENTRY DllMain( HANDLE hModule, 
                DWORD  ul_reason_for_call, 
                LPVOID lpReserved)
{
           // Note this is a *very* dangerous function so do nothing at all in here
           // It is not known which DLLs are currently loaded
           // If you need to do initialization/deinitialization, you should do
           // this explicitly by exporting init/deinit functions to be called from
           // Haskell
        return TRUE;
}
#endif

