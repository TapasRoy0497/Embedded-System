/* *********************************************************************************************************

NAME 		:	TAPAS ROY
DATE		:	03/06/2021

DESCRIPTION	:	To Print all ascii characters
			• Print the Decimal numbers from 0 to 127 in Octal, Hexadecimal 
			  and in ASCII representation.
			• Display as 'Non Printable' for non-printable characters
			
INPUT 		:	None
			
OUTPUT 		: 	 Dec  	  Oct      Hex     ASCII 
			----- 	 -----    -----    ----- 
			 0 	  000 	    00    Not Printable

			 1 	  001 	    01    Not Printable

			 2 	  002 	    02    Not Printable

			 3 	  003 	    03    Not Printable

			 4 	  004 	    04    Not Printable

********************************************************************************************************** */
#include<stdio.h>

int main() 
{
    printf ("\t Dec  \t  Oct  \t  Hex  \t ASCII \n");
    printf ("\t----- \t ----- \t ----- \t ----- \n");
    
    //Loop to print the ASCII table
    for ( int i=0;i<=127;i++)
    {
	//Condition to print ASCII characters as non printable and Dec, Oct, Hex values from 0 - 32 and 127
        if(i <= 32 || i == 127)
	{
	    printf("\t %d \t  %03o \t  %02X \t  Not Printable\n", i, i, i);
	}
	else 	//then print Dec, Oct, Hex and ASCII for index values 33-126
	{
	    printf("\t %d \t  %03o \t  %02X \t  %c\n", i,i,i,i);
	}
        printf("\n");
    }
    
    return 0;
}
