/****************************************************************************************************************************************
  
NAME              : TAPAS ROY

DATE              : 16-07-2021

DESCRIPTION       : Program to implement binary search tree for all basic data types

INPUT             :
OUTPUT            :

			1. int
			2. char
			3. float
			4. double
			Enter choice : 1

			Enter 'n' value : 5

			Enter 5 elements of type int :
			3
			4
			6
			8
			9
			3 4 6 8 9
			Elements After sorting : 3 4 6 8 9
			Enter Key element to search : 6

			Search element 6 is at position of 2
			Do you want to continue (y / Y) : y
			1. int
			2. char
			3. float
			4. double
			Enter choice : 1

			Enter 'n' value : 4

			Enter 4 elements of type int :
			5
			6
			7
			8
			5 6 7 8
			Elements After sorting : 5 6 7 8
			Enter Key element to search : 4
			Element not found

			Do you want to continue (y / Y) : y
			1. int
			2. char
			3. float
			4. double
			Enter choice : 2

			Enter 'n' value : 5

			Enter 5 characters of type char :
			e
			f
			h
			j
			k

			Elements before sorting : e f h j k
			Elements After sorting : e f h j k
			Enter Key character to search : h

			Search element h is at position of 2
			Do you want to continue (y / Y) : y
			1. int
			2. char
			3. float
			4. double
			Enter choice : 2

			Enter 'n' value : 5

			Enter 5 characters of type char :
			d
			g
			h
			j
			k

			Elements before sorting : d g h j k
			Elements After sorting : d g h j k
			Enter Key character to search : e
			Element not found

			Do you want to continue (y / Y) : y
			1. int
			2. char
			3. float
			4. double 
			Enter choice : 3

			Enter 'n' value : 5

			Enter 5 elements of type float : 
			3.4
			3.2
			6.5
			2.5
			2.4

			Elements before sorting : 3.4 3.2 6.5 2.5 2.4 
			Elements After sorting : 2.4 2.5 3.2 3.4 6.5 
			Enter Key element to search : 3.2

			Search element 3.2 is at position of 2
			Do you want to continue (y / Y) : y
			1. int
			2. char
			3. float
			4. double 
			Enter choice : 3

			Enter 'n' value : 4

			Enter 4 elements of type float : 
			3.2
			6.5
			2.4
			2.1

			Elements before sorting : 3.2 6.5 2.4 2.1 
			Elements After sorting : 2.1 2.4 3.2 6.5 
			Enter Key element to search : 2.5
			Element not found 

			Do you want to continue (y / Y) : y

*****************************************************************************************************************************************/

#include <stdio.h>
#include <stdio_ext.h>

// function declaration

void read_array(void *ptr, int n, int choice);
void print_array(void *ptr, int n, int choice);
void sort_array(void *arr, int n, int choice);
void generic_swap(void *ptr1, void *ptr2, int size);
int binary_search(void *arr, int n, void *key, int choice);

int main()
{
    char ch;

    do
    {   // Declaring variables
	int choice;
        int n = 0, ret;
	// prompt to ask user to select data type 
	printf("1. int\n2. char\n3. float\n4. double \nEnter choice : ");
	scanf("%d", &choice);

	if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
	{
	    printf("Please enter an valid choice\n");   // prints error msg if choice is not (1/2/3/4) 
	}
	else
	{	// prompt to read n value from user
		printf("\nEnter 'n' value : ");
		scanf("%d", &n);   
	    	
		if (choice == 1)  // if choice is 1 means then binary search is for integer data type
	    	{
		    	int Integer[n], key;
			printf("\nEnter %d elements of type int : \n", n);
			read_array(Integer, n, choice);	 // read array elements from user

			print_array(Integer, n, choice);  // print array elements	
			sort_array(Integer, n, choice);   // sorting array elements

			printf("\nElements After sorting : ");
			print_array(Integer, n, choice);	

			printf("\nEnter Key element to search : ");
			scanf("%d", &key);

			ret = binary_search(Integer, n, &key, choice);   // funtion call to binary search (int data type)
			
			if (ret == -1)    // if return value from function is -1 means prints msg as element not found
		    		printf("Element not found \n");
			else
		    		printf("\nSearch element %d is at position of %d", key, ret);  // prints element position in an array
	    	}
		else if (choice == 2)   // char data type
		{	
			char Char[n], key;    
			
			printf("\nEnter %d characters of type char : \n", n);
			__fpurge(stdin);
			read_array(Char, n, choice);
			
			printf("\nElements before sorting : ");
			print_array(Char, n, choice);

			sort_array(Char, n, choice);

			printf("\nElements After sorting : ");
			print_array(Char, n, choice);

			printf("\nEnter Key character to search : ");
			scanf(" %c", &key);

			ret = binary_search(Char, n, &key, choice);
		
			if (ret == -1)
			    printf("Element not found \n");
			else
			    printf("\nSearch element %c is at position of %d", key, ret);

	       }
	       else if (choice == 3)	
	       {
		   	float Float_arr[n], key;  // float data type
		   	printf("\nEnter %d elements of type float : \n", n);
			read_array(Float_arr, n, choice);

			printf("\nElements before sorting : ");
			print_array(Float_arr, n, choice);

			sort_array(Float_arr, n, choice);

			printf("\nElements After sorting : ");
			print_array(Float_arr, n, choice);

			printf("\nEnter Key element to search : ");
			scanf("%f", &key);

			ret = binary_search(Float_arr, n, &key, choice);

			if (ret == -1)
			    printf("Element not found \n");
			else
			    printf("\nSearch element %g is at position of %d", key, ret);
               }
	      else
	      {
		  	double Double_arr[n], key;  // double data type

			printf("\nEnter %d elements of type double : \n", n);

			read_array(Double_arr, n, choice);	
			
			sort_array(Double_arr, n, choice);

			printf("\nElements After sorting : ");
		
			print_array(Double_arr, n, choice);

			printf("\nEnter Key element to search : ");
			scanf("%lf", &key);

			ret = binary_search(Double_arr, n, &key, choice);
		
			if (ret == -1)
			    printf("Element not found \n");
			else
			    printf("\nSearch element %g is at position of %d", key, ret);
			
	     }

	}
	fflush(stdout);  // clearing stdout buffer
	// ask permission from user to repeat the operation
	printf("\nDo you want to continue (y / Y) : ");
	scanf(" %c", &ch);
    }
    while (ch == 'y' || ch == 'Y');  // if user enters (y / Y) then repeat the operation

    printf("Operation terminated\n");
    return 0;
}
 // function call to read input for array elements from user
void read_array(void *ptr, int n, int choice) 
{
    int i;

        if (choice == 1)
        {
            for (i = 0; i < n; i++)
                scanf("%d", ((int *)ptr + i) );  // type cast to int data type and stores in an array
        }
        else if(choice == 2)
        {
            for (i = 0; i < n; i++)
                scanf(" %c", ((char *)ptr + i) ); // type cast to char data type and stores in an array
        }
        else if (choice == 3)
        {
            for (i = 0; i < n; i++)
                scanf("%f", ((float *)ptr + i) ); //  type cast to float data type and stores in an array
        }
        else
        {
            for (i = 0; i < n; i++)
                scanf("%lf", ((double *)ptr + i) ); // type cast to double data type and stores in an array
        }
}
// generic function to print array elements
void print_array(void *ptr, int n, int choice)
{
    int i;

	if (choice == 1)
	{
	    for (i = 0; i < n; i++)
		printf("%d ", *((int *)ptr + i) );   // type cast to int data type and print array elements
	}
	else if(choice == 2)
	{
	    for (i = 0; i < n; i++)
	    	printf("%c ", *((char *)ptr + i) ); // type cast to char data type and print array elements
	}
	else if (choice == 3)
	{
	    for (i = 0; i < n; i++)
		printf("%g ", *((float *)ptr + i) );  // type cast to float data type and print array elements
	}
	else
	{
	    for (i = 0; i < n; i++)
		printf("%g ", *((double *)ptr + i) ); // type cast to double data type and print array elements
	}
}

// generic function to sort array elements 
void sort_array(void *ptr, int n, int choice)
{
    int i, j;
        for ( i = 0; i < n; i++)
        {
                for(j = 0; j < (n - 1 - i) ; j++)
                {
		    if (choice == 1)
		    {
                        if( *((int *)ptr + j) > *((int *)ptr + j + 1) )  // comparing i'th index array element with i+1'th index element
                        {
			    generic_swap( ((int *)ptr + j), ((int *)ptr + j + 1), sizeof(int) ); //generic function call to swap elements
                        }
		    }
		    if (choice == 2) 
		    {
                        if( *((char *)ptr + j) > *((char *)ptr + j + 1) )  // comparing i'th index array element with i+1'th index element
                        {
			    generic_swap( ((char *)ptr + j), ((char *)ptr + j + 1), sizeof(char) );
                        }
		    }
		    if (choice == 3)
		    {
                        if( *((float *)ptr + j) > *((float *)ptr + j + 1) )
                        {
			    generic_swap( ((float *)ptr + j), ((float *)ptr + j + 1), sizeof(float) );
                        }
		    }
		    if (choice == 4)
		    {
                        if( *((double *)ptr + j) > *((double *)ptr + j + 1) )
                        {
			    generic_swap( ((double *)ptr + j), ((double *)ptr + j + 1), sizeof(double) );
                        }
		    }
                }
        }

}
// generic function call for swap function
void generic_swap(void *ptr1, void *ptr2, int size)
{
    char temp;
    int i;
    for(i = 0; i < size; i++)
    {
	temp = *(char *)ptr1;
	*(char *)ptr1 = *(char *)ptr2;
	*(char *)ptr2 = temp;
	ptr1++;
	ptr2++;
    }
}
 // generic function call for binary search 
int binary_search(void *ptr, int n, void *key, int choice)
{
    int low, high, mid, count = 0, i;
    
    low = 0;
    high = n - 1;
	
    if ( choice == 1 )
    {
	for (i = 0; i < n; i++)               
	{
	    if ( *( (int *)ptr + i) == *(int *)key )  // condition to check whether key value is present in array or not
		count++;
	}

	if (count == 0)  // count will be 0 if key element is not present . return -1 to main function
	    return -1;

    	while ( low < high)
    	{
		mid = (low + high) / 2; // find mid position of an array
	
		if ( *((int *)ptr + mid ) == *(int *)key)  // if key element is found return position of that ele to main 
	    		return mid;
		else if ( ( *(int *)key > *(int *)ptr + mid) )
	    		low = mid + 1;
		else
	    		high = mid - 1;
    	}
    }
    if ( choice == 2 )
    {
	for (i = 0; i < n; i++)
        {
            if ( *( (char *)ptr + i) == *(char *)key )  // condition to check whether key value is present in array or not
                count++;
        }

        if (count == 0)
            return -1;

    	while ( low < high)
    	{
		mid = (low + high) / 2;
	
		if ( *((char *)ptr + mid ) == *(char *)key)
	    		return mid;
		else if ( ( *(char *)key > *(char *)ptr + mid) )
	    		low = mid + 1;
		else
	    		high = mid - 1;
    	}
    }
    if ( choice == 3 )
    {
	for (i = 0; i < n; i++)
        {
            if ( *( (float *)ptr + i) == *(float *)key )  // condition to check whether key value is present in array or not
                count++;
        }

        if (count == 0)
            return -1;

    	while ( low < high)
    	{
		mid = (low + high) / 2;
	
		if ( *((float *)ptr + mid ) == *(float *)key)
	    		return mid;
		else if ( ( *(float *)key > *(float *)ptr + mid) )
	    		low = mid + 1;
		else
	    		high = mid - 1;
    	}
    }
    if ( choice == 4 )
    {
	for (i = 0; i < n; i++)
        {
            if ( *( (double *)ptr + i) == *(double *)key )  // condition to check whether key value is present in array or not
                count++;
        }

        if (count == 0)
            return -1;

    	while ( low < high)
    	{
		mid = (low + high) / 2;
	
		if ( *((double *)ptr + mid ) == *(double *)key)
	    		return mid;
		else if ( ( *(double *)key > *(double *)ptr + mid) )
	    		low = mid + 1;
		else
	    		high = mid - 1;
    	}
    }
}
