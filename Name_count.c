#include <stdio.h>
#include <string.h>
struct first_name
{
	int id;
	char name[25];
};
int main()
{
	struct first_name *s;
	int i,n,j,m=0,len,count,k,index[10];
	char temp[25],str[25];
	printf("\nNumber of students:");
	scanf("%d",&n);
	s=(struct first_name*)malloc(sizeof(struct first_name)*n);
	for(i=0;i<n;i++)
	{
		scanf("%d\t",&s[i].id);
		fgets(s[i].name,25,stdin);
	}
	for(i=0;i<n;i++)
	{
		strcpy(temp,s[i].name);
		len=strlen(temp);
		for(j=0;j<len;j++)
		{
			if(temp[j]=='.')
			{
				m=0;
				continue;
			}
			else if(temp[j]==' ')
			{
				break;
			}
			else
			{
				str[m]=temp[j];
				m++;
			}
		}
		str[m]='\0';
		m=0;
		strcpy(s[i].name,str);
	}
	for(i=0;i<n;i++)
	{
		count=1,m=0,k=0;
		for(j=i+1;j<n;j++)
		{
			if(strcmp(s[i].name,s[j].name) == 0)
			{
				*s[j].name='\0';
				count++;
				index[m]=j;
				m++;
				}
			}
			if(*s[i].name!='\0')
			{
				printf("\n%s %d [%d",s[i].name,count,i+1);
				while(k<m)
				{
					printf(",%d",index[k]+1);
					k++;
				}
				printf("]");
			}
	}
	return 0;
}

