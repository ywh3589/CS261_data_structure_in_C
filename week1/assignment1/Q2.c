/* CS261- Assignment 1 - Q.2*/
/* Name: Woohyuk Yang
 * Date: Oct. 1st, 2016
 * Solution description: We should compare the values of three variables before calling function foo and after calling function foo.  
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = 2* (*a);
    
    /*Set b to half its original value*/
    *b = (*b) / 2;
    /*Assign a+b to c*/
    c = *a + *b;
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5, y = 6, z = 7;
    /*Print the values of x, y and z*/
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("z = %d\n", z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
    int returnValue = foo(&x, &y, z);
    /*Print the value returned by foo*/
    printf("return value of foo = %d", returnValue);
    /*Print the values of x, y and z again*/
    printf("\n");
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("z = %d\n", z);
    /*Is the return value different than the value of z?  Why?
     * 
     * Calling foo, we passed three variable x, y, z from main function.
     * We should figure out why the values of x and y has been changed but not the value of z. 
     * foo function gets the addresses of x and y value so through foo function, actual values stored 
     * in x and y values could be changed but foo function can not change the value of z. because foo function can not access to variable z not knowing the address of the variable.     
     *  
     */
    return 0;
}
    
    
