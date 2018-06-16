/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string
	pre: s is not null
*/
char nextChar(char* s)
{
    static int i = -1;
    char c;
    ++i;
    c = *(s+i);
    if ( c == '\0' )
        return '\0';
    else
        return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string
	pre: s is not null
	post:
*/
int isBalanced(char* s)
{
    /* FIXME: You will write this function */

    //create dynamic array implemented as stack
    DynArr* stack = newDynArr(10);

    //loop through all characters in provided string
    TYPE c = nextChar(s);
    while (c != '\0')
    {
        //If an opening bracket, push to stack
        if (c == '(' || c == '{' || c == '[')
        {
            pushDynArr(stack, c);
        }

            //if a closing parenthesis, check top of stack for opening brother
        else if (c == ')')
        {
            if (isEmptyDynArr(stack))
            {
                deleteDynArr(stack);
                return 0;
            }

            else if (topDynArr(stack) == '(')
            {
                popDynArr(stack);
            }

            else
            {
                deleteDynArr(stack);
                return 0;
            }
        }

            //if a closing square bracket, check top of stack for opening brother
        else if (c == ']')
        {
            if (isEmptyDynArr(stack))
            {
                deleteDynArr(stack);
                return 0;
            }

            else if (topDynArr(stack) == '[')
            {
                popDynArr(stack);
            }

            else
            {
                deleteDynArr(stack);
                return 0;
            }
        }

            //if a closing parenthesis, check top of stack for opening brother
        else if (c == '}')
        {
            if (isEmptyDynArr(stack))
            {
                deleteDynArr(stack);
                return 0;
            }

            else if (topDynArr(stack) == '{')
            {
                popDynArr(stack);
            }

            else
            {
                deleteDynArr(stack);
                return 0;
            }
        }

        //update c to next character in string
        c = nextChar(s);
    }

    //string is balanced if all parentheses were matched and removed from stack
    if (isEmptyDynArr(stack))
    {
        deleteDynArr(stack);
        return 1;
    }

    else
    {
        for (int i = 0; i < sizeDynArr(stack); i++)
        {
            printf("%c, ", getDynArr(stack, i));
        }
        deleteDynArr(stack);
        return 0;
    }
}

int main(int argc, char* argv[]){

    char* s=argv[1];
    int res;

    printf("Assignment 2\n");

    res = isBalanced(s);

    if (res)
        printf("The string %s is balanced\n",s);
    else
        printf("The string %s is not balanced\n",s);

    return 0;
}

