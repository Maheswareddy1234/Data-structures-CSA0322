#include<stdio.h>
int main()
{
	int arr[20],n,i,sum=0;
	printf("enter the number of elements :");
	scanf("%d",&n);
	
	printf("enter the elements in the array :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<=n;i++)
	{
		sum=sum+i;
	}
	printf("%d is the sum of %d number of array ",sum,n);
}
