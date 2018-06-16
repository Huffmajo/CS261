/* CS261- Assignment 1 - Q.4*/
/* Name: Joel Huffman
 * Date: 4/8/2018
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
    return ch-'a'+'A';
}

/**********************************************************
 * Function: stringValidator
 * description: Accepts a pointer to char (as a array of chars/
 * a string). Checks to see if the string is valid (lowercase
 * letters and underscores only). Returns 1 if string is valid,
 * 0 if string is invalid.
 **********************************************************/
int stringValidator(char* word)
{
    int valid = 1;

    //iterate through whole string
    for (int i = 0; word[i] != '\0'; i++)
    {
        //if char is underscore or lowercase letter, it's valid
        if (word[i] != '_' && (word[i] < 'a' || word[i] > 'z'))
        {
            valid = 0;
        }
    }
    return valid;
}

/**********************************************************
 * Function: camelCase
 * description: Accepts a pointer to char (as a array of chars/
 * a string). Checks to see if the string is valid (lowercase
 * letters and underscores only). If string is valid, prints
 * the word in camelCase. If string is invalid, prints "Invalid
 * input"
 **********************************************************/
void camelCase(char* word){
    /*Convert to camelCase*/

    //if string is invalid print error message
    if (stringValidator(word) == 0)
    {
        printf("Invalid input\n");
    }

    else
    {
        //iterate through entire string
        for (int i = 0; word[i] != '\0'; i++)
        {
            //if current char is an underscore, capitalize next letter
            if (word[i] == '_')
            {
                word[i + 1] = toUpperCase(word[i + 1]);

                //shift each char one position back
                for (int j = i; word[j] != '\0'; j++)
                {
                    word[j] = word[j + 1];
                }
            }
        }

        printf("Inputted string in (lower) camelCase: %s\n", word);
    }


}

int main(){
    /*Read the string from the keyboard */
    char input[300];

    printf("Enter a string: ");
    scanf("%s", input);

    /*Call camelCase*/
    camelCase(input);
    /*Print the new the string */

    return 0;
}
