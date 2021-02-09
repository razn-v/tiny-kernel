#include "screen.h"
#include "cursor.h"

unsigned short* video_mem = (unsigned short*) VIDEO_ADDRESS;

void init_screen() {
    clear_screen();
    set_cursor_pos(0);
}

void clear_screen() {
    for (int x = 0; x < VGA_WIDTH; x++) {
        for (int y = 0; y < VGA_HEIGHT; y++) {
            write_char('\0');
        }
    }
}

void write_char(char c) {
    int offset = get_cursor_pos();

    video_mem[offset] = (video_mem[0] & 0xff00) | c;
    set_cursor_pos(offset + 1);
}

void write_str(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        write_char(str[i]);
    }
}