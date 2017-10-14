

#include<stdio.h>

#include<stdlib.h>

#include<string.h>

union dt

{

    int a;

    char b;

    double c;

}data;

int main()

{

    data.a=5;

    printf("%f\n",data.c);

    return 0;

} 

