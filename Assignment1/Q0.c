/* CS261- Assignment 1 - Q.0*/
/* Name: Joel Huffman
 * Date: 4/5/2018
 * Solution description: Get some practice with pointer manipulation in c
 */


#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
    /*Print the value of iptr*/
    printf("The value pointed to be iptr is: %d\n", *iptr);

    /*Print the address pointed to by iptr*/
    printf("The address pointed to by iptr is: %p\n", iptr);

    /*Print the address of iptr itself*/
    printf("The address of iptr itself is: %p\n", &iptr);

    /*Change the value of iptr itself*/
    *iptr = 100;
}

int main(){

    /*declare an integer x and initialize it randomly to a value in [0,10] */
    int x;
    x = rand() % 11;

    /*Print the address of x*/
    printf("The address of x is: %p\n", &x);

    /*Call fooA() with the address of x*/
    fooA(&x);

    /*Print the value of x*/
    printf("The value of x is: %d\n", x);

    /*Answer the question */
    /*Yes, the value of x is different than the value that was first printed. We changed the value of x when we
     *modified the value of iptr in the foo function.
     */
    return 0;


}

