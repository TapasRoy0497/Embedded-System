/* *********************************************************************************************************

NAME 		:	TAPAS ROY
DATE		:	02/06/2021

DESCRIPTION	:	Program to find which day of the year, given the number from 1 to 365
			
			•Suppose, in a week let us assume first day is 'Sunday', then second day
			 will be 'Monday' and so on. If first day is 'Monday' then the second day
			 will be 'Tuesday' and so on.
		
INPUT 		:	Positive integer say 'N'. Where 1 <= 'N' <= 365. 
			1 <= Starting day <= 7
			Option to set the first day.
			
OUTPUT 		: 	Enter the value of 'n' : 9
			Choose First Day :
			  1. Sunday
			  2. Monday
			  3. Tuesday
			  4. Wednesday
			  5. Thursday
			  6. Friday
			  7. Saturday
			Enter the option to set the first day : 2
			The 9 th day is Tuesday
			
			Do you want to continue(y/Y): y
			Enter the value of 'n' : 9
			(Menu to be displayed)
			Enter the option to set the first day : 8
			Error : Invalid input first day should be > 0 and <= 7
			
			Do you want to continue(y/Y): y
			Enter the value of 'n' : 0
			Error : Invalid Input, n value should be > 0 and <= 365
			
			Do you want to continue(y/Y): y
			Enter the value of 'n' : 366
			Error : Invalid Input, n value should be > 0 and <= 365

********************************************************************************************************** */
#include <stdio.h>

int main ()
{
    // Declaring variables
    int n, day, i;
    char ch;
      
    do
    {
    	// Read input from the user
     	printf ("Enter the value of 'n' : ");
	scanf ("%d", &n);

	// Checking if entered number is within the range
	if ( n > 365 || n == 0 )
	{
	    printf ("Error: Invalid Input, 'n' value should be > 0 and <= 365 \n");
	    
	    printf ("Do you want to continue (y/Y) : ");
	    scanf (" %c", &ch);
	}
	
	else
	{
	    // Read input from the user
	    printf ("Choose First Day : \n");
	    printf ("  1. Sunday \n");
	    printf ("  2. Monday \n");
	    printf ("  3. Tuesday \n");
	    printf ("  4. Wednesday \n");
	    printf ("  5. Thursday \n");
	    printf ("  6. Friday \n");
	    printf ("  7. Saturday \n");
	    printf("Enter the option to set the first day : ");	    
	    scanf ("  %d", &day);

	    //Checking if entered day is within range 1<= day <=7
	    if ( day >=1 && day <=7 )
	    {
		int next_day = day;
		for (i = 1; i < n; i++ )
		{
		    next_day=next_day + 1;
		    if( next_day == 8 )
		    {
			next_day = next_day - 7;
		    }
		}
		
		//Using switch case to print the next day 
		switch (next_day)
		{

		    case 1:
			printf ("\n The day after %d day(s) is Sunday.\n",n);
			break;
		    case 2:
			printf ("\n The day after %d day(s) is Monday.\n",n);
			break;
		    case 3:
			printf ("\n The day after %d day(s) is Tuesday.\n",n);
			break;	
		    case 4:
			printf ("\n The day after %d day(s) is Wednesday.\n",n);
			break;
		    case 5:
			printf ("\n The day after %d day(s) is Thursday.\n",n);
			break;
		    case 6:
			printf ("\n The day after %d day(s) is Friday.\n",n);
			break;
		    case 7:
			printf ("\n The day after %d day(s) is Saturday.\n",n);
			
		}
		
		printf ("\nDo you want to continue (y/Y) : ");
		scanf (" %c", &ch);
	    }
	    else 	//when entered day is not within range
	    {
		printf ("Error: Invalid Input, first day should be > 0 and <= 7 \n");
		
		printf ("Do you want to continue (y/Y) : ");
		scanf (" %c", &ch);
	    }
	}
    }while(ch == 'y' || ch == 'Y');
}
