// Decimal to Binary Conversion
#include<stdio.h>
int main()
{   
	printf("We have entered the main function \n");
	int i=0;
	int a[100];
	
	printf("Enter the number to convert into binary format \n");
	int n;
	scanf("%d",&n);
	int r=0, s=0;
	
	int index = 100;
	while(n!=0)
	{
		r=n%2;
		a[i]=r;
		i = i+1;
		n=n/2;
		
		
	}
	
	printf("The number in binary format is \n");
	for(int j=i-1; j>=0; j--)
		printf("%d  ",a[j]);
	
	return 0;
}
