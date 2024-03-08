#include<stdio.h>

int main() {
    int a[3][3], b[3][3], c[3][3], i, j, rows, cols;
    
    
    printf("Enter the number of rows and columns for the matrices (both should be 3): ");
    scanf("%d%d", &rows, &cols);

    if (rows != 3 || cols != 3) {
        printf("Invalid dimensions. Both matrices must be 3x3.\n");
        return 1;
    }

   
    printf("Enter the elements of the first matrix:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    
    printf("Enter the elements of the second matrix:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Multiplication of matrices
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            c[i][j] = 0;
            for(int k = 0; k < cols; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

  
    printf("First matrix:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    printf("\nSecond matrix:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }

    printf("\nProduct of the matrices:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}

