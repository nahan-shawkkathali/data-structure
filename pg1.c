#include<stdio.h>
int main()
{
	int a[50],sum=0,i,n;
	printf("Enter the array limit"); 
	scanf("%d",&n);
	if(n>50)
	{
		printf("error! array size out of limit");
	}
	else
	{
		printf("enter the array elements");
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			sum=sum+a[i];
		
		}
		printf("the sum is %d",sum);
	}
return 0;
}
		
	
