#include "gdt.h"
#include "idt.h"
#include "../drivers/screen.h"

void kernel_main() {
    gdt_init();
    idt_init();
    screen_init();

    asm volatile("int $0x5");
}
