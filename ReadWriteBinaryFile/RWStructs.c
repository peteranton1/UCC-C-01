#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    char name[256];
    int age;
    double average;
} Student;

// method headers
int write_data(char *filename, Student *data, int total);
Student *read_data(char *filename, int *total);

// main method
int main()
{
    Student *school;

    int records = 3;
    school = malloc(sizeof(Student) * records);

    strcpy(school[0].name, "John");
    school[0].age = 19;
    school[0].average = 80.25;

    strcpy(school[1].name, "Nyra");
    school[1].age = 21;
    school[1].average = 90.50;

    strcpy(school[2].name, "Nageeb");
    school[2].age = 20;
    school[2].average = 85.66;

    // write file
    int new_records = write_data("school.bin", school, records);
    printf("Written : %d\n", new_records);

    if (new_records == records)
        printf("Write Data OK.\n");
    else
    {
        printf("Error writing to file\n");
        return 1;
    }

    free(school);

    int total = 0;
    Student *file_data;

    // read file
    file_data = read_data("school.bin", &total);

    if (file_data == NULL)
    {
        printf("Error reading from file.\n");
        return 1;
    }

    printf("\nData read OK.\n\n");
    for(int i = 0; i < total; i++)
    {
        printf("Student %d\n", i + 1);
        printf("Name: %s\n", file_data[i].name);
        printf(" Age: %d\n", file_data[i].age);
        printf(" Avg: %.2f\n", file_data[i].average);
        printf("\n");
    }

    free(file_data);

    return 0;
}

int write_data(char *filename, Student *data, int total)
{
    FILE *file;
    int new_total = 0;
    
    file = fopen(filename, "wb");

    if(file == NULL) 
        return EOF;

    if (fwrite(&total, sizeof(int), 1, file) != 1)
        return EOF;

    new_total = fwrite(data, sizeof(Student), total, file);
    if (new_total != total)
        return EOF;

    if (fclose(file) == EOF)
        return EOF;

    return new_total;
}

Student *read_data(char *filename, int *total)
{
    FILE *file;

    file = fopen(filename, "rb");

    if (file == NULL) return NULL;

    if (fread(total, sizeof(int), 1, file) != 1)
        return NULL;

    Student *data = malloc(sizeof(Student) * *total);

    if (fread(data, sizeof(Student), *total, file) != *total)
    {
        free(data);
        return NULL;
    }
        
    if (fclose(file) == EOF)
    {
        free(data);
        return NULL;
    }

    return data;
}