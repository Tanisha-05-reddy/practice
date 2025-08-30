#include <stdio.h>
void rightRotate(int arr[], int start, int end) 
{
    int temp = arr[end];
    for (int i = end; i > start; i--) 
    {
        arr[i] = arr[i - 1];
    }
    arr[start] = temp;
}
void rearrange(int arr[], int n) 
{
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0 && i % 2 == 1) {
            for (int j = i + 1; j < n; j++) 
            {
                if (arr[j] < 0) 
                {
                    rightRotate(arr, i, j);
                    break;
                }
            }
        }
          else if (arr[i] < 0 && i % 2 == 0) 
          {
            for (int j = i + 1; j < n; j++) {
                if (arr[j] >= 0) {
                    rightRotate(arr, i, j);
                    break;
                }
            }
        }
    }
}
int main() {
    int arr[] = {1, 2, 3, -4, -1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrange(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}