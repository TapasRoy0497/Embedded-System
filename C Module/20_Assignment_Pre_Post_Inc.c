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

#include<stdio.h>

//Function Prototype
int pre_increment(int *number);
int post_increment(int *number);

int main()
{
    	//Declaring the variable(s)
	char option;

	do
	{
	    	//Declaring the variable(s)
		unsigned int number, user_choice, i;

		//prompt the user for the number
		printf("Enter the value of N : ");
		scanf("%d", &number);

		//prompt the user for the user_choice
		printf("Enter the operation :\n 1.Pre-Increment\n 2.Post-Increment\nChoice : ");
		scanf("%d", &user_choice);

		//validate the user_choice
		switch(user_choice)
		{
			case 1:
			        	//Calling the pre-increment function and storing the result
					i = pre_increment(&number);
					printf("After pre increment ret = %d num = %d.", i, number);
					break;
			case 2:
					//Calling the post-increment function and storing the result
					i = post_increment(&number);
					printf("After post increment ret = %d, num = %d.", i, number);
					break;
		
			default: 
			        	printf("Invalid Entry....Please enter option 1 or option 2");
		}
        
        	//Prompt if the program is to be repeated
		printf("\nDo you want to continue (y/Y) : ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');

	return 0;
}

//function goes to location, increments the actual value by 1 and returns the value to the main function
int pre_increment(int *number)
{
	if (*number % 2 == 0)
	{
		return   *number = (*number) | 1   ;
	}
	else
	{
		//	return ++*number;
		return *number = (*number & ~(1)) | (1 << 1); //(~(1 << 2) - 1 ))| (1 << 1));//shift 31 bits by 1 and inverse it to get last bit 1 and remaining bit as '0'
	}
}

//function returns the value present it that particular location and then increments the value by 1
int post_increment(int *number)
{
	int num = *number;
	if (*number % 2 == 0)
	{

	   *number = (*number) | 1   ;
	}
	else
	{
		//	return ++*number;
		 *number = (*number & ~(1)) | (1 << 1); //(~(1 << 2) - 1 ))| (1 << 1));//shift 31 bits by 1 and inverse it to get last bit 1 and remaining bit as '0'
	}
	return num;
}
