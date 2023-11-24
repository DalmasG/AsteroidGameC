#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 
#define DICT_SIZE 5757
#define WORD_SIZE 5
#define maxguess 6
//utils.c function
void 
load_word_list (char dictionary[DICT_SIZE][WORD_SIZE + 1]) 
{
  
 
 
 
 
 
char *file_name = "./word_list.txt";
  
 
 
 
 
 
FILE * f = fopen (file_name, "r");
  
 
 
 
 
int idx = 0;
  
 
 
 
 
 
if (f == NULL)
    
 
 
 
    {
      
 
 
 
 
printf 
	("%s does not exist. Please ensure you have downloaded it from Canvas.",
	 
 
 
 
file_name);
    
 
 
 
 
}
  
 
 
 
 
  else
    
 
 
 
    {
      
 
 
 
 
while (fscanf (f, "%s", dictionary[idx++]) != EOF);
    
 
 
 
 
}

 
 
 
 
 
 
}


 
 
 
 
 
 
//

int 
main () 
{
  
 
 
 
//Calls load_word_list
  char dictionary[DICT_SIZE][WORD_SIZE + 1];
  
 
 
load_word_list (dictionary);
  
 
 
 
//Time index
    srand (time (NULL));
  
 
 
 
 
 
int word_pos = rand () % DICT_SIZE;
  
 
 
 
//holds chosen word from dictionary
  char *chosenword = dictionary[word_pos];
  
 
 
 
//char correct_position
  
char userguess[WORD_SIZE + 1];
  
 
 
 
 
int guesspos = 0;
  
 
 
 
//Information relating to menu 
    printf ("*DEV* word =%s", chosenword);
  
 
 
 
printf ("\nPlease enter your guess 1 letter at a time");
  
 
 
 
printf ("\nAny letters after the first letter will be discarded");
  
 
 
 
printf ("\nGuess the 5-letter word!\n");
  
 
 
 
    //Loop to get users guess, Letter at a time
    for (int i = 0; i < WORD_SIZE; i++)
    
 
 
    {
      
 
 
//User prompt      
	printf ("\nEnter letter %d: ", guesspos + 1);
      
 
 
 
 
char c = getchar ();
      
 
 
 
while (c == '\n')
	
 
 
	{
	  
 
 
 
c = getchar ();
	
 
 
 
}
      
 
 
 
 
userguess[i] = c;
      
 
 
 
 
 
guesspos++;
      
 
 
 
 
while (getchar () != '\n');	//gets rid of the enter from the user prompt 
      //Used to stop the program from spamming the Enter guess
      
if (userguess[i] == chosenword[i])
	
 
	  //if letters are different = incorrect
	{
	  
 
 
//User guess is correct and tells user the inputted letter at position i 
	    printf ("This letter is correct:%c", userguess[i]);
	
 
 
 
 
}
      
 
 
      else
	
 
 
	{
	  
 
 
//Guess from user is incorrect on i letter        
	    printf ("This guess is incorrect:%s", "-");
	
 
 
 
}
    
 
 
 
}
  
 
 
 
 
 
userguess[WORD_SIZE] = '\0';	// add null terminator to guess string
  
int correct_guess = 1;	//assume correct
  
for (int i = 0; i < WORD_SIZE; i++)
    
 
 
 
    {
      
 
 
 
 
if (userguess[i] != chosenword[i])
	
 
 
 
	{
	  
 
 
 
// if any letters are different, guess is incorrect
	    correct_guess = 0;
	  
 
 
 
 
break;
	
 
 
 
 
}
    
 
 
 
 
}
  
 
 
 
 
 
if (correct_guess)
    
 
 
 
    {				// print congratulatory message if guess is correct
      printf ("\nCongratulations, you guessed the word!");
    
 
 
 
 
}
  
 
 
 
  else
    
 
 
 
    {
      
 
 
 
	//Prompt for incorrect guess
	printf ("\nSorry, that was not the correct word. The word was %s.\n",
		
 
 
 
chosenword);
    
 
 
 
 
}
  
 
return 0;

 
}


 
 
 
 
 
 
