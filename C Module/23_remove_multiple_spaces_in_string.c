/****************************************************************************************************************************************
  
Name              : Tapas Roy
Date              : 30-06-2021
Description       : Program to remove multiple spaces from string which is entered by user
Input             :
Output            :

			Enter the string with more spaces in between two words
			gyhujkl;,           ftygujiokpl    			ftgyujiokp

			String without extra spaces :
			gyhujkl;, ftygujiokpl ftgyujiokp

			Do you want to continue (y / Y) : y

			Enter the string with more spaces in between two words
					tfyguji          erdtgyubjnmk	dftgyui      	fgyuhi

			String without extra spaces :
			tfyguji erdtgyubjnmk dftgyui fgyuhi

			Do you want to continue (y / Y) : y

			Enter the string with more spaces in between two words
				 tyguhji	f6gyujio            		56f7yghuji

			String without extra spaces :
			tyguhji f6gyujio 56f7yghuji

			Do you want to continue (y / Y) : y

			Enter the string with more spaces in between two words
				   yguihjo	t yuiok        67ghuji

			String without extra spaces :
			yguihjo t yuiok 67ghuji

			Do you want to continue (y / Y) : n
			Operation Terminated

*****************************************************************************************************************************************/

#include <stdio.h>
#include <stdio_ext.h>

// Function declaration
void remove_multiple_spaces(char *str);

int main()
{
    // Declaring character variable
    char ch;

    do 
    {

	// Defining and resetting character array
    	char str[200] = {0};
	
	__fpurge(stdin);	
	fflush(stdout);

	printf("\nEnter the string with more spaces in between two words\n");
  
	scanf("%200[^\n]s", str);
	fflush(stdout);
	__fpurge(stdin);
    	
	remove_multiple_spaces(str); // function call to remove multiple spaces

	fflush(stdout);
	__fpurge(stdin);
    	printf("\nString without extra spaces :\n%s", str);  // printing string after removing extra spaces 
   
	__fpurge(stdin);	
	fflush(stdout);

	printf("\n\nDo you want to continue (y / Y) : ");  // prompt to ask user to repeat the operation
	scanf(" %c", &ch);

    }
    	while ( ch == 'y' || ch == 'Y');  // if user enters y / Y then repeat the operation

    	printf("Operation Terminated\n");
	return 0;
}

void remove_multiple_spaces(char *str)
{
    int i = 0,j = 0, count = 0;

	
    for ( i = 0; *(str+i) != '\0'; i++)    // Iterates the string1 till reaches null character
    {
	// checks for multiple ' '(space)  and tab space ('\t')

	if ( ( *(str+i) == ' ') && (*(str+i+1) == ' ') || ( *(str+i) == '\t' ) && (*(str+i+1) == '\t') || (*(str+i) == ' ') &&(*(str+i+1) == '\t') || ( *(str+i) == '\t' ) && (*(str+i+1) == ' ') )
	{
	    	count++;

	   	continue;    // it will go to loop for inc i, will discard the spaces 
	}
	else
	{
	    if ( ( j == 0 && (*(str + i) == ' ') ) || ( j == 0 && (*(str + i) == '\t'))) //if starting char is tab or space will remove
	    {
		continue;
	    }
	    else if (count > 0 && j != 0)    // if it is not starting of the string then add space
	    {
		    *(str + j++) = ' ';
                     count = 0;    // reset the count value
	    }
	    else if ( *(str+i) == '\t')
	    {
		*(str+j++) = ' ';
	    }
	    else
	    {
		     *(str + j++) = *(str + i);   // will update the string without extra space
		     count = 0;      // reset the count
	    }
	}

    }
    
	*(str + j) = '\0';   // adding null character at last
}


