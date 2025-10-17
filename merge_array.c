#include<stdio.h>
void display(int ary[],int k)
{
	printf("array elements are:");
	for(int i=0;i<k;i++)
		printf("%d",ary[i]);
	printf("\n");
}
void merge_array(int ary1[],int ary2[],int ary3[],int n,int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		ary3[i]=ary1[i];
	}
	for(j=0;j<m;j++)
		{
		ary3[i]=ary2[j];
		i++;
		}
}
void sort_array(int ary[],int k);

int main()
{
	
	int ary1[10],ary2[10],ary3[20],n,m,i,size;
	printf("enter the limit of first array");
	scanf("%d",&n);
	if(n<=10)
	{
		printf("enter the elements of first array");
		for(i=0;i<n;i++)
			scanf("%d",&ary1[i]);
	}
	else
	{
		printf("erroe!,out of size");
	}
	
	printf("enter the limit of second array");
	scanf("%d",&m);
	if(m<=10)
	{
		printf("enter the elements of second array");
		for(i=0;i<m;i++)	
			scanf("%d",&ary2[i]);
	}
	else
	{
		printf("erroe!,out of size");
	}
	printf("First array before sorting:");
	printf("\n");
	display(ary1,n);
	printf("second array before sorting");
	printf("\n");
	display(ary2,m);
	sort_array(ary1,n);
	sort_array(ary2,m);
	printf("sorted first");
	printf("\n");
	display(ary1,n);
	printf("sorted second");
	printf("\n");
	display(ary2,m);
	printf("the merged array ");
	printf("\n");
	size=n+m;
        merge_array(ary1,ary2,ary3,n,m);
        sort_array(ary3,size);
	display(ary3,size);
}
void sort_array(int ary[],int k)
{
	int temp=0;
	for(int i=0;i<k;i++)
	{
		for(int j=i+1;j<k;j++)
		{
			if(ary[i]>ary[j])
			{
			temp=ary[i];
			ary[i]=ary[j];
			ary[j]=temp;
			}
		}
	}
}	
	
	
