#include <stdio.h>

#include <stdlib.h>

#include <stdbool.h>

#include <string.h>

#define MAX_LIMIT 30

/* Return true (non-zero) if c is a whitespace characer

   ('\t' or ' ').

   Zero terminators are not printable (therefore false) */

bool delim_character(char c)

{

     if(c == '\t' || c == ' ')

     {

     	return 1;

     }

     return 0;

}



/* Return true (non-zero) if c is a non-whitespace

   character (not tab or space).

   Zero terminators are not printable (therefore false) */

bool non_delim_character(char c){

    if(c != '\t' || c != ' ')

       {

    	return 1;

       }

        return 0;

}



/* Returns a pointer to the first character of the next

   space-separated word*/

char *word_start(char* str){

    char* p = str;

    while(*p != '\0')

    {

        if(delim_character(*str))

        {

            p++;

        }

    }

    return p;

}
/* Returns a pointer to the first space character of the zero

terminated string*/

char *end_word(char* str){

    char* p = str;

    while(*p != '\0')

    {

        if(non_delim_character(*str))

        {

            p++;

        }

    }

    return p;

}

// counts the number of words or tokens

int count_tokens(char* str){

    int counter = 0;

    char* current_word = word_start(str);

    while(*current_word != '\0')

    {

        if(non_delim_character(*str))

	    {

	        counter++;

	    }//end if

        	current_word = end_word(current_word);

        	current_word = word_start(current_word);

    }//end for 



}


/* Returns a freshly allocated zero-terminated vector of freshly allocated

   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:

     tokens[0] = "hello"

     tokens[1] = "world"

     tokens[2] = "string"

     tokens[3] = 0

*/

char *copy_str(char *inStr, short len){

    int i = 0;

    char* copy_str = (char*)malloc((len + 1)* sizeof(char));

    for(i = 0; i < len; i++)

    {

        copy_str[i] = inStr[i];

    }

    copy_str[i] = '\0';

    return copy_str;

}



char** tokenize(char* str)

{

    int i = 0; 

    int count = count_tokens(str);

    char* start = str;

    char* end = str;

    char** currentToken = malloc((count + 1)* sizeof(char*));

    while(i < count)

    {

        start = end_word(end);

        end = word_start(start);

        currentToken[i] = copy_str(start, end - start);

        i++;

    }//end while loop

    start[i] = 0;

    return currentToken;

    

}
void print_all_tokens(char** tokens)

{

    for(int i = 0; tokens[i] != 0; i++)

    {

        printf("Tokens[%d]",i);

        printf("%s\n",tokens[i]);

    }//end for 

    printf("\n");

}//end method

int main()

{

    char input[MAX_LIMIT];

    printf("please enter the input string\n");

    printf("$");

    fgets(input,MAX_LIMIT,stdin);

    char** tokens = tokenize(input);

    print_all_tokens(tokens);

    return 0;

}


