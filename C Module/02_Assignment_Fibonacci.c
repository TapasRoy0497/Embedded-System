/* *********************************************************************************************************

NAME 		:	TAPAS ROY
DATE		:	01/06/2021

DESCRIPTION	:	Program to generate fibbonacci numbers <= 'n'
			
			•In mathematics, the Fibonacci numbers or Fibonacci sequence are the
			 numbers in the following integer sequence 1, 1, 2, 3, 5, 8, 13, 21, 34, 55,
			 89, 144 . . . OR 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 . . .
			 By definition, the first two numbers in the Fibonacci sequence are 0 and
			 1, each subsequent number is the sum of the previous two
			•By definition, the first two numbers in the Fibonacci sequence are 0 and
			 1, each subsequent number is the sum of the previous two

INPUT		:	Integer 'n', Where -2^20 < 'n' < 2^20

OUTPUT		: 	Enter a number: 8
			0, 1, 1, 2, 3, 5, 8
			Do you want to continue (y/Y) : y
			Enter a number: 10
			0, 1, 1, 2, 3, 5, 8
			Do you want to continue (y/Y) : y
			Enter a number: -21
			0, 1, -1, 2, -3, 5, -8, 13, -21
			Do you want to continue (y/Y) : y
			Enter a number: -13
			0, 1, -1, 2, -3, 5, -8, 13
			Do you want to continue (y/Y) : y
			Enter a number: 2000000
			Error : Number out of range, please enter the value -2 20 < 'N' < 2 20
			Do you want to continue (y/Y) : n

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
	range = range*2;
    }
    posrange = range; 	//positive range of the limit
    negrange = -range; 	//negative range of the limit
   
    do
    {
    	// Read number from the user
     	printf ("Enter a number : ");
	scanf ("%d", &n);

	// Checking if entered number is within the range
	if ( n < negrange || n > posrange )
	{
	    printf ("Error : Number out of range, please enter the value -2^20 < n <2^20 \n");
	    
	    printf ("Do you want to continue(y/Y) : ");
	    scanf (" %c", &ch); 
	}
	else if ( n > 0) //if entered number is +ve
	{
	    //Declaring local variables
	    int first_num=0, second_num=1, next_num;
	    
	    printf ("%d, %d", first_num, second_num);
	    
	    //Fibonacci series for +ve entered number
	    while ( n != 0 )
	    {
		next_num = first_num + second_num; 	//Generating next number of the series
		if ( next_num <= n ) 			//Checking if next number is <= entered number
		{
		    printf (", %d", next_num);
		    //swapping the values
		    first_num = second_num;
		    second_num = next_num;
		}
		else
		    break;
	    }
	    printf("\n");
	    
	    printf ("Do you want to continue(y/Y) : ");
	    scanf (" %c", &ch); 
	}
	else  		//if entered number is -ve
	{	    
	    //Declaring variables
	    int first_num=0, second_num=1, next_num;
	    printf ("%d, %d", first_num, second_num);
	    //Fibonacci series for -ve entered number
	    while (n != 0 )
	    {
		next_num = first_num - second_num; 		//Generating next number of the series
		if ( next_num <= -n && next_num >= n ) 		//checking if next number is within the limit
		{
		    printf(", %d", next_num);
		    //swapping the values
		    first_num = second_num;
		    second_num = next_num;
		}
		else
		    break;
	    }
	    printf("\n");
	    printf ("Do you want to continue(y/Y) : ");
	    scanf (" %c", &ch); 
	}
		
    }while ( ch == 'y' || ch== 'Y' );
    return 0;
}
