#include "idt.h"
#include "../libc/string.h"

#define MAKE_ENTRY(x) idt_set_entry(x, (uint32_t) isr##x, 0x08, 0x8e)

idt_entry_t idt_entries[256];
idt_ptr_t idt_ptr;

void idt_set_entry(uint8_t num, uint32_t base, uint16_t selector, uint8_t flags) {
    idt_entries[num].base_low = base & 0xffff;
    idt_entries[num].selector = selector;
    idt_entries[num].zero = 0;
    idt_entries[num].flags = flags;
    idt_entries[num].base_high = (base >> 16) & 0xffff;
}

void idt_init() {
    idt_ptr.size = sizeof(idt_entry_t) * 256 - 1;
    idt_ptr.address = (uint32_t) &idt_entries;

    // Initializing the entries to zeros
    memset(&idt_entries, 0, sizeof(idt_entry_t) * 256);

    MAKE_ENTRY(0);
    MAKE_ENTRY(1);
    MAKE_ENTRY(2);
    MAKE_ENTRY(3);
    MAKE_ENTRY(4);
    MAKE_ENTRY(5);
    MAKE_ENTRY(6);
    MAKE_ENTRY(7);
    MAKE_ENTRY(8);
    MAKE_ENTRY(9);
    MAKE_ENTRY(10);
    MAKE_ENTRY(11);
    MAKE_ENTRY(12);
    MAKE_ENTRY(13);
    MAKE_ENTRY(14);
    MAKE_ENTRY(15);
    MAKE_ENTRY(16);
    MAKE_ENTRY(17);
    MAKE_ENTRY(18);
    MAKE_ENTRY(19);
    MAKE_ENTRY(20);
    MAKE_ENTRY(21);
    MAKE_ENTRY(22);
    MAKE_ENTRY(23);
    MAKE_ENTRY(24);
    MAKE_ENTRY(25);
    MAKE_ENTRY(26);
    MAKE_ENTRY(27);
    MAKE_ENTRY(28);
    MAKE_ENTRY(29);
    MAKE_ENTRY(30);
    MAKE_ENTRY(31);

    idt_load();
}
