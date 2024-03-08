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
	
	printf("enter the value of array:");
	scanf("%d",&value);
	
for(i=n-1;i>=pos-1;i--)
a[i+1]=a[i];
a[pos-1]=value;
printf("resultant array is:\n");
for(i=0;i<=n;i++)
{
	printf("%d\n",a[i]);
}
return 0;
}
