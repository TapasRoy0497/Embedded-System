/****************************************************************************************************************************************
  
NAME              : TAPAS ROY

DATE              : 22-06-2021

DESCRIPTION       : Program to find endianess of the processor using pointers
INPUT             :
OUTPUT            :
 
			Enter any number
			43
			Little endian system
			Do you want to continue (Y / y)
			y
			Enter any number
			-34
			Little endian system
			Do you want to continue (Y / y)
			y
			Enter any number
			0x4e
			Little endian system
			Do you want to continue (Y / y)
			y
			Enter any number
			0
			Little endian system
			Do you want to continue (Y / y)
			y
			Enter any number
			2356
			Little endian system
			Do you want to continue (Y / y)
			y
			Enter any number
			0300
			Little endian system
			Do you want to continue (Y / y)
			n
			Operation terminated

*****************************************************************************************************************************************/

#include<stdio.h>

int main()
{
    char option;
    int num;
    char *ptr = NULL;

    do
    {
	//Read value
	printf("\nEnter a number less than or equal to 15 1Byte: ");
	scanf("%d", &num);

	{
	    //Point to the first byte
	    ptr = (char *)&num;

	    if(*ptr == (char)num)
	    {
		printf("Your system is Little Endian\n");
	    }	    
	    else
	    {
		printf("Your system is Big Endian\n");
	    }
	}

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	getchar();
	scanf("%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
