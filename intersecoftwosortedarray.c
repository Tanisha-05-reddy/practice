#include <stdio.h>
void intersection(int a[], int m, int b[], int n, int res[], int *res_size)
 {
    for (int i = 0; i < m; i++) {
        if (i > 0 && a[i - 1] == a[i])
            continue;
        for (int j = 0; j < n; j++) {
            if (a[i] == b[j]) {
                res[(*res_size)++] = a[i];
                break;
            }
        }
    }
}

int main() {
    int a[] = {3, 5, 10, 10, 10, 15, 15, 20};
    int b[] = {5, 10, 10, 15, 30};
    int res[10];
    int res_size = 0; 
    intersection(a, 8, b, 5, res, &res_size);
    for (int i = 0; i < res_size; i++) {
        printf("%d ", res[i]);
    }
    return 0;
}