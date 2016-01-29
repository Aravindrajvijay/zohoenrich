#include <stdio.h>
int main()
{
    int num,rem,rev=0;
    printf("\nNumber:\n");
    scanf("%d",&num);
    while(num!=0)
    {
        rem = num%10;
        rev = rev*10 + rem;
        num = num/10;
    }
    printf("\nReversed Number: %d",rev);
	  return 0;
}

