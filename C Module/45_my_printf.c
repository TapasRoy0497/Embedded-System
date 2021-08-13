/****************************************************************************************************************************************
  
NAME              : TAPAS ROY

DATE              : 28-07-2021 

DESCRIPTION       : Program to implement printf function using variadic function concept

INPUT             :
OUTPUT            :

			Enter a number : 34

			Enter an character : R

			Enter an float value : 4.6

			Enter a double value : 2.4

			Enter an string : hello

			num = 34
			char = R
			str = hello
			float = 4.600000
			double = 2.400000

			Do you want to continue ( y / Y ) : n

			Operation terminated

*****************************************************************************************************************************************/

#include <stdio.h>
#include <stdarg.h>

// function declaration
int my_itoa(int num, char *str);
int my_floatToString(float f, char *str, int precision);
int my_printf(const char *format, ...);
int display(char *ptr);

int main()
{

    char ch;  // declaring char variable

    do
    {
	// declaring variables for all data type
	int num;
	char ch1;
	float f;
	double d;
	char str[100];

	// prompt to read input from user
	my_printf("\nEnter a number : ");
	scanf("%d", &num);
	
	my_printf("\nEnter an character : ");
	scanf(" %c", &ch1);

	my_printf("\nEnter an float value : ");
	scanf("%f", &f);

	my_printf("\nEnter a double value : ");
	scanf("%lf", &d);
	
	my_printf("\nEnter an string : ");
	scanf("%s", str);
	
	// printing values which is stored
	my_printf("\nPrinting values which we read : ");
	my_printf("\nnum = %d\nchar = %c\nstr = %s\nfloat = %f\ndouble = %lf \n\n", num, ch1, str, f, d);

	my_printf("Checking return value of the my_printf function : \n\n");
	my_printf("ret value from my_printf =  %d \n", my_printf("%d %s %f\n", num, str, f) );
	my_printf("\n");
	printf("ret value from printf=  %d \n", printf("%d %s %f\n", num, str, f) );

	// prompt to ask permission from user to repeat the operation
	my_printf("\nDo you want to continue ( y / Y ) : ");
	scanf(" %c", &ch);
    }
    while(ch == 'y' || ch == 'Y');   // if user enters y / Y then repeat the operation

    my_printf("\nOperation terminated\n");

    return 0;
}

int my_printf(const char *format, ...)
{
    int x;
    char ch2;
    float f;
    double d;
    char *str;
    int ret = 0;
    char int_buffer[100],string_buffer[100],float_buffer[100],double_buffer[100];

    va_list ap;  // creating ptr variable to point the function arguments

    va_start(ap, format);  // assigning first arg to ap

	static int count = 0;
    while (*format)
    {
	if( *format == '%')   // condition true if it find %
	{
		format++;

		switch( *format)
		{
		    case 'd' :
				x = va_arg(ap, int);   // extracting next value from the funtion argument and storing in variable
				my_itoa(x, int_buffer);   // converting int to string
				ret = display(int_buffer);      // printing string
				format++;                 // incrementing pointer variable
				count = count + ret;
				break;
		    case 'c':
				ch2 = va_arg(ap, int);
				putchar(ch2);
				count++;
				format++;
				break;
		    case 's' :
				str = va_arg(ap, char *);
				ret = display(str);
				count = count + ret;
				format++;
				break;
		    case 'f' :
				f = va_arg(ap, double);
			        ret = my_floatToString(f, float_buffer, 6);
				count = count + ++ret;
				display(float_buffer);
				format++;
				break;
		    case 'l' :
				format++;
				if (*format == 'f')
				{
					d = va_arg(ap, double);
					ret = my_floatToString(d, double_buffer, 6);
					count = count + ++ret;
					display(double_buffer);
					format++;
					break;
				}
		}

	}
	else
	{
//	    printf("%c\n", *format);
	    putchar(*format);  // printing string which is stored in code segment
	    count++;
//	    printf("Count in else %d \n", count);
	    format++;  // incrementing pointer var
	}
    }
    	int count1 = count;
	count = 0;
	return count1;
}


int my_floatToString(float f, char *str, int precision)
{
    int count = 0;
        int i = 0, j = 0, power = 1;
        int d = f;
        i = my_itoa(d, str);
	count = count + i;
        str[i++] = '.';
        f = f - d;                              //  float - integer not gives round off value

        for(j; j < precision ; j++)
                power *= 10;

        f = f + (0.1 / (float)power);      
        f = (f * power);
        j = my_itoa((int)f, &str[i]);
	count = count + j;
        i = i + j;

        for(j; j < 6; j++)
                str[i++] = '0';

        str[i]='\0';
	return count;
}

int my_itoa(int num, char *str)
{
        int i = 0, j, count = 0, temp = num;
        if(num < 0)
        {
                str[i++] = '-';                   // if value is neg, then assign '-' to 0th index and increment the i
                num *= -1; 
        }
        while(temp > 0)                           // count no.of digits in an entered number
        {
                i++;
                temp = temp / 10;
        }
        str[i] = '\0';                            // adding null character at last

        for(j = i - 1; num != 0; j--)             // index starts from last (excluding null character)
        {
                str[j] = num % 10 + 48;           // conversion of digit to character
                num = num / 10;             
        }
        return i;
}


int display(char *ptr)
{
    int len = 0;
    while (*ptr)    // printing string char by char
    {
	len++;
	putchar(*ptr);
	ptr++;
    }
    return len;
}
