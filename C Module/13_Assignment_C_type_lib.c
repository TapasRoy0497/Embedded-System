/* *********************************************************************************************************

NAME 		:	TAPAS ROY
DATE		:	15/06/2021

DESCRIPTION	:	Implement your own c-type library (any four).

INPUT		:	An ASCII character

OUTPUT		: 	Enter the character: a
			Select any option:
			1 - isalpha
			2 - isalnum
			3 - isascii
			4 - isblank
			Enter you choice: 2
			The character 'a' is an alnum character.
			Do you want to continue(y/Y): y
			Enter the character: ?
			Select any option:
			1 - isalpha
			2 - isalnum
			3 - isascii
			4 - isblank
			Enter you choice: 2
			The character '?' is not an alnum character.
			Do you want to continue(y/Y): n

********************************************************************************************************** */


#include <stdio.h>

//functions prototype
int is_alnum(char ch);
int is_alpha(char ch);
int is_ascii(char ch);
int is_blank(char ch);

int main()
{
	char choice;

	do
	{
		//declaration of function
		char ch;
		int num, status;
		
		//get the character from the user
		printf("Enter the character : ");
		scanf("%c",&ch);
		
		//prompt the user for the option 
		printf("1.isalpha\n2.isalnum\n3.isascii\n4.isblank\nEnter your Option : ");
		scanf("%d", &num);

		//validation of the num
		switch(num)
		{
			case 1:
			        status = is_alpha(ch);
				if(status == 1)
				{
					printf("The character '%c' is an alpha character", ch);
				}
				else
				{
					printf("The character '%c' is not an alpha character", ch);
				}
				break;

			case 2:
			        status = is_alnum(ch);
				if(status == 1)
				{
					printf("The character '%c' is an alnum character", ch);
				}
				else
				{
					printf("The character '%c' is not an alnum character", ch);
				}
				break;
					
			case 3:
				status = is_ascii(ch);
				if(status == 1)
				{
					printf("The character '%c' is an ascii characater", ch);
				}
				else
				{
					printf("The character '%c' is not an ascii character", ch);
				}
				break;

			case 4:
				status = is_blank(ch);
				if(status == 1)
				{
					printf("The character '%c' is an blank character", ch);
				}
				else
				{
					printf("The character '%c' is not blank character", ch);
				}
				break;

			default:
				printf("Invalid Choice.....");
		}

		printf("\nDo you want to continue (y/Y) : ");
		scanf(" %c", &choice);
		getchar();
	}
	while (choice == 'Y' || choice == 'y');

	return 0;
}


//functionn checks for the alphabets
int is_alpha(char ch)
{
	return (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') ? 1 : 0;

}

//Function checks for the Number
int is_alnum(char ch)
{
	return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) ?  1 : 0;
}

//function checks for the ascii
int is_ascii(char ch)
{
	return (ch >= 0 && ch <= 127) ? 1 : 0;
}

//function checks for the blank
int is_blank(char ch)
{
	return (ch == ' ' || ch == '\t') ?  1 : 0; 
}


