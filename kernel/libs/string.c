#include "string.h"

inline void memcpy(uint8_t *dest, const uint8_t *src, uint32_t len)
{
    for (; len != 0; len--) {
        *dest++ = *src++;
    }
}

inline void memset(void *dest, uint8_t val, uint32_t len)
{
    uint8_t *dst = (uint8_t *)dest;

    for ( ; len != 0; len--) {
        *dst++ = val;
    }
}

inline void bzero(void *dest, uint32_t len)
{
    memset(dest, 0, len);
}

int strlen(const char *src)
{
    if(src==NULL) return 0;
    int count =0;
    while(*src!='\0'){
	count++;
        src++;
    }
    return count;
}

int strcmp(const char *str1, const char *str2)
{
    while(*str1 == *str2)
    {
        if(*str1 == '\0')
            return 0;
        str1++;
        str2++;
    }
    return *str1 - *str2;
}
