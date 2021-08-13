/* *********************************************************************************************************

NAME 		:	TAPAS ROY
DATE		:	01/06/2021

DESCRIPTION	:	Program toto check whether a given number is perfect or not.
			
			• In number theory, a perfect number is a positive integer that is equal to
			  the sum of its proper positive divisors, that is, the sum of its positive
			  divisors excluding the number itself (also known as its aliquot sum).
			• Equivalently, a perfect number is a number that is half the sum of all of
			  its positive divisors (including itself).

INPUT		:	A positive integer say 'n'. Where n < 2^20

OUTPUT		: 	Enter a number: 6
			Yes, entered number is perfect number
			Do you want to continue (y/Y) : y
			Enter a number: 10
			No, entered number is not a perfect number
			Do you want to continue (y/Y) : y
			Enter a number: -1
			Error : Invalid Input, Enter only positive number
			Do you want to continue (y/Y) : y
			Enter a number: 2000000
			Number out of range
			Do you want to continue (y/Y) : n

********************************************************************************************************** */

#include <stdio.h>

int main ()
{
    // Declaring variables
    int n, i, range=1, sum=0;
    char ch;
    
    // Calculating range for the number to be checked
    for ( i = 1; i <= 20; i++ )
    {
	range=range*2;
    }
    
    do
    {
    	// Read number from the user
     	printf ("Enter a number : ");
	scanf ("%d", &n);

	// Checking if entered number is within the range
	if ( n > range )
	{
	    printf ("Number out of range \n");
	    
	    printf ("Do you want to continue (y/Y) : ");
	    scanf (" %c", &ch);
	}
	else if ( n <= 0 ) 		//Checking if number is positive and not equal to 0
	{
	    printf ("Error : Invalid Input, Enter only positive number \n");
	    
	    printf ("Do you want to continue (y/Y) : ");
	    scanf (" %c", &ch);
	}
	else
	{
	    for ( i = 1; i <= n/2; i++ )
	    {
		if ( n % i == 0 ) 	//Finding the divisors of entered number
		{
		    sum = sum + i; 	//Calculating the sum of the divisors
		}
	    }
	    //Checking perfect number or not
	    if ( sum == n )
	    {
		printf ("Yes, entered number is perfect number. \n");
	    }
	    else
	    {
		printf ("No, entered number is not a perfect number. \n");
	    }

	    printf ("Do you want to continue (y/Y) : ");
	    scanf (" %c", &ch);
	}
    }while( ch == 'y' || ch == 'Y');

    return 0;
}
