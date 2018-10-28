#include<stdio.h>

int GCD(int m,int n)
{
    int result;
    if(n>m)
    {
        result = GCD(n,m);
    }
    else if(n==0)
    {
        result = m;
    }
    else
    {
        result = GCD(n,m%n);
    }
    return result;
}

void main()
{
    int m,n,answer;
    printf("Enter the value of m and n respectively :\n");
    scanf("%d %d",&m,&n);
    answer = GCD(m,n);
    printf("Greatest common deviser of %d and %d is %d.\n",m,n,answer);
}
