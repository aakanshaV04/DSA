#include <stdio.h>
main()
{   int a[10];int k ;
printf("enter the 10 elements of the array\n");
for(int i = 0 ; i<10 ;i++)
{
	scanf("%d\t",&a[i]);
}printf("\n");
for(int i = 0 ; i<10 ;i++)
{
	printf("%d\t",a[i]);
}

int t ; 

for(int j = 1 ; j<10; j++)

{   t=a[j];
	for( k=0 ; k<j ; k++)
	{
		if(a[j]<a[k])
		{
			for(int p = j; p>k ; p--)
			{
				a[p]=a[p-1];
			}
		}
	}a[k]=t;
}

printf("\n");
for(int i = 0 ; i<10 ;i++)
{
	printf("%d\t",a[i]);
}




}
