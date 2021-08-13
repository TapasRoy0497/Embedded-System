/****************************************************************************************************************************************
  
NAME              : TAPAS ROY

DATE              : 10-07-2021 

DESCRIPTION       : Program to implement strtok function

Input             :
OUTPUT            :


			Enter string 1 : WET:GNB"wg?
			Enter string 2 : :"?
			Tokens :
			WET
			GNB
			wg

			Do you want to continue (y / Y) : y

			Enter string 1 : WTRHGB?Erag:RAT$
			Enter string 2 : ?:$
			Tokens :
			WTRHGB
			Erag
			RAT

			Do you want to continue (y / Y) : y

			Enter string 1 : waregt?ray:ra"awt%#
			Enter string 2 : ?:"%#
			Tokens :
			waregt
			ray
			ra
			awt

			Do you want to continue (y / Y) : y

			Enter string 1 : wrrg:Wt"
			Enter string 2 : ?
			Tokens :
			wrrg:Wt"

			Do you want to continue (y / Y) : n
			Operation terminated


*****************************************************************************************************************************************/


#include <stdio.h>
#include <stdio_ext.h>
// function declaration
char *my_strtok(char *str1, char *token_str);


int main()
{
    char ch;
    do
    {
    	char str1[100] = {0};  
    	char token_str[50] = {0};
    
	__fpurge(stdin);   // clear stdin buffer 
    	printf("\nEnter string 1 : ");
	scanf("%[^\n]s", str1);

	__fpurge(stdin);
	printf("Enter string 2 : ");
	scanf("%50[^\n]s",token_str);

	char *ret = my_strtok(str1, token_str);

	printf("Tokens :");
	while (ret != NULL)
	{
	    printf("\n%s", ret);
	    ret = my_strtok(NULL,token_str);  
	}
	__fpurge(stdin);
	printf("\n\nDo you want to continue (y / Y) : ");
	scanf(" %c", &ch);

    }
    while (ch == 'y' || ch == 'Y');

    printf("Operation terminated\n");

    return 0;
}

char *my_strtok(char *str1, char *token_str)
{
    static int pos = 0;
    static char *temp_str;
    int j, start;

    start = pos;
    
    if (str1 != NULL)
    {
	temp_str = str1;
    }

    // iterate string till reaching null character
    while ( temp_str[pos] != 0 )
    {
	// check for token_str match
	for(j = 0; token_str[j] != '\0'; j++)
	{
	    // get pos for next string
	    if ( temp_str[pos] ==token_str[j] )
	    { 
		// replace token_str with null character
		temp_str[pos] = '\0';

		pos = pos + 1;

		if( temp_str[start] != '\0' )
		{
		    return (&temp_str[start]);
		}
		else
		{
		    // for next token_str
		    start = pos;
		    pos--;
		    break;
		}
	    }
	}
	pos++;
    }

    // to make broken token_strs as string
//    temp_str[pos] = '\0';
    if ( temp_str[start] == '\0')
    {
	pos = 0;
	return NULL;
    }
    else
    {
	return (&temp_str[start]);
    }
}

