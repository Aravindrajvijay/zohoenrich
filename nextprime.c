#include <stdio.h>
int main(void)
{
    int num,i;
    printf("Number:");
    scanf("%d",&num);
    num++;
    for(i=2;i<=num/2;i++)
    {
        if(num%i==0)
        {
            num++;
            i=2;
        }
    
    }
    printf("\n%d",num);
	// your code goes here
	return 0;
}
