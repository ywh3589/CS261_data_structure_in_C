#include "circularList.h"
#include <stdio.h>

int main()
{	
	struct CircularList* deque = circularListCreate(); 
printf("1");
	circularListAddBack(deque, (TYPE)1);
printf("1");
	circularListAddBack(deque, (TYPE)2);
printf("1");
	circularListAddBack(deque, (TYPE)3);
printf("1");
	circularListAddFront(deque, (TYPE)4);
printf("1");
	circularListAddFront(deque, (TYPE)5);
printf("1");
	circularListAddFront(deque, (TYPE)6);
printf("1");
	circularListPrint(deque);
printf("1");
	printf("%g\n", circularListFront(deque));
printf("1");
	printf("%g\n", circularListBack(deque));
printf("1");
	
	circularListRemoveFront(deque);
printf("1");
	circularListRemoveBack(deque);
printf("1");
	circularListPrint(deque);
printf("1");
	
	circularListReverse(deque);
printf("1");
	circularListPrint(deque);
printf("1");
	
	circularListDestroy(deque);
printf("1");
	
	return 0;
}
