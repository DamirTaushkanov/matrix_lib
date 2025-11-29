#include "s21_matrix.h"
#include <stdlib.h>
#include <math.h>

#define SUCCESS 1
#define FAILURE 0

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    if (rows<=0||columns<=0||result==NULL)return 1;

    double **matrix = malloc(columns * sizeof(double*));
    if (matrix == NULL)return 1;

    for (int i = 0; i<columns; i++) {
        matrix[i] = calloc(rows, sizeof(double));
        if (matrix[i]==NULL) {
            for (int j = 0; j<i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return 1;
        }
    }

    result->matrix = matrix;
    result->rows = rows;
    result->columns = columns;
    return 0;
}

void s21_remove_matrix(matrix_t *A) {
    if (A == NULL) return;
    
    if (A->matrix != NULL) {
        for (int i = 0; i<A->columns; i++) {
            free(A->matrix[i]);
        }
        free(A->matrix);
        A->matrix = NULL;
    }
    
    A->rows = 0;
    A->columns = 0;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    if (A == NULL || B == NULL || A->matrix == NULL || B->matrix == NULL) return FAILURE;
    
    if (A->columns!=B->columns || A->rows!=B->rows)return 2;
    
    for (int i = 0; i<A->columns; i++) {
        for (int j = 0; j<A->rows; j++){
            if (fabs(A->matrix[i][j]-B->matrix[i][j])>1e-7)return FAILURE;
        }
    }
    return SUCCESS;
}