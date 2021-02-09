#include "../drivers/screen.h"

void kernel_main() {
    init_screen();

    write_str("Tiny Kernel.");
}