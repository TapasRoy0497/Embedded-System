/****************************************************************************************************************************************
  
NAME              : TAPAS ROY

DATE              : 9-07-2021

DESCRIPTION       : Program to squeeze the string by using pointers and arrays

INPUT             :
OUTPUT            :

			Enter string1 :sangeetha

			Enter string2 :senthil raja

			After squeeze string1 : g
			Do you want to continue (y / Y) : y

			Enter string1 :senthil raja

			Enter string2 :sugeertha raja

			After squeeze string1 : nil
			Do you want to continue (y / Y) : n
			Operation terminated

*****************************************************************************************************************************************/

#include <stdio.h>
#include <stdio_ext.h>

// function declaration
char *my_squeeze(char *str1, char *str2);

int main()
{

    char ch;

    do
    {
	char str1[50], str2[50];  // declaring character array

	__fpurge(stdin); // clearing stdin buffer
	printf("\nEnter string1 :");
	scanf("%50[^\n]s", str1);
	
	__fpurge(stdin);
	printf("\nEnter string2 :");
	scanf("%50[^\n]s", str2);

	my_squeeze(str1, str2);  // function call to squeeze string

	printf("\nAfter squeeze string1 : %s", str1);  // printing squeezed string 

	// Prompt to ask permission from user to continue the operation
	printf("\nDo you want to continue (y / Y) : ");
	scanf(" %c", &ch);

    }
    while (ch == 'y' || ch == 'Y');  // if user enters y / Y then continue the operation

    printf("Operation terminated\n");
    return 0;
}

char *my_squeeze(char *str1, char *str2)
{
    // initialising local variables
    int i, j, k = 0, count = 0;

    for (i = 0; *(str1 + i) != '\0'; i++) 
    {
	for (j = 0; *(str2+j) != '\0'; j++)
	{
	    if ( *(str1 + i) == *(str2 + j))  // checks character in str1 is available str2 or not
	    	count++;   // inc count value if char matck found
	}

		if (count == 0)  // if no match found in both the strings then update the character in str1
		{
			*(str1 + k) = *(str1 + i);
			k++;
		}

		count = 0;  // resetting count value

    }
    *(str1 + k) = '\0';  // termianting string with null character
}
	    

