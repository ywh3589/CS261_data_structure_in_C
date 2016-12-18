/* CS261- Assignment 5 - toDo.c*/
/* Name: Woohyuk Yang
 * Date: Nov. 11th ,2016
 * Solution description: function library for todo application. 
 */

#include "dynamicArray.h"
#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Loads into heap a list from a file with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listLoad(DynamicArray* heap, FILE* file)
{
    const int FORMAT_LENGTH = 256;
    char format[FORMAT_LENGTH];
    snprintf(format, FORMAT_LENGTH, "%%d, %%%d[^\n]", TASK_NAME_SIZE);
    
    Task temp;
    while (fscanf(file, format, &temp.priority, &temp.name) == 2)
    {
        dyHeapAdd(heap, taskNew(temp.priority, temp.name), taskCompare);
    }
}

/**
 * Writes to a file all tasks in heap with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listSave(DynamicArray* heap, FILE* file)
{
    for (int i = 0; i < dySize(heap); i++)
    {
        Task* task = dyGet(heap, i);
        fprintf(file, "%d, %s\n", task->priority, task->name);
    }
}

/**
 * Prints every task in heap.
 * @param heap
 */
void listPrint(DynamicArray* heap)
{
    DynamicArray* temp = dyNew(1);
    dyCopy(heap, temp);
    while (dySize(temp) > 0)
    {
        Task* task = dyHeapGetMin(temp);
        printf("\n");
        taskPrint(task);
        printf("\n");
        dyHeapRemoveMin(temp, taskCompare);
    }
    dyDelete(temp);
}

/**
 * Handles the given command.
 * @param list
 * @param command
 */
void handleCommand(DynamicArray* list, char command)
{
    // FIXME: Implement
    char com = command;
    switch(com)
    {	
    	case 'l':
    	{
    		char fileName[30];
    		printf("Please enter the filename: ");
    		fgets(fileName, sizeof(fileName), stdin);
    		fileName[strlen(fileName)-1] = 0;

    		FILE *output_file = fopen(fileName, "r");
    		listLoad(list, output_file);
    		printf("The list has been loaded from file successfully.\n");
    		printf("\n");
    		break;
    	}
    	case 's':
    	{	
    		char fileName[30];
    		printf("Please enter the filename: ");
    		fgets(fileName, sizeof(fileName), stdin);
    		fileName[strlen(fileName)-1] = 0;

    		FILE *output_file = fopen(fileName, "w");
    		listSave(list, output_file);
    		printf("The list has been saved into the file successfully.\n");
    		printf("\n");
    		break;
     	}
     	case 'a':
    	{
    		
    		#if 1
    		char task[TASK_NAME_SIZE];
    		int priority;
    		printf("Please enter the task description: ");
    		fgets(task, sizeof(task), stdin);
    		task[strlen(task)-1] = 0;
    		do
    		{
    			printf("\nPlease enter the task priority(0-999): ");
    			scanf("%d",&priority);
    			while (getchar() != '\n'); //Eat newlines		
    		}while(priority < 0 || priority > 999);
    		struct Task* newTask = taskNew(priority, task);
    		dyHeapAdd(list, newTask, taskCompare);

    		printf("\nThe task "); printf("'%s'",newTask->name);  printf("has been added to your to-do list.\n");
			#endif
			printf("\n");    		
    		break;
    	}
    	case 'g':
    	{
    		
    		#if 1
    		if(0 == dySize(list))
    			printf("Your to-do list is empty\n");
    		else
    		{
    			struct Task* pTask;
    			pTask = (struct Task*)dyGet(list, 0);
    			printf("Your first task is: ");
    			printf("%s\n", pTask->name);
    		}
    		#endif
    		printf("\n");
    		break;
    	}
        case 'r':
    	{
    		if(0 == dySize(list))
    		{
    			printf("Your to-do list is empty\n");
    			printf("\n");
    				break;
    		}
    		struct Task* pTask;
    		printf("%s, %d\n",__FILE__, __LINE__);
    		pTask = (struct Task*)dyGet(list, 0);
    		printf("%s, %d\n",__FILE__, __LINE__);
    		char deletedName[TASK_NAME_SIZE];
    		printf("%s, %d\n",__FILE__, __LINE__);
    		memset(deletedName,0X00,sizeof(char)*TASK_NAME_SIZE);
    		printf("%s, %d\n",__FILE__, __LINE__);
    		strcpy(deletedName, pTask->name);
    		printf("%s, %d\n",__FILE__, __LINE__);
            dyHeapRemoveMin(list, taskCompare);
            printf("%s, %d\n",__FILE__, __LINE__);
    		printf("Your first task ");printf("'%s' has been removed from the list.\n", deletedName);
   			printf("\n");
    		break;
    	}
    	case 'p':
    	{
    		if(0 == dySize(list))
    		{
    			printf("Your to-do list is empty\n");
    			printf("\n");
    				break;
    		}
    		listPrint(list);
    		printf("\n");
      		break;	
    	}
    }
}

int main()
{
    // Implement
    printf("\n\n** TO-DO LIST APPLICATION **\n\n");
    DynamicArray* list = dyNew(8);
    char command = ' ';
    do
    {
        printf("Press:\n"
               "'l' to load to-do list from a file\n"
               "'s' to save to-do list to a file\n"
               "'a' to add a new task\n"
               "'g' to get the first task\n"
               "'r' to remove the first task\n"
               "'p' to print the list\n"
               "'e' to exit the program\n"
        );
       // printf("%s, %d\n",__FILE__, __LINE__);
        command = getchar();
        //printf("%s, %d\n",__FILE__, __LINE__);
        // Eat newlines
        while (getchar() != '\n');
        //printf("%s, %d\n",__FILE__, __LINE__);
        handleCommand(list, command);
        //printf("%s, %d\n",__FILE__, __LINE__);
    }
    while (command != 'e');
    dyDelete(list);
    return 0;
}