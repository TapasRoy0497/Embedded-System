/****************************************************************************************************************************************
  
NAME              : TAPAS ROY

DATE              : 10-07-2021

DESCRIPTION       : Program to print possible combinations of an entered string using strings , pointers and arrays

INPUT             :
OUTPUT            :

			Enter a string
			abc
			Possible combinations of entered string are :
			abc
			acb
			bac
			bca
			cba
			cab

			Do you want to continue (y / Y) :y
			Enter a string
			wert
			Possible combinations of entered string are :
			wert
			wetr
			wret
			wrte
			wtre
			wter
			ewrt
			ewtr
			erwt
			ertw
			etrw
			etwr
			rewt
			retw
			rwet
			rwte
			rtwe
			rtew
			terw
			tewr
			trew
			trwe
			twre
			twer

			Do you want to continue (y / Y) :y
			Enter a string
			aba
			Please enter only distict characters

			Do you want to continue (y / Y) :n
			Operation terminated

*****************************************************************************************************************************************/

#include <stdio.h>
#include <stdio_ext.h>

void swap(char *, char *);
void str_combinations(char *str, int base, int len);
int check_len(char *str);
int repeat_char_check(char *str, int N);

int main()
{

    char ch;

    do
    {
	char str[50];
	// variable initialisation
	int i = 0, ret = 0, len = 0;
	
	__fpurge(stdin);
	// Read input from user
	printf("Enter a string\n");
	scanf("%50[^\n]s", str);

	
	len = check_len(str);

	ret = repeat_char_check(str, len);

	    if (ret == -1)
		printf("Please enter only distict characters\n");
	    else
	    {
		printf("Possible combinations of entered string are :\n");
		str_combinations(str, 0, len-1);
	    }

	__fpurge(stdin);
	printf("\nDo you want to continue (y / Y) :");
	scanf(" %c", &ch);

    }while (ch == 'y' || ch == 'Y');

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

void str_combinations(char *str, int base, int len)
{
    int i;
    if (base == len)
	printf("%s\n", str);
    else
    {
	for(i = base; i <= len; i++)
	{
	    swap((str + base), (str + i));

	    str_combinations(str, base + 1, len);   // recursive function call

	    swap( (str + base), (str + i));
	}
    }
}


void swap(char *ch1, char *ch2)
{
    char temp;

    temp = *ch1;
    *ch1 = *ch2;
    *ch2 = temp;
}
