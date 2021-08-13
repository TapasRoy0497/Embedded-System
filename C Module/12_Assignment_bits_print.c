/* *********************************************************************************************************

NAME 		:	TAPAS ROY
DATE		:	14/06/2021

DESCRIPTION	:	Program to print bits of signed and unsigned types for given number 
			and check for 2’s complement
			•Read number n from user.
			•Print the 32 bit binary representation of n and 2’s complement of n.
			•And compare both.
			•Prompt for continue option.
			 
INPUT 		:	Integer N

OUTPUT 		: Enter the number : 12
		  +12 -> 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0
		  -12 -> 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 0 0
		  Do you want to continue(y/Y): n	

********************************************************************************************************** */



#include <stdio.h>

//Function declaration
void print_bit (int);

int main ()
{
    // Declaring variables
    int num, num1;
    char ch;
    
    do
    {
    	//Promting and Reading input from user
    	printf("Enter a number : ");
    	scanf("%d", &num);
    	
    	printf("\t%d -> ", num); 	
    	print_bit(num); 	//Function call
    	
    	num1= -num;
    	
    	printf("\n");
    	printf("\t%d -> ", num1);
	print_bit(num1); 	//Function call

    	printf("\n\nDo you want to continue : ");
    	scanf(" %c", &ch);
    }while( ch == 'y' || ch == 'Y');

    return 0;
}

//Function to print the bits 
void print_bit (int num) 	//Function defination
{
    unsigned int i;
    for (i = 1 << 31; i > 0; i = i / 2)
    {
        (num & i) ? printf(" 1 ") : printf(" 0 "); 	//Using ternary operator to print the bits
    }
}
