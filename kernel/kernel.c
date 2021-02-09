#include "gdt.h"
#include "../drivers/screen.h"

void kernel_main() {
    gdt_init();
    screen_init();

    write_str("Tiny Kernel.");
}