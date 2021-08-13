/****************************************************************************************************************************************
  
NAME              : TAPAS ROY

DATE              : 20-07-2021 

DESCRIPTION       : Program to generate magic square of n*n (n is odd and positive)

INPUT             : 
OUTPUT            :

			Enter a number : 3
			8	1	6
			3	5	7
			4	9	2

			Do you want to continue (y / Y) : y

			Enter a number : 5
			17	24	1	8	15
			23	5	7	14	16
			4	6	13	20	22
			10	12	19	21	3
			11	18	25	2	9

			Do you want to continue (y / Y) : y

			Enter a number : -3
			Please enter only positive odd values
			Do you want to continue (y / Y) : y

			Enter a number : 4
			Please enter only positive odd values
			Do you want to continue (y / Y) : n
			Operation terminated

*****************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void magic_square(int n, int *arr);

int main()
{
    char ch;   // declaring char variable

    do
    {
	// declaring variables
    	int num, row, col, i, j;
	// prompt to read input from user
    	printf("\nEnter a number : ");
    	scanf("%d", &num);

    	if ( (num % 2) == 0 || num < 0)
    	{
		printf("Please enter only positive odd values");
	}
	else
	{
	    	row = col = num;  // assigning value num to row and col 

		int *ptr; // ptr variable for 2D array
		ptr = calloc(row * col, sizeof(int));  // allocating memory for row*col size
		
		magic_square(num, ptr);  // function call to generate magic square

		// logic to print array values
		for (i = 0; i < row; i++)
		{
		    for (j = 0; j < col; j++)
		    {
			printf("%d\t", *(ptr + i * num + j));
		    }
		    printf("\n");
		}

		free(ptr); // freeing memory pointed by ptr
		ptr = NULL; 
	}

	// prompt to ask permission from user to repeat the opeartion
	printf("\nDo you want to continue (y / Y) : ");
	scanf(" %c", &ch);
    }
    while(ch == 'y' || ch == 'Y'); // if user enters y / Y then repeat the operation

    printf("Operation terminated\n");

    return 0;
}

void magic_square(int n, int *arr)
{
    int N = n * n;  // calculating total no.of elements

    int i = 0, j = (n/2), k;

    for (k = 1; k <= N; k++)
    {
	*(arr + i * n + j) = k;    // assigning value to the array 
	i--;
	j++;

	if(i < 0)
	{
	    i = i + n;
	}
	if ( j == n )
	{
	    j = 0;
	}

	if ( *(arr + i * n + j) != 0 )
	{
	    i = i + 2;
	    j = j - 1;

	    if (i > n && j < 0)
	    {
		i = i - n;
		j = n - 1;
	    }
	}
    }

}

