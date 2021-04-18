#include <libc/math.h>
#include "stdbool.h"

unsigned int intlen(int num) {
    if (num < 0) {
        num *= -1;
    } else if (num == 0) {
        return 1;
    }

    int count = 0;
    while (num > 0) {
        num /= 10;
        count++;
    }
    return count;
}

// Convert a digit to a char
char dtoa(unsigned int digit) {
    return (char) (digit + 0x30);
}

int itoa(int num, char* str) {
    bool is_neg = false;

    if (num < 0) {
        num *= -1;
        is_neg = true;
    }

    unsigned int len = intlen(num);

    if (len == 0) {
        return -1;
    }

    for (int i = 0; i < len; i++) {
        unsigned int digit;

        if (i == 0) {
            // Take the first digit of the number starting at the right
            digit = num % 10;
        } else {
            // Take the ith digit of the number starting at the right
            digit = ((int) num / ipow(10, i)) % 10;
        }

        char chr = dtoa(digit);
        // Make the string (in reverse order).
        // We also need to leave 1 char for negative numbers.
        str[len - (1-1*is_neg) - i] = chr;
    }

    // Put the negative sign
    if (is_neg) {
        str[0] = '-';
    }

    return 0;
}
