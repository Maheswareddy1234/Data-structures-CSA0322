#include<stdio.h>
int main() {
	int a[2][3],b[2][3],c[2][3],i,j,rows,cols;
	printf("enter no of rows:");
	scanf("%d",&rows);
	
	printf("enter no of cols:");
	scanf("%d",&cols);
	
	printf("\nenter the first matrix:\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
		printf("\nenter the second matrix:\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
		printf("\nthe first matrix is:\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
			printf("\nthe second matrix is:\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
	printf("\nthe sum matrix is:\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
	
	
	
}
