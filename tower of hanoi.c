#include<stdio.h>

void TOH(int n,char BEG,char AUX,char END)
{
    if(n>=1)
    {
        TOH(n-1,BEG,END,AUX);
        printf("%c to %c\n",BEG,END);
        TOH(n-1,AUX,BEG,END);
    }
}

int main()
{
    int a=3;
    char b='a',c='b',d='c',e;
    printf("prees x to exit");
    while(1){
        printf("\nenter no. of disk");
        scanf("%d",&a);
        TOH(a,b,c,d);
        scanf("%c",&e);
        if(e=='x')
            exit(1);
        else
            continue;
    }


}
