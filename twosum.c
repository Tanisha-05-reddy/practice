#include <stdio.h>
int main()
{
    int i,j;
    int arr[5]={2,6,5,8,11};
    int target = 14;
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            if(i==j)
            continue;
            if(arr[i]+arr[j]==target)
            printf("%d %d sum is target",i,j,target);
        }
    }
}