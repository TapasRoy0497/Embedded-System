/* *********************************************************************************************************

NAME 		:	TAPAS ROY
DATE		:	10/06/2021

DESCRIPTION	:	Program to print all primes smaller than or equal to n.
			Use Sieve of Eratosthenes method
			
			•In mathematics, the sieve of Eratosthenes, one of a number of prime
			 number sieves, is a simple, ancient algorithm for finding all prime
			 numbers up to any given limit. It does so by iteratively marking as
			 composite (i.e., not prime) the multiples of each prime, starting with the
			 multiples of 2.
			
			•The sieve of Eratosthenes is one of the most efficient ways to find all of
			 the smaller primes. It is named after Eratosthenes of Cyrene, a Greek
			 mathematician.
			 
INPUT 		:	A positive integer 'N'. Where 1 < 'N' < 2^20

OUTPUT 		: 	Enter the value of 'n' : 20
			The primes less than or equal to 20 are : 2, 3, 5, 7, 11, 13, 17, 19
			
			Do you want to continue(y/Y) : y
			
			Enter the value of 'n' : -20
			Invalid Input
			
			Do you want to continue(y/Y) : y
			
			Enter the value of 'n' : 2000000
			Number out of range
			
			Do you want to continue(y/Y) : N

********************************************************************************************************** */

#include <stdio.h>

int main()
{
    // Declaring variables
    int num, i, range=1;
    char ch;
    
    // Calculating range for the number to be checked
    for ( i = 1; i <= 20; i++ )
    {
	range = range*2;
    }
       
    do
    {
    	// Read number from the user
     	printf ("\nEnter a number : ");
	scanf ("%d", &num);

	// Checking if entered number is within the range
	if ( num > range )
	{
	    printf ("Error : Number out of range, please enter the value 1 < num <2^20 \n");
	    
	    printf ("\nDo you want to continue(y/Y) : ");
	    scanf (" %c", &ch); 
	}
	else if ( num < 0 ) //if entered number is -ve
	{    
	    printf("Invalid Input\n");
	    printf ("\nDo you want to continue(y/Y) : ");
	    scanf (" %c", &ch); 
	}
	else  		
	{	    
	    
	    int i, j, arr[num+1];
	    
	    //Storing 0 in positions- 0 and 1 since 0 and 1 are not primes
	    arr[0]=0;
	    arr[1]=0;
	
	    /*Storing 1 in the remaining array from position 2 to the end 
	    since those position numbers are the potential primes*/ 
	    for( i = 2; i <=num; i++)
		arr[i]=1;
	    
	    //Starting from the least prime number i.e 2	    
	    for ( i = 2; i <= num; i++ )
	    {
		//check if number i is prime
		if (arr[i] == 1) 
	        {
	            //marking the multiples as 0, indicating not prime
	            for ( j = i * i; j <= num; j+=i )
	            {
	                arr[j]=0;
	            }
	        }
	    }
	    
	    //Print all the prime numbers
	    printf("The Prime numbers less than or equal %d are : ", num);
	    for ( i = 1; i <= num; i++)
	    {
	        if (arr[i] == 1)
	        { 
	            printf("%d ", i);	        
	        }
	    }
	    printf ("\n\nDo you want to continue(y/Y) : ");
    scanf (" %c", &ch); 
	}
		
    }while ( ch == 'y' || ch== 'Y' );
    return 0;
}
