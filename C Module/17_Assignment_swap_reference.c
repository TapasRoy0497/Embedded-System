/* *********************************************************************************************************

NAME 		:	TAPAS ROY
DATE		:	19/06/2021

DESCRIPTION	:	•Read number a from user.
			•Read number b from user.
			•Call a swap function by passing address of both a & b.
			•After swap function, num1 and num2 values should get swapped without 
			 using temprory variable and using bitwise operator.
			•Prompt for continue option.

INPUT		:	2 Integers num1 and num2

OUTPUT		: 	Enter a number num1 : 10
			Enter a number num2 : 20
			After swapping,
			num1 = 20
			num2 = 10
			Do you want to continue(y/Y) : n

********************************************************************************************************** */

#include<stdio.h>

void swap(int *, int *); 	//Function protoype

int main()
{
    char ch;
    do
    {
    	int num1, num2;
    	
    	//Prompting and reading inputs from user
    	printf("\nEnter num1 : ");
    	scanf("%d",&num1);
    	printf("Enter num2 : ");
    	scanf("%d",&num2);

    	swap(&num1, &num2); 	//Function call (pass by reference)

    	//Printing the swapped values
    	printf("After swapping : \n");
    	printf("num1 = %d\n", num1);
    	printf("num2 = %d\n", num2);

	printf("\nDo you want to continue : ");
	scanf (" %c", &ch);
    }while ( ch == 'y' || ch == 'Y');
    return 0;
}

//Function defination
void swap( int *n1, int *n2)
{
    //Making use of Bitwise operator XOR(^) to swap the values
    *n1 = *n1 ^ *n2;
    *n2 = *n1 ^ *n2;
    *n1 = *n1 ^ *n2;
}
