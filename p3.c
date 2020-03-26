//Bitwise Operators

#include<stdio.h>
int main()
{
	printf("Enter the first number in integer format \n");
	int n1;
	scanf("%d",&n1);
	int n1_copy = n1;
	printf("Enter the second number in integer format \n");
	int n2;
	scanf("%d",&n2);
	int n2_copy = n2;

	//Decimal to Binary Conversion
	int a1[100];
	int a2[100];

	int i1=0,r1=0;
    while(n1!=0)
	{
		r1=n1%2;
		a1[i1]=r1;
		i1+=1;
		n1=n1/2;
	}

	int i2=0,r2=0;
	while(n2!=0)
	{
		r2=n2%2;
		a2[i2]=r2;
		i2+=1;
		n2=n2/2;
	}
    
	printf("Size of first index 'i1' is %d",i1);
	printf("\nSize of second index 'i2' is %d \n",i2);

    printf("The first number in binary format is \n");
	for(int j=i1-1; j>=0; j--)
		printf("%d  ",a1[j]);

	printf("\nThe second number in binary format is \n");
	for(int j=i2-1; j>=0; j--)
		printf("%d  ",a2[j]);

	//Organizing the arrays in straight order
	int x1[100];
	int o = 0;
	for(int j=i1-1; j>=0; j--)
	{
		x1[o]=a1[j];
		o++;
	}

	int x2[100];
	o = 0;
	for(int j=i2-1; j>=0; j--)
	{
		x2[o]=a2[j];
		o++;
	}

	//Making the binary array format equal i.e. for any missing lsb we'll add 0 to it

	int f_index = 1;
	f_index = (i1>i2) ? i1 : i2;

	for(int j=0; j<f_index; j++)
	{
		if(x1[j]!=0 && x1[j]!=1)
			a1[j]=0;

		if(x2[j]!=0 && x2[j]!=1)
			a2[j]=0;
	}

	int new_array[100];
	int x;
	
    
    //Menu System for Choosing Operator Operation
    printf("\nEnter 1 for && operation \nEnter 2 for || operation \nEnter 3 for ^  operation \nEnter 4 for << Operation \nEnter 5 for >> Operation");
    int choice;
    scanf("%d",&choice);

    			int s=0;
				int rem = 0;
				int number_2, number_1;
				int shift;
    switch(choice)
    {
    	case 1:
    			for(int j=0; j<f_index; j++)
					{
						x = x1[j] && x2[j];
						new_array[j] = x;
					}
    			printf("\nThe && Operator Conversion is ");
				for(int j=0; j<f_index; j++)
					printf("%d ",new_array[j]);
				break;

		case 2:
				for(int j=0; j<f_index; j++)
				{
					x = x1[j] || x2[j];
					new_array[j] = x;
				}
				printf("\nThe || Operator Conversion is ");
				for(int j=0; j<f_index; j++)
					printf("%d",new_array[j]);
				break;

		case 3:
				for(int j=0; j<f_index; j++)
				{
					x = x1[j] ^ x2[j];
					new_array[j] = x;
				}
				printf("The ^ Operator Conversion is ");
				for(int j=0; j<f_index; j++)
					printf("%d",new_array[j]);
				break;

		case 4: 

			  printf("Enter the value by which u would like to shift");
			  scanf("%d",&shift);
			  printf("\nNumber 1 was %d and Number 2 was %d ",n1_copy,n2_copy);
			  number_1 = n1_copy << shift;
			  number_2 = n2_copy << shift;
			  printf("\nThe numbers after shifting are %d and %d ",number_1,number_2);
				break;


		case 5:
			  printf("Enter the value by which u would like to shift");
			  scanf("%d",&shift);
			  printf("\nNumber 1 was %d and Number 2 was %d ",n1_copy,n2_copy);
			  number_1 = n1_copy >> shift;
			  number_2 = n2_copy >> shift;
			  printf("\nThe numbers after shifting are %d and %d ",number_1,number_2);
			  break;
		default:
				printf("Enter an appropriate command\n");
    }
	

	return 0;

}	