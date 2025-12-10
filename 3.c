// Implement a "C program" that dynamically allocates memory for strings and concatenates them. The program
// should perform the following steps:

// 1. Input:
// · Prompt the user to enter two strings of varying lengths.
// Use dynamic memory allocation to create char arrays to store the input strings.

// 2. Functionality:
// . Create a function that takes the two input strings and dynamically allocates memory to concatenate
// them into a new string.
// . The concatenated string should have sufficient space for the combined strings and the null-
// terminator.
// . Repetitively take user inputs and concatenate until the users stops it with 'Q'.
// . All new inputs must be concatenated with the previous data. Do not over-write previous data in the
// variables. (Hint: Something related to re-allocation might help)

// 3. Output: Display the original input strings and the concatenated result.

// 4. Error Handling: Implement appropriate error handling. Check for memory allocation failures and inform the
// user if there's an issue.

// 5. Testing: Test your program with strings of different lengths to ensure correct memory allocation,
// concatenation, and freeing of memory.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *input_string()
{
    char buffer[1024]; // temporary buffer
    printf("Enter a string: ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
        return NULL;
    }
    // Remove newline
    size_t len = strlen(buffer);
    if (buffer[len - 1] == '\n')
        buffer[len - 1] = '\0';

    char *str = malloc((len + 1) * sizeof(char));
    if (str == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    strcpy(str, buffer);
    return str;
}

int main()
{
    char *concatenated = malloc(1); // start empty
    if (concatenated == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    concatenated[0] = '\0';

    while (1)
    {
        printf("\nEnter 'Q' to quit.\n");

        char *str1 = input_string();
        if (str1 == NULL)
            break;
        if (strcmp(str1, "Q") == 0)
        {
            free(str1);
            break;
        }

        char *str2 = input_string();
        if (str2 == NULL)
        {
            free(str1);
            break;
        }
        if (strcmp(str2, "Q") == 0)
        {
            free(str1);
            free(str2);
            break;
        }

        // Resize concatenated string
        size_t new_len = strlen(concatenated) + strlen(str1) + strlen(str2) + 1;
        char *temp = realloc(concatenated, new_len);
        if (temp == NULL)
        {
            printf("Memory allocation failed!\n");
            free(concatenated);
            free(str1);
            free(str2);
            return 1;
        }
        concatenated = temp;

        // Concatenate new strings
        strcat(concatenated, str1);
        strcat(concatenated, str2);

        printf("String 1: %s\n", str1);
        printf("String 2: %s\n", str2);
        printf("Concatenated Result: %s\n", concatenated);

        free(str1);
        free(str2);
    }

    printf("\nFinal concatenated string: %s\n", concatenated);
    free(concatenated);

    return 0;
}