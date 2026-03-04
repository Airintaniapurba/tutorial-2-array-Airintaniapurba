#include <stdio.h>
#include <float.h>

int main() {
    int n, current, prev;
    int min_val, max_val;
    double min_avg = DBL_MAX;
    double max_avg = -DBL_MAX;

    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &current);

        if (i == 0) {
            min_val = current;
            max_val = current;
        } else {
            if (current < min_val) min_val = current;
            if (current > max_val) max_val = current;

            double avg = (double)(prev + current) / 2.0;
            if (avg < min_avg) min_avg = avg;
            if (avg > max_avg) max_avg = avg;
        }
        prev = current;
    }

    printf("%d\n", min_val);
    printf("%d\n", max_val);
    if (n > 1) {
        printf("%.2f\n", min_avg);
        printf("%.2f\n", max_avg);
    }

    return 0;
}