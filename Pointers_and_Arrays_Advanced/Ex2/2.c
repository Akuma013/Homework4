#include <stdio.h>

#define MAX_ROW 100
#define MAX_COL 100

void printMatrix(int matrix[MAX_ROW][MAX_COL], int row, int col);
void transposeMatrix(int matrix[MAX_ROW][MAX_COL], int tmatrix[MAX_COL][MAX_ROW], int row, int col);


int main(){
    int matrix[MAX_ROW][MAX_COL];
    int tmatrix[MAX_COL][MAX_ROW];
    int row, col;

    printf("Enter the number of rows and columns(x y): ");
    scanf("%d %d", &row, &col);

    printf("Enter the elements of the matrix e.g.\na11 a12\na21 a22\n");
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++)
            scanf("%d", &matrix[i][j]);
    }

    transposeMatrix(matrix, tmatrix, row, col);

    printf("Original Matrix:\n");
    printMatrix(matrix, row, col);

    printf("Transpose Matrix:\n");
    printMatrix(tmatrix, col, row);

    return 0;
}

void printMatrix(int matrix[MAX_ROW][MAX_COL], int row, int col){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++)
            printf("%d ", matrix[i][j]);

        printf("\n");
    }
}

void transposeMatrix(int matrix[MAX_ROW][MAX_COL], int tmatrix[MAX_COL][MAX_ROW], int row, int col){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++)
            tmatrix[j][i] = matrix[i][j];
    }
}