/****************************************************************************************************************************************
  
NAME              : TAPAS ROY

DATE              : 30-07-2021

DESCRIPTION       : Program to implement scanf function by using variadic function.

INPUT             :
OUTPUT            :

			Enter an number : 45
			Enter an character  : A
			Enter an string : Hello
			Enter an float number  : 5.674
			Enter an double value : 5.36788888

			Data which is stored after reading input from user :

			Entered number is : 45
			Entered character is : A
			Entered string is : Hello
			Entered float value is : 5.674000
			Entered double value is : 5.367889

			Enter 2 int values :
			4
			5
			No.of successful read input(s) : 2
			num1 = 4, num2 = 5

			Do you want to continue ( y / Y ) : n

			Operation terminated

*****************************************************************************************************************************************/
#include <stdio.h>
#include<stdarg.h>
#include <stdlib.h>
#include<stdio_ext.h>
// function declaration
int my_scanf(const char *, ...);
void scan_int(int *dptr);
int my_atoi(char *str);

int main()
{
        char choice;

        do
        {
	       __fpurge(stdin);	   // clearing stdin buffer
		// Declaring variables
        	int num = 0, num1 = 0, num2 = 0;
        	char ch;
        	char *str;
        	float f;
        	double d;

		// prompt to read input from user
        	printf("\nEnter an number : ");
        	my_scanf("%d", &num);                    // read int data from user
       		
	       __fpurge(stdin);	
        	printf("Enter an character  : ");
        	my_scanf(" %c", &ch);                   // read char data from user
	       
		__fpurge(stdin);	
                printf("Enter an string : ");
        	my_scanf("%s", str);                    // read string from user
        
        	printf("Enter an float number  : ");
        	my_scanf("%f", &f);                     // read float data from user
        
       		printf("Enter an double value : ");
        	my_scanf("%lf", &d);                    // read double data from user

		printf("\nData which is stored after reading input from user : \n");

		// Printing stored values which is read from user
        	printf("\nEntered number is : %d\n", num);
        	printf("Entered character is : %c\n", ch);
        	printf("Entered string is : %s\n", str);
        	printf("Entered float value is : %f\n", f);
        	printf("Entered double value is : %lf\n", d); 


		printf("Enter 2 integer values , str, float, double: \n");
		printf("\nNo.of successful read input(s) : %d\n", my_scanf("%d %d", &num1, &num2) );
		printf("num1 = %d, num2 = %d\n", num1, num2);
        
		__fpurge(stdin);
		printf("\nDo you want to continue ( y / Y ) : ");
                my_scanf(" %c",&choice); 
         } 
	while ( choice == 'y' || choice =='Y' );

	printf("\nOperation terminated \n");

        return 0;
}

int my_scanf(const char *format, ...)
{
      
        va_list ap;   // creating argument pointer
        int *iptr = NULL;
	int *int_iptr = NULL;
	int count = 0, i;
        char *cptr;
        char *str;
        float *fptr;
        double *dptr;
	char *check_ptr;

        va_start(ap, format);   // argument pointer pointing to first argument to the function

        while (*format)
	{
                if ( *format == '%' )
                {
                        format++;
                        if ( *format == '\0' )
			{
			        printf("Error : Invalind format specifier\n");
				exit(1);
			}
                	if ( *format == 'd')
			{
			    fflush(stdout);
                            __fpurge(stdin);
			    //fflush(stdout);
	    		    iptr == NULL;		    
			    iptr = va_arg(ap, int *);
                	    scan_int(iptr);

			    if (*iptr != 0)
                	    	count++;
                       	    format++;
                        }

                        if ( *format == 'c' )
			{
                             __fpurge(stdin);
			     fflush(stdout);
                             cptr = va_arg(ap, char *);
                             *cptr = getchar();
                             count++;
                             format++;
                         }

                         if ( *format == 's' )
			 {

                              __fpurge(stdin);
                              str = va_arg(ap, char *);
                              fscanf(stdin,"%s",str);
                              count++;
                              format++;
                          }

                          if ( *format == 'f' )
			  {
                              __fpurge(stdin);
                              fptr = va_arg(ap, float *);
                              fscanf(stdin,"%f",fptr);
                              count++;
                              format++;
                          }

                          if ( *format == 'l' )
			  {
			       format++;
                               __fpurge(stdin);
                      
		      	       if(*format == 'f')
                               {
                                    dptr = va_arg(ap, double *);
                                    fscanf(stdin,"%lf",dptr);
                                    format++;
                                }
                                else
                                    format--;
			   }
                }
                else
                {
		    format++;
                }
        }
        va_end(ap);   // clearing ptr variable
        return count;  // returning count (no.of i/p successfully read)
}

void scan_int(int *dptr)
{
    char sbuf[200] = {0};
    char ch;    
    int i;
    
    ch = getchar();
    /* read the data from stdin till it reaches space, 
     * tab or newline and save that into a buf
     */
    for (i = 0; ((ch != ' ') && (ch != '\t') && (ch != '\n')) ; i++)
    {
        sbuf[i] = ch;
        ch = getchar();
    }
    
    /* return intger value into obtained address */
    *dptr = my_atoi(sbuf);

}
int my_atoi(char *str)
{
     char str1[50];  // Defining an char array
        int i, val, count = 0, temp1 = 0, temp2 = 0, sign = 0;  // Initialising variables

        // logic to implement function like scanf
        for( i = 0; *(str+i) != '\0'; i++)
        {
            // if base address of string is <48 || >57 && (+ && -) then return 0 to  main fun
            if ( ( *str < 48 || *str > 58 ) && ( *str != '+' && *str != '-') )
            {
                return 0;
            }
            else if ( (count == 0 && *str == '+') || ( count == 0 && *str == '-') ) //if base address of str is + / - then assign the sign
            {

                if ( *str == '+')
                {
                        sign = 1;
                        count++;
                }
                else if( *str == '-')
                {
                        sign = -1; 
                        count++;
                }
            }
            else if ( *(str+i) >= 48 && *(str+i) <= 57 )  // condition true if element of str is >=48 && <=57
            {
                temp1 = (int)(*(str+i));  // converting Ascii to int
                temp1 = temp1 - 48; 
                temp2 = (temp2 * 10) + temp1;
            }
            else if ( (count == 1 && *(str+1) == '+') || ( count == 1 && *(str+1) == '-'))
            {
                return 0;  // if str+1 = +/- then return 0 (++ / -- / -+ / +-)
            }

        }

        if ( sign == 1 ) 
                return temp2;
        else if (sign == -1) 
                return -temp2;
        else
                return temp2;
}

