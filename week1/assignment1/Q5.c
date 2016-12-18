/* CS261- Assignment 1 - Q.5*/
/* Name: Woohyuk Yang
 * Date: Oct, 1st , 2016
 * Solution description: Applying sticky function to the words input by the user. 
 *                       I only made sticky function to be applied to 20 words at most. 
 *                       If a user input 26 words then only 20 words at will be stored in 
 *                       input stream and be processed. 
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){
     /*Convert to sticky caps*/
	int i = 0;
    int length = 0;
    while(word[length] != 0) //getting the length of the words
    length++;
 
    while(i != length)
	{
		if(i % 2 == 0)
        {
            if((97 <= word[i])&&(word[i] <= 122)) //when the word is a lower case word. 
            word[i] = toUpperCase(word[i]);
            

		}
        else
        {
            if((65 <= word[i])&&(word[i] <= 90)) //when the word is a upper case word.
			word[i] = toLowerCase(word[i]);
        
		}
        i++;
	}
}

int main(){
    /*Read word from the keyboard using scanf*/
    char word[20];
   // memset(word, 0x00, 20);
    printf("type in words less than 20 word\n");
    scanf("%20s", word);
    printf("before stickey");
    printf("\n%s\n", word);
    

    /*Call sticky*/
    sticky(word); 
    printf("after stickey");
    /*Print the new word*/
   	printf("\n%s\n", word);
    
    return 0;
}
