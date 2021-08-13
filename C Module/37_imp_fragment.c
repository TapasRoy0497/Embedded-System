/****************************************************************************************************************************************
  
NAME              : TAPAS ROY

DATE              : 26-07-2021 

DESCRIPTION       : Program to implement fragments using array of pointers 

INPUT             :
OUTPUT            :
			Enter no.of rows : 4

			Enter no.of coloumns in arr[0] : 3

			Enter no.of coloumns in arr[1] : 4

			Enter no.of coloumns in arr[2] : 3

			Enter no.of coloumns in arr[3] : 5

			Enter 3 values for arr[0] : 3 5 6

			Enter 4 values for arr[1] : 4 3 5 3

			Enter 3 values for arr[2] : 3 4 5

			Enter 5 values for arr[3] : 3 4 5 6 4

			Array elements before sorting :
			3  5  6   4.66667
			4  3  5  3   3.75
			3  4  5   4
			3  4  5  6  4   4.4
			Array elements after sorting :
			4 3 5 3 3.75
			3 4 5 4
			3 4 5 6 4 4.4
			3 5 6 4.66667

			Do you want to continue (y / y) : n
			Operation terminated

*****************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>


int main()
{
    char ch;

    do
    {
	// declaring variables
    	int row, col, i, j, col_arr[100], size[20];
       float sum = 0;

	printf("\nEnter no.of rows : ");
	scanf("%d", &row);

	float *arr[row];  // initialising memory for row is static

	int out_arr[row];


	for (i = 0; i < row; i++)
	{
	    printf("\nEnter no.of coloumns in arr[%d] : ", i);
	    scanf("%d", &col);
	    col_arr[i] = col;

	    arr[i] = (float *)malloc( (col + 1) * sizeof(float));   // initialising memory for col dynamically
	    out_arr[i] = i;
	}
	
	// Read input from user
	for (i = 0; i < row; i++)
	{
	    
	    printf("\nEnter %d values for arr[%d] : ", col_arr[i], i);
	    
	    for (int k = 0; k < col_arr[i]; k++)
	    {
	    	scanf("%f", (*(arr + i) + k) );
	    }
	}

	printf("\nArray elements before sorting : \n");
	float temp_arr[100];
	int k = 0;

	for (i = 0; i < row; i++)
	{
	    sum = 0; float avg = 0;
	    for (j = 0; j < col_arr[i] ; j++)
	    {
		printf("%g  ", arr[i][j]); // printing array elements before sorting

		sum = sum + arr[i][j];  // sum calculation
	    }

	    avg = (sum / col_arr[i]);  // avg calculation
	    arr[i][j] = avg;

	    printf(" %g \n", arr[i][j]); // printing avg on each row
	}
	
	                /*checking the mean and sorting with the mean values of 'n' arrays*/
         for( i=0; i < row-1; i++)
         {
              for( j=0; j < row-1-i; j++)
              {

                  if(arr[out_arr[j]][col_arr[out_arr[j]]] > arr[out_arr[j+1]][col_arr[out_arr[j+1]]])  // comparing array elements
		  {
                                        out_arr[j] = out_arr[j] + out_arr[j+1] - (out_arr[j+1] = out_arr[j]); // swapping 
		  }
              }

          }

	 printf("Array elements after sorting : \n");

	 for (i = 0; i < row; i++)
	 {
	     for (j = 0; j < (col_arr[out_arr[i]] + 1 ); j++)
	     {
		 printf("%g ", arr[out_arr[i]][j]);  // printing array elements
	     }
	     printf("\n");
	 }


	// Ask permission from user to repeat the operation	
	printf("\nDo you want to continue (y / y) : ");
	scanf(" %c", &ch);
    }
    while (ch == 'y' || ch == 'Y'); // if user enters y / Y then repeat the operation

    printf("Operation terminated \n");

    return 0;
}


