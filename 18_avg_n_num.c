/****************************************************************************************************************************************
  
NAME              : TAPAS ROY

DATE              : 07-08-2021 

DESCRIPTION       : Program to read input in 3 diff ways and find avg of n numbers

INPUT             :
OUTPUT            :

			Test case 1 : 
			Select the method to calculate avg :
			1. Scan from keyboard
			2. Proceed with environment variables

			Enter your choice : 1

			Enter how many elements you want to add : 4

			Please enter 4 elements :
			34 68 43 13

			Array elements are : 34 68 43 13
			The average of entered numbers : 39.5

			Test case 2 :
			Select the method to calculate avg : 
			1. Scan from keyboard
			2. Proceed with command line arguments
			3. Proceed with environment variables 

			Enter your choice : 2

			Values provided in command line arguments are :  2 3 4 6
			The average of entered numbers : 3.75

			Test case 3 :
			Select the method to calculate avg :
			1. Scan from keyboard
			2. Proceed with environment variables

			Enter your choice : 2
			Values stored in env variable "arr" are : 1 2 3 4
			The average of entered numbers : 2.5

*****************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// function declaration
char *my_strtok(char *str1, char *token_str);
int my_atoi(char *str);

int main(int argc, char **argv, char *envp[])
{

    // declaring variables
	int choice;
	float sum = 0, avg = 0;
     	
	printf("Select the method to calculate avg : ");
	
	// Display choice to the user (depends on the no.of arg prompt will be displayed)
	if (argc > 1)        
	{
		printf("\n1. Scan from keyboard\n2. Proceed with command line arguments\n3. Proceed with environment variables ");
	}
	if (argc == 1)
	{
		printf("\n1. Scan from keyboard\n2. Proceed with environment variables ");
	}
        
	// prompt to read choice from user
     	printf("\n\nEnter your choice : ");
	scanf("%d", &choice);

	// It will read input through keyboard
	if (choice == 1)
	{
	    // read n from user
	    int n;
	    printf("\nEnter how many elements you want to add : ");
	    scanf("%d", &n);
	    // Declaring array with size n
	    int arr[n];

	    printf("\nPlease enter %d elements : \n", n);
	    
	    for (int i = 0; i < n; i++)
	    {
		scanf("%d", &arr[i]);  // read array elements from user

		sum = sum + arr[i];  // calculating sum of array elements
	    }

	    // displaying array elements
	    printf("\nArray elements are : ");
	    for (int i = 0; i < n; i++)
	    {
		printf("%d ", arr[i] );
	    }

	    avg = (sum / n);  // avg calculation
	    printf("\nThe average of entered numbers : %g\n", avg);

	}  // choice to read i/p through command line
	else if (choice == 2 && argc > 1)
	{
                printf("\nValues provided in command line arguments are : ");
		
		for (int i = 1; i < argc; i++)
		{
                    printf(" %s", argv[i]);
		    sum = sum + my_atoi(argv[i]);  // converting string to int and adding arg values
		}
		avg = (sum / (argc - 1) );  // avg calculation
	
		printf("\nThe average of entered numbers : %g\n", avg);
	
	} // choice to read i/p from env variable
	else if (choice == 2 && argc == 1 || choice == 3 && argc > 1)
	{
	    int count = 0;
	    // declaring pointer variables
	    char *ptr, *token; 

	    char str[5] = " ";  // token

	    // Read i/p from env variable
	    ptr = getenv("Arr");

	    if (ptr == NULL)
	    {
		printf("Environment variable \"arr\" does not exist\n");
	        printf("Please initialise int values with env variable name \"arr\" \n");
	    }
	    else
	    {

            	printf("Values stored in env variable \"arr\" are : ");
	    	puts(ptr);

	 	// get 1st token 
	        token = my_strtok(ptr, str);

	       // To get remaining token
	       while (token != NULL)
	       {
		      count++;
		      sum = sum + my_atoi(token);  // convert string to integer and adding to sum
		      token = my_strtok(NULL, str);
	       }
	       avg = sum / count;  // calculating avg of env variables
	       printf("The average of entered numbers : %g\n", avg);
    	   }
	}
  
    return 0;
}
 

int my_atoi(char *str)
{
     char str1[50];  // Defining an char array
        int i, val, count = 0, temp1 = 0, temp2 = 0, sign = 0;  // Initialising variables

        // logic to implement function like scanf
        for( i = 0; *(str+i) != '\0'; i++)
        {
            // if base address of string is <48 || >57 && (+ && -) then return 0 to  main fun
            if ( ( *str < 48 || *str > 58 ) && ( *str != '+' && *str != '-') )
            {
                return 0;
            }
            else if ( (count == 0 && *str == '+') || ( count == 0 && *str == '-') ) //if base address of str is + / - then assign the sign
            {

                if ( *str == '+')
                {
                        sign = 1;
                        count++;
                }
                else if( *str == '-')
                {
                        sign = -1;
                        count++;
                }
            }
            else if ( *(str+i) >= 48 && *(str+i) <= 57 )  // condition true if element of str is >=48 && <=57
            {
                temp1 = (int)(*(str+i));  // converting Ascii to int
                temp1 = temp1 - 48;
                temp2 = (temp2 * 10) + temp1;
            }
            else if ( (count == 1 && *(str+1) == '+') || ( count == 1 && *(str+1) == '-'))
            {
                return 0;  // if str+1 = +/- then return 0 (++ / -- / -+ / +-)
            }

        }

        if ( sign == 1 )
                return temp2;
        else if (sign == -1)
                return -temp2;
        else
                return temp2;
}


char *my_strtok(char *str1, char *token_str)
{
    static int pos = 0;
    static char *temp_str;
    int j, start;

    start = pos;

    if (str1 != NULL)
    {
        temp_str = str1;
    }

    // iterate string till reaching null character
    while ( temp_str[pos] != 0 )
    {
        // check for token_str match
        for(j = 0; token_str[j] != '\0'; j++)
        {
            // get pos for next string
            if ( temp_str[pos] ==token_str[j] )
            {
                // replace token_str with null character
                temp_str[pos] = '\0';

                pos = pos + 1;

                if( temp_str[start] != '\0' )
                {
                    return (&temp_str[start]);
                }
                else
                {
                    // for next token_str
                    start = pos;
                    pos--;
                    break;
                }
            }
        }
        pos++;
    }

    // to make broken token_strs as string
//    temp_str[pos] = '\0';
    if ( temp_str[start] == '\0')
    {
        pos = 0;
        return NULL;
    }
    else
    {
        return (&temp_str[start]);
    }
}

