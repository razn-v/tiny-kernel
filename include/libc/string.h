#pragma once

#include "stdint.h"

uint8_t *memcpy(uint8_t *dest, const uint8_t *src, int count);

uint8_t *memset(uint8_t *dest, uint8_t val, int count);

uint16_t *memsetw(uint16_t *dest, uint16_t *val, int count);

int strlen(const char *str);
