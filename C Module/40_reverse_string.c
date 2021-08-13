/****************************************************************************************************************************************
  
NAME              : TAPAS ROY

DATE              : 8-07-2021

DESCRIPTION       : Program to reverse the string using iterative and recursive method

INPUT             :
OUTPUT            :

			Enter the string : sangeetha
			1. Iterative method
			2. Recursive method
			Enter your choice : 1

			Reversed string using iterative method : ahteegnas
			Do you want to continue (y / Y) : y

			Enter the string : sugeertha raja
			1. Iterative method
			2. Recursive method
			Enter your choice : 2

			Reversed string using recursive method : ajar ahtreegus
			Do you want to continue (y / Y) : y

			Enter the string : sangi
			1. Iterative method
			2. Recursive method
			Enter your choice : 3
			Please Enter valid option

			Do you want to continue (y / Y) : n
			OPeration terminated

*****************************************************************************************************************************************/

#include <stdio.h>
#include <stdio_ext.h>

// Function declaration
void reverse_string_iterative(char *str, int len);
void reverse_string_recursive(char *str, int start, int end);
int my_strlen(char *str);

int main()
{
    // char variable declaration
    char ch;

    do
    {
	char str[50]; // char array declaration
	int choice, len = 0;

	__fpurge(stdin);

	// Read string from user
    	printf("\nEnter the string : ");
	scanf("%50[^\n]s", str);

	// select menu from user
	printf("1. Iterative method\n2. Recursive method");
	printf("\nEnter your choice : ");
	scanf("%d", &choice);

	len =  my_strlen(str);
	if (choice == 1)
	{
	    reverse_string_iterative(str, len);  // function call to iterative method
	    printf("\nReversed string using iterative method : %s", str);
	}
	else if (choice == 2)
	{
	    reverse_string_recursive(str, 0, len-1 );   // function call to recursive methor
	    printf("\nReversed string using recursive method : %s", str);
	}
	else
	    printf("Please Enter valid option\n"); 

	// ask permission from user to repeat the operation
	printf("\nDo you want to continue (y / Y) : ");
	scanf(" %c", &ch);

    }
    while (ch == 'y' || ch == 'Y'); // if user enters y/Y then repeat the opeartion

    printf("OPeration terminated\n");

    return 0;
}

int my_strlen(char *str)
{
    int len = 0, i = 0;

    while (*(str+i) != '\0')   // logic to find string length
    {
	i++;
	len++;
    }

    return len;
}

void reverse_string_iterative(char *str, int len)
{
	int i = 0, j = len - 1;
	char temp;

	while (i < j)   // logic to swap characters using iterative method
	{

	    temp = *(str + i);
	    *(str + i) = *(str + j);
	    *(str + j) = temp;
	    i++;
	    j--;
	}
}

void reverse_string_recursive(char *str, int start, int end)
{
	char temp;

	if (start >= end)
	    return;

	temp = *(str + start);                   // logic to swap characters
	*(str + start) = *(str + end);
	*(str + end) = temp;

	reverse_string_recursive(str, ++start, --end);  // recursive function call
}

