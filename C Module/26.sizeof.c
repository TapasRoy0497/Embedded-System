/******************************************************************************

NAME        :   TAPAS ROY

DATE        :   13/08/21

DESCRIPTION :   To define a macro sizeof(x), where x is a variable, without using sizeof operator

INPUT       :  
OUTPUT      :   
                Size of int               : 4 bytes
                Size of float             : 4 bytes
                Size of char              : 1 byte
                Size of long int          : 8 bytes
                Size of double            : 8 bytes
                Size of unsigned int      : 4 bytes
                Size of long long         : 8 bytes
                Size of short int         : 2 bytes
                Size of unsigned char     : 1 byte
                Size of long double       : 16 bytes
                Size of signed int        : 4 bytes
                Size of signed char       : 1 byte
                Size of signed short int  : 2 bytes
                Size of unsigned short int: 2 bytes
                Size of signed long int   : 8 bytes
                Size of unsigned long int : 8 bytes
                Size of signed long long  : 8 bytes
                Size of unsigned long long: 8 bytes

*******************************************************************************/
#include<stdio.h>

//user defined macro for calculation of size for all data type
#define MY_SIZEOF(x)   ((char *)(&x + 1) - (char *)&x)

int main()
{
	//declaring  all type of variable
	int i;
	float f;
	char c;
	long int l;
	double d;
	unsigned int u;
	long long ll;
	short int s;
	unsigned char uc;
	long double ld;
	signed int si;
	signed char sc;
	signed short int ssi;
	unsigned short int usi;
	signed long int sli;
	unsigned long int uli;
	signed long long sll;
	unsigned long long ull;

	
	//printing size of for all datatype by calling macro
	printf("Size of int                : %ld bytes\n",MY_SIZEOF(i));
	printf("Size of float              : %ld bytes\n",MY_SIZEOF(f));
	printf("Size of char               : %ld byte\n",MY_SIZEOF(c));
	printf("Size of long int           : %ld bytes\n",MY_SIZEOF(l));
	printf("Size of double             : %ld bytes\n",MY_SIZEOF(d));
	printf("Size of unsigned int       : %ld bytes\n",MY_SIZEOF(u));
	printf("Size of long long          : %ld bytes\n",MY_SIZEOF(ll));
	printf("Size of short int          : %ld bytes\n",MY_SIZEOF(s));
	printf("Size of unsigned char      : %ld byte\n",MY_SIZEOF(uc));
	printf("Size of long double        : %ld bytes\n",MY_SIZEOF(ld));
	printf("Size of signed int         : %ld bytes\n",MY_SIZEOF(si));
	printf("Size of signed char        : %ld byte\n",MY_SIZEOF(sc));
	printf("Size of signed short int   : %ld bytes\n",MY_SIZEOF(ssi));
	printf("Size of unsigned short int : %ld bytes\n",MY_SIZEOF(usi));
	printf("Size of signed long int    : %ld bytes\n",MY_SIZEOF(sli));
	printf("Size of unsigned long int  : %ld bytes\n",MY_SIZEOF(uli));
	printf("Size of signed long long   : %ld bytes\n",MY_SIZEOF(sll));
	printf("Size of unsigned long long : %ld bytes\n",MY_SIZEOF(ull));


return 0;
}

