/* CS261- Assignment 1 - Q.4*/
/* Name: Woohyuk Yang
 * Date: Oct. 1st, 2016
 * Solution description: Sorting the array of students with ascending scores.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/     
    int i = 0, j = 0; //variable i and j are iterators which will be used.
    int temp = 0; //temp variable will be used to switch two elements later.
    for(i = 0; i < n-1; i++)
        for(j = i+1; j < n; j++)
            if(students[i].score > students[j].score)
            {
                temp = students[i].score;
                students[i].score = students[j].score;
                students[j].score = temp;
            }
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 10; 
    /*Allocate memory for n students using malloc.*/
    struct student* pStudent = (struct student*)malloc(10*sizeof(struct student));
    /*Generate random and unique IDs and random scores for the n students, using rand().*/
 //   srand(time(NULL));
    int randomScores = rand() % 101;
    int uniqueIDs = 0;
    int studentCount = 0;
    int i = 0; //i will be used for iterator 

    while(studentCount != 10)
    {
        
          randomScores = rand() % 101;            //generating scores randomly between 0 and 100
          pStudent[studentCount].score = randomScores; //assigning randomly made scores to each students;

         do
         {
            uniqueIDs = rand() % n + 1;         //generating random ID
           
           for(i = 0 ; i < studentCount; i++) //checking randomly made ID is unique
           {
              if(pStudent[i].id == uniqueIDs)   //if ID is not unique
              {
                uniqueIDs = -1;                   //assign -1(works as flag) to uniqueID
                break;  
              }    
           }
              pStudent[studentCount].id = uniqueIDs;
        }while(pStudent[studentCount].id == -1);
         
        studentCount++;

    }


    
    
    /*Print the contents of the array of n students.*/
    printf("\nbefore sorting\n");
    for(i = 0 ; i < n; i++)
    {
        printf("%d %d\n",pStudent[i].id, pStudent[i].score);
    }

    /*Pass this array along with n to the sort() function*/
    sort(pStudent, n);
    /*Print the contents of the array of n students.*/
    printf("\nafter sorting\n");
    for(i = 0 ; i < n; i++)
    {
        printf("%d %d\n",pStudent[i].id, pStudent[i].score);
    }

    free(pStudent);     // deallocating pStudnet.
    pStudent = NULL;


    return 0;
}
