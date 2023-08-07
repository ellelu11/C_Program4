/*



Homework Week 12

For week 12 homework, I had to write a program that prompts the user to input information about college courses.
The output will show each course neatly formatted. 

Before the main, each function is declared alongside with the parameter that will be used througout the program.

*/


#include <stdio.h>
#include <string.h>

#define MAX_COURSES 5
#define MAX_STRING_LENGTH 24

// The function course_prefix will hold the course name in a prefix
void course_prefix(char prefix[]);
// The function course_number will hold the course number 
void course_number(char number[]);
// The function course_name will hold the full lenght course name
void course_name(char name[]);
// The function course_info will combine the course prefix, course number,and course name in one string
void course_info(char result[], const char prefix[], const char number[], const char name[]);
// The function print_course_list will print the list of strings and the course information
void print_course_list(const char *course_list[]);


// In the main the function course_list is declared which will hold a list of strings that represent the course information
int main() 
{
    char course_list[MAX_COURSES][MAX_STRING_LENGTH + 1] = {0};

//   The counter controlled loop will get the input from the user 
    for (int i = 0; i < MAX_COURSES; i++) 
	{
        char prefix[4] = {0};
        char number[4] = {0};
        char name[MAX_STRING_LENGTH + 1] = {0};
        char result[MAX_STRING_LENGTH + 10] = {0};

// Calls the function to get the course prefix information
        course_prefix(prefix);
// Calls the function to get the course number       
        course_number(number);
// Calls the function to get the course name       
        course_name(name);
// Calls the function to gather all the information and stores it in the index of the course list        
        course_info(result, prefix, number, name);
        strncpy(course_list[i], result, MAX_STRING_LENGTH);
    }
 // Calls the function to print the course list
    print_course_list(course_list);

    return 0;
}

// Course_prefix will read the course prefix that was input by the user
void course_prefix(char prefix[])
 {
    int valid_prefix = 0;
// The loop will continue iuntil a valid prefix is entered
    while (valid_prefix == 0) 
	{
        printf("Course prefix: ");
        scanf("%3s", prefix);

        if (strlen(prefix) != 3) 
		{
            printf("Course prefix must be 3 characters\n");
        } else 
		{
            valid_prefix = 1;
        }
    }
}

void course_number(char number[]) 
{
    int valid_number = 0;
// The loop will continue until a valid number is entered
    while (valid_number == 0) 
	{
        printf("Course number: ");
        scanf("%3s", number);

        if (strlen(number) != 3) 
		{
            printf("Course number must be 3 digits.\n");
        } else 
		{
            valid_number = 1;
        }
    }
}
// This function will read the course name
void course_name(char name[]) 
{
    printf("Course name: ");
    scanf("%s", name);

    if (strlen(name) > 16) 
	{
        printf("Course name exceeds 16 characters and will be truncated.\n");
        name[16] = '\0';
    }
}
// This function will combine all of the course prefix, number, and the name into a single string
void course_info(char result[], const char prefix[], const char number[], const char name[]) 
{
    sprintf(result, "%s %s %s", prefix, number, name);
}
// This function will print the course list
void print_course_list(const char *course_list[]) 
{
    printf("Courses:\n");
    for (int i = 0; i < MAX_COURSES && course_list[i][0] != '\0'; i++) 
	{
        printf("%s\n", course_list[i]);
    }
}
