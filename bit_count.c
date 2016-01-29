#include <stdio.h>
int binary(int);
int main() 
{ 
    int deci_num,bin_num,count=1;
    printf("\nEnter the Number:\n");
    scanf("%d",&deci_num);
    bin_num=binary(deci_num);
    while(bin_num>1)
    {
        bin_num=bin_num/10;
        count++;
    }
    printf("\nBits required:\n%d",count);
	return 0;
}
int binary(int num)
{
    if(num==0)
    {
        return 0;
    }
    else
    {
        return (num % 2) + 10 * binary(num/2);
    }
}

