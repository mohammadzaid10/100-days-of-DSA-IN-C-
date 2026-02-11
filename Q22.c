/*The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.*/
#include <stdio.h>

int main() {
    int m, n;

    // Read rows and columns
    scanf("%d %d", &m, &n);

    int A[m][n];

    // Read matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Print transpose (swap rows and columns)
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < m; i++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}
