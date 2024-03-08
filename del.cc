#include<stdio.h>
int main()
{
	int n,value,a[20],i,pos;
	
	printf("enter no of elements in array:");
	scanf("%d",&n);
	printf("enter the elements in array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter position of array:\n");
	scanf("%d",&pos);
	
for(i=pos-1;i<n-1;i++)
a[i]=a[i+1];
printf("resultant array is:\n");
for(i=0;i<n-1;i++)
{
	printf("%d\n",a[i]);
}
return 0;
}
