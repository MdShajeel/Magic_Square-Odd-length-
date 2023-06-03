#include<stdio.h>
int space(int a[][100],int i,int j)
{
	int s=0,v=a[i][j];
	while(v!=0)
    {
        v/=10;
        s++;
    }
    return s;
}
int main()
{
	int n,arr[100][100],sp=0,k;
	printf("enter box size : ");
	scanf("%d",&n);
	int v=1,j=n/2,i=0;
	if(n%2==0)
	{
		printf("\nmagic square not possible ");
		return 0;
	}
	else
	{
		
		while(v<((n*n)+1))
		{
			if(arr[i][j]!=0)
			{
				i+=2;
				j+=1;
				arr[i][j]=v;
				j-=1;
				i-=1;
				v++;
			}
			else 
			{
				arr[i][j]=v;
				if(j==0&&i==0)
				{
					i+=1;
				}
				else if(i==0)
				{
					i=n-1;
					j-=1;
				}
				else if(j==0)
				{
					j=n-1;
					i-=1;
				}
				else
				{
					j-=1;
					i-=1;
				}		
				v++;
			}
		}
	}
	while(v!=0)
    {
        v/=10;
        sp++;
    }
    printf("\n");
    for(j=0;j<n;j++)
    {
    	printf("|");
		for(k=sp;k>=0;k--)
		printf("-");
	}
	printf("|\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("|");
			printf(" %d",arr[i][j]);
			for(k=space(arr,i,j);k<sp;k++)
			printf(" ");		
		}
		printf("|\n");
		for(j=0;j<n;j++)
		{
			printf("|");
			for(k=sp;k>=0;k--)
			printf("-");
		}
		printf("|\n");
	}
	return 0;
}

