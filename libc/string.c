#include "string.h"

uint8_t *memcpy(uint8_t *dest, const uint8_t *src, int count) {
    uint8_t *_dest = dest;
    const uint8_t *_src = src;

    while (count-- > 0) {
        *_dest++ = *_src++;
    }
    return dest; 
}

uint8_t *memset(uint8_t *dest, uint8_t val, int count) {
    uint8_t *_dest = dest;
    
    while (count-- > 0) {
        *_dest++ = val;
    }
    return dest;
}

uint16_t *memsetw(uint16_t *dest, uint16_t *val, int count) {
    uint16_t *_dest = dest;

    while (count-- > 0) {
        *_dest++ = val;
    }
    return dest;
}

int strlen(const char *str) {
    int count = 0;

    while (str[count++]);
    return count;
}
