#include "../kernel/io.h"

int get_cursor_pos() {
    int pos = 0;
    byte_out(0x3D4, 0x0F);

    pos |= byte_in(0x3d5);
    byte_out(0x3d4, 0x0e);
    pos |= (byte_in(0x3d5)) << 8;

    return pos;
}

void set_cursor_pos(int offset) {
    byte_out(0x3d4, 0x0f);
    byte_out(0x3d5, offset & 0xff);
    byte_out(0x3d4, 0x0e);
    byte_out(0x3d5, (offset >> 8) & 0xff);
}