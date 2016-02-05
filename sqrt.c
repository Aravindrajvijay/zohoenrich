#include <stdio.h>
double babylonian(int);
int main(void) 
{
    int num;
    double sq_rt;
    printf("Number:");
    scanf("%d",&num);
    sq_rt=babylonian(num);
    printf("\nSquare Root:%f",sq_rt);
    return 0;
}
double babylonian(int n)
{
    double a,b=1.0,accuracy=0.000001;
    a=n;
    while((a-b)>accuracy)
    {
        a=(a+b)/2;
        b=n/a;
    }
    return a;
}

