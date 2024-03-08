#include<stdio.h>
int main()
{
	int pos,value,n,arr[20],i;
	printf("enter the number of elmemnts in the array :");
	scanf("%d",&n);
	
	printf("enter the elemnts in the array :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("enter the position of the array :\n");
	scanf("%d",&pos);
	
	printf("enter the value of the array :\n");
	scanf("%d",&value);
	
	for(i=n-1;i>=pos-1;i--)
	arr[i+1]=arr[i];
	
	arr[pos-1]=value;
	printf("resultant array is:\n");
	for(i=0;i<=n;i++)
	printf("%d\n",arr[i]);

}
