#include <stdio.h>
#include <math.h>
int bin_conv(int);
int main(void) 
{
    int i,j,n,a[20],num,comb,r;
    printf("\nEnter the num of digits:\n");
	scanf("%d",&n);
	comb = pow(2,n) - 1;
	printf("\nEnter the number:\n");
	for(i=0;i<n;i++)
	{
	    scanf("%d",&a[i]);
	}
	for(i=1;i<=comb;i++)
	{
	   num = bin_conv(i);
	   for(j=0;j<n;j++)
	   {
	       r = num % 10;
	       if(r==1)
	       {
	           printf("%d",a[j]);
	       }
	       num = num / 10;
	   }
	   printf("\n");
	}
	return 0;
}
int bin_conv(int bin)
{
    if(bin==0)
    {
    return 0;
    }
    else
    {
    return (bin%2) + 10 * bin_conv(bin/2);
    }
}


