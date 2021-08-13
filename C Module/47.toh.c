/******************************************************************************
NAME        :   TAPAS ROY
DATE        :   03/07/21
DESCRIPTION :   WAP implement the solution for tower of hanoi.
INPUT       :   Enter the number of disks N: 3
OUTPUT      :   make the legal move from rod A to C
                make the legal move from rod A to B
                make the legal move from rod C to B
                make the legal move from rod A to C
                make the legal move from rod B to A
                make the legal move from rod B to C
                make the legal move from rod A to C
                Do you want to continue(y/Y) : y

Input       :   Enter the number of disks N : -3
output      :   Error : Enter only positive values
                Do you want to continue (y/Y) : n


*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>

//Declaring the functions
void hanoi(int, char *, char *, char *);
int isvalid(int status);

int main()
{
	//Clear the output screen
	system("clear");

	//Declare the variables here
	char source[] = "A", temp[] = "B", dest[] = "C", option;
	int disk, status;

	do
	{

		//Prompt + read the entered value
		printf("\nEnter the number of disks N : ");
		status = scanf("%d", &disk);

		//Validation of the entered value
		if (isvalid(status) || disk <= 0)
		{
			printf("Error : Enter only positive values\n ");
		
		}

		//Calling the hanoi function
		hanoi(disk, source, temp, dest);

		//Prompt if the program is to be repeated
		printf("Do you want to continue (y/Y) : ");
		scanf("\n%c", &option);

	}while (option == 'Y'|| option == 'y');
	return 0;
}

//Defining the hanoi function
void hanoi(int disk, char *source, char *temp, char *destination)
{
	if (disk > 0)
	{
		//Recursively calling the same function to implement the operation
		hanoi(disk - 1, source, destination, temp);

		//Displaying the action performed 
		printf("make the legal move from rod %s to %s\n", source, destination);
	
		//Recursively calling the same function to implement the operation
		hanoi(disk - 1, temp, source, destination);
	}
}

//Defining the validation function
int isvalid(int status)
{
	if (status != 1)
	{
		return 1;
	}
	return 0;
}	
