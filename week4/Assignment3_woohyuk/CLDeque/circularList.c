/* CS261- Assignment 3 - circularList.c*/
/* Name: Woohyuk Yang
 * Date: Oct. 12th ,2016
 * Solution description: function library for circular list. 
  
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

struct CircularList
{
	int size;
	struct Link* sentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 */
static void init(struct CircularList* list)
{
	list->sentinel = (struct Link*)malloc(sizeof(struct Link));
	list->sentinel->next = list->sentinel;
	list->sentinel->prev = list->sentinel;
	list->size = 0;
}

/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
static struct Link* createLink(TYPE value)
{
	// FIXME: you must write this
	struct Link* newLink = (struct Link*)malloc(sizeof(struct Link));
	newLink->value = value;
	newLink->prev = newLink->next = NULL;
	return newLink;
}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this
	struct Link* newLink = createLink(value);
	link->next->prev = newLink;
	newLink->next = link->next;

	link->next = newLink;
	newLink->prev = link;

	list->size++;
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct CircularList* list, struct Link* link)
{
	// FIXME: you must write this
	struct Link* temp = link;
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;

	free(link);

	list->size--;
}

/**
 * Allocates and initializes a list.
 */
struct CircularList* circularListCreate()
{
	struct CircularList* list =(struct CircularList*)malloc(sizeof(struct CircularList));
	init(list);
	return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
void circularListDestroy(struct CircularList* list)
{
	
    while(list->size != 0)
    	circularListRemoveFront(lsit);
    free(list->sentinel);
    free(list);
    list->sentinel = NULL;
    list->sentinel = NULL;

}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void circularListAddFront(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
	addLinkAfter(list, list->sentinel, value);

}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
	addLinkAfter(list, list->sentinel->prev, value);
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront(struct CircularList* list)
{
	// FIXME: you must write this
	return list->sentinel->next->value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack(struct CircularList* list)
{
	// FIXME: you must write this
	return list->sentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront(struct CircularList* list)
{
	// FIXME: you must write this
	removeLink(list, list->sentinel->next);
}

/**
 * Removes the link at the back of the deque.
 */
void circularListRemoveBack(struct CircularList* list)
{
	// FIXME: you must write this
	removeLink(list, list->sentinel->prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
	// FIXME: you must write this
	if(list->size == 0)
		return 1;
	else
		return 0;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void circularListPrint(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list != NULL);
#if 1
    if(circularListIsEmpty(list))
	{
		printf("this list is empty\n");
		return;
	}
#endif
	struct Link* itr = list->sentinel->next;
	int i;
	for(i = 0; i < list->size; i++)
	{
		printf("%lf\n", itr->value);
		itr = itr->next;
	}
}

/**
 * Reverses the deque.
 */
void circularListReverse(struct CircularList* list)
{
	// FIXME: you must write this
	struct Link* cur = list->sentinel;
	struct Link* temp = cur;
    int i;
	for(i = 0; i < list->size; i++)
	{
		cur->next = cur->prev;
		cur->prev = temp->next;
		cur = temp->next;
        temp = cur->next;
	}
	printf("after reverse\n");
}
