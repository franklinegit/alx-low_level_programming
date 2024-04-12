#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <string.h>

/* Struct for student */
struct Student
{
    char name[50];
    int score;
} *students;


/**
 * main - Funtion that allocates memory for array of sructures of student information
 * 
 * Return: EXIT_SUCCES or EXIT_FAILURE
*/

int main(void)
{
    int no_of_students, i;
    
    /* Take user input on number of students */
    printf("Enter number of students: \n");
    scanf("%d", &no_of_students);

    /* Dinamically allocate memory aand handle any error */
    students = (struct Student *)malloc(no_of_students * sizeof(struct Student));
    if (students == NULL)
    {
        fprintf(stderr, "Error. Couldn't allocate memory: %s\n", strerror(errno));
        return (EXIT_FAILURE);
    }

    /* Take student information from user and store in memory */
    for (i = 0; i < no_of_students; i++)
    {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter score of student %d: ", i + 1);
        scanf("%d", &students[i].score);

        printf("\n");
    }

    /* Print student information */
     for (i = 0; i < no_of_students; i++)
     {
        printf("Student: %d     Name: %s    Score: %d    \n", i + 1, students[i].name, students[i].score);
     }

    /* Free allocated memory */
    free(students);


    return (EXIT_SUCCESS);
}