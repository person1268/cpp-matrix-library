/* *************************************************
*  Name: John Pleasant
*  Assignment: 9
*  Purpose: Creating Integer Matrix Class
************************************************* */

#include "main.h"

int main() {
/* **********************************
 * This function is the application driver. It
 * creates an object containing an array
 * and fills it with varying values.
 *
 * @param na : none
 * @return (int) : application exit code
 * @exception na : na
 * @note na
 * **********************************/

    srand(time(NULL));  // call only once per application

    /* This will create a matrix of size ROW_SIZE x COL_SIZE
     * and initialize it to all zeros */
     cout << "create and initialize matrix" << endl;
     Matrix mymatrix(ROW_SIZE, COL_SIZE);
     mymatrix.printMatrix();
     cout << endl;

     /*Set all elements in matrix to 50*/
     cout << "setting all elements in matrix to 50" << endl;
     mymatrix.setMatrix(50);
     mymatrix.printMatrix();
     cout << endl;

     /*This will fail and set random values 1 to 10*/
     cout << "attempting to fill with random values between -2 and 4" << endl;
     mymatrix.setRandom(-2, 4);
     mymatrix.printMatrix();
     cout << endl;

     /*This will fail and set random values 1 to 10*/
     cout << "attempting to fill with random values between 4 and 4" << endl;
     mymatrix.setRandom(4, 4);
     mymatrix.printMatrix();
     cout << endl;

     /*This will succeed and fill the matrix with random numbers 1 to 50*/
     cout << "fill matrix with random values between 1 and 50" << endl;
     mymatrix.setRandom(1, 50);
     mymatrix.printMatrix();
     cout << endl;

     /*This will sort the matrix in order*/
     cout << "sorting the matrix row by row" << endl;
     mymatrix.sortMatrix();
     mymatrix.printMatrix();
     cout << endl;

     /*This will rotate the matrix by 90 degrees*/
     cout << "rotating matrix by 90 degrees" << endl;
     mymatrix.rotateMatrix();
     mymatrix.printMatrix();
     cout << endl;

     /*This will fail to find value 100*/
     cout << "attempting to find value 100 in matrix" << endl;
     if (mymatrix.findValue(100))
     {
        cout << "value 100 found" << endl;
     }
     else
     {
        cout << "value 100 not found" << endl;
     }
     cout << endl;

     /*This will fail to set element*/
     cout << "attempting to set element 100 at [5][5]" << endl;
     if (mymatrix.setElement(100, 5, 5))
     {
        mymatrix.printMatrix();
     }
     cout << endl;

     /*This will succeed and set element 100*/
     cout << "attempting to set element 100 at [2][2]" << endl;
     if (mymatrix.setElement(100, 2, 2))
     {
        mymatrix.printMatrix();
     }
     cout << endl;

     /*This will succeed at finding value 100*/
     cout << "attempting to find value 100 in matrix" << endl;
     if (mymatrix.findValue(100))
     {
        cout << "value 100 found" << endl;
     }
     else
     {
        cout << "value 100 not found" << endl;
     }
     cout << endl;
     
     /*This will fail to print row 5*/
     cout << "attempting to print row 5" << endl;
     mymatrix.printRow(5);
     cout << endl;

     /*This will succeed and print row 0*/
     cout << "attempting to print row 0" << endl;
     mymatrix.printRow(0);
     cout << endl;

     /*This will fail to print column 5*/
     cout << "attempting to print column 5" << endl;
     mymatrix.printColumn(5);
     cout << endl;

     /*This will succeed and print column 0*/
     cout << "attempting to print column 0" << endl;
     mymatrix.printColumn(0);
     cout << endl;

     /*This will fail to find sum of row 5*/
     cout << "attempting to find sum of row 5" << endl;
     cout << "The sum of row 5 is " << mymatrix.rowSum(5) << endl;
     cout << endl;

     /* This will succeed and find the sum of row 0*/
     cout << "attempting to find sum of row 0" << endl;
     cout << "The sum of row 0 is " << mymatrix.rowSum(0) << endl;
     cout << endl;

     /*This will fail to find average of row 5*/
     cout << "attempting to find average of row 5" << endl;
     cout << "The average of row 5 is " << mymatrix.rowAverage(5) << endl;
     cout << endl;

     /* This will succeed and find the average of row 0*/
     cout << "attempting to find average of row 0" << endl;
     cout << "The average of row 0 is " << mymatrix.rowAverage(0) << endl;
     cout << endl;

     /*Finding min and max*/
     cout << "The min value of the matrix is " << mymatrix.min() << endl;
     cout << "The max value of the matrix is " << mymatrix.max() << endl;
     cout<< endl;

     
    return 0;
}
