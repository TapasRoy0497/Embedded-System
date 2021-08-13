/* *********************************************************************************************************

NAME 		:	TAPAS ROY
DATE		:	31/05/2021

DESCRIPTION	:	WAP to demote the type of given float number to integer using bitwise operators and bitfields.
			
			
INPUT 		: 	
OUTPUT		: 	
			Enter a float value : 98.635

			Demoted value : 98.000000

			Do you want to continue? [Yy | Nn] : y

			Enter a float value : -978.6542

			Demoted value : -978.000000

			Do you want to continue? [Yy | Nn] : n

********************************************************************************************************** */


#include<stdio.h>

//Union to store float value
union float_bits{

    float num;
    struct bits{

	unsigned m : 23;
	unsigned e : 8;
	unsigned s : 1;

    }elements;
};

//Function to demote float value
void demote_float(union float_bits *ptr)
{
    int num = ptr->elements.e - 127;

    //printf("N-%d M-%u\n", num, ptr->elements.m);

    //If num is less than 1 0.xyz
    if(num < 0)
    {
	ptr->elements.e = 0;
    }
    else
    {
	//Retain num bits from msb of mantissa
	ptr->elements.m = ptr->elements.m & ~((1 << (23 - num)) - 1);
    }


}

int main()
{
    char option;
    union float_bits var;

    do
    {
	//Read value
	printf("\nEnter a float value : ");
	scanf("%f", &var.num);	
	
	//Call function and print result
	demote_float(&var);
	
	printf("\nDemoted value : %f\n", var.num);

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	getchar();
	scanf("%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
