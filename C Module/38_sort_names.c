/****************************************************************************************************************************************
  
NAME              : TAPAS ROY

DATE              : 27-07-2021 

DESCRIPTION       : Program to sort names by using static and dynamic arrays

INPUT             :
OUTPUT            :
			Please enter how many names you want to enter : 5

			Enter 5 names of length max 32 characters in each :
			[0] -> Delhi
			[1] -> Agra
			[2] -> Kolkata
			[3] -> Bangalore
			[4] -> Chennai

			Sorted names are :
			[0] -> Agra
			[1] -> Bangalore
			[2] -> Chennai
			[3] -> Delhi
			[4] -> Kolkata

			Do you want to continue (y / Y) : y

			Please enter how many names you want to enter : 3

			Enter 3 names of length max 32 characters in each :
			[0] -> hello
			[1] -> kojopw
			[2] -> woijfcoplkmsvpjovlkywyteivjbdihvsvodiiwueegu
			Error : please enter name upto characters including null character

			Do you want to continue (y / Y) : n
			Operation terminated

*****************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

// function declaration
int my_string_length(char *str);
int my_strcmp(char *str1, char *str2);

int main()
{
    char ch;

    do
    {	// Deaclaring variables
	int row, i, j, len = 0;

	char **arr;

	printf("\nPlease enter how many names you want to enter : ");
	scanf("%d", &row);

	char name[row]; // no.of character in static

	arr = malloc( sizeof(char *) * row ); 

	printf("\nEnter %d names of length max 32 characters in each : \n", row);

	for (i = 0; i < row; i++)
	{
	    name[i] = i;
	    arr[i] = (char *) malloc (sizeof (char) * 32);   // allocating memory dynamically for col values

	    printf("[%d] -> ", i);
	    scanf("%s", arr[i]);   // read names from user

	    len = my_string_length(arr[i]); // function call to find string length

	    if (len > 32)
	    {
		break;  // if length is > 32 then come out of loop and stops reading input
	    }
	}

	if (i != row)   // if no.of characters entered for name is greater than 32 means print error msg
	{	    
		printf("Error : please enter name upto 32 characters including null character \n");
	}
	else
	{

	    for (i = 0; i < row -1 ; i++)
	    {
		for(j = 0; j < row - i - 1; j++)
		{
		    if (my_strcmp(arr[name[j]], arr[name[j+1]]) > 0)   // function call to cmp 2 strings
		    {
			name[j] = name[j] + name[j+1] - ( name[j+1] = name[j] );   // swap two strings
		    }
		}
	    }

	    printf("\nSorted names are : \n");

	    for (i = 0; i < row; i++)
	    {
		printf("[%d] -> %s\n", i, arr[name[i]]);  // printing sorted names in ascending order
	    }
	}


	__fpurge(stdin); // clearing input buffer

	// prompt to ask permission from user to repeat the operation
	printf("\nDo you want to continue (y / Y) : ");
	scanf(" %c", &ch);
    }
    while (ch == 'y' || ch == 'Y'); // if user enters y / Y then repeat the operation

    printf("Operation terminated \n");

    return 0;
}

int my_string_length(char *str)
{
    int len = 0;
    // logic to find string length
    while (*str)
    {
	len++;
	str++;
    }
    return len;
}

int my_strcmp(char *str1, char *str2)
{
        while( *str1 && *str2 )
        {
                if( *str1 != *str2 )
                {
                         if( ( *str1 >= 97 && *str1 <= 122 ) && ( *str2 >= 65 && *str2 <= 90 ) )
                         {
                                if( *str1 != *str2 + 32 )   // strcmp with ignoring case
                                {
                                        return ( (*str1) - *str2+32 );  // return the difference
                                }
                         }
                         else if( (*str2 >= 97 && *str2 <= 122 && *str1 >= 65 && *str1 <= 90) )
                         {
                                if(*str1+32 != *str2 )
                                {
                                        return ((*str1 + 32) - (*str2));
                                }
                         }
                         else
                         {
                                return (*str1 - *str2);  // return the difference
                         }
                }
                *str1++;  // incrementing ptr variable (next char check)
                *str2++;
        }
        return (*--str1 - *--str2);  // return diff of two strings (if any one string is null char or both)
}

