
#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of integers to use: ");
    scanf("%i", &n);
    float numbers[n];
    int i;
    for(i=0; i<n; i++)
    {
        printf("Enter the next number: ");
        float next;
        scanf("%f", &next);
        numbers[i] = next;
    }
    float sum = 0.0; 
    int j;
    for(j=0; j<n; j++)
    {
        sum = sum + numbers[j];
    }
    float average = 0.0;
    average = sum / n;
    printf("%.2f\n", average);
    return 0;
}
