/******************************************************************************
NAME 		:	TAPAS ROY

DATE		:	27/06/2021

DESCRIPTION	:	WAP to generate fibbonacci numbers <= 'n' using recursions 
			without using static keyword and global variables.

INPUT		:	Enter the value of N: 8

OUTPUT		: 	Fibbonacci series using recursive functions is
                	0, 1, 1, 2, 3, 5, 8
                	Do you want to continue(y/Y) : y

INPUT		:	Enter the value of N: -13

OUTPUT		: 	Fibbonacci series using recursive functions is
		        0, 1, -1, 2, -3, 5, -8, 13
		        Do you want to continue(y/Y) : n

                
*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>

//Declaring the function
int pos_fibbo(int, int, int, int);
int neg_fibbo(int, int, int, int);

int main()
{
	//Declare the variables
	int num1, num2, res, limit, status;
	char option;

	do
	{
		//Clear the output screen
		system("clear");

		//Prompt + read the limit
		printf("Enter the value of N: ");
		status = scanf("%d", &limit);

		//Validation to check if entered value is an integer
		if (status != 1)
		{
			printf("Invalid entry.. Please enter an integer number\n");
			return 0;
		}

		//Display the result
		printf("Fibbonacci series using recursive functions is\n", limit);

		//Initialising the variables for logic operation
		num1 = 0;
		num2 = 1;
		res = 0;

		//Condition to call positive or negative function based on entered limit 
		if (limit > 0)
		{
			pos_fibbo(num1, num2, res, limit);
		}
		else
		{
			neg_fibbo(num1, num2, res, limit);
		}

		//Prompt is the program is to be repeated
		printf("\nDo you want to continue(y/Y) : ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
}

//Defining the function to print postive fibonacci series
int pos_fibbo(int num1, int num2, int res, int limit)
{
	if (num1 <= limit)
	{
		printf("%d ", num1);
		res = num1 + num2;
		num1 = num2;
		num2 = res;
		pos_fibbo(num1, num2, res, limit);
	}
	return 0;
}

//Defining the function to print negative fibonacci series
int neg_fibbo(int num1, int num2, int res, int limit)
{
	if (num1 >= limit &&  num1 <= -limit)
	{
		printf("%d ", num1);
		res = num1 - num2;
		num1 = num2;
		num2 = res;
		neg_fibbo(num1, num2, res, limit);
	}
	return 0;
}

