/*
* CS 261 Data Structures
* Assignment 5
* Name: Joel Huffman
* Date: 5/31/18
*/

#include "hashMap.h"
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
* Calculates the Levenshtein edit distance between the two provided strings
* CODE MODIFIED FROM FOLLOWING SOURCE:
* Author: Ben Bollock
* Link: https://www.lemoda.net/c/levenshtein/
* @param word1
* @param word2
* @return Int of Levenshtein edit distance
*/
int getLevDiv(const char* word1, const char* word2)
{
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    int matrix[len1 + 1][len2 + 1];
    int i;
    for (i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (i = 0; i <= len2; i++) {
        matrix[0][i] = i;
    }
    for (i = 1; i <= len1; i++) {
        int j;
        char c1;

        c1 = word1[i-1];
        for (j = 1; j <= len2; j++) {
            char c2;

            c2 = word2[j-1];
            if (c1 == c2) {
                matrix[i][j] = matrix[i-1][j-1];
            }
            else {
                int delete;
                int insert;
                int substitute;
                int minimum;

                delete = matrix[i-1][j] + 1;
                insert = matrix[i][j-1] + 1;
                substitute = matrix[i-1][j-1] + 1;
                minimum = delete;
                if (insert < minimum) {
                    minimum = insert;
                }
                if (substitute < minimum) {
                    minimum = substitute;
                }
                matrix[i][j] = minimum;
            }
        }
    }
    return matrix[len1][len2];
}

/**
* Checks if array contains the provided string
* @param array
* @param arraySize
* @param string
* @return 1 for true, 0 for false
*/
int arrayContains(char** array, int arraySize, char* string)
{
    for (int i = 0; i < arraySize; i++)
    {
        if (strcmp(array[i], string) == 0)
        {
            return 1;
        }
    }
    return 0;
}

/**
* Verifies string is acceptable (letters only).
* Also converts all letters to lowercase
* @param string
* @return 1 for true, 0 for false
*/
int validateString(char* str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        char c = str[i];
        if (!(c >= 'A' && c <= 'Z') &&
            !(c >= 'a' && c <= 'z'))
        {
            return 0;
        }
    }
    return 1;
}

/**
* Allocates a string for the next word in the file and returns it. This string
* is null terminated. Returns NULL after reaching the end of the file.
* @param file
* @return Allocated string or NULL.
*/
char* nextWord(FILE* file)
{
    int maxLength = 16;
    int length = 0;
    char* word = malloc(sizeof(char) * maxLength);
    while (1)
    {
        char c = fgetc(file);
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == '\'')
        {
            if (length + 1 >= maxLength)
            {
                maxLength *= 2;
                word = realloc(word, maxLength);
            }

            if (c >= 'A' && c <= 'Z')
            {
                c = tolower(c);
            }
            word[length] = c;
            length++;
        }
        else if (length > 0 || c == EOF)
        {
            break;
        }
    }
    if (length == 0)
    {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}

/**
* Loads the contents of the file into the hash map.
* @param file
* @param map
*/
void loadDictionary(FILE* file, HashMap* map)
{
    // FIXME: implement
    char* currentWord = nextWord(file);
    while (currentWord != 0)
    {
        hashMapPut(map, currentWord, 999);
        free(currentWord);
        currentWord = nextWord(file);
    }
}

/**
* Prints the concordance of the given file and performance information. Uses
* the file input1.txt by default or a file name specified as a command line
* argument.
* @param argc
* @param argv
* @return
*/
int main(int argc, const char** argv)
{
    // FIXME: implement
    HashMap* map = hashMapNew(1000);
    int maxLevDiv = 0;

    FILE* file = fopen("dictionary.txt", "r");
    clock_t timer = clock();
    loadDictionary(file, map);
    timer = clock() - timer;
    printf("Dictionary loaded in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    fclose(file);

    char inputBuffer[256];
    int quit = 0;
    while (!quit)
    {

        //validate input (only letters)
        int isValid = 0;
        while (!isValid)
        {
            printf("\nEnter a word or \"quit\" to quit: ");
            scanf("%s", inputBuffer);
            isValid = validateString(inputBuffer);
            if (!isValid)
            {
                printf("Input must consist of only letters. Try again.\n");
            }
        }


        //change all letter to lowercase
        char* newBuffer =  malloc(sizeof(char) * (strlen(inputBuffer)) + 1);
        for (int i = 0; i < strlen(inputBuffer) + 1; i++)
        {
            newBuffer[i] = tolower(inputBuffer[i]);
        }
        strcpy(inputBuffer, newBuffer);
        free(newBuffer);

        // Implement the spell checker code here..
        int isWord = 0;

        if (strcmp(inputBuffer, "quit") == 0)
        {
            quit = 1;
        }
        else
        {
            //set every value of each key to levenshtein distance
            for (int i = 0; i < map->capacity; i++)
            {
                struct HashLink* temp = map->table[i];
                while (temp != 0)
                {
                    int levDiv = getLevDiv(inputBuffer, temp->key);
                    hashMapPut(map, temp->key, levDiv);

                    //check if word is in dictionary
                    if (temp->value == 0)
                    {
                        isWord = 1;
                    }
                    temp = temp->next;
                }
            }

            if (isWord)
            {
                printf("The inputted word %s is spelled correctly\n", inputBuffer);
            }
            else
            {
                //create array where similar words will be stored
                char* similarWords[5];
                for (int i = 0; i < 5; i++)
                {
                    similarWords[i] = malloc(sizeof(char) * 256);
                    assert(similarWords[i] != 0);
                    strcpy(similarWords[i], "0");
                }

                //check for lowest levDiv

                for (int i = 0; i < 5; i++)
                {
                    maxLevDiv = 0;
                    while (strcmp(similarWords[i], "0") == 0)
                    {
                        maxLevDiv++;
                        //search through map and compare levDivs
                        for (int j = 0; j < map->capacity; j++)
                        {
                            struct HashLink* temp = map->table[j];
                            while (temp != 0)
                            {
                                if (temp->value <= maxLevDiv && !arrayContains(similarWords, 5, temp->key))
                                {
                                    strcpy(similarWords[i], temp->key);
                                }
                                temp = temp->next;
                            }
                        }
                    }
                }

                printf("The inputted word %s is spelled incorrectly\nDid you mean:\n", inputBuffer);
                for (int i = 0; i < 5; i++)
                {
                    printf("%d) %s\n", i+1, similarWords[i]);
                }

                //free saved words
                for (int i = 0; i < 5; i++)
                {
                    free(similarWords[i]);
                }
            }
            //end of spell checker code
        }
    }

    hashMapDelete(map);


    return 0;
}