/****************************************************************************************************************************************
  
NAME              : TAPAS ROY
DATE              : 28-06-2021
DESCRIPTION       : Program to write function exactly works like scanf funtion using pointers and functions
INPUT             :
OUTPUT            :

			Enter an number : 9075
			The number is : 9075

			Do you want to continue (y / Y) : y

			Enter an number : +28975
			The number is : 28975

			Do you want to continue (y / Y) : y

			Enter an number : -326
			The number is : -326

			Do you want to continue (y / Y) : y

			Enter an number : ++136
			The number is : 0

			Do you want to continue (y / Y) : y

			Enter an number : --236
			The number is : 0

			Do you want to continue (y / Y) : y

			Enter an number : +-326
			The number is : 0

			Do you want to continue (y / Y) : y

			Enter an number : 427dsg
			The number is : 427

			Do you want to continue (y / Y) : y

			Enter an number : fh57
			The number is : 0

			Do you want to continue (y / Y) : y

			Enter an number : %^&j347
			The number is : 0

			Do you want to continue (y / Y) : y

			Enter an number : 437769%^&*(
			The number is : 437769

			Do you want to continue (y / Y) : n
			Operation terminated

*****************************************************************************************************************************************/

#include <stdio.h>
#include <stdio_ext.h>

// function declaration
int read_int_function(char *);

int main()
{
    char check;  // DEclaring char variable
    do
    {
	__fpurge(stdin);  // clearing stdin buffer
	char ch;
    	char str[100] = {0};  // resetting an array
    	int res = 0, i = 0;  // Initialising variables

    	printf("\nEnter an number : ");  // Prompt to read number from user

    	while ( (ch = getchar() ) != '\n')  // read character by character
    	{
		str[i] = ch;
		i++;
    	}

    	res = read_int_function(str);  // function call

   	printf("The number is : %d\n", res);  // Printing the result

	fflush(stdout);  // clearing stdout buffer
	
	printf("\nDo you want to continue (y / Y) : ");  // prompt to ask user to repeat the operation
	scanf(" %c", &check);
	

    }while ( check == 'y' || check == 'Y');  // if user enters y / Y then continue the operation

    printf("Operation terminated\n");

    	return 0;
}

int read_int_function(char *str)
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

