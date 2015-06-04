
#include <stdio.h>

float main(void)
{
    
    int i;
    float fib[50];
    fib[0] = 0;
    fib[1] = 1;
    
    for(i=2; i<50; i++)
    {
        fib[i] = fib[i-2] + fib[i-1];
    }
        
	printf("The first 50 numbers in the Fibonacci Sequence are:\n");
	
	int j;
	for(j=0; j<50; j++)
	{
		printf("%f\n", fib[j]);
	}

    return 0;
}
