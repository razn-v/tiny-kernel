int ipow(int x, int y) {
    if (y == 0) {
        return 1;
    }

    int res = x;
    y -= 1;

    while (y--) {
        res *= x;
    }
    return res;
}
