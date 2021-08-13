/* *********************************************************************************************************

NAME 		:	TAPAS ROY
DATE		:	10/06/2021

DESCRIPTION	:	Program to check a given number is even or odd and it’s sign using bitwise operators
			
			•Read number n from user.
			•Check the 0 th bit(on LSB end) of the number.
			  ◦ if last bit is 1, number is odd.
			  ◦ if last bit is zero, number is even.
			•Check the number is positive or negative.
			  ◦ Check the 31 st bit for sign
			•Prompt for continue option.
			 
INPUT 		:	A Integer N

OUTPUT 		: 	Enter the value of 'N' : 4
			4 is +ve even number
			
			Do you want to continue(y/Y): y
			
			Enter the value of 'N' : -5
			-5 is -ve odd number
			
			Do you want to continue(y/Y) : N

********************************************************************************************************** */

#include <stdio.h>

int main ()
{
    // Declaring variables
    int num, num_check, sign_check;
    char ch;
    
    do
    {
    	// Read number from the user
     	printf ("\nEnter a number : ");
	scanf ("%d", &num);
	
	num_check = num & 1; 	//Performing bitwise AND (&) operation to get the LSB i.e the 0th bit
	
	sign_check = ( num >> 31 ) & 1; //Performing bitwise right shift(>>) and then bitwise AND (&) to get the MSB i.e the 31st bit

	if ( sign_check == 0 ) 		//When the sign bit is 0 then it is positive number
	{
	    if ( num_check == 0 )	//When the LSB is 0 it is even
	        printf("%d is +ve even number \n", num);
	    else			//When the LSB is 1 it is odd
	        printf("%d is +ve odd number \n", num);
	}	
	else 				//When the sign bit is 1 then it is negative number
	{
	    if ( num_check == 0 ) 	//When the LSB is 0 it is even
	        printf("%d is -ve even number \n", num);
	    else			//When the LSB is 1 it is odd
	        printf("%d is -ve odd number \n", num);
	}
	printf ("\nDo you want to continue(y/Y) : ");
	scanf (" %c", &ch); 
		
    }while ( ch == 'y' || ch== 'Y' );
    
    return 0;
}
