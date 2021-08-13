/****************************************************************************************************************************************
  
NAME              : TAPAS ROY

DATE              : 1-07-2021

DESCRIPTION       : Program to print array elements in an sorted order without modifying an original array

INPUT             :
OUTPUT            :
			Enter the count of float elements need to store : 5
			[0] = 24.5
			[1] = 54.3
			[2] = 78.3
			[3] = 12.45
			[4] = 34.6

			Array elements before displaying sorted elements : 	24.50  54.30  78.30  12.45  34.60

			Array elements after sorting without modifying an original array : 12.45  24.50  34.60  54.30  78.30

			Array elements after displaying sorted elements : 	24.50  54.30  78.30  12.45  34.60

			Do you want to continue (y / Y) : y

			Enter the count of float elements need to store : 4
			[0] = 23.4
			[1] = 2.4
			[2] = 1.5
			[3] = 65.3

			Array elements before displaying sorted elements : 	23.40  2.40  1.50  65.30  

			Array elements after sorting without modifying an original array : 1.50  2.40  23.40  65.30  

			Array elements after displaying sorted elements : 	23.40  2.40  1.50  65.30  

			Do you want to continue (y / Y) : n
			Operation terminated

*****************************************************************************************************************************************/

#include <stdio.h>

// function declaration
void print_array(float *arr, int);
void sort_array(float *arr, int);

int main()
{
    char ch;
    do
    {
	// variable declaration
    	int size, i;
	 // read N value from user
	printf("\nEnter the count of float elements need to store : ");
	scanf("%d", &size);
	
	float arr[size];  // declaring an array with entered size

	// read array elements in an array
	for(i = 0; i < size; i++)
	{
	    printf("[%d] = ", i);
	    scanf("%f", (arr + i) );
	}

	printf("\nArray elements before displaying sorted elements : \t");
	print_array(arr,size);
	
	sort_array(arr,size);  // logic to print sorted elements in an array

	printf("\n\nArray elements after displaying sorted elements : \t");
	print_array(arr,size);

	// ask permission from user to repeat the operation
	printf("\n\nDo you want to continue (y / Y) : ");
	scanf(" %c", &ch);
    }
    while ( ch == 'y' || ch == 'Y');  // if user enters y/ Y then repeat the operation

    printf("Operation terminated\n");

    return 0;
}

void print_array(float *arr, int size)
{
    int i;
    for( i = 0; i < size; i++)
	printf("%.2f  ", *arr++); 
}

void sort_array(float *arr, int size)
{

    float min, max, temp = 0;
    int i, j;

    min = max = *arr;

    printf("\n\nArray elements after sorting without modifying an original array : ");

    // logic to find max and min value in an array
    for (j = 0; j < (size - 2); j++)
    {
	temp = max;

    	for (i = 0; i < size; i++)
    	{
		if ( *(arr + i) < min )
	    		min = *(arr + i);
		if ( *(arr + i) > max )
	    		max = *(arr + i);
    	}
    }

    printf("%.2f  ", min);  // prints min value in an array
    temp = max;

    for(i = 0; i < (size - 2); i++)
    {
	temp = max;

	for (j = 0; j < size; j++)
	{ // logic to find value in ascending order in an array
	    if ( ( *(arr + j) < temp ) && ( *(arr + j) > min ) )
	    {
		temp = *(arr + j);
	    }
	}
	printf("%.2f  ", temp); 
	min = temp;
    }
    printf("%.2f  ", max);   // prints max value in an array
}

