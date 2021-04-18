#include <kernel/gdt.h>
#include <kernel/idt.h>
#include <drivers/screen.h>

void kernel_main() {
    screen_init();

    write_str("Initializing GDT... ");
    gdt_init();
    write_str("OK\n");

    write_str("Initializing IDT... ");
    idt_init();
    write_str("OK\n");
}
