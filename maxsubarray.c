#include <stdio.h>

int main() {
	// your code goes here
	int T;
	scanf("%d", &T);
	while(T--)
	{
	    int N;
	    scanf("%d", &N);
	    int a[N];
	    int i;
	    for(i=0; i<N; i++)
	    {
	        scanf("%d",&a[i]);
	    }
	    int maxsum = a[0];
	    int currentsum = a[0];
	    for(i =1; i<N; i++)
	    {
	        if(currentsum < 0)
	        currentsum = a[i];
	        else{
	            currentsum += a[i];
	        }
	        if(currentsum > maxsum)
	        maxsum = currentsum;
	    }
	    printf("%d\n",maxsum);
	}

}

