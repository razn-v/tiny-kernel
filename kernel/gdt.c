#include "gdt.h"

static gdt_segment_t gdt_segments[3];
static gdt_descriptor_t gdt_ptr;

void gdt_init() {
    gdt_ptr.size = sizeof(gdt_segment_t) * 3 - 1;
    gdt_ptr.address = (uint32_t) & gdt_segments;

    // Null segment
    gdt_set_segment(0, 0, 0, 0, 0, 0, 0);

    // Code segment
    gdt_set_segment(1, 0xffff, 0, 0, 0x9a, 0b11001111, 0);

    // Data segment
    gdt_set_segment(2, 0xffff, 0, 0, 0x92, 0b11001111, 0);
}

void gdt_set_segment(int num, uint16_t limit_low, uint16_t base_low, uint8_t base_middle, uint8_t access,
                     uint8_t flags, uint8_t base_high) {
    gdt_segments[num].limit_low = limit_low;
    gdt_segments[num].base_low = base_low;
    gdt_segments[num].base_middle = base_middle;
    gdt_segments[num].access = access;
    gdt_segments[num].flags = flags;
    gdt_segments[num].base_high = base_high;
}