/* CS261- Assignment 1 - Q.3*/
/* Name: Joel Huffman
 * Date: 4/8/2018
 * Solution description:
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
    int id;
    int score;
};

/**********************************************************
 * Function: sort
 * description: Accepts a pointer to an array of struct
 * students and an int of the size of that array. Sorts the
 * array by score in ascending order. Sorting algorithm is a
 * modified version of Gnome sort sourced from:
 * https://www.geeksforgeeks.org/gnome-sort-a-stupid-one/
 **********************************************************/
void sort(struct student* students, int n){
    /*Sort the n students based on their score*/

    int i = 0;
    while (i < n)
    {
        if (i == 0)
        {
            i++;
        }

        if (students[i].score >= students[i-1].score)
        {
            i++;
        }
        else
        {
            //swap scores
            int temp = students[i].score;
            students[i].score = students[i-1].score;
            students[i-1].score = temp;

            //swap IDs
            temp = students[i].id;
            students[i].id = students[i-1].id;
            students[i-1].id = temp;
            i--;
        }
    }
}

/**********************************************************
 * Function: randomizeIDS
 * description: Accepts a pointer to int array and an int
 * of the size of the array. Randomizes the positions of the
 * contents of the provided array per fisher-yates shuffle.
 **********************************************************/
void randomizeIDs(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int j = rand() % (size - 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

/**********************************************************
 * Function: generate
 * description: Accepts an array of struct students. Provides
 * unique IDs and non-unique scores for each struct student
 * in the array.
 **********************************************************/
void generate(struct student* students){
    // create array of IDs
    int ids[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int* ptrIDs = ids;

    //randomize ID array
    randomizeIDs(ptrIDs, 10);

    //assign randomized, unique IDs to students
    //assign random scores to students
    for (int i = 0; i < 10; i++)
    {
        students[i].id = ptrIDs[i];
        students[i].score = rand() % 101;
    }
}

/**********************************************************
 * Function: output
 * description: Accepts an array of struct students. Prints
 * out the ID and corresponding scores for each struct student
 * in the array.
 **********************************************************/
void output(struct student* students){
    printf("ID SCORE\n");

    //print each ID and score
    for (int i = 0; i < 10; i++)
    {
        printf("%d %d\n", students[i].id, students[i].score);
    }
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 10;

    /*Allocate memory for n students using malloc.*/
    struct student* stud = malloc(n * sizeof(struct student));

    /*Generate random and unique IDs and random scores for the n students, using rand().*/
    generate(stud);

    /*Print the contents of the array of n students.*/
    printf("==BEFORE SORTING==\n");
    output(stud);

    /*Pass this array along with n to the sort() function*/
    sort(stud, n);

    /*Print the contents of the array of n students.*/
    printf("==AFTER SORTING==\n");
    output(stud);

    //deallocate memory
    free(stud);

    return 0;
}
