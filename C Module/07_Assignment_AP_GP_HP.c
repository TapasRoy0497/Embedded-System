/* *********************************************************************************************************

NAME 		:	TAPAS ROY
DATE		:	01/06/2021

DESCRIPTION	:	Program to read 3 numbers a, r, n. Generate AP, GP, HP
			
			• AP
			◦ In mathematics, an arithmetic progression (AP) or arithmetic sequence
			  is a sequence of numbers such that the difference between the
			  consecutive terms is constant.
			◦ For instance, the sequence 5, 7, 9, 11, 13, 15 … is an arithmetic
			  progression with common difference of 2.
			
			• GP
			◦ In mathematics, a geometric progression, also known as a geometric
			  sequence, is a sequence of numbers where each term after the first is
			  found by multiplying the previous one by a fixed, non-zero number
			  called the common ratio.
			◦ For example, the sequence 2, 6, 18, 54, ... is a geometric progression
			  with common ratio 3. Similarly 10, 5, 2.5, 1.25, ... is a geometric
			  sequence with common ratio 1/2.
			
			• HP
			◦ In mathematics, a harmonic progression (or harmonic sequence) is a
			  progression formed by taking the reciprocals of an arithmetic
			  progression.

INPUT		:	Positive integers say 'A', 'R' and 'N'
			where:
			A = First number
			R = Common difference(AP & HP), Common ratio(GP)
			N = number of terms
			A, R and N should be < 2^10

OUTPUT		: 	Enter the First Number 'A': 2
			Enter the Common Difference / Ratio 'R': 3
			Enter the number of terms 'N': 5
			AP = 2, 5, 8, 11, 14
			GP = 2, 6, 18, 54, 162
			HP = 0.5, 0.2, 0.125, 0.0909091, 0.0714285
			
			Do you want to continue(y/Y) : y
			Enter the First Number 'A': -2
			Enter the Common Difference / Ratio 'R': 3
			Enter the number of terms 'N': 5
			Invaild Input(s) : Please enter only positve values
			
			Do you want to continue(y/Y) : y
			Enter the First Number 'A': 2000
			Enter the Common Difference / Ratio 'R': 3
			Enter the number of terms 'N': 5
			Input(s) out of range
			
			Do you want to continue(y/Y) : y
			Enter the First Number 'A': 2
			Enter the Common Difference / Ratio 'R': -3
			Enter the number of terms 'N': -5
			Invaild Input(s) : Please enter only positve values
			
			Do you want to continue(y/Y) : n
********************************************************************************************************** */

#include <stdio.h>

int main ()
{
    // Declaring variables
    int a, r, n, i, range=1, ap, gp;
    float hp;
    char ch;

    // Calculating range for the values entered 
    for ( i=1; i<=10; i++ )
    {
	range=range*2;
    }

    do
    {
	    // Read values from the user
     	printf ("Enter the first number 'a' : ");
	scanf ("%d", &a);
	printf ("Enter the Common Difference / Ratio 'r' : ");
	scanf ("%d", &r);
	printf ("Enter the number of terms 'n' : ");
        scanf ("%d", &n);

	    // Checking if entered number is within the range
	    if ( a > range || r > range || n > range)
	    {
	    printf ("Input(s) out of range");

	    printf ("\n\n Do you want to continue (y/Y) : ");
	    scanf (" %c ", &ch);
	    }
	    else if ( a < 0 || r < 0 || n < 0) 	//Checking if number is positive
	    {
	        printf ("\n Invalid Input(s) :Please enter only positive values");

	        printf ("\n\n Do you want to continue (y/Y) : ");
	        scanf (" %c", &ch);
	    }
	    else
	    {
	        //Generating AP series
	        ap = a;
	        printf("\n AP = ");
	        for(i = 1; i <= n; i++ )
	        {
	            printf(" %d ", ap);
	            ap = ap + r;
	        }
	        printf("\n");

	        //Generating GP series
	        printf("\n GP = ");
	        gp = a;
	        for(i=1; i<=n; i++)
	        {
	            printf(" %d ", gp);
	            gp = gp * r;
	        }
	        printf("\n");
	        
		//Generating HP series
	        printf("\n HP = ");
	        ap = a;
	        for(i=1; i<=n; i++)
	        {
	            hp =  1/(float)ap;
	            printf(" %f ", hp);
	            ap = ap +r;
	        }
	        printf("\n");
	        printf ("\nDo you want to continue (y/Y) : ");
	        scanf (" %c", &ch);
	    }
    }while(ch == 'y' || ch == 'Y');

    return 0;
}
