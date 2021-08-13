/****************************************************************************************************************************************
  
NAME              : TAPAS ROY
DATE              : 12-07-2021
DESCRIPTION       : Program to calculate variance with static and dynamic memory allocation
INPUT             : 
OUTPUT            :
			Enter the no.of elements : 10
			1. Static allocation
			2. Dynamic allocation
			Enter your choice : 
			1
			Enter the elements : 
			[0] = 9
			[1] = 12
			[2] = 15
			[3] = 18
			[4] = 20
			[5] = 22
			[6] = 23
			[7] = 24
			[8] = 26
			[9] = 31

				x(input) 	 D = x - mean 	 D^2 

				9 		 -11 		 121
				12 		 -8 		 64
				15 		 -5 		 25
				18 		 -2 		 4
				20 		 0 		 0
				22 		 2 		 4
				23 		 3 		 9
				24 		 4 		 16
				26 		 6 		 36
				31 		 11 		 121
			sum_input = 200 				 sum_D^2 = 400

			The variance of the entered numbers is : 40

			Do you want to continue (y / Y) : y

			Enter the no.of elements : 10
			1. Static allocation
			2. Dynamic allocation
			Enter your choice : 
			2
			Enter the elements : 
			[0] = 9
			[1] = 12
			[2] = 15
			[3] = 18
			[4] = 20
			[5] = 22
			[6] = 23
			[7] = 24
			[8] = 26
			[9] = 31

				x(input) 	 D = x - mean 	 D^2 

				9 		 -11 		 121
				12 		 -8 		 64
				15 		 -5 		 25
				18 		 -2 		 4
				20 		 0 		 0
				22 		 2 		 4
				23 		 3 		 9
				24 		 4 		 16
				26 		 6 		 36
				31 		 11 		 121
			sum_input = 200 				 sum_D^2 = 400

			The variance of the entered numbers is : 40

			Do you want to continue (y / Y) : y

			Enter the no.of elements : 5
			1. Static allocation
			2. Dynamic allocation
			Enter your choice : 
			1
			Enter the elements : 
			[0] = 2
			[1] = 43
			[2] = 5
			[3] = 3
			[4] = 54

				x(input) 	 D = x - mean 	 D^2 

				2 		 -19.4 		 376.36
				43 		 21.6 		 466.56
				5 		 -16.4 		 268.96
				3 		 -18.4 		 338.56
				54 		 32.6 		 1062.76
			sum_input = 107 				 sum_D^2 = 2513.2

			The variance of the entered numbers is : 502.64

			Do you want to continue (y / Y) : n
			Operation terminated

*****************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// function declaration
static int read_input(int *, int );
static int memory_allocation(int, int);
int find_variance(int *, int , int );

int main()
{
    char ch;

    do
    {
	// variable declaration and definition
	int n, choice, mean = 0;
	
	// prompt to read input from user
	printf("\nEnter the no.of elements : ");
	scanf("%d", &n);

	// prompt to ask user to select option
	printf("1. Static allocation\n2. Dynamic allocation\nEnter your choice : \n");
	scanf("%d", &choice);
	printf("Enter the elements : \n");

	// function call to allocate memory for static / dynamic 
	memory_allocation(n, choice); 

 	// prompt to ask permission from user to repeat the operation
	printf("\nDo you want to continue (y / Y) : ");
	scanf(" %c", &ch);

    } while (ch == 'y' || ch == 'Y');  // if user enters y /Y then then repeat the operation

    printf("Operation terminated\n");

    return 0;
}

// function to read input from user for static / dynamic depends on choice
static int read_input(int *arr, int n) 
{
    int i = 0, sum = 0;

    for(i = 0; i < n; i++)
    {
	printf("[%d] = ", i);
	scanf("%d", (arr + i) );

	sum =  sum + *(arr + i);
    }

    find_variance(arr, n, sum);
}

// function to allocate memory static / dynamic depends on choice
static int memory_allocation(int n, int choice)
{

	if (choice == 1) 
        {
                int arr[n];  // static memory allocation
                read_input(arr, n); // function call to read input for array elements
        }
        else if (choice == 2)
        {
                int *ptr = (int *)malloc(n * sizeof(int));  // memory allocation (DMA)
                if (ptr == NULL)
                {
                    printf("Memory not allocated\n");
                }
                else
                {
                        read_input(ptr, n);  // function call to read input for DMA 
                        free(ptr);  // freeing ptr
                        ptr = NULL;  // making pointer as null after freeing
                }
        }
        else
        {
                printf("Invalid choice\n");  // if user enters other than 1 , 2 then print error msg
        } 

}

// function to calculate the variance
int find_variance(int *arr, int n, int sum)
{
    	float mean = 0, sum1 = 0; 
	float variance = 0;

    	int i;
       	float arr_D[n], arr_D2[n];
    	
	mean = ((float) sum / n);   // find avg of entered elements

	printf("mean = %g\n", mean);

    	for (i = 0; i < n; i++)
    	{
		arr_D[i] = arr[i] - mean;   
		arr_D2[i] = ( (arr_D[i]) * (arr_D[i]) );   
		sum1 = sum1 + arr_D2[i];  
    	}
    	
	i = 0;
	printf("\n\tx(input) \t D = x - mean \t D^2 \n\n");

    	for(i = 0; i < n; i++)
    	{
		printf("\n\t%d \t\t %g \t\t %g", arr[i], arr_D[i], arr_D2[i]);
    	}
	
    	printf("\nsum_input = %d \t\t\t\t sum_D^2 = %g\n", sum, sum1);
	
	variance = (sum1 / n );
    	printf("\nThe variance of the entered numbers is : %g\n", variance);
}
