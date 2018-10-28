#include<stdio.h>

int factorial(int n)
{
    int result,temp;
    if(n==1)
    {
        result=1;
    }
    else
    {
        temp=factorial(n-1);
        result = n * temp;
    }
    return result;
}

void main()
{
    int n,answer;
    printf("Enter the value of n:\n");
    scanf("%d",&n);
    answer=factorial(n);
    printf("Factorial of %d is %d.\n",n,answer);
}
