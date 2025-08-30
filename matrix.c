#include <stdio.h>

int main()
{
    int a[4][4];
    int i, j;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("The matrix is:\n");

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    int top=0;
    int bottom=3;
    int left=0;
    int right=3;


while (top <= bottom && left <= right)
{
    
    for(j=left;j<=right;j++)
    {
        printf("%d",a[top][j]);
       
    }
     top++;
    for(j=top;j<=bottom;j++)
    {
        printf("%d",a[j][right]);
       
    }
     right--;
    for(j=right;j>=left;j--)
    {
        printf("%d",a[bottom][j]);
       
    }
     bottom--;
    for(j=bottom;j>=top;j--)
    {
        printf("%d",a[j][left]);
     
    }
     left++;
}
    return 0;
}