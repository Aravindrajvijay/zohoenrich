#include <stdio.h>
#include <stdlib.h>
struct material
{
	int price,weight,num;
};
int main()
{
	int sack_weight,i,j,n,max_price=0,temp1,temp2,temp3,l,price=0,weight=0,;
	printf("\nEnter the sack weight...");
	scanf("%d",&sack_weight);
	printf("\nEnter the number of materials...");
	scanf("%d",&n);
	struct material *m = (struct material*)malloc(sizeof(struct material*) * n);
	for(i=0;i<n;i++)
	{
		scanf("%d\n%d\n%d",&m[i].price,&m[i].weight,&m[i].num);
	}
	for(i=0;i<n;i++)
	{
		printf("price=%d weight=%d num=%d\n\n\n",m[i].price,m[i].weight,m[i].num);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(m[j].price>m[i].price)
			{
				temp1=m[i].price;
				temp2=m[i].weight;
				temp3=m[i].num;
				m[i].price=m[j].price;
				m[i].weight=m[j].weight;
				m[i].num=m[j].num;
				m[j].price=temp1;
				m[j].weight=temp2;
				m[j].num=temp3;

			}
		}
	}
	for(i=0;i<n;i++)
	{
		l=1;
		while(l<=m[i].num)
		{
			price=m[i].price*l;
			weight=m[i].weight*l;
			if(weight<=sack_weight)
			{
				max_price = max_price + price;
				printf("price=%d weight=%d num=%d\n",m[i].price,m[i].weight,m[i].num);
				l++;
			}
			else
			{
				break;
			}
		}

		
	}
	return 0;
}
