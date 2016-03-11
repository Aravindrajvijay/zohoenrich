#include <stdio.h>
#include <string.h>
struct details
{
	int id;
	char name[25];
};
struct first_name
{
    char f_name[25];
    int index[10];
    int count;
};

int main()
{
	int n,i,j,len,m,k;
	char temp[25],str[25];
	printf("\nNumber of students:");
	scanf("%d", &n);
	struct details *s = (struct details*)malloc(sizeof(struct details) * n);
	struct first_name *f = (struct first_name*)malloc(sizeof(struct first_name) * n);
	for(i=0;i<n;i++)
	{
		scanf("%d\t", &s[i].id);
		fgets(s[i].name, 25, stdin);
	}
	for(i=0;i<n;i++)
	{
		strcpy(temp,s[i].name);
		len = strlen(temp);
		for(j=0;j<len;j++)
		{
			if(temp[j] == '.')
			{
				m = 0;
				continue;
			}
			else if(temp[j] == ' ')
			{
				break;
			}
			else
			{
				str[m] = temp[j];
				m++;
			}
		}
		str[m] = '\0';
		m=0;
		strcpy( f[i].f_name, str);
	}
	for(i=0;i<n;i++)
	{
	    f[i].count=1;
		m=0;
		k=0;
		for(j=i+1;j<n;j++)
		{
			if(strcmp(f[i].f_name,f[j].f_name) == 0)
			{
				*f[j].f_name ='\0';
				 f[i].count++;
				*f[i].index = j;
				m++;
			}
		}
		if(*f[i].f_name!='\0')
		{
			printf("\n%s %d [%d",f[i].f_name,f[i].count,i+1);
			while(k<m)
			{
				printf(",%d",*f[i].index+1);
				k++;
			}
			printf("]");
		}
	}
	return 0;
}
