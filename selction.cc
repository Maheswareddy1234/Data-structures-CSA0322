#include<Stdio.h>
int main()
{
	int i,j,n,a[20],temp;
	printf("enter the of elements in the array :");
	scanf("%d",&n);
	
	printf("enter the elemnts in  the array :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		int min=i;
		for(j=j+1;j<n;j++)
		{
			if(a[j]<a[min])
			{
			min=j;
			}
			temp = a[i];
            a[i] = a[min];
            a[min] = temp;
		}
	}
	printf("sorted array ");
	for(i=0;i<n;i++)
	{
		printf(" %d ",&a[i]);
	}
	return 0;
}
