#include <stdio.h>
#include <stdlib.h>
struct election
{
	int contestant_id,count;
	char contestant_name[15],party_name[10];

};
int main()
{
	int n,i,j,choice,vote,max;
	printf("\nEnter the Number of Contestants...\n");
	scanf("%d",&n);
	struct election *s = (struct election*)malloc(sizeof(struct election*) * n);
	printf("\nEnter the Contestant name and Party name...\n");
	for(i=0;i<n;i++)
	{
		scanf("%d\n",&s[i].contestant_id);
		fgets(s[i].contestant_name,25,stdin);
		fgets(s[i].party_name,15,stdin);
	}
	for(i=0;i<n;i++)
	{
		printf("%d\t%s\t%s",s[i].contestant_id,s[i].contestant_name,s[i].party_name);
	}
	while(1)
	{
		printf("\nAre you ready to cast your vote...\nPRESS 1 TO VOTE AND 0 TO EXIT:\n");
		scanf("%d",&choice);
		if(choice)
		{
			printf("\nCast Your Vote....\n");
			scanf("%d",&vote);
			for(i=0;i<n;i++)
			{
				if((i+1)==vote)
				{
					s[i].count++;
				}
				//printf("%d\t%s\t%s",s[i].contestant_id,s[i].contestant_name,s[i].party_name);
			}
		}
		else
		{
			break;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(s[i].count>s[j].count)
			{
				max=i;
			}
			else
			{
				max=j;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(i==max)
		{
			printf("%d\t%s\t%s\thave won...",s[i].contestant_id,s[i].contestant_name,s[i].party_name);
		}
	}
	return 0;	
}
