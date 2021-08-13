/* *********************************************************************************************************

NAME 		:	TAPAS ROY
DATE		:	12/06/2021

DESCRIPTION	:	Program to find the median of two unsorted arrays.
			 
INPUT 		:	2 Integer Array of 'N' elements. Where 1 < 'N' < 10

OUTPUT 		: 	Enter the 'n' value for Array A: 5
			Enter the elements one by one for Array A: 3 2 8 5 4
			After sorting : 2 3 4 5 8
			Median of array1 : 4
			Enter the 'n' value for Array B: 5
			Enter the elements one by one for Array A: 12 3 7 8 5
			After sorting : 3 5 7 8 12
			Median of array2 : 7
			Median of both arrays : 5.5
			(4 + 7 = 11; 11 / 2 = 5.5)
			
			Do you want to continue(y/Y) : y
			
			Enter the 'n' value for Array A: 5
			Enter the elements one by one for Array A: 3 2 8 5 4
			After sorting : 2 3 4 5 8
			Median of array1 : 4
			Enter the 'n' value for Array B: 4
			Enter the elements one by one for Array A: 12 13 7 5
			After sorting : 5 7 12 13
			Median of array1 : 9.5
			(7 + 12 = 19; 19 / 2 = 9.5)
			Median of both arrays : 6.75
			(4 + 9.5 = 13.5; 13.5 / 2 = 6.75)
			
			Do you want to continue(y/Y) : y
			
			Enter the 'n' value for Array A: 20
			Max array elements exceeded
			
			Do you want to continue(y/Y) : n	

********************************************************************************************************** */

#include <stdio.h>

int main ()
{
    //Declaring variables
    int n1, n2, i, j, temp, mid1, mid2, mid;
    float median1, median2, median;
    char ch;

   do
   {     
       printf("\nEnter the 'n' value for array A : ");
       scanf ("%d", &n1); 	//Reading size of array A
       
       if ( n1 > 10 || n1 < 1 ) //Checking if size exceeding limit
       {
	   printf("Max Array elements exceeded.\n");
	   
	   printf("\nDo you want to continue? (y/Y) : ");
	   scanf(" %c", &ch);
       }
       else 			//If 1st array size within limit 
       {
		   //Reading first array elements from user
		   int arr1[n1];
		   printf("Enter the elelments one by one for Array A : ");
		   for ( i = 0; i < n1; i++ )
		   {
		       scanf ("%d", &arr1[i]);
		   }
		   
		   //Sorting the first array (bubble sort)
		   for  (i = 0; i < n1-1; i++ )
		   {
		       for  ( j = 0; j < n1-1-i; j++ )
		       {
			   if ( arr1[j] > arr1[j+1])
			   {
			       temp = arr1[j];
			       arr1[j] = arr1[j+1];
			       arr1[j+1] = temp;
			   }
		       }
		   }

		   //Printing after sorting the first array 
		   printf("After sorting : ");
		   for ( i = 0; i < n1; i++ )
		   {
		       printf("%d ", arr1[i]);
		   }
		   
		   //Finding the median for first array
		   if ( n1 % 2 == 0 ) 	//When number of elements in the array is even
		   {
		       mid1 = (n1 / 2) - 1;
		       mid2 = mid1 + 1;
		       median1 = (float)( arr1[mid1] + arr1[mid2] ) / 2;
		       printf ("\nMedian of array A is : %.3f\n", median1 );
		   }
		   else			//When number of elements in the array is odd
		   {
		       mid = (n1 / 2);
		       median1 = arr1[mid];
		       printf("\nMedian of array A is : %d\n", arr1[mid]);
		   }
		   
		   printf("Enter the 'n' value for array B : ");
		   scanf ("%d", &n2); 		//Reading size of array B
		   
		   if ( n2 > 10 || n2 < 1) 	//Checking if size exceeding limit
		   {
		       printf("Max array elements exceeded.\n");
		       printf("\nDo you want to continue? (y/Y) : ");
		       scanf(" %c", &ch);
		       continue;    
		   }
		   else
		   {
		       //Reading second array elements from user
		       int arr2[n2];
		       printf("Enter the elements one by one for Array B : ");
		       for ( i = 0; i < n2; i++ )
		       {
		           scanf("%d", &arr2[i]);
		       }
		       
		       //Sorting the second array
		       for  (i = 0; i < n2-1; i++ )
		       {
			   for  ( j = 0; j < n2-1-i; j++ )
			   {
			       if ( arr2[j] > arr2[j+1])
			       {
				   temp = arr2[j];
				   arr2[j] = arr2[j+1];
				   arr2[j+1] = temp;
			       }
			   }
		       }
		       
		       //Printing after sorting the second array 
		       printf("After sorting : ");
		       for ( i = 0; i < n1; i++ )
		       {
			   printf("%d ", arr2[i]);
		       }
		       
		       //Finding the median for second array
		       if ( n2 % 2 == 0 ) 	//When number of elements in the array is even
		       {
			   mid1 = (n2 / 2) - 1;
			   mid2 = mid1 + 1;
			   median2 = (float)( arr2[mid1] + arr2[mid2] ) / 2;
			   printf ("\nMedian of array B is : %.3f", median1 );
		       }
		       else 			//When number of elements in the array is odd
		       {
			   mid = (n2 / 2);
			   median2 = arr2[mid];
			   printf("\nMedian of array B is : %d", arr2[mid]);
		       }
		   }
		   
		   //Finding the median of both the arrays
		   median = (median1 + median2) / 2;
		   printf("\nMedian of both the arrays : %.3f\n", median);
		       
		   printf("\nDo you want to continue? (y/Y) : ");
		   scanf(" %c", &ch); 
       }
   }while ( ch == 'y' || ch =='Y');
}
