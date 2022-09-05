#include <stdio.h>

typedef struct 
{
    char type;
    char name[50];
    int age;
    double average;
} Student;

int main(void)
{
    FILE *file;

    file = fopen("file.txt","r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    Student students[100];

    int read = 0;
    int records = 0;
    do 
    {
        read = fscanf(file,"%c,%49[^,],%d,%lf\n",
            &students[records].type,
            students[records].name,
            &students[records].age,
            &students[records].average);
        
        if (read == 4) records++;

        if (read != 4 && !feof(file))
        {
            printf("File format incorrect.\n");
            return 1;
        }

        if (ferror(file))
        {
            printf("Error reading file.\n");
            return 1;
        }

    } while (!feof(file));

    fclose(file);

    printf("\n%d records read.\n", records);

    for (int i = 0; i < records; i++)
    {
        printf("%c %s %d %.2f\n",
            students[i].type,
            students[i].name,
            students[i].age,
            students[i].average
            );
    }

    printf("\n");

    return 0;
}
