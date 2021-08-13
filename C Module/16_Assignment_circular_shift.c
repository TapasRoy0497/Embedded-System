/* *********************************************************************************************************

NAME 		:	TAPAS ROY
DATE		:	17/06/2021

DESCRIPTION	:	Read an integer & a number n. Circular right & left shift the int by n.

INPUT		:	Integers N(both +ve and -ve), S(No.of shifts)

OUTPUT		: 	Enter num: 12
			Enter n : 3
			Possible operations
			1. circular right shift
			2. circular left shift
			Enter your choice: 1
			The binary form of number : 00000000 00000000 00000000 00001100
			After circular right shifting by 3
			The bianry form of number : 10000000 00000000 00000000 00000001
			Want to continue ( y/Y ) : y
			Enter num: -12
			Enter n : 3
			Possible operations
			1. circular right shift
			2. circular left shift
			Enter your choice: 1
			The binary form of number : 11111111 11111111 11111111 11110100
			After circular right shifting by 3
			The bianry form of number : 10011111 11111111 11111111 11111110
			Want to continue (y/Y) : n

********************************************************************************************************** */


#include<stdio.h>

//function declaration
unsigned int right_shift( unsigned int number,unsigned  int n_bits);
unsigned int left_shift(unsigned int number,unsigned int n_bits);
void print_bits(int value);

int main()
{
    //Declare the variable
	unsigned int num, value, n_bits, user_choice;
	char option;

	do
	{
		//prompt the user for the Number
		printf("Enter num : ");
		scanf("%d", &num);

		//prompt for the n-bit to be shifted
		printf("Enter n : ");
		scanf("%d", &n_bits);

		//prompt the user for the User_choice
		printf("Possible operations\n1. Circular Right shift\n2. Circular Left shift\nEnter Your Choice : ");
		scanf("%d", &user_choice);

		//validate the user_option
		switch(user_choice)
		{
		    //Function call within the switch case
			case 1:
			        //Function call to right rotate bits
				    printf("The binary form of number : ", num);
				    print_bits(num);
				
				    //calls the function to perform right shift
				    value = right_shift(num, n_bits);
                
                    printf("\nAfter circular right shifting by %d ", n_bits);
                    
                    //Calling function to print bits
				    printf("\nThe binary form of number : ");
				    print_bits(value);

				    break;
				    
			case 2:
			        //Function call to left rotate bits
				    printf("The binary form of number : ", num);
				    print_bits(num);

				    //calls the function to perform left shift
				    value = left_shift(num, n_bits);
				
				    printf("\nAfter circular left shifting by %d ", n_bits);
                    
                    //Calling function to print bits
				    printf("\nThe binary form of number : ");
				    print_bits(value);

				    break;
				    
			default:
				    printf("Invlid Entry. Please select option 1 or option 2");
		}
        //Prompt if the program is to be repeated
		printf("\nDo you want to continue (y/Y) : ");
		scanf("\n%c", &option);
	}
	while (option == 'Y' || option == 'y');

	return 0;
}

//function returns the circular_right shifted value
unsigned int right_shift(unsigned int num,unsigned int n_bits)
{
	return  ((num & ((1 << n_bits) - 1)) << (sizeof(int) * 8 - n_bits)) | (num >> n_bits);

}

//function returns the circular_left shifted value
unsigned int left_shift(unsigned int num,unsigned int n_bits)
{
	return   ((num & (~0 << (sizeof(int) * 8 - n_bits))) >> (sizeof(int) * 8 - n_bits))  | (num << n_bits)  ; 
}

//function prints the value in binary form
void print_bits(int value)
{
	unsigned mask;

	for(mask = (1 << (sizeof(int) * 8 - 1)); mask; mask >>= 1)
	{
		(value & mask) ? putchar('1'): putchar('0');
	}

}
