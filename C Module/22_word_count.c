/****************************************************************************************************************************************
  
Name              : Tapas Roy
Date              : 28-06-2021
Description       : Program to count number of characters, words, lines entered through stdin buffer
Input             :
Output            :

			Enter the string
			jhhkl	lnkb jldnsk.b
			vblk lsk;n	fn

			Character count : 34
			Line count : 2
			Word count : 6
			Do you want to continue (y / Y) : y

			Enter the string
			hi      kij	nnlwr
			kglw blmlb/k
			Character count : 25
			Line count : 2
			Word count : 5
			Do you want to continue (y / Y) : n

			Enter the string : 
			sagn;l	bi;j	bn;
			bvnd boipn

			Character count : 27 
			Line count : 2 
			Word count : 5 
			Do you want to continue (y / Y) : y

			Enter the string : 
			jkui	fugo iv
				ouij fgulih

			Character count : 26 
			Line count : 2 
			Word count : 5 
			Do you want to continue (y / Y) : n
			Operation Terminated

*****************************************************************************************************************************************/
#include <stdio.h>
#include <stdio_ext.h>

int main()
{
    char ch;   // char var declaration
    do
    {
	// Initialising variables
    	char wc = 0;
	int line = 0, word = 0, Char = 0, i = 0, count = 0;

	__fpurge(stdin); // clearing stdin buffer
	
	printf("\nEnter the string : \n"); // Prompt to read input from user

	// Logic to find no.of words,lines,characters entered from user
	while ( ( wc = getchar()) != EOF)
	{	
		++Char;  // char count
		
		if ( ( Char == 1 && wc == ' ') || ( Char == 1 && wc == '\t') || ( Char == 1 && wc == '\n') )
		{ 
			++count;  // if user enters ' ',\t,\n as 1st char it will inc count to avoid word count increment
		} 

		else if ( (wc == ' ') || (wc == '\t') || ( wc == '\n') )
		{
		    	++count;  // count will be inc if user enters ' ' or '\t' or '\n'

			if (count == 1)
			    ++word;     // word count increment
		}

		if ( wc != '\t' && wc != ' ' && wc != '\n')
		    count = 0;  // if user not enters '\t' or '\n' or ' ', then reset count value

		if ( wc == '\n')
		    ++line;  // line count increment
	}

		if (count == 0 && wc == EOF)  // if user enters EOF without pressing \n then count will be inc for word and line
		{
		    ++word;
		}

	
	fflush(stdout);  // clearing stdout buffer
	
	// Printing result on terminal

	printf("\nCharacter count : %d ", Char);
	printf("\nLine count : %d ", line);
	printf("\nWord count : %d ", word);

	printf("\nDo you want to continue (y / Y) : ");  // ask permission to user to repeat the operation
	scanf(" %c", &ch);

	__fpurge(stdin);

    } while ( ch == 'y' || ch == 'Y'); // if user enters y/Y then repeat the operation
    printf("Operation Terminated\n");

    return 0;
}


