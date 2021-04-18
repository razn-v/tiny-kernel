#include <drivers/screen.h>
#include <drivers/cursor.h>

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

void swap_line(int y1, int y2) {
    for (int x = 0; x < VGA_WIDTH; x++) {
        video_mem[VGA_WIDTH * y1 + x] = video_mem[VGA_WIDTH * y2 + x];
    }
}

int get_offset() {
    return VGA_WIDTH * y_pos + x_pos;
}

void scroll() {
    for (int y = 0; y < VGA_HEIGHT - 1; y++) {
        swap_line(y, y+1);
    }

    y_pos--;
    set_cursor_pos(get_offset());
}

void write_char(char c) {
    if (x_pos >= VGA_WIDTH) {
        x_pos = 0;
        y_pos++;
    }

    if (y_pos >= VGA_HEIGHT) {
        y_pos = VGA_HEIGHT;
        scroll();
    }

    if (c == '\n') {
        x_pos = 0;
        y_pos++;
        set_cursor_pos(get_offset());
        return;
    }

    video_mem[get_offset()] = (video_mem[0] & 0xff00) | c;

    x_pos++;
    set_cursor_pos(get_offset());
}

void write_str(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        write_char(str[i]);
    }
}
