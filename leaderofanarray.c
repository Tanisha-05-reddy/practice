#include <stdio.h>

int main() {
	// your code goes here
	int n,i;
	scanf("%d", &n);
	int a[n], l[n];
	int c = 0;
	for(int i = 0; i < n; i++)
	{
	    scanf("%d", &a[i]);
	}
	int max = a[n - 1];
	l[c++] = max;
	for(int i = n - 2; i >= 0; i--)
	{
	    if(a[i]>max)
	    {
	        max = a[i];
	        l[c++] = max;
	    }
	}
	for(i = c-1; i>=0; i--)
	{
	    printf("%d", l[i]);
	}
return 0;
}

