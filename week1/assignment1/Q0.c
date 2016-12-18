/* CS261- Assignment 1 - Q. 0*/
/* Name: Woohyuk Yang
 * Date: Sep. 30th ,2016
 * Solution description: printing an address of integer x declared and call function fooA, which print the value pointed to by iptr and the address pointed to by iptr and the address of iptr itself. After calling fooA function print the value of x. 
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
	printf("%d\n", *iptr);
     
     /*Print the address pointed to by iptr*/
	printf("%p\n", iptr);
     /*Print the address of iptr itself*/
	printf("%p\n", &iptr);

}

int main(){
    
    /*declare an integer x*/
	int x;
    
    /*print the address of x*/
	printf("%p\n", &x);
    /*Call fooA() with the address of x*/
	fooA(&x);
    /*print the value of x*/
	printf("%d\n", x);
    return 0;
}
