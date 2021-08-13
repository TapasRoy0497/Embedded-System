/* *********************************************************************************************************

NAME 		:	TAPAS ROY
DATE		:	31/05/2021

DESCRIPTION	:	Program to check whether a given number is odd or even and its signedness
			
			The user entered number should identified whether its a odd or a even
			number. Mention its sign too.
			
			Inputs: -
			Integer 'N'. Where -2^20 < 'N' < 2^20
			
			Sample execution: -
			Test Case 1:
			
			Enter the value of 'n' : -4
			-4 is -ve even number
			Do you want to continue(y/Y): y
			Enter the value of 'n' : 4
			4 is +ve even number
			Do you want to continue(y/Y): y
			Enter the value of 'n' : 2000000
			Number out of range
			Do you want to continue(y/Y): y
			Enter the value of 'n' : 0
			0 is neither odd nor even
			Do you want to continue(y/Y): n

INPUT 		: 	-10
OUTPUT		: 	-10 is -ve even number

********************************************************************************************************** */

#include <stdio.h>

int main()
{
    // Declaring variables
    int n, i, range=1, posrange, negrange;
    char ch;
    
    // Calculating range for the number to be checked
    for ( i=1; i<=20; i++ )
    {
	range=range*2;
    }
    posrange = range; 	//positive range of the limit
    negrange = -range; 	//negative range of the limit
   
    do
    {
    	// Read number from the user
     	printf ("Enter the value of 'n' : ");
	scanf ("%d", &n);

	// Checking if entered number is within the range
	if ( n < negrange || n > posrange )
	{
	    printf ("Number out of range \n");
	    
	    printf ("Do you want to continue : ");
	    scanf (" %c", &ch); 
	}
	else if ( n == 0 ) 	// Checking if the entered number is 0
	{
	    printf ("%d is neither odd nor an even number. \n", n);
	    
	    printf ("Do you want to continue : ");
	    scanf (" %c", &ch); 
	}
	else
	{
	    //Checking for even or odd
	    if ( n % 2 == 0 )
	    {
		if ( n < 0 ) 	// Checking -ve or +ve even
		{
		    printf ("%d is a -ve even number. \n", n);
		}
		else
		{
		    printf ("%d is a +ve even number. \n", n);
		}
	    }
	    else
	    {
		if ( n < 0 ) 	// Checking -ve odd or +ve odd
		{
		    printf ("%d is a -ve odd number. \n", n);
		}
		else
		{
		    printf ("%d is a +ve odd number. \n", n);
		}
	    }
	    printf ("Do you want to continue : ");
	    scanf (" %c", &ch); 
	}
	
    }while( ch == 'y' || ch == 'Y' );
    
    return 0;
}
