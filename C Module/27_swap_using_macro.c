/***********************i*****************************************************************************************************************
  
NAME              : TAPAS ROY

DATE              : 31-07-2021

DESCRIPTION       : Program to interchage 2 arguments (swap values) of all data type by using macro 

INPUT             : 
OUTPUT            :
			1. Int
			2. char
			3. short
			4. float
			5. double
			6. string
			Enter your choice : 1
			Enter 2 integer values  : 
			3 5

			Before Swapping : 
			num1 = 3 , num2 = 5
			After swapping  : 
			num1 = 5 , num2 = 3

			Do you want to continue( Y / y)  :  y
			1. Int
			2. char
			3. short
			4. float
			5. double
			6. string
			Enter your choice : 2
			Enter 2 characters number : 
			G S

			Before Swapping : 
			c1 = G , c2 = S
			After swapping  : 
			c1 = S , c2 = G

			Do you want to continue( Y / y)  :  y
			1. Int
			2. char
			3. short
			4. float
			5. double
			6. string
			Enter your choice : 3
			Enter 2 short int values : 
			5 8 

			Before Swapping : 
			s1 = 5 , s2 = 8
			After swapping  : 
			s1 = 8 , s2 = 5

			Do you want to continue( Y / y)  :  y
			1. Int
			2. char
			3. short
			4. float
			5. double
			6. string
			Enter your choice : 4
			Enter 2 float values : 
			2.3 5.32

			Before Swapping : 
			f1 = 2.300000 , f2 = 5.320000
			After swapping  : 
			f1 = 5.320000 , f2 = 2.300000

			Do you want to continue( Y / y)  :  y
			1. Int
			2. char
			3. short
			4. float
			5. double
			6. string
			Enter your choice : 6
			Enter 2 strings : 
			Hi Hello

			Before Swapping : 
			str1 = Hi , str2 = Hello
			After swapping  : 
			str1 = Hello , str2 = Hi

			Do you want to continue( Y / y)  :  y
			1. Int
			2. char
			3. short
			4. float
			5. double
			6. string
			Enter your choice : 7

			Please select an valid option
			Do you want to continue( Y / y)  :  n
			 Operation terminated 

*****************************************************************************************************************************************/

#include<stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

#define SWAP(TYPE, x, y)          \
{                                 \
    TYPE temp;                    \
    temp = x;                     \
    x = y;                        \
    y = temp;                     \
}

int main()
{
        char ch;  //declaring char variable
	
	do
	{
	    // Declaring variables for all data type
	    int choice;
	    int num1, num2;
	    char c1, c2;
	    short s1, s2;
	    float f1, f2;
	    double d1, d2;
	    char *str1, *str2;
	    
	    // memory allocation for string variable (DMA)
	    str1 = malloc( sizeof(char) * 50 );
	    str2 = malloc(sizeof(char) * 50 );

        	// Pompt to print menu

        	printf("1. Int\n2. char\n3. short\n4. float\n5. double\n6. string\nEnter your choice : ");
        	
        	scanf("%d", &choice);  // read choice from user
        	
		switch ( choice )
		{
		    case 1 :
                        	printf("Enter 2 integer values  : \n");
                        	scanf("%d %d",&num1, &num2);  // read 2 int values from user

           		        printf("\nBefore Swapping : \nnum1 = %d , num2 = %d\n", num1, num2);

                		SWAP(int, num1, num2);  // logic to swap 2 values using macro (type of data, var1, var2)

                		printf("After swapping  : \nnum1 = %d , num2 = %d\n", num1, num2);
				break;

		    case 2 :
				__fpurge(stdin);  // clearing stdin buffer
				printf("Enter 2 characters number : \n");
                        	scanf("%c %c", &c1, &c2);
           		        
				printf("\nBefore Swapping : \nc1 = %c , c2 = %c\n", c1, c2);
                		SWAP(char, c1, c2);

                		printf("After swapping  : \nc1 = %c , c2 = %c\n", c1, c2);
				break;

		    case 3 :

                        	printf("Enter 2 short int values : \n");
                       		scanf("%hd %hd", &s1, &s2);
				
				printf("\nBefore Swapping : \ns1 = %hd , s2 = %hd\n", s1, s2);

                		SWAP(short, s1, s2);

                		printf("After swapping  : \ns1 = %hd , s2 = %hd\n", s1, s2);
				break;
		    case 4 :

                        	printf("Enter 2 float values : \n");
                       		scanf(" %f %f", &f1, &f2);
				
				printf("\nBefore Swapping : \nf1 = %f , f2 = %f\n", f1, f2);

                		SWAP(float, f1, f2);

                		printf("After swapping  : \nf1 = %f , f2 = %f\n", f1, f2);
				break;

		    case 5 :

                        	printf("Enter 2 double values : \n");
                       		scanf(" %lf %lf", &d1, &d2);
				
				printf("\nBefore Swapping : \nd1 = %lf , d2 = %lf\n", d1, d2);

                		SWAP(double, d1, d2);

                		printf("After swapping  : \nd1 = %lf , d2 = %lf\n", d1, d2);
				break;

		    case 6 :
                        	printf("Enter 2 strings : \n");
				__fpurge(stdin);
				scanf("%s %s", str1, str2);
				
				printf("\nBefore Swapping : \nstr1 = %s , str2 = %s\n", str1, str2);

                		SWAP(char* , str1, str2);

                		printf("After swapping  : \nstr1 = %s , str2 = %s\n", str1, str2);

				free(str1);
				free(str2);
				
				break;
		    default:
				printf("\nPlease select an valid option");
				break;

		}

                //if you continue to exection again following statement will execute
                printf("\nDo you want to continue( Y / y)  :  ");
                scanf(" %c", &ch);
	}
        while (  ch == 'Y' || ch == 'y' );  // if user enters y/Y then repeat  the operation

        printf(" Operation terminated \n");


return 0;
}

