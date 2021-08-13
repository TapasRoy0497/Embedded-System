/* *********************************************************************************************************

NAME 		:	TAPAS ROY
DATE		:	27/06/2021

DESCRIPTION	:	WAF for pre and post increment and passing int pointer as their parameter.

INPUT		:	Integer N

OUTPUT		: 	Enter the value of N : 5
			Enter the operation :
			1. Pre-Increment
			2. Post-Increment
			Choice : 2
			After post increment ret = 5, num = 6
			Do you want to continue(y/Y) : n

********************************************************************************************************** */
#include <stdio.h>

int main ()
{
    char ch;
    static long int num, fact =1, n ;
    
    if ( fact == 1 )
    {
	/*int range = 1;
    	for(int i =1; i <= 20; i++)
	    range = range * 2; */

	printf("\nEnter a number : ");
    	scanf ("%ld", &num);
	n = num;
    }

    if (num > 1)
    {
	fact = fact * (num--);

	main();
    }
    else
    {
	printf("Factorial of %ld is : %ld\n",n, fact);
	printf("\nDo you want to continue : ");
	scanf(" %c", &ch);

	if(ch == 'y' || ch == 'Y')
	{
    		fact = 1;
    		main();
	}
    }   	
}
