#include <stdlib.h>
#include <stdint.h>
#include "basic_string.h"

void *
override_memcpy(void *dest, const void *src, size_t n)
{
	uint8_t    *src_p = (uint8_t *) src;
	uint8_t    *dest_p = (uint8_t *) dest;

	for (int i = 0; i < n; i++)
		dest_p[i] = src_p[i];

	return dest;
}

void *
override_memset(void *s, int c, size_t n)
{
	uint8_t    *s_p = (uint8_t *) s;

	for (size_t i = 0; i < n; i++)
		s_p[i] = (uint8_t) c;

	return s;
}

int
override_memcmp(const void *s1, const void *s2, size_t n)
{
	uint8_t    *s1_p = (uint8_t *) s1;
	uint8_t    *s2_p = (uint8_t *) s2;

	for (size_t i = 0; i < n; i++)
	{
		if (s1_p[i] < s2_p[i])
			return -1;
		if (s1_p[i] > s2_p[i])
			return 1;
	}

	return 0;
}

size_t
override_strlen(const char *s)
{
	size_t		count = 0;

	while (s[count] != '\0')
		count++;

	return count;
}

char *
override_strdup(const char *s)
{
	size_t		len = override_strlen(s);

	char	   *new_string = (char *) malloc(len + 1);

	if (new_string == NULL)
		return new_string;

	return (char *) override_memcpy(new_string, s, len + 1);
}

char *
override_strchr(const char *s, int c)
{
	size_t		count = 0;

	while (s[count] != c && s[count] != '\0')
		count++;

	if (s[count] != c)
		return NULL;

	return (char *) &s[count];
}

char *
override_strrchr(const char *s, int c)
{
	size_t		len = override_strlen(s);

	while (1)
	{
		if (s[len] == c)
			return (char *) &s[len];

		if (len == 0)
			return NULL;

		len--;
	}
}

char *
override_strchrnul(const char *s, int c)
{
	size_t		count = 0;

	while (s[count] != c && s[count] != '\0')
		count++;

	return (char *) &s[count];
}

void *
override_memmove(void *dest, const void *src, size_t n)
{
	void	   *ret = dest;

	while (n--)
	{
		if (dest < src)
			*(uint8_t*) dest++ = *(uint8_t*) src++;
		else
			((uint8_t *) dest)[n] = ((uint8_t *) src)[n];
	}

	return ret;
}
