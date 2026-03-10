/* *************************************************
*  Name: John Pleasant
*  Assignment: 9
*  Purpose: Creating Integer Matrix Class
************************************************* */

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>     /* cout, endl */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <algorithm>    /* copy */

using std::cout;
using std::endl;
using std::sort;
using std::swap;

#define RMIN 1          /*default min*/
#define RMAX 10         /*default max*/
#define DEFAULT_SIZE 0  /*default array size*/

class Matrix {
public:

    /**********************
    Constructors/Destructor
    ***********************/
    Matrix();
    Matrix(int, int);
    ~Matrix();

    /**********************
    Getters/Accessors
    ***********************/
    int rowSum(int);
    double rowAverage(int);
    int min();
    int max();
    bool findValue(int);

    /**********************
    Setters/Mutators
    ***********************/
    void setRandom(int, int);
    void sortMatrix();
    void rotateMatrix();
    bool setElement(int, int, int);
    void setMatrix(int);

    /**********************
    Printing Methods
    ***********************/
    void printMatrix();
    void printRow(int);
    void printColumn(int);

private:
    /**********************
    Attributes
    ***********************/
    int rowLength;
    int colLength;
    int **matrix;
    bool sorted;
};

#endif //MYLIST_H
