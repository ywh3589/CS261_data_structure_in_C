/* CS261- Assignment 2 - dynamicArray.c*/
/* Name: Woohyuk Yang
 * Date: Oct. 5th ,2016
 * Solution description: function library for dynamic array. 
 The instructor let to change even "main" function to handle null string, I modified main function to handle null string.
 Thanks. 
 */
/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */
	if(s==NULL) //To handle null string, return 2
    {
        return 2;
    }
	
    char nextCharacter;
	DynArr *dyn;
	dyn = newDynArr(10); //new array to store brakets. 
        
	while(1) //filling up the new array. 
	{
		nextCharacter = nextChar(s);

		if(nextCharacter == '[')
			pushDynArr(dyn, ']');
		else if(nextCharacter == '{')
			pushDynArr(dyn, '}');
		else if(nextCharacter == '(')
			pushDynArr(dyn, ')');
		else if(nextCharacter == ']')
		{
			if(isEmptyDynArr(dyn))
				return 0;
			else if(topDynArr(dyn) == ']')
				popDynArr(dyn);
			else 
				return 0; //not balanced
		}
		else if(nextCharacter == '}')
		{
			if(isEmptyDynArr(dyn))
				return 0;
			else if(topDynArr(dyn) == '}')
				popDynArr(dyn);
			else 
				return 0; //not balanced
		}
		else if(nextCharacter == ')')
		{
			if(isEmptyDynArr(dyn))
				return 0;
			else if(topDynArr(dyn) == ')')
				popDynArr(dyn);
			else 
				return 0; //not balanced
		}
		else if(nextCharacter == '\0')
		{
            if(isEmptyDynArr(dyn))
				break;
			else
				return 0;
		
        }
		else
			continue;
	}



		return 1; // balanced

}



int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res == 1)
		printf("The string %s is balanced\n",s);
	else if(res == 2)
        printf("This is null string\n");
    else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

