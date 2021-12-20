#ifndef LIB_H_
#define LIB_H_

#if defined(LIB_SHARED)
#if defined(LIB_BUILD)
#define LIB_API  __declspec(dllexport)
#else
#define LIB_API  __declspec(dllimport)
#endif
#else
#define LIB_API
#endif

LIB_API void lib_function();

#endif // LIB_H_
