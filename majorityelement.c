#include <stdio.h>
int majorityElement(int arr[], int n) 
{
    for (int i = 0; i < n; i++) {
        int count = 0; 
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > n / 2) {
            return arr[i]; 
        }
    }
    return -1;
}
int main() {
    int arr[] = {1, 1, 2, 1, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);   
    printf("%d\n", majorityElement(arr, n));
    return 0;
}