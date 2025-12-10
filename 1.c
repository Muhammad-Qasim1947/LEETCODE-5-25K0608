// Write a C program that creates a 2D dynamic array with 10 rows.
// The number of rows is fixed (10), but the number of columns for each row must be decided by the user,
// one row at a time.
// Your program must:
// Ask the user 10 times to input an integer n.

// n represents how many columns will be allocated for that row.

// Dynamically allocate exactly n integers for that row.

// Fill the entire row with the row index, where indices start from 1.

// Row 1 should be filled with 1

// Row 2 should be filled with 2

// Row 10 should be filled with 10

// After all 10 inputs are processed, print the entire 2D array.
// Make sure memory is properly freed.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows = 10;
    int **matrix;
    int *col_sizes;

    matrix = malloc(rows * sizeof(int *));
    col_sizes = malloc(rows * sizeof(int));

    if (matrix == NULL || col_sizes == NULL)
    {
        printf("Memory Allocation Failed\n");
        return 1;
    }

    for (int i = 0; i < rows; i++)
    {
        int cols;
        printf("Enter The Number Of Columns For Row %d: ", i + 1);
        scanf("%d", &cols);
        col_sizes[i] = cols;

        matrix[i] = malloc(cols * sizeof(int));

        if (matrix[i] == NULL)
        {
            printf("Memory allocation failed for row %d!\n", i + 1);
            for (int j = 0; j < i; j++)
                free(matrix[j]);
            free(matrix);
            free(col_sizes);
            return 1;
        }

        for (int j = 0; j < cols; j++)
            matrix[i][j] = i + 1;
    }

    // Print matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col_sizes[i]; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
    free(col_sizes);

    return 0;
}
