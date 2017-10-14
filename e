

#include<stdio.h>

#include<stdlib.h>

#include<math.h>

int main()

{

    int n=1;

    float m=1.0,t=1.0;

    while(fabs(t)>=1e-7){

        t/=n;

        m+=t;

        n++;

    }

    printf("%f",m);

    return 0;

}

