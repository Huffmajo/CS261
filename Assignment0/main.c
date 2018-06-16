/************************************
 * Program: Triangle Area Calculator
 * Author: Joel Huffman
 * Description: Calculates and prints out the area of a triangle with hard-coded sides.
 ************************************/

#include <stdio.h>
#include <math.h>

double calcSemiperimeter(int a, int b, int c);
double calcTriangleArea(int a, int b, int c, double s);

int main() {
    int a = 4;
    int b = 13;
    int c = 15;
    double s;
    double area;

    s = calcSemiperimeter(a, b, c);
    area = calcTriangleArea(a, b, c, s);

    printf("Area of a triangle with sides: %d, %d, and %d is %f.\n", a, b, c, area);
    return 0;
}

/************************************
 * Function: calcSemiperimeter
 * Description: Accepts 3 int values for the lengths of the triangles sides.
 * Returns the semiperimeter for the triangle based on the sides given
 ************************************/
double calcSemiperimeter(int a, int b, int c)
{
    double semi;
    semi = (a + b + c) / 2;
    return semi;
}

/************************************
 * Function: calcTriangleArea
 * Description: Accepts 3 int values for the lengths of the triangles sides and one double for the semiperimeter
 * Returns the area for the triangle based on the values given.
 ************************************/
double calcTriangleArea(int a, int b, int c, double s)
{
    double area;
    area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}