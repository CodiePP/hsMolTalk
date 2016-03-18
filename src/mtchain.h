#ifndef _MT_Chain
#define _MT_Chain

#include "FFI.h"

#ifdef __cplusplus
extern "C" {
#endif

MT_API char mtchain_code(HsPtr rawptr);
MT_API int mtchain_number(HsPtr rawptr);
MT_API const char* mtchain_name(HsPtr rawptr);
MT_API const char* mtchain_description(HsPtr rawptr);
MT_API const char* mtchain_fullPDBCode(HsPtr rawptr);
MT_API const char* mtchain_source(HsPtr rawptr);
MT_API const char* mtchain_compound(HsPtr rawptr);
MT_API const char* mtchain_eccode(HsPtr rawptr);

#ifdef __cplusplus
}
#endif

#endif //_MT_Chain
