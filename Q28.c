/*Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1*/
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    
    int rows = matrixSize;
    int cols = matrixColSize[0];
    
    int firstRowZero = 0;
    int firstColZero = 0;
    
    // Step 1: Check if first row has zero
    for(int j = 0; j < cols; j++) {
        if(matrix[0][j] == 0) {
            firstRowZero = 1;
            break;
        }
    }
    
    // Step 2: Check if first column has zero
    for(int i = 0; i < rows; i++) {
        if(matrix[i][0] == 0) {
            firstColZero = 1;
            break;
        }
    }
    
    // Step 3: Mark zeros in first row & column
    for(int i = 1; i < rows; i++) {
        for(int j = 1; j < cols; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    // Step 4: Set cells to zero using marks
    for(int i = 1; i < rows; i++) {
        for(int j = 1; j < cols; j++) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    
    // Step 5: Handle first row
    if(firstRowZero) {
        for(int j = 0; j < cols; j++)
            matrix[0][j] = 0;
    }
    
    // Step 6: Handle first column
    if(firstColZero) {
        for(int i = 0; i < rows; i++)
            matrix[i][0] = 0;
    }
}
