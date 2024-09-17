#include <stdlib.h>

int add(int x, int y) {
    int sum = x + y;
    return sum;
}

int add_all (int max) {
    int sum = 0, i = 0;
    for (; i <= max; ) {
        sum += i;
        ++i;
    }
    return sum;
}

int add_all_recursive(int max) {
    if (max <= 0) {
        return 0;
    }
    return max + add_all_recursive(max - 1);
}


int main() {
    int a = 9;
    int b = 3;
    int c = add(a, b);

    int* pA = NULL;
    int* pB = 0;

    pA = &a;
    pB = &b;

    *pA = 10;
    *pB = *pA + 4;

    int d = add_all(5);
    int e = add_all_recursive(5);
    
    return 0;
}