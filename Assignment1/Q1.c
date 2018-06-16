/* CS261- Assignment 1 - Q.1*/
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
 * Function: allocate
 * description: No parameters. Allocates memory for 10 struct
 * students and returns the pointer to the beginning of the
 * array of struct students.
 **********************************************************/
struct student* allocate(){
    /*Allocate memory for ten students*/
    struct student* ptrStudents = malloc(10 * sizeof(struct student));

    /*return the pointer*/
    return ptrStudents;
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
    /*Generate random and unique ID and random scores for ten students, ID being between 1 and 10, scores between 0 and 100*/

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
    /*Output information about the ten students in the format:
             ID1 Score1
             ID2 score2
             ID3 score3
             ...
             ID10 score10*/

    printf("==STUDENTS==\nID SCORE\n");

    //print each ID and score
    for (int i = 0; i < 10; i++)
    {
        printf("%d %d\n", students[i].id, students[i].score);
    }
}

/**********************************************************
 * Function: summary
 * description: Accepts an array of struct students. Prints
 * out the maximum, minimum and average score of the struct
 * students.
 **********************************************************/
void summary(struct student* students){
    /*Compute and print the minimum, maximum and average scores of the ten students*/

    int maxScore = students[0].score;
    int minScore = students[0].score;
    int scoreSum = students[0].score;
    double avgScore;

    //find maximum and minimum scores
    //get sum of all scores
    for (int i = 1; i < 10; i++)
    {
        // check if score is the new max
        if (students[i].score > maxScore)
        {
            maxScore = students[i].score;
        }

        //check if score is the new min
        if (students[i].score < minScore)
        {
            minScore = students[i].score;
        }

        //add score to the scoreSum
        scoreSum += students[i].score;
    }

    //calculate average
    avgScore = scoreSum / 10.0;

    //print the results
    printf("==SCORES==\n");
    printf("Minimum: %d\n", minScore);
    printf("Maximum: %d\n", maxScore);
    printf("Average: %f\n", avgScore);
}

/**********************************************************
 * Function: deallocate
 * description: Accepts an array of struct students. Frees
 * memory of the provided array.
 **********************************************************/
void deallocate(struct student* stud){
    /*Deallocate memory from stud*/
    free(stud);
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
