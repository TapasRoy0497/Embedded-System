/****************************************************************************************************************************************
  
NAME              : TAPAS ROY

DATE              : 19-07-2021

DESCRIPTION       : Program to find mean for all data type values using void pointer

INPUT             :
OUTPUT            :

			1. Int
			2. Short
			3. float
			4. Double
			Enter the choice : 1

			Enter no.of elements to an array : 5

			Enter 5 elements
			Int_arr[0] -> 4
			Int_arr[1] -> 3
			Int_arr[2] -> 5
			Int_arr[3] -> 3
			Int_arr[4] -> 2
			The mean value : 3.40
			Do you want to continue (y / Y ) : y
			1. Int
			2. Short
			3. float
			4. Double
			Enter the choice : 2

			Enter no.of elements to an array : 6

			Enter 6 elements
			Short_arr[0] -> 2
			Short_arr[1] -> 5
			Short_arr[2] -> 7
			Short_arr[3] -> 4
			Short_arr[4] -> 3
			Short_arr[5] -> 6
			The mean value : 4.50
			Do you want to continue (y / Y ) : y

			1. Int
			2. Short
			3. float
			4. Double
			Enter the choice : 3

			Enter no.of elements to an array : 5

			Enter 5 elements
			Float_arr[0] -> 4.5
			Float_arr[1] -> 4.5
			Float_arr[2] -> 2.4
			Float_arr[3] -> 2.5
			Float_arr[4] -> 6.6
			The mean value : 4.10
			Do you want to continue (y / Y ) : y
			1. Int
			2. Short
			3. float
			4. Double
			Enter the choice : 4

			Enter no.of elements to an array : 5

			Enter 5 elements
			Double_arr[0] -> 34.6
			Double_arr[1] -> 6.5
			Double_arr[2] -> 4.7
			Double_arr[3] -> 3.5
			Double_arr[4] -> .5
			The mean value : 9.96
			Do you want to continue (y / Y ) : y
			1. Int 
			2. Short 
			3. float 
			4. Double 
			Enter the choice : 5
			Please enter an valid choice 

			Do you want to continue (y / Y ) : n
			Operation terminated

			Operation terminated

*****************************************************************************************************************************************/

#include <stdio.h>

// function declaration

float mean_calculation(void *ptr, int size, int choice);

int main()
{
    char ch;

    do
    {   // Declaring variables
	int N, i, choice;
	float mean;

	// prompt to ask choice from user
	printf("1. Int \n2. Short \n3. float \n4. Double \n");
	printf("Enter the choice : ");
	scanf("%d", &choice);
	// prints error msg if choice is not 1/2/3/4
	if (choice !=1 && choice != 2 && choice != 3 && choice != 4)
	{
		printf("Please enter an valid choice \n");
	}
	else
	{	// read n value from user
		printf("\nEnter no.of elements to an array : ");
		scanf("%d", &N);
	
		printf("\nEnter %d elements \n", N);

		if ( choice == 1 )
		{
			int Int_arr[N];  // declaring integer array
		
			for (i = 0; i < N; i++)
                	{
                		printf("Int_arr[%d] -> ", i);
                        	scanf("%d", &Int_arr[i]);  // read input from user 
                	}

               		mean = mean_calculation(Int_arr, N, choice);  // stores mean val from function    

               		printf("The mean value : %.2f", mean);
		}
		else if ( choice == 2 )
		{
                	short Short_arr[N];  // declaring short array

                	for (i = 0; i < N; i++)
                	{
                        	printf("Short_arr[%d] -> ", i);
                        	scanf("%hi", &Short_arr[i]);  // read input from user
                	}

               		mean = mean_calculation(Short_arr, N, choice);

               		printf("The mean value : %.2f", mean);
        	}
		else if ( choice == 3 )
        	{
                	float Float_arr[N];  // Declaring an array of float type

                	for (i = 0; i < N; i++)
                	{
                        	printf("Float_arr[%d] -> ", i);
                        	scanf("%f", &Float_arr[i]);   // read input from user
                	}

               		mean = mean_calculation(Float_arr, N, choice);

               		printf("The mean value : %.2f", mean);
        	}
        	else if ( choice == 4 )
        	{
                	double Double_arr[N];  // declaring an array of double type 

                	for (i = 0; i < N; i++)
                	{
                        	printf("Double_arr[%d] -> ", i);
                        	scanf("%lf", &Double_arr[i] ); // read input from user
                	}

               		mean = mean_calculation(Double_arr, N, choice);
               		printf("The mean value : %.2f", mean);
        	}
	}
	// Ask user to repeat the operation
	printf("\nDo you want to continue (y / Y ) : ");
	scanf(" %c", &ch);
    }

    while (ch == 'y' || ch == 'Y');  // if user enters y/Y then repeat the operation

    printf("Operation terminated\n");

    return 0;
}

float mean_calculation(void *ptr, int size, int choice)
{
    int i;
    double sum, mean;
    if (choice == 1)
    {
    	for (i = 0; i < size; i++) 
    	{
		sum = sum +  *( (int *)ptr + i);   // type casting to int and add all the element of an array
    	}
    }
    else if (choice == 2)
    {
        for (i = 0; i < size; i++)
        {
                sum = sum +  *( (short *)ptr + i);  // type casting to short and add all the elements of an array
        }
    }
    else if (choice == 3)
    {
        for (i = 0; i < size; i++)
        {
                sum = sum +  *( (float *)ptr + i);  // type casting to float and add array elements of an array
        }
    }
    else if (choice == 4)
    {
        for (i = 0; i < size; i++)
        {
                sum = sum +  *( (double *)ptr + i); // type casting to double and add array elements of an array
        }
    }

    mean = (float) sum / size;   // finding avg of an array

    return mean;                 // returning mean value to called function
}


