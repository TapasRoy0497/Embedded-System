/****************************************************************************************************************************************
  
NAME              : TAPAS ROY

DATE              : 8-07-2021 

DESCRIPTION       : Program to generate nrps string using pinters, arrays and arrays

INPUT             :
OUTPUT            :

			Enter no.of characters : 3

			Enter length of the string : 6

			Enter 3 distinct characters : ert

			Possible NRPS string is : ertrte

			Do you want to continue (y / Y) : y

			Enter no.of characters : 3

			Enter length of the string : 6

			Enter 3 distinct characters : eert

			Invalid no. of characters , Please enter 3 characters
			Do you want to continue (y / Y) : y

			Enter no.of characters : 3

			Enter length of the string : 6

			Enter 3 distinct characters : qwq
			Error : Please enter 3 distinct characters

			Do you want to continue (y / Y) : n
			Operation terminated

*****************************************************************************************************************************************/

#include <stdio.h>
#include <stdio_ext.h>

// function declaration
char get_NRPS_string(char *str1, char *str2, int n, int len);
int repeat_char_check(char *str, int N);
int check_len(char *str);

int main()
{
    char ch; // var declaration

    do
    {
	int N, L, ret = 0, len = 0;
        
	// character array declaration	
    	char str1[50];
	char str2[50];

	// Prompt to read input from user
    	printf("\nEnter no.of characters : ");
    	scanf("%d", &N);

    	printf("\nEnter length of the string : ");
    	scanf("%d", &L);


	// Input validation
    	if (N > 10 || N < 1)
    	{
		printf("Invalid : No.of characters should be 1 to 10\n");
    	}
    	else
    	{
    		printf("\nEnter %d distinct characters : ", N);
		
		__fpurge(stdin);  //  clearing stdin buffer
		scanf("%50[^\n]s", str1);
		
		len = check_len(str1);
		
		if (len > N || len < N)   // if entered string length is not equal to N means print error msg
		{
		    printf("\nInvalid no. of characters , Please enter %d characters", N);
		}
		else
		{
		
			ret = repeat_char_check(str1, N);  // function call to check for repeated characters in entered string

			if (ret == -1)
			{
		    		printf("Error : Please enter %d distinct characters\n", N);  // validation
			}
			else
			{
				printf("\nPossible NRPS string is : ");
		
				get_NRPS_string(str1, str2, N, L);   // Function call to generate NRPS

				printf("%s\n", str2);
			}
		}

		__fpurge(stdin);  //  clearing stdin buffer
		// Prompt to ask permission from user to repeat the operation
		printf("\nDo you want to continue (y / Y) : ");
		scanf(" %c", &ch);
    	}
    }
    while(ch == 'y' || ch == 'Y');  // if user enters y/Y then repeat the operation
    
    printf("Operation terminated\n");
    return 0;
}

int check_len(char *str)
{
    int len = 0;

    while (*str)
    {
	str++;
	len++;
    }

    return len;
}


int repeat_char_check(char *str, int N)
{
    int i, j;

    for (i = 0; i < N; i++)
    {
	for (j = (i + 1); j < N; j++)
	{
	    if (str[i] == str[j])   //  condition to find repeated char in string
		return -1;
	}
    }
}
char get_NRPS_string(char *str1, char *str2, int n, int len)
{
    int i, count = 0;

    for(i = 0; i < len; i++)
    {
	if (i % n == 0 && i != 0)
	    count++;
	*(str2 + i) = *(str1 + ((i + count) % n));  // Generating and storing NRPS string
    }

    *(str2 + i) = '\0';  // terminating string with null character
}
    

