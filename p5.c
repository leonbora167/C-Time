//Operations on a n*n matrix

#include<stdio.h>
#include<conio.h>



int main()
{
	printf("Enter the size of rows or columns of the matrix \n");
	int n;
	scanf("%d",&n);
	int arr1[n][n];
	printf("The matrix will be of size %d",n*n);
	printf("\nEnter the values for the matrix");
	
	for(int i=0; i<n; i++)
	{
		printf("\nEnter value for row %d \n",i+1);
		for(int j=0; j<n; j++)
		{
			scanf("%d", &arr1[i][j]);
			
		}
	
	
	}
	
	printf("\n The %d size sqaure matrix is ",n*n);
	for(int i=0; i<n; i++)
		{
			printf("\n");
			for(int j=0; j<n; j++)
				printf("%d",arr1[i][j]);
		}
	
	
	//2nd Matrix		
	printf("\nNow enter values for matrix 2");
	int arr2[n][n];
	
	for(int i=0; i<n; i++)
	{
		printf("\nEnter values for row %d \n",i+1);
		for(int j=0; j<n; j++)
		{
		
			scanf("%d", &arr2[i][j]);
	    }
	}	
	
	printf("\n The matrix number 2 is\n");
	
	for(int i=0; i<n; i++)
	{
		printf("\n");
		for(int j=0; j<n; j++)
			printf("%d",arr2[i][j]);
	}
	
	printf("\nEnter 1 for Adding both Matrixes \nEnter 2 for subtracting both matrixes \nEnter 3 to multiply both matrixes");
	int ch;
	scanf("\n %d",&ch);
	
	
	//Declaring Functions
    //void add(int arr1[n][n], int arr2[n][n], int n);
	
	
	switch(ch)
	{
		case 1:
				add(arr1, arr2, n);
				break;
		/*
		case 2:
				sub(arr1, arr2, n);
				break;
		
		case 3:
				mul(arr1, arr2, n);
				break;
		*/
		default:
				printf("\nWrong Choice Entered \n");
	}	
	return 0;
}


//Function to add 2 matrixes
void add(int arr1[][100], int arr2[][100], int n)
{
	int sum[n][n];
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			sum[i][j] = arr1[i][j] + arr2[i][j];
			
	printf("\nThe resulting matrix sum is \n");
	for(int i=0; i<n; i++)
	{
		printf("\n");
		for(int j=0; j<n; j++)
			printf("%d",sum[i][j]);
    }
    
    
}

void sub(int arr1[][100], int arr2[][100], int n)
{
	int sum[n][n];
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			subtract[i][j] = arr1[i][j] - arr2[i][j];
			
}

void mul(int arr1[][100], int arr2[][100], int n)
{
	int multi[n][n];
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			multi[i][j] += arr1[i][j] * arr2[i][j];
}
