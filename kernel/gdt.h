#pragma once

#include "stdint.h"

typedef struct {
    uint16_t limit_low;     // Segment limit (0-15 bits)
    uint16_t base_low;      // Base (0-15 bits)
    uint8_t base_middle;    // Base (16-23 bits)
    uint8_t access;
    uint8_t flags;
    uint8_t base_high;      // Base (24-31 bits)
} __attribute__((packed)) gdt_segment_t;

typedef struct {
    uint16_t size;
    uint32_t address;
} __attribute__((packed)) gdt_descriptor_t;

void gdt_init();

void gdt_set_segment(int num, uint16_t limit_low, uint16_t base_low, uint8_t base_middle, uint8_t access,
                     uint8_t flags, uint8_t base_high);

extern void gdt_load();
