/* *********************************************************************************************************

NAME 		:	TAPAS ROY
DATE		:	01/06/2021

DESCRIPTION	:	Program to print sizes of all basic data types of C.
			
			•Print the size of basic data types – int, char, float, double, void
			•Print the size of the above data types while using different qualifiers –
			short, long, unsigned etc.
		
INPUT 		:	None
OUTPUT 		: 	Size of int 		:	4 bytes
			Size of char 		:	1 bytes
			Size of float		:	4 bytes
			Size of double		:	8 bytes
			Size of unsigned int	:	4 bytes
			Size of long int 	:	8 bytes
			------
			------

********************************************************************************************************** */

#include <stdio.h>

int main()
{
    //Using sizeof opertator to get the size of different data tytes
    
    printf("\t\t Size of int \t\t : \t %zu bytes \n", sizeof(int));
    
    printf("\t\t Size of short int \t : \t %zu bytes \n", sizeof(short int));
    
    printf("\t\t Size of long int \t : \t %zu bytes \n", sizeof(long int));
    
    printf("\t\t Size of signed int \t : \t %zu bytes \n", sizeof(signed int));
    
    printf("\t\t Size of unsigned int \t : \t %zu bytes \n", sizeof(unsigned int));
    
    printf("\t\t Size of long long int \t : \t %zu bytes \n", sizeof(long long int));
    
    printf("\t\t Size of float \t\t : \t %zu bytes \n", sizeof(float));
    
    printf("\t\t Size of double \t : \t %zu bytes \n", sizeof(double));
    
    printf("\t\t Size of long double \t : \t %zu bytes \n", sizeof(long double));
    
    printf("\t\t Size of char \t\t : \t %zu bytes \n", sizeof(char));
    
    printf("\t\t Size of signed char \t : \t %zu bytes \n", sizeof(signed char));
    
    printf("\t\t Size of unsigned char \t : \t %zu bytes \n", sizeof(unsigned char));
    
    printf("\t\t Size of unsigned short  : \t %zu bytes \n", sizeof(unsigned short));
    
    printf("\t\t Size of signed short \t : \t %zu bytes \n", sizeof(signed short));
        
    return 0;
}
