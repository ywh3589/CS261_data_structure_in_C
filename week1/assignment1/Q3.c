/* CS261- Assignment 1 - Q.3*/
/* Name: Woohyuk Yang
 * Date: Sep. 30th, 2016
 * Solution description: sort() function sorts a given array of n integers. 
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>


void sort(int* number, int n){
     /*Sort the given array number , of length n*/
	int i = 0, j = 0; // variable i and j are for iterators.
	int temp = 0;	  // variable temp will be used to swap two numbers which are unorderd.
	for(i = 0; i < n-1; i++)
		for(j = i+1; j < n; j++)
			if(number[j] < number[i])
			{
				temp = number[i];
				number[i] = number[j];
				number[j] = temp;
		    }
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    /*Allocate memory for an array of n integers using malloc.*/
    int *p = NULL;
    p = (int*)malloc(n*sizeof(int));
    /*Fill this array with random numbers, using rand().*/
    int i = 0 ; // variable i will be used as a iterator.
    for(i = 0; i < n; i++)
    	p[i] = rand();
    /*Print the contents of the array.*/
   printf("\nbefore sort function\n");
    for(i = 0; i < n; i++)
    	printf("%d\n", p[i]);
    /*Pass this array along with n to the sort() function of part a.*/
    sort(p, n);
    /*Print the contents of the array.*/    
   printf("\nafter sort function\n");
   for(i = 0; i < n; i++)
    	printf("%d\n", p[i]); 
   
   free(p);
   p = NULL; 
   return 0;
}
