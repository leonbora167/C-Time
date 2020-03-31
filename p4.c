//Search Algorithm
#include<stdio.h>
#include<time.h>
#include<math.h>

int main()
{
	int size;
	printf("Enter the size of the array to be searched for \n");
	scanf("%d",&size);
	int arr[size];
	printf("Enter the values of the array one by one \n");
	for(int i = 0; i<size; i++)
		scanf("%d",&arr[i]);
    
    printf("\n *** Loop Exit *** \n");
	void LinearSearch(int*, int, int);  //We can also use (int arr[], int n, int num)
	void BinarySearch(int*, int, int); 
	void InterpolationSearch(int*,int, int);
	void JumpSearch(int*, int, int);

	int num;
	printf("Enter the number you are searching for \n");
	scanf("%d",&num);

	printf("\nEnter 1 for LinearSearch \nEnter 2 for Binary Search \nEnter 3 for InterpolationSearch \nEnter 4 for Jump Search");
	int choice;
	scanf("%d",&choice);
    
    clock_t t; //To calculate time complexity of the program
    double time_taken;
	switch(choice)
	{
		case 1: t = clock();
				LinearSearch(arr, size, num);
				t = clock() - t;
				time_taken = ((double)t)/CLOCKS_PER_SEC;
				printf("Time taken for LinearSearch to run is %f seconds",time_taken);
				break;

		case 2: t = clock();
				BinarySearch(arr, size, num);
	            t = clock() - t;
				time_taken = ((double)t)/CLOCKS_PER_SEC;
				printf("Time taken for Binary Search to run is %f seconds",time_taken);
				break;

		case 3: t = clock();
				InterpolationSearch(arr, size, num);
				  t = clock() - t;
				time_taken = ((double)t)/CLOCKS_PER_SEC;
				printf("Time taken for Interpolation Search to run is %f seconds",time_taken);
				break;		

		case 4: t=clock();
				JumpSearch(arr, size, num);
				t = clock() - t;
				time_taken = ((double)t)/CLOCKS_PER_SEC;
				printf("Time taken for Jump Search to run is %f seconds\n",time_taken);
				break;
	}

	return 0;
}

//Linear Search Algorithm Function
void LinearSearch(int array[], int n, int num)
{
	int flag =0;
	for(int i=0; i<n; i++)
	{
		if(array[i]==num)
		{
			printf("\nThe number was found at %d position\n",++i);
			flag = 1;
			break;
		}

	}

	if(flag == 0)
		printf("\n Number not found");
}

//Binary Search Algorithm
void BinarySearch(int array[], int size, int num)
{
	//First We need to sort the algorthm in ascending order
	int temp;
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size-i-1; j++)
		{
			if(array[j] > array[j+1])
			{
				temp = array[j];          
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}

	//Print the arranged array now
	printf("The Array in Ascending order is \n");
	for(int i=0; i<size; i++)
	{
		printf("%d ",array[i]);
	}

	printf("\n \n");

	//Searching ALgo Now
	int pos, low, mid, high;
	low = 0;
	high = size-1;
	int flag = 0;
	while(low <= high)
	{
		mid = (low + high)/2;

		if(array[mid] == num)
		{
			printf("\nNumber is at position %d \n",mid+1);
			flag=1;
			break;
		}

		else if(array[mid] > num)
		{
			high = mid - 1;
		}
		else if(array[mid] < num)
		{
			low = mid +1;
		}
	}

	if(low > high && flag == 0)
		printf("\nThe number doesn't exist in the array\n ");
}



void InterpolationSearch(int array[], int size, int num)
{
	int low,high;
	low = 0; //First index of the Array
	high = size-1; // Index of last element in array
    
    /* Interpolation Search uses a formula to make the possibility of
    Jumping to the middel element more viable and probable.
    in normal cases it makes log(logn) comparisons 
    While in worst case it can go upto O(n) comparison
    */

    int mid;

    /* The formula is
       mid = low +(high-low) *((num-array[low]) / (array[high] - array[low]) )
    */

    int flag = 0;
    while(low <= high)
    {
    	mid = low +((high-low) *((num-array[low]) / (array[high] - array[low]) ));
    	if(num == array[mid])
    	{
    		printf("Number found at position %d \n",mid+1);
    		flag = 1;
    		break;
    	}

    	if(num < array[mid])
    		high = mid - 1;

    	if(num > array[mid])
    		low = mid+1;
    }
    if(flag == 0)
    	printf("\nThe number you are searching for is not available in the array\n");

}



void JumpSearch(int array[], int size, int num)
{
	int step;
	int flag=0;
	int high = size - 1, low = 0;
	step = sqrt(size);
	for(int i = 0; i<step; i++)
	{
		if(num < array[step])
			high = step - 1;

		if(num > array[step])
			low = step - 1;
	}

	for(int i = low; i<=high; i++)
	{
		if(array[i] == num)
		{
			printf("Array is at position %d \n",i+1);
			flag = 1;
		}
	}

	if(flag == 0)
		printf("Number not found in the array \n");
}