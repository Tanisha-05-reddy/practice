#include <stdio.h>
#include <limits.h>  

int find2max(int arr[], int n)
{
    if (n < 2) {
        printf("Array must contain at least two elements.\n");
        return INT_MIN;
    }

    int max = INT_MIN, slargest = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            slargest = max;
            max = arr[i];
        } else if (arr[i] < max && arr[i] > slargest) {
            slargest = arr[i];
        }
    }

    if (slargest == INT_MIN) {
        printf("No second largest element found.\n");
        return INT_MIN;
    }

    return slargest;
}

int main()
{
    int arr[] = {2, 5, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = find2max(arr, n);

    if (result != INT_MIN)
        printf("Second largest element: %d\n", result);

    return 0;
}