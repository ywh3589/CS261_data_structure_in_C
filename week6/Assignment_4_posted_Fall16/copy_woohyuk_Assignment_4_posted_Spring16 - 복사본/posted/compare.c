#include <stdio.h>
#include <assert.h>
#include "bst.h"
#include "structs.h"

/*----------------------------------------------------------------------------
 very similar to the compareTo method in java or the strcmp function in c. it
 returns an integer to tell you if the left value is greater then, less then, or
 equal to the right value. you are comparing the number variable, letter is not
 used in the comparison.

 if left < right return -1
 if left > right return 1
 if left = right return 0
 */

 /*Define this function, type casting the value of void * to the desired type.
  The current definition of TYPE in bst.h is void*, which means that left and
  right are void pointers. To compare left and right, you should first cast
  left and right to the corresponding pointer type (struct data *), and then
  compare the values pointed by the casted pointers.

  DO NOT compare the addresses pointed by left and right, i.e. "if (left < right)",
  which is really wrong.
 */
int compare(TYPE left, TYPE right)
{
//printf("%d, %s\n",__LINE__,__FILE__);
    /*FIXME: write this*/
    struct data* pleft;
    pleft = (struct data*)left;
//printf("%d, %s\n",__LINE__,__FILE__);
    struct data* pright;
    pright = (struct data*)right;
//printf("%d, %s\n",__LINE__,__FILE__);
    if(pleft->number < pright->number)
    {
//printf("%d, %s\n",__LINE__,__FILE__);
        return -1;
    }
    else if (pleft->number > pright->number)
    {
//printf("%d, %s\n",__LINE__,__FILE__);
        return 1;
    }
    else
    {
//printf("%d, %s\n",__LINE__,__FILE__);
        return 0;
    }
 }

/*Define this function, type casting the value of void * to the desired type*/
void print_type(TYPE curval)
{
    /*FIXME: write this*/


    struct data* ptype = (struct data*)curval;
	printf("the current value is : %d\n", ptype->number);
}


