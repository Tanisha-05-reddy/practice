#include <stdio.h>

int findMissingNo(int arr[], int size) {
    int n = size + 1; // Total numbers including the missing one
    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;

    for (int i = 0; i < size; i++) {
        actualSum += arr[i];
    }

    return expectedSum - actualSum;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6}; // Missing number is 4
    int size = sizeof(arr) / sizeof(arr[0]);

    int missing = findMissingNo(arr, size);
    printf("MissingNo found: %d\n", missing);

    return 0;
}