#ifndef _MT_Structure
#define _MT_Structure

#include "FFI.h"

#ifdef __cplusplus
extern "C" {
#endif

MT_API HsPtr mtstructure_load_pdb(const char * pdbid);
MT_API const char* mtstructure_header(HsPtr strxptr);
MT_API void mtstructure_release(HsPtr strxptr);
MT_API HsPtr mtstructure_get_chain(HsPtr strxptr, int code);

#ifdef __cplusplus
}
#endif

#endif //_MT_Structure
