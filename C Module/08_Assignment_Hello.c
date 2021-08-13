/* *********************************************************************************************************

NAME 		:	TAPAS ROY
DATE		:	02/06/2021

DESCRIPTION	:	Program to print “Hello” in X format.
			
			•When the program is run, the provided string should be printed on the
			terminal in X formation
		
INPUT 		:	A positive integer say 'N'. Where N < 2^5
OUTPUT 		: 	Enter a number lines: 5
			Hello   Hello
			 Hello Hello
			 HelloHello
			 Hello Hello
			Hello   Hello
			
			Do you want to continue(y/Y) : y
			
			Enter a number lines: 32
			Number out of range
			
			Do you want to continue(y/Y) : y
			
			Enter a number lines: 6
			Hello   Hello
			 Hello Hello
			  HelloHello
			  HelloHello
			 Hello Hello
			Hello   Hello
			Do you want to continue(y/Y) : y
			
			Enter a number lines: -3
			Enter only positive values

********************************************************************************************************** */

#include <stdio.h>

int main()
{
    //Declaring variables
    int num, row, col, range=1, i;
    char ch;
     
    //Calculating range for the entered number
    for ( i=1; i<=5; i++)
    {
	range = range * 2;
    }


    do
    {
	//Reading input from user 
    	printf("Enter number of lines : ");
    	scanf("%d",&num);

	printf ("\n");
	
	if ( num < 0 ) 		//Checing if the entered number is positive or negative
	{
	    printf("Enter only positive values. \n");
	    
	    printf ("Do you want to continue (y/Y) : ");
	    scanf (" %c", &ch);
	}
	else if ( num > range ) 	//Checking if the enterd number is within range
	{
	    printf("Number out of range. \n");
	    
	    printf ("Do you want to continue (y/Y) : ");
	    scanf (" %c", &ch);
	}
	else 			//If number is positive and within range then generating the pattern
	{
	    for( row = 1; row <= num; row++ )
	    {
		for ( col = 1; col <= num; col++ )
		{
		    if( row == col || row+col == num+1 ) 	
		    {
			printf("Hello");
			if (row == col && row+col == num+1)
			{
			    printf("Hello");
			}
		    }
		    else
		    {
			printf(" ");
		    }
		}
		printf("\n");
	    }
	    
	    printf ("\n");
	    printf ("Do you want to continue (y/Y) : ");
	    scanf (" %c", &ch);
	}
    }while( ch == 'y' || ch == 'Y');

    return 0;
}

