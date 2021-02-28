#include "gdt.h"
#include "idt.h"
#include "../drivers/screen.h"

void kernel_main() {
    gdt_init();
    idt_init();
    screen_init();

    write_str("Tiny Kernel.\n");
    write_str("A tiny kernel made in C for learning purposes.");
}
