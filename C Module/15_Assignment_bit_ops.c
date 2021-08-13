/* *********************************************************************************************************

NAME 		:	TAPAS ROY
DATE		:	15/06/2021

DESCRIPTION	:	Program to Read int val, Read 0 ≤ a ≤ b ≤ 31. Read an int n, 
			put the (b-a+1) lsb’s of n into i[b:a]
			
			•Read number n from user.
			•Read number val from user.
			•Read number a from user(0 < a <= 31)
			 ◦ Do error checking
			 ◦ Check a is within limit or not.
			•Read number b from user(a <= b <=31)
			•Do error checking
			 ◦ Check b is within limit or not.
			•Call replace_nbits_from_pos function by passing val, b - a + 1, b and n as
			arguments.
			 ◦ replace_nbits_from_pos(val, b - a + 1, b, n);
			•Print the new value of val .
			•Prompt for continue option.
			 
INPUT 		:	Integers n, val, a, b

OUTPUT 		: Enter the value of 'n' : 11
		  Enter the value of 'val': 174
		  Enter the value of 'a' : 3
		  Enter the value of 'b' : 5
		  The binary form of 'n' : 00000000 00000000 00000000 00001011
		  The binary form of 'I' : 00000000 00000000 00000000 10101110
		  Updated form of 'I'(158): 00000000 00000000 00000000 10011110
		  Want to continue ( y/Y ) : n
********************************************************************************************************** */



#include <stdio.h>

//Function declaration
void print_bit (int);

int replace_nbits_from_pos(int, int, int, int);

int main ()
{
    char ch;
    do
    {
        //Declaring variables
        int n, val, a, b, c, result, choice;
        
        printf("Enter the value of 'n' : ");
        scanf ("%d", &n);
        printf("Enter the value of 'val' : ");
        scanf ("%d", &val);
        printf("Enter the value of 'a' : ");
        scanf ("%d", &a);
        printf("Enter the value of 'b' : ");
        scanf ("%d", &b);

	if (a > 0 || a <=31 && b >= a || b <= 31)  //Checking if a and b within range
	{
	    printf("\nBinary value of 'n' : %d -> ",n);
	    print_bit(n);
	    printf("\nBinary value of 'val' : %d -> ",val);
	    print_bit(val);
	
	    result = replace_nbits_from_pos(val, b-a+1 , b, n);

	    printf("\nResult after fetching b-a+1=%d bits from LSB of 'n'=%d and replacing it in from positionth=%d bit of 'val'=%d is : %d", b-a+1, n, b, val, result);
	    printf("\nUpdated form of 'val': %d -> ",result);	    
	    print_bit(result);
	}
	else
	{
	    printf("Value of 'a' or 'b' out of limit, please enter within limit(0<a<=31)&(a<=b<=31)\n");
	}
	
	printf("\n\nDo you want to continue? (y/Y) : ");
	scanf (" %c", &ch);
    }while(ch == 'y' || ch == 'Y');
}


//Function defination
int replace_nbits_from_pos(int val, int c, int b, int n)
{
    int i, mask_n, result_n, shift, n_shift, mask_val, result_val, result;
    
    result_val=val;

    mask_n = ((1 << c) - 1 );	//Generating mask using left shift
    result_n = n & mask_n; 	//bitwise & to clear bits
    shift= b - (c-1);
    n_shift = result_n << shift;
   
    //clearing the bits from pos
    for(i = 1; i <= b ; i++)
    {
	mask_val= (1 << b) ; 	
	b--;
	result_val = result_val & (~ mask_val);	
    }
      
    result = result_val | n_shift;
            
    return result;
}

void print_bit (int num) 	//Function defination of print_bit to print binary representation in other cases
{
    unsigned int i;
    for (i = 1 << 31; i > 0; i = i / 2)
    {
        (num & i) ? printf(" 1 ") : printf(" 0 ");
    }
}

