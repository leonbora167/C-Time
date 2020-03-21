// Binary to decimal conversion
#include<stdio.h>
#include<math.h>

int main()
{
	printf("Enter the number for Binary to Decimal conversion \n");
	int n;
	scanf("%d",&n);
	
	int i=0,r;
	int s=0;
	while(n!=0)
	{
		r=n%10;
		s+=pow(2,i);
		i=i+1;
		n=n/10;
	}
	
	printf("The number in Decimal form is %d",s);
	return 0;
}