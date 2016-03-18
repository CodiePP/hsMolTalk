#include "mtchain.h"
#include "libmoltalk/MTChain.hpp"

#include <iostream>
#include <cstring>

// our functions need to be C-functions
#ifdef __cplusplus
  extern "C" {
#endif

FF_PTR2CHR(mtchain_code, mt::MTChain, code)
FF_PTR2INT(mtchain_number, mt::MTChain, number)

FF_PTR2STR(mtchain_name, mt::MTChain, name)
FF_PTR2STR(mtchain_description, mt::MTChain, description)
FF_PTR2STR(mtchain_fullPDBCode, mt::MTChain, fullPDBCode)
FF_PTR2STR(mtchain_source, mt::MTChain, source)
FF_PTR2STR(mtchain_compound, mt::MTChain, compound)
FF_PTR2STR(mtchain_eccode, mt::MTChain, eccode)

#ifdef __cplusplus
  }
#endif

