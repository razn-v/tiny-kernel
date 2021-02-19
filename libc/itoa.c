// Convert an integer to string
char *itoa(int value) {
    for (int i = 0; i < n_digits(value); i++) {
                 
    }
}

// Convert a digit to char
char dtoa(int digit) {
    return (char) (digit + 48);
}

int n_digits(int value) {
    int count = 0;

    while (value > 0) {
        value /= 10;
        count++;
    }
    return count;
}
