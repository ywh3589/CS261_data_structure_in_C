/* CS261- Assignment 1 - Q.1*/
/* Name: Woohyuk Yang
 * Date: Oct. 1st. 2016
 * Solution description:After making an array of structures, which can store information which should be made randomly of 10 studnets,  studnets' ids, scores, the minumum score, maximum score, and average score of the ten students should be printed. Deallocation is required after all process.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student* pStudent = (struct student*)malloc(10*sizeof(struct student));
     /*return the pointer*/
     return pStudent;
}

void generate(struct student* students){
     /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
    int uniqueID = -1, randomScores = 0, studentCount = 0;
    int i = 0; // variable i will be used as an iterator below. 
  //  srand(time(NULL));
    while(studentCount != 10)
    {
        
          randomScores = rand() % 101;            //generating scores randomly between 0 and 100
          students[studentCount].score = randomScores; //assigning randomly made scores to each students;

         do
         {
            uniqueID = rand() % 10 + 1;         //generating random ID
           
           for(i = 0 ; i < studentCount; i++) //checking randomly made ID is unique
           {
              if(students[i].id == uniqueID)   //if ID is not unique
              {
                uniqueID = -1;                   //assign -1(works as flag) to uniqueID
                break;  
              }    
           }
              students[studentCount].id = uniqueID;
        }while(students[studentCount].id == -1);
         
        studentCount++;

    }
     
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    int i = 0;   // variable i is an iterator which will be used below. 
    for(i = 0 ; i < 10; i++)
    {
        printf("%d %d\n",students[i].id, students[i].score);
    }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/

  int minScore = students[0].score;
  int maxScore = students[0].score; 
  int sum = 0;
  double average = 0.0;
  int i = 0; // variable i is an iterator which will be used below. 
  for(i = 0; i < 10; i++)
  {
      if(minScore > students[i].score)
        minScore = students[i].score;

      if(maxScore < students[i].score)
        maxScore = students[i].score;

      sum += students[i].score;
  }

    average = sum / 10;

    printf("the minimum score is %d\n", minScore);
    printf("the maximum score is %d\n", maxScore);
    printf("the average score is %lf\n", average);
}


void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
  free(stud);
  stud = NULL;
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate();
    
    /*call generate*/
    generate(stud);
    
    /*call output*/
    output(stud);

    /*call summary*/
    summary(stud);    
    
    /*call deallocate*/
    deallocate(stud);

    return 0;
}
