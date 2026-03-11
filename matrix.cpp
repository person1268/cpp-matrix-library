/* *************************************************
*  Name: John Pleasant
*  Assignment: 9
*  Purpose: Creating Integer Matrix Class
************************************************* */

#include "matrix.h"

Matrix::Matrix()
{
/* **********************************
 * This function is the default constructor
 * for class Matrix. It creates an array and
 * sizes it according to the DEFAULT_SIZE
 * 
 * @param (int) : rowSize
 * @param (int) : colSize
 * @return (int) : na
 * @exception na : na
 * @note na
 * **********************************/
    this-> rowLength = DEFAULT_SIZE;
    this->colLength = DEFAULT_SIZE;
    this->matrix = new int*[rowLength];
}

Matrix::Matrix(int rowSize, int colSize)
{
/* **********************************
 * This function is the constructor for
 * class Matrix. It creates an array and
 * sizes it according to the rowSize
 * and colSize parameters
 *
 * @param (int) : rowSize
 * @param (int) : colSize
 * @return (int) : na
 * @exception na : na
 * @note na
 * **********************************/

    if (rowSize < DEFAULT_SIZE)
    {
        rowSize = DEFAULT_SIZE;
    }
    if (colSize < DEFAULT_SIZE)
    {
        colSize = DEFAULT_SIZE;
    }
 
    this->rowLength = rowSize;
    this->colLength = colSize;
    this->matrix = new int*[rowLength];
    for (int i = 0; i < rowLength; i++)
    {
        matrix[i] = new int[colLength];
    }
    this->setMatrix(0);
    this->sorted = false;
}

Matrix::~Matrix() {
    /* **********************************
     * This is the destructor for Matrix
     * objects
     *
     * @param na : none
     * @return (int) : na
     * @exception na : na
     * @note na
     * **********************************/
    for (int i = 0; i < rowLength; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int Matrix::rowSum(int rowNumber)
{
/* **********************************
 * This function returns the sum of
 * the indexes at rowNumber
 *
 * @param na : int rowNumber
 * @return (int) : int total
 * @exception na : na
 * @note na
 * **********************************/
    int total = 0;
    if (rowNumber >= 0 && rowNumber < rowLength)
    {
        for (int i = 0; i < colLength; i++)
        {
            total += matrix[rowNumber][i];
        }
    }

    return total;
}

double Matrix::rowAverage(int rowNumber) {
    /* **********************************
     * This function returns the average
     * of the indexes at rowNumber
     *
     * @param na : int rowNumber
     * @return (double) : double average
     * @exception na : na
     * @note na
     * **********************************/
    double average = 0;

    if (rowNumber >= 0 && rowNumber < rowLength && colLength > 0) {
        average = static_cast<double>(rowSum(rowNumber)) / colLength;
    }

    return average;
}

int Matrix::min()
{
/* **********************************
 * This function returns the minimum
 * value of the matrix
 *
 * @param na : na
 * @return (int) : int minimum
 * @exception na : na
 * @note na
 * **********************************/
    int minimum = matrix[0][0];
    for (int i = 0; i < rowLength; i++)
    {
        for (int j = 0; j < colLength; j++)
        {
            if (matrix[i][j] < minimum)
            {
                // Update minimum if a smaller value is found
                minimum = matrix[i][j];
            }
        }
    }
    return minimum;
}

int Matrix::max()
{
/* **********************************
 * This function returns the maximum
 * value of the matrix
 *
 * @param na : na
 * @return (int) : int maximum
 * @exception na : na
 * @note na
 * **********************************/
    int maximum = matrix[0][0];
    for (int i = 0; i < rowLength; i++)
    {
        for (int j = 0; j < colLength; j++)
        {
            if (matrix[i][j] > maximum)
            {
                // Update maximum if a larger value is found
                maximum = matrix[i][j];
            }
        }
    }
    return maximum;
}

bool Matrix::findValue(int value) {
    /* **********************************
     * This function returns true if the
     * value is found in the matrix
     *
     * @param na : int value
     * @return (bool) : bool found
     * @exception na : na
     * @note na
     * **********************************/
    for (int i = 0; i < rowLength; i++) {
        for (int j = 0; j < colLength; j++) {
            if (matrix[i][j] == value) {
                return true;
            }
        }
    }

    return false;
}

void Matrix::setRandom(int low, int high)
{
    if (low == high || low < 0)
    {
        low = RMIN;
        high = RMAX;
    }

    for (int i = 0; i < rowLength; i++)
    {
        for (int j = 0; j < colLength; j++)
        {
            matrix[i][j] = rand() % (high - low + 1) + low; // Generate random number
        }
    }
}

void Matrix::sortMatrix()
{
/* **********************************
 * This function sorts the matrix
 * row by row
 *
 * @param na : na
 * @return (int) : int 
 * @exception na : na
 * @note na
 * **********************************/
    for (int i = 0 ; i < rowLength; i++)
    {
        sort(matrix[i], matrix[i] + colLength);
    }

    sorted = true;
}

void Matrix::rotateMatrix() {
    /* **********************************
     * This function rotates the matrix
     * by 90 degrees clockwise
     *
     * @param na : na
     * @return (int) : int
     * @exception na : na
     * @note na
     * **********************************/
    int **newmatrix = new int*[colLength];

    for (int i = 0; i < colLength; i++) {
        newmatrix[i] = new int[rowLength];
    }

    for (int i = 0; i < rowLength; i++) {
        for (int j = 0; j < colLength; j++) {
            newmatrix[j][rowLength - 1 - i] = matrix[i][j];
        }
    }

    for (int i = 0; i < rowLength; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    matrix = newmatrix;

    int temp = rowLength;
    rowLength = colLength;
    colLength = temp;

    sorted = false;
}

bool Matrix::setElement(int element, int i, int j)
{
/* **********************************
 * This function sets th value of
 * the matrix element at [i][j]
 *
 * @param na : int element, int i, int j
 * @return (int) : int 
 * @exception na : na
 * @note na
 * **********************************/
    bool goodData = false;
    if (i < rowLength && j < colLength && i >=0 && j >= 0)
    {
        matrix[i][j] = element;
        sorted = false;
        goodData = true;
    }
    else
    {
        cout << "Row and Column must be in range" << endl;
    }
    return goodData;
    
}

void Matrix::setMatrix(int element)
{
/* **********************************
 * This function sets each element
 * in the matrix to one value
 *
 * @param na : int element
 * @return (int) : int 
 * @exception na : na
 * @note na
 * **********************************/
    for (int i = 0; i < rowLength; i++)
    {
        for (int j = 0; j < colLength; j++)
        {
            matrix[i][j] = element;
        }
    }
    sorted = true;
}

void Matrix::printMatrix()
{
/* **********************************
 * This function prints out the 
 * matrix
 *
 * @param na : na
 * @return (int) : int 
 * @exception na : na
 * @note na
 * **********************************/
    for (int i = 0; i < rowLength; i++)
    {
        cout << "[ ";
        for (int j = 0; j < colLength; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "]" << endl;  
    }
}

void Matrix::printRow(int row)
{
/* **********************************
 * This function prints out a row
 * in the matrix
 *
 * @param na : na
 * @return (int) : int 
 * @exception na : na
 * @note na
 * **********************************/
    if (row < rowLength && row >= 0)
    {
        cout << "[ ";
        for (int i = 0; i < colLength; i++)
        {
            cout << matrix[row][i] << " ";
        }
        cout << "]" << endl;
    }
    else
    {
        cout << "Row must be in range" << endl;
    }
}

void Matrix::printColumn(int column)
{
/* **********************************
 * This function prints out a column
 * in the matrix
 *
 * @param na : int column
 * @return (int) : int 
 * @exception na : na
 * @note na
 * **********************************/
    if (column < colLength && column >= 0)
    {
        cout << "[ ";
        for (int i = 0; i < rowLength; i++)
        {
            cout << matrix[i][column] << " ";
        }
        cout << "]" << endl;
    }
    else
    {
        cout << "Column must be in range" << endl;
    }
}
