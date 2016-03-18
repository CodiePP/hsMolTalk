#include "mtutils.h"

#include <cstring>

// our functions need to be C-functions
#ifdef __cplusplus
  extern "C" {
#endif

MT_API void mtutils_free(HsPtr extptr)
{
	if (extptr) {
		delete extptr;
	}
}


#ifdef __cplusplus
  }
#endif

