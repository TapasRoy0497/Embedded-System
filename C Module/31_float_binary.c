/****************************************************************************************************************************************
  
NAME              : TAPAS ROY

DATE              : 05-08-2021

DESCRIPTION       : Print bits of float & double. Check IEEE std.
			
			• Read the choice from user.
				◦ float or double
			•Read the fractional number from user.
			•Print the bits of the entered number.
			•Write function to print the bits of float and double.
INPUT             :
OUTPUT            :
			Enter the Choice:
			1. float
			2. doubleChoice: 1
			Enter the float value: 2.3
			
			The Binary Form : 0  1 0 0 0 0 0 0 0  0 0 1 0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1
			
			Do you want to continue (y/Y) : y
			
			Enter the Choice:
			1. float
			2. double
			Choice: 2
			Enter the float value: -2.3
			
			The Binary Form is : 1 10000000000 0010011001100110011001100110011001100110011001100110
			Do you want to continue (y/Y) : n
			
*****************************************************************************************************************************************/

#include <stdio.h>

//Function to print float bits
void print_float_bits(int num)
{
    unsigned mask;

    printf("\nThe binary form : ");
    
    for(mask = 1 << sizeof(int) * 8 - 1; mask > 0;mask >>= 1)
    {
	(num & mask) == 0 ? printf("0") : printf("1");
    }
    printf("\n");
}

//Function to print double bits
void print_double_bits(long int num)
{
    unsigned long int mask = 1;

    printf("\nThe binary form : ");

    for(mask = mask << sizeof(long int) * 8 - 1;mask > 0;mask >>= 1)
    {
	(num & mask) == 0 ? printf("0") : printf("1");
    }
    printf("\n");
}

int main()
{
    int choice, *ptr = NULL;
    char option;
    float f_num;
    double d_num;

    do
    {
	//Read choice
	printf("\nMenu\n1. Float\n2. Double\n\nEnter your choice : ");
	scanf("%d", &choice);

	//Execute choice
	switch(choice)
	{
	    case 1:
		    printf("\nEnter the value : ");
		    scanf("%f", &f_num);

    		    print_float_bits(*(int *)&f_num);

		break;
	    case 2:
		    printf("\nEnter the value : ");
		    scanf("%lf", &d_num);

		    print_double_bits(*(long int *)&d_num);

		break;
	    default:
		    printf("ERROR\n");
	}	    

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	getchar();
	scanf("%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
