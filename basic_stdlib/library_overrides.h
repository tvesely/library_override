/*
 * ================
 *    <string.h>
 * ================
 */

/*
 * void *memcpy(void *dest, const void *src, size_t n);
 */
LIBRARY_CALL_3(memcpy, void *, void *, const void *, size_t);

/*
 * void *memset(void *s, int c, size_t n);
 */
LIBRARY_CALL_3(memset, void *, void *, int, size_t);

/*
 * int memcmp(const void *s1, const void *s2, size_t n);
 */
LIBRARY_CALL_3(memcmp, int, const void *, const void *, size_t);

/*
 * size_t strlen(const char *s);
 */
LIBRARY_CALL_1(strlen, size_t, const char *);

/*
 * char *strdup(const char *s);
 */
LIBRARY_CALL_1(strdup, char *, const char *);

/*
 * char *strchr(const char *s, int c);
 */
LIBRARY_CALL_2(strchr, char *, const char *, int);

/*
 * char *strrchr(const char *s, int c);
 */
LIBRARY_CALL_2(strrchr, char *, const char *, int);

/*
 * char *strchrnul(const char *s, int c);
 */
LIBRARY_CALL_2(strchrnul, char *, const char *, int);

/*
 * void *memmove(void *dest, const void *src, size_t n);
 */
LIBRARY_CALL_3(memmove, void *, void *, const void *, size_t);
