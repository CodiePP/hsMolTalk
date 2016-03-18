#ifndef FFI_H
#define FFI_H

#ifdef _WINDOWS
#ifdef __MT_DLL_EXPORT
#define MT_API __declspec(dllexport)
#else
#define MT_API
#endif
#else
#define MT_API
#endif

/*
typedef unsigned int HsChar;  // on 32 bit machine
typedef int HsInt;
typedef unsigned int HsWord;
*/

// Ensure that we use C linkage for HsFunPtr 
#ifdef __cplusplus
extern "C"{
#endif

typedef void (*HsFunPtr)(void);

#ifdef __cplusplus
}
#endif

typedef void *HsPtr;
typedef void *HsForeignPtr;
typedef void *HsStablePtr;

#define HS_BOOL_FALSE 0
#define HS_BOOL_TRUE 1

#define FF_PTR2TYPE(fn, cl, tfn, tp, def) \
MT_API tp fn(HsPtr extptr) \
{ \
	cl* c = (cl*)extptr; \
	if (c) { \
		return c->tfn ; \
	} \
	return def; \
} \

/*
 *  we have to make a copy of the string
 *  to be released by the receiver
 */
#define FF_PTR2STR(fn, cl, tfn) \
MT_API const char * fn(HsPtr extptr) \
{ \
	cl* c = (cl*)extptr; \
	if (c) { \
		const std::string s(c->tfn() ); \
		return strdup(s.c_str()); \
	} \
	return "?"; \
} \


#define FF_PTR2INT(fn, cl, tfn) \
 FF_PTR2TYPE(fn, cl, tfn (), int, -1)

#define FF_PTR2CHR(fn, cl, tfn) \
 FF_PTR2TYPE(fn, cl, tfn (), char, ' ')

#endif // FFI_H
