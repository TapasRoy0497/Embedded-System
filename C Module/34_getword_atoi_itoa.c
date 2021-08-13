/****************************************************************************************************************************************
  
NAME              : TAPAS ROY

DATE              : 09-07-2021

DESCRIPTION       : Program to implement getword, atoi, itoa functions using functions and pointers

INPUT             :
OUTPUT            :
			1. getword
			2. atoi
			3. itoa
			Enter your choice : 1

			Enter a word :hello all

			You entered hello all and length of first word is 5
			Do you want to continue (y / Y) : y

			1. getword
			2. atoi
			3. itoa
			Enter your choice : 1

			Enter a word :hello

			You entered hello and length of first word is 5
			Do you want to continue (y / Y) : y

			1. getword
			2. atoi
			3. itoa
			Enter your choice : 2

			Enter a numeric string : -5689
			String to integer is : -5689
			Do you want to continue (y / Y) : y

			1. getword
			2. atoi
			3. itoa
			Enter your choice : 654
			Please enter an valid option

			Do you want to continue (y / Y) : y

			1. getword
			2. atoi
			3. itoa
			Enter your choice : 2     

			Enter a numeric string : 678hhj
			String to integer is : 678
			Do you want to continue (y / Y) : y

			1. getword
			2. atoi
			3. itoa
			Enter your choice : yuhv3345
			Please enter an valid option

			Do you want to continue (y / Y) : y

			1. getword
			2. atoi
			3. itoa
			Enter your choice : 2

			Enter a numeric string : uui4499
			String to integer is : 0
			Do you want to continue (y / Y) : y

			1. getword
			2. atoi
			3. itoa
			Enter your choice : 2    

			Enter a numeric string : ++56 
			String to integer is : 0
			Do you want to continue (y / Y) : y

			1. getword
			2. atoi
			3. itoa
			Enter your choice : 3

			Enter an number : 43615
			Integer to string is : 43615
			Do you want to continue (y / Y) : y

			1. getword
			2. atoi
			3. itoa
			Enter your choice : 3

			Enter an number : -6135
			Integer to string is : -6135
			Do you want to continue (y / Y) : n
			Operation terminated

*****************************************************************************************************************************************/

#include <stdio.h>
#include <stdio_ext.h>

// function declaration
int get_word(char *str);
int my_atoi(char *str);
char my_itoa(int num, char *str);

int main()
{
    char ch;

    do
    {
	// Variable initialisation
	int choice = 0, len = 0, num = 0;
	char str[50];

	__fpurge(stdin);  // clears stdin buffer
	printf("\n1. getword\n2. atoi\n3. itoa\nEnter your choice : ");  // prompt to read choice from user
	scanf("%d", &choice);

	switch(choice)
	{
	    case 1:
		__fpurge(stdin);
		printf("\nEnter a word :");
		scanf("%50[^\n]", str);
	
	//	len = get_word(str);  // function call to get a word

		printf("\nYou entered %s", str );
		printf(" and length of first word is %d", get_word(str));  // prints result
		break;

	    case 2:
		__fpurge(stdin);
		printf("\nEnter a numeric string : ");
		scanf("%50[^\n]", str); // read string from user

		printf("String to integer is : %d", my_atoi(str));  // function call to convert string to integer
		break;

	    case 3:

		__fpurge(stdin);
		printf("\nEnter an number : ");  // read number fro user
		scanf("%d", &num);

		my_itoa(num, str);
		printf("Integer to string is : %s", str); // function call to convert integer to string
		break;

	    default :
		printf("Please enter an valid option\n");
		break;
	}

	__fpurge(stdin);
	// prompt to ask permission from user to repeat the operation
	printf("\nDo you want to continue (y / Y) : ");
	scanf(" %c", &ch);
	
    }while(ch == 'y' || ch == 'Y'); // If user enters (y / Y ) then repeat the operation

    printf("Operation terminated\n");
    return 0;
}

int get_word(char *str)
{
	int len = 0;
    while (*str != '\n' && *str != ' ' && *str != '\t' && *str != '\0')  // logic to count length of first word
    {
	len++;
	str++;
    }
    *str = '\0';
    return len;
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

char my_itoa(int num, char *str)
{

    int i = 0, j = 0, rem = 0;
    int l = 0, k = 0, len = 0, num1 = num;
    char temp = 0;

    if ( num < 0 ) 
	 num = -1 * num;

    for (i = 0; num != 0; i++ )  // logic to convert int to string (it wil be in reversed order)
    {
	rem = num % 10;
	num = num / 10;
	*(str + i) = rem + 48;
	len++;
    }

    l = 0;		
    k = len - 1;
    
    for (i = 0; i < k; i++)  // string reverse function to make it in order as per i/p
    {
	temp = *(str + i);
       *(str + i) = *(str + k);
	*(str + k) = temp;
 	k--; 
    }

	if (num1 < 0)   // if number is negative shift all data to 1 position towards right 
	{
	    int end = 1;
		for (j = len + 1; j > 0; j--)
		{
	    		*(str + j) = *(str + j - 1);
			end++;
		}

		*(str + j) = '-';        // insert '-' in 0th index
		*(str + --end ) = '\0';    // inset null character at last

	}
	else  // for positive number
	{
	    	*(str + len) = '\0';  // insert null character at last
	}
}
