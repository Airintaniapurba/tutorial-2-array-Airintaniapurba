#include <stdio.h>

int main() {
    int n, angka, min_val, max_val;

    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &angka);
        if (i == 0) {
            min_val = angka;
            max_val = angka;
        } else {
            if (angka < min_val) min_val = angka;
            if (angka > max_val) max_val = angka;
        }
    }

    printf("%d\n", min_val);
    printf("%d\n", max_val);

    return 0;
}