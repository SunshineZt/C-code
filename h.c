

#include<stdio.h>

#include<stdlib.h>

#include<math.h>

long h(int n)

{

    int f;

    if(n==0)

    f=1;

    else f=2*h(n-1)+1; 

    return f;

}

int main()

{

    long y;

    int n;

    printf("input a integer
number :\n");

    scanf("%d",&n);

    if(n<0)

    printf("data error\n");

    else

    {

        y=h(n);

        printf("%ld",y);

    }

    return 0;

}

