/* *********************************************************************************************************

NAME 		:	TAPAS ROY
DATE		:	14/06/2021

DESCRIPTION	:	Program to implement bitwise functions
			 
INPUT 		:	An integer N, No of bits B and Position P (as per choice by user)

OUTPUT 		: 	Select bit operation from below list
			1. get_nbits
			2. replace_nbits
			3. get_nbits_from_pos
			4. replace_nbits_from_pos
			5. toggle_bits_from_pos
			6. print_bits
			Enter your choice: 3
			Enter num : 12
			Enter n: 3
			Enter pos : 5
			Binary format for 12 -> 0000 0000 0000 0000 0000 0000 0000 1100
			3 bits from position 5 => 0000 0000 0000 0000 0000 0000 0000 0001
			Value at 12[5(pos):3(bits)] -> 1
			
			Do you want to continue(y/Y) : n

********************************************************************************************************** */

#include <stdio.h>

//Function declaration

int get_nbits ( int, int );
/*  If num is 10 and n is 2,
    10 -> 0 0 0 0 1 0 1 0 
    Take 2 bits from LSB end of 10 (1 0) 
    and return the corresponding decimal of that.
    So get_nbits(10, 2) function should return 2  */

int replace_nbits (int, int, int );
/*  Fetch n number of bits from LSB end of val and 
    replace in the last n bits of num.
    
    Return new value of num.
   
    If num is 10 and n is 3 and val is 12
    10 -> 0 0 0 0 1 0 1 0
    ---------------------
    12 -> 0 0 0 0 1 1 0 0
    -----
    The function should return 12 (1 1 0 0) */

int get_nbits_from_pos(int, int, int);
/*  Fetch n number of bits from given position 'pos' (starting from LSB) of num 
    and return the decimal value of it.
    If num is 12, n is 3 and pos is 4
    pos : 7 6 5 4 3 2 1 0
         -----------------
    12 -> 0 0 0 0 1 1 0 0
         -----------------
    The function should return 3 (0 1 1) */

int replace_nbits_from_pos(int, int, int, int);
/* .Fetch n number of bits from LSB of val.
   .Place those fetched bits from pos positionth bit of num and
    return new value of num.
    If num is 20, n is 3, pos is 4 and val is 12
    pos:  7 6 5 4 3 2 1 0
    20 -> 0 0 0 1 0 1 0 0
         -----------------
    12 -> 0 0 0 0 1 1 0 0
         -----------------
    return value-> 0 0 0 1 0 0 0 0
   So function should return 16 (1 0 0 0 0) */
   
int toggle_bits_from_pos(int, int, int);
/*  Invert the n number of bits from pos positionth bit of num.
    Return the new value of num
    If num is 10, n is 3, and pos is 5
    pos:  7 6 5 4 3 2 1 0
         -------------------
    10 -> 0 0 0 0 1 0 1 0
         ------------------
    return value -> 0 0 1 1 0 0 1 0
    So the function should return 50 (0 0 1 1 0 0 1 0) */

int print_bits(unsigned int, int);
/*  If n is greater than integer size, assign n value as sizeof integer.
    Print n number of bits of num from LSB end.
    If num is 10 and n is 12, then print last 12 bits of binary representation of 10.
    The output should be -> 0 0 0 0 0 0 0 0 1 0 1 0 */

void print_bit ( int ); //to print bits of entered integers in each case

int main()
{   
    char ch;
    do
    {
        //Declaring variables
        int num, n, val, pos, result, choice;
        
        //Displaying the bit operation list and reading the choice
        printf ("Select bit operation from below list : \n");
        printf ("\t 1. get_nbits \n\t 2. replace_nbits \n\t 3. get_nbits_from_pos \n\t 4. replace_nbits_from_pos \n\t 5. toggle_bits_from_pos \n\t 6. print_bits \n");
        printf ("Enter your choice : ");
        scanf ("%d", &choice);
        
        //using switch case for individual operation
        switch (choice)
        {
            case 1 :
            	printf("Enter num : ");
            	scanf ("%d", &num);
            	printf("Enter n   : ");
            	scanf ("%d", &n);
            	
            	result = get_nbits (num, n);
            	
            	printf("Binary format for %d -> ",num);
            	print_bit(num);
		printf("\nResult after taking %d bits form LSB of %d is : %d", n, num, result);
		printf("\nBinary format for %d -> ",result);
		print_bit(result);
		
		break;
	    
	    case 2 :
		printf("Enter num : ");
            	scanf ("%d", &num);
            	printf("Enter n   : ");
            	scanf ("%d", &n);
		printf("Enter val : ");
		scanf ("%d", &val);
            	
            	result = replace_nbits (num, n, val);
            	
            	printf("Binary format for %d -> ",num);
            	print_bit(num);
            	printf("\nBinary format for %d -> ",val);
            	print_bit(val);
		printf("\nResult after taking n=%d bits form LSB end of val=%d and replace in the last n=%d bits of num=%d is : %d", n, val, n, num, result);
		printf("\nBinary format for %d -> ",result);
            	print_bit(result);
		
		break;

	    case 3 :
		printf("Enter num : ");
		scanf ("%d", &num);
		printf("Enter n   : ");
		scanf ("%d", &n);
		printf("Enter pos : ");
		scanf ("%d", &pos);
		
		result = get_nbits_from_pos(num, n, pos);
		
		printf("\nBinary format for %d -> ",num);
            	print_bit(num);
		printf("\nResult after fetching n=%d bits form position=%d of num=%d is : %d", n, pos, num, result);
		printf("\nBinary format for %d -> ",result);
            	print_bit(result);
		
		break;
		
	    case 4 :
		printf("Enter num : ");
		scanf ("%d", &num);
		printf("Enter n   : ");
		scanf ("%d", &n);
		printf("Enter pos : ");
		scanf ("%d", &pos);
		printf("Enter val : ");
		scanf ("%d", &val);
		
		result = replace_nbits_from_pos(num, n, pos, val);
		
		printf("\nBinary format for %d -> ",num);
            	print_bit(num);
            	printf("\nBinary format for %d -> ",val);
            	print_bit(val);
		printf("\nResult after fetching n=%d bits from LSB of val=%d and replacing it in from positionth=%d bit of num=%d is : %d", n, val, pos, num, result);
		printf("\nBinary format for %d -> ",result);
            	print_bit(result);
		
		break;
	    
	    case 5 :
		printf("Enter num : ");
		scanf ("%d", &num);
		printf("Enter n   : ");
		scanf ("%d", &n);
		printf("Enter pos : ");
		scanf ("%d", &pos);
		
		result = toggle_bits_from_pos(num, n, pos);
		
		printf("\nBinary format for %d -> ",num);
            	print_bit(num);
		printf("\nResult after inverting n=%d number of bits from position=%dth of num=%d is : %d", n, pos, num, result);
		printf("\nBinary format for %d -> ",result);
            	print_bit(result);
		
		break;
		
	    case 6 :
		printf("Enter num : ");
		scanf ("%d", &num);
		printf("Enter n   : ");
		scanf ("%d", &n);
		
		printf("Binary format for %d -> ",num);
		print_bits(num , n);
				
		break;
		
	    default:
		printf("Wrong choice !!");
        }
	printf("\n\nDo you want to continue : ");
	scanf(" %c", &ch);
    
    }while ( ch == 'y' || ch== 'Y' );
    return 0;
}


//Function defination
int get_nbits (int num, int n)
{
    int mask, result;

    mask = (1 << n) - 1;	//Generating mask using left shift
    result = num & mask; 	//bitwise & to clear bits
    
    return result;
}

int replace_nbits (int num, int n, int val)
{
    int mask_num, mask_val, result_num, result_val, final_result;
    
    mask_val = ((1 << n) - 1 );		//Generating mask for val
    result_val = val & mask_val;	//bitwise & to clear bits

    mask_num = ~((1 << n) - 1 );	//Generating mask for num	
    result_num = num & mask_num;	//bitwise & to clear bits

    final_result = result_num | result_val; //bitwise | to set bits

    return final_result;
}

int get_nbits_from_pos(int num, int n, int pos)
{
    int num_shift, mask, result;
    
    num_shift = ( num >> (pos - n + 1)); //Right shifting 
    mask = (1 << n) - 1;		 //Generating mask
    result = num_shift & mask; 		 

    return result;
}

int replace_nbits_from_pos(int num, int n, int pos, int val)
{
    int i, mask_val, result_val, n_shift, val_shift, mask_num, result_num, result;
    result_num=num;

    mask_val = ((1 << n) - 1 );		 //Generating mask using left shift
    result_val = val & mask_val; 	 //bitwise & to clear bits
    n_shift= pos - (n-1);
    val_shift = result_val << n_shift;
   
    //clearing the bits from pos
    for(i = 1; i <= n ; i++)
    {
	mask_num = (1 << pos) ; 	
	pos--;
	result_num = result_num & ( ~ mask_num);	
    }
      
    result = result_num | val_shift;
            
    return result;
}

int toggle_bits_from_pos(int num, int n, int pos)
{
    int i, shift;

    for(i = pos; i >= pos-n + 1 ; i--)
    {
	shift = 1 << i; 	//right shifting
	num = num ^ shift;	//using bitwise XOR ^ to toggle bits
    }
    return num;
}

int print_bits(unsigned int num , int n)
{
    unsigned int i;
    if (n>=1 && n <= 32) 	//checking if n is within size of integer
    { 
        for (i = 1 << n-1; i > 0; i = i / 2)
        {
            (num & i) ? printf(" 1 ") : printf(" 0 ");
        }
    }
    else 			//if greater than int size then printing only 32 bits representation
    {
        for (i = 1 << 31; i > 0; i = i / 2)
        {
            (num & i) ? printf(" 1 ") : printf(" 0 ");
        }
    }
    
}

void print_bit (int num) 	//Function defination of print_bit to print binary representation in other cases
{
    unsigned int i;
    for (i = 1 << 31; i > 0; i = i / 2)
    {
        (num & i) ? printf(" 1 ") : printf(" 0 ");
    }
}
