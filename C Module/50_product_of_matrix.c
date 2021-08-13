/****************************************************************************************************************************************
  
NAME              : TAPAS ROY
DATE              : 21-07-2021
DESCRIPTION       : Program to find product of given matrix using Dynamic Memory Allocation
INPUT             :
OUTPUT            :

			Enter no.of rows : 3
			Enter no.of columns : 3
			Enter values for 3 x 3 matrix :
			1 2 3
			1 2 3
			1 2 3
			Input matrix
			1  2  3
			1  2  3
			1  2  3

			Transpose of given matrix :
			1  1  1
			2  2  2
			3  3  3

			Product of two matrix :
			14  14  14
			14  14  14
			14  14  14

			Do you want to continue (y / Y) : y

			Enter no.of rows : 2
			Enter no.of columns : 3
			Enter values for 2 x 3 matrix :
			1 2 3
			1 2 3
			Input matrix
			1  2  3
			1  2  3

			Transpose of given matrix :
			1  1
			2  2
			3  3

			Product of two matrix :
			14  14
			14  14

			Do you want to continue (y / Y) : y

			Enter no.of rows : -3
			Enter no.of columns : 2

			Please enter only positive value
			Do you want to continue (y / Y) : n

			Operation terminated
*****************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// function declaration

void print_matrix(int r, int c, int *ptr[c]);

int main()
{
    char ch;

    do
    {
	// declaring variables
	int row, col, row_t, col_t, i, j, k, sum;

	// prompt to read i/p from user
	printf("\nEnter no.of rows : ");
	scanf("%d", &row);

	printf("Enter no.of columns : ");
	scanf("%d", &col);

	if (row <= 0 || col <= 0 ) // if user enters neg value then print error msg
	{
	    	printf("\nPlease enter only positive value");
	}
	else
	{
		int **A;  // declaring ptr variable
		A = malloc( row * sizeof(int) );  // memory allocation for row 

		for (i = 0; i < row; i++)
		{
		    A[i] = (int *)malloc( col * sizeof(int) );   // memory allocation for col
		}

		printf("Enter values for %d x %d matrix : \n", row, col);

		for (i = 0; i < row; i++)
		{
	    		for (j = 0; j < col; j++)
	    		{
				scanf("%d", &A[i][j]);
	    		}
		}
                
		printf("Input matrix \n");
		print_matrix(row, col, A);
		
		// Transpose of an matrix
		int **AT;

		row_t = col;
		col_t = row;

		AT = malloc( row_t * sizeof(int) );  // memory allocation for row 

		for (i = 0; i < row_t ; i++)
		{
		    AT[i] = (int *)malloc( col_t * sizeof(int) );   // memory allocation for col
		}

		for (i = 0; i < col; i++)
		{
	    		for(j = 0; j < row; j++)
	    		{
				AT[i][j] = A[j][i];
	    		}
		}

		printf("\nTranspose of given matrix : \n");
		print_matrix(col, row, AT);

		// Product of an matrix
		
		int **P;

		P = malloc( row * sizeof(int) );  // memory allocation for row 

		for (i = 0; i < row; i++)
		{
		    P[i] = (int *)malloc( col * sizeof(int) );   // memory allocation for col
		}

		printf("\nProduct of two matrix : \n");

		for (i = 0; i < row; i++)
		{
	    		for (j = 0; j < row; j++)
	    		{
			    sum = 0;
			    for ( k = 0; k < col; k++)
			    {
				sum = sum + (A[i][k]) * (AT[k][j]);
			    }
			    P[i][j] = sum;
	    		}
		}

		print_matrix(row, col_t, P);

		free(A);  // freeing data which is pointed by ptr variable
		A = NULL;  // Assigning Null to ptr variable
		free(AT);
		AT = NULL;
		free(P);
		P = NULL;
	}
	// prompt to ask user to repeat the operation
	printf("\nDo you want to continue (y / Y) : ");
	scanf(" %c", &ch);

    }
    while (ch == 'y' || ch == 'Y'); // if user enters y/Y then repeat the operation

    printf("\nOperation terminated \n");

    return 0;
}

void print_matrix(int r, int c, int *ptr[c])  // function to print value in matrix
{
    int i,j;

    for (i = 0; i < r; i++)
    {
	for(j = 0; j < c; j++)
	{
	    printf("%d  ", ptr[i][j]);
	}
	printf("\n");
    }
}


