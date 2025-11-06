#include <stdio.h>

enum { NX = 14, NY = 6 };  // NX = columns (x), NY = rows (y)

// Given an x and y coordinate, return the index into a row-major array
int ii(int x, int y) {
    // row-major: index = y * NX + x
    return y * NX + x;
}

int main(void) {
    int x, y;

    // quick spot checks from the sheet
    printf("(10,0) -> %d\n", ii(10,0)); // expected 10
    printf("(0,3)  -> %d\n", ii(0,3));  // expected 42
    printf("(7,4)  -> %d\n", ii(7,4));  // expected 63

    // full table (optional)
    for (y = 0; y < NY; ++y) {
        for (x = 0; x < NX; ++x) {
            printf("(%d,%d) %3d%s", x, y, ii(x,y), x==NX-1 ? "\n" : "  ");
        }
    }
    return 0;
}

