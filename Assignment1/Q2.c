/* CS261- Assignment 1 - Q.2*/
/* Name: Joel Huffman
 * Date: 4/8/2018
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /* Increment a */
    (*a)++;

    /* Decrement  b */
    (*b)--;

    /* Assign a+b to c */
    c = *a + *b;

    /* Return c */
    return c;
}

int main(){
    /* Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    int x = rand() % 11;
    int y = rand() % 11;
    int z = rand() % 11;

    /* Print the values of x, y and z */
    printf("x: %d\ny: %d\nz: %d\n", x, y, z);

    /* Call foo() appropriately, passing x,y,z as parameters */
    int* ptrX = &x;
    int* ptrY = &y;
    int fooReturn = foo(ptrX, ptrY, z);

    printf("Int return value of foo: %d\n", fooReturn);

    /* Print the values of x, y and z */
    printf("x: %d\ny: %d\nz: %d\n", x, y, z);

    /* Print the value returned by foo */


    return 0;
}