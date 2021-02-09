#pragma once

#define VIDEO_ADDRESS 0xb8000
#define VGA_HEIGHT 25
#define VGA_WIDTH 80

void screen_init();

void screen_clear();

void write_digit(int digit);

void write_char(char c);

void write_str(const char *str);