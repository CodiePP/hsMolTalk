#include "mtstructure.h"
#include "libmoltalk/MTPDBParser.hpp"
#include "libmoltalk/MTStructure.hpp"
#include "libmoltalk/MTChain.hpp"

#include "boost/format.hpp"

#include <iostream>
#include <cstring>

// our functions need to be C-functions
#ifdef __cplusplus
  extern "C" {
#endif

MT_API void mtstructure_release(HsPtr extstrx)
{
	mt::MTStructure* s = (mt::MTStructure*)extstrx;
	if (s) {
		delete s;
	}
}

MT_API HsPtr mtstructure_read(const char * fname)
{
	mt::MTPDBParser p;
	mt::MTStructure* s = p.parseStructureFromPDBFile(fname);
	return (void*)s;
}

FF_PTR2STR(mtstructure_header, mt::MTStructure, header)
/*
MT_API const char* mtstructure_header(HsPtr strxptr)
{
	mt::MTStructure* s = (mt::MTStructure*)strxptr;
	if (s) {
		return s->header().c_str();
	}
	return NULL;
} */

MT_API HsPtr mtstructure_get_chain(HsPtr strxptr, int code)
{
	mt::MTStructure* s = (mt::MTStructure*)strxptr;
	mt::MTChain* c = nullptr;
	if (s) {
		c = s->getChain(code);
	}
	return (void*)c;
}

#ifdef __cplusplus
  }
#endif

