#include<stdio.h>
void palindrome(int);
void main()
{
	int num;
	printf("enter the number:\n");
	scanf("%d",&num);
	palindrome(num);

}
void palindrome(int n)
{
  int m,r,i,rev;
	n++;
while(1)
	{	
		m=i;
		sum=0;
		while(m!=0)
		{
			r=m%10;
			rev=(rev*10)+r;
			m=m/10;
		}
		if(i==sum)
			{
		  	printf("the next palindrome is %d",i);
		  	break;
			}
		i=n;
		i++;
			
	}
	
	}

