#ifndef BASIC_STRING_H
#define BASIC_STRING_H

void	   *override_memcpy(void *dest, const void *src, size_t n);
void	   *override_memset(void *s, int c, size_t n);
int			override_memcmp(const void *s1, const void *s2, size_t n);
size_t		override_strlen(const char *s);
char	   *override_strdup(const char *s);
char	   *override_strchr(const char *s, int c);
char	   *override_strrchr(const char *s, int c);
char	   *override_strchrnul(const char *s, int c);
void	   *override_memmove(void *dest, const void *src, size_t n);

#endif							/* BASIC_STRING_H */
