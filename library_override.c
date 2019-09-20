#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#include "override.h"

__attribute__((constructor)) static void init();

#define LIBRARY_CALL_1(FUNC, RET, ARG1TYPE, ...) \
static RET(* _##FUNC) (ARG1TYPE ARG1); \
RET \
FUNC (ARG1TYPE ARG1) \
{ \
    __VA_ARGS__ ; \
    return _##FUNC(ARG1); \
}

#define LIBRARY_CALL_2(FUNC, RET, ARG1TYPE, ARG2TYPE, ...) \
static RET(* _##FUNC) (ARG1TYPE ARG1, ARG2TYPE ARG2); \
RET \
FUNC (ARG1TYPE ARG1, ARG2TYPE ARG2) \
{ \
    __VA_ARGS__ ; \
    return _##FUNC(ARG1, ARG2); \
}

#define LIBRARY_CALL_3(FUNC, RET, ARG1TYPE, ARG2TYPE, ARG3TYPE, ...) \
static RET(* _##FUNC) (ARG1TYPE ARG1, ARG2TYPE ARG2, ARG3TYPE ARG3); \
RET \
FUNC (ARG1TYPE ARG1, ARG2TYPE ARG2, ARG3TYPE ARG3) \
{ \
    __VA_ARGS__ ; \
    return _##FUNC(ARG1, ARG2, ARG3); \
}

#include "library_overrides.h"

#undef LIBRARY_CALL_3
#undef LIBRARY_CALL_2
#undef LIBRARY_CALL_1

#define LIBRARY_CALL_3(FUNC, RET, ARG1, ARG2, ARG3, ...) LIBRARY_CALL(FUNC)
#define LIBRARY_CALL_2(FUNC, RET, ARG1, ARG2, ...) LIBRARY_CALL(FUNC)
#define LIBRARY_CALL_1(FUNC, RET, ARG1, ...) LIBRARY_CALL(FUNC)
static void
init()
{
#ifdef REPLACE_LIBRARY_CALLS
#define LIBRARY_CALL(FUNC) _##FUNC = *override_##FUNC;

#include "library_overrides.h"

#undef LIBRARY_CALL
#else
#define LIBRARY_CALL(FUNC) _##FUNC = dlsym(RTLD_NEXT, #FUNC);

#include "library_overrides.h"

#undef LIBRARY_CALL
#endif

#define LIBRARY_CALL(FUNC) fprintf(stderr, "_" #FUNC "=%p\n", _##FUNC);
#include "library_overrides.h"
#undef LIBRARY_CALL
}
