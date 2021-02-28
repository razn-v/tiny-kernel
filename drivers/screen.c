#include "screen.h"
#include "cursor.h"

unsigned short* video_mem = (unsigned short*) VIDEO_ADDRESS;

unsigned int x_pos = 0;
unsigned int y_pos = 0;

void screen_init() {
    screen_clear();

    x_pos = 0;
    y_pos = 0;
    set_cursor_pos(0);
}

void screen_clear() {
    for (int x = 0; x < VGA_WIDTH; x++) {
        for (int y = 0; y < VGA_HEIGHT; y++) {
            write_char('\0');
        }
    }
}

void write_char(char c) {
    if (x_pos >= VGA_WIDTH) {
        x_pos = 0;
        y_pos++;
    } else if (c == '\n') {
        x_pos = 0;
        y_pos++;
        return;
    } else {
        x_pos++;
    }

    int offset = VGA_WIDTH * y_pos + x_pos;

    video_mem[offset] = (video_mem[0] & 0xff00) | c;
    set_cursor_pos(offset);
}

void write_str(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        write_char(str[i]);
    }
}
