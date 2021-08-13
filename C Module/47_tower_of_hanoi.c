/****************************************************************************************************************************************
  
Name              : Tapas Roy
Date              : 01-07-2021
Description       : Program to find tower of hanoi using recursive function
Input             :
Output            :

Enter the number of disks 'N' : 3
Make the legal move from rod A to C
Make the legal move from rod A to B
Make the legal move from rod C to B
Make the legal move from rod A to C
Make the legal move from rod B to A
Make the legal move from rod B to C
Make the legal move from rod A to C

Do you want to continue (Y/ y) : y

Enter the number of disks 'N' : 2
Make the legal move from rod A to B
Make the legal move from rod A to C
Make the legal move from rod B to C

Do you want to continue (Y/ y) : y

Enter the number of disks 'N' : -4
Error : Please enter only positive values

Do you want to continue (Y/ y) : y

Enter the number of disks 'N' : 1
Invalid : Please enter number of disks more than 2 

Do you want to continue (Y/ y) : y

Enter the number of disks 'N' : 5
Make the legal move from rod A to C
Make the legal move from rod A to B
Make the legal move from rod C to B
Make the legal move from rod A to C
Make the legal move from rod B to A
Make the legal move from rod B to C
Make the legal move from rod A to C
Make the legal move from rod A to B
Make the legal move from rod C to B
Make the legal move from rod C to A
Make the legal move from rod B to A
Make the legal move from rod C to B
Make the legal move from rod A to C
Make the legal move from rod A to B
Make the legal move from rod C to B
Make the legal move from rod A to C
Make the legal move from rod B to A
Make the legal move from rod B to C
Make the legal move from rod A to C
Make the legal move from rod B to A
Make the legal move from rod C to B
Make the legal move from rod C to A
Make the legal move from rod B to A
Make the legal move from rod B to C
Make the legal move from rod A to C
Make the legal move from rod A to B
Make the legal move from rod C to B
Make the legal move from rod A to C
Make the legal move from rod B to A
Make the legal move from rod B to C
Make the legal move from rod A to C

Do you want to continue (Y/ y) : n
Operation terminated

*****************************************************************************************************************************************/

#include <stdio.h>
// Function declaration
void tower_of_hanoi(int n, char A, char B, char C);

int main()
{
    char ch;
    do
    {
	// Variable declaration
    	int N;
        char A, B, C;

	// Prompt to read N (no.of disks) feom user
    	printf("\nEnter the number of disks 'N' : ");  
	scanf("%d", &N);

	// validation of i/p
	if( N < 0 )
	{
	    printf("Error : Please enter only positive values\n");
	}
	else if ( N < 2 )
	{
	    printf("Invalid : Please enter number of disks more than 2 \n");
	}
	else
	{

		tower_of_hanoi(N, 'A', 'C', 'B');  // function call 
	}
	
		printf("\nDo you want to continue (Y/ y) : ");  // ask permission from user to continue the operation
		scanf(" %c", &ch);

    }
    while ( ch == 'y' || ch == 'Y'); // if user enters (y / Y) then repeat the operation

    printf("Operation terminated\n");

    return 0;
}

void tower_of_hanoi(int n, char A, char C, char B)
{
 
  	if ( n == 1)
	{
		printf("Make the legal move from rod %c to %c\n", A, C);
		return;
	}
   	tower_of_hanoi( n-1, A, B, C);  	// recursive function call
	
	printf("Make the legal move from rod %c to %c\n", A, C);
   	
	tower_of_hanoi( n-1, B, C, A); 
}
