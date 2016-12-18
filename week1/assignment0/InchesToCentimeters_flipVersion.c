/* CS261- Assignment 0 */
/* Name: Woohyuk Yang
 * Date: 09/28/16
 * Solution description: A simple C program to convert a value from inches to centimeters
 						 and vice versa.  
 */


#include <stdio.h>

void InchesToCenti()
{
	double centi, inches = 0;
	do{
		printf("Input the number you want to chage to centimeters\n");
	   __fpurge(stdin);
        //fflush(stdin);
	} while (scanf("%lf", &inches) != 1);
	
	centi = 2.54 * inches;

	printf("the result is %lf cm.\n", centi);

}

void CentiToInches()
{
	double centi, inches = 0;
	do{
		printf("Input the number you want to chage to inches\n");
		//fflush(stdin);
	   __fpurge(stdin);
	} while (scanf("%lf", &centi) != 1);
	
	inches = centi / 2.54;

	printf("the result is %lf inches. \n", inches);
}


int main()
{
	while (1)
	{
		int menuSelect = 0;
		do
		{
			printf("\n\n");
			printf("1. Inches to Centimeters \n");
			printf("2. Centimeters to Inches\n");
			printf("3. Exit\n\n");
			printf("Choose what you want\n");
			//fflush(stdin);
	        __fpurge(stdin);
		} while (scanf("%d", &menuSelect) != 1);

		
		if (menuSelect == 1)
			InchesToCenti();
		else if (menuSelect == 2)
			CentiToInches();
		else if (menuSelect == 3)
			break;
		else
			continue;
	} 	
	return 0;
}
