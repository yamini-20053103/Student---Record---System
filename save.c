
#include "header.h"

typedef struct
{
    int roll;
    char name[50];
    float percentage;
} StudentData;

void stud_save(void)
{
    FILE *fp;
    ST *temp;
    StudentData data;
   
    fp = fopen("student.dat", "w");

    if (fp == NULL)
    {
        printf("File Opening Failed\n");
        return;
    }
    temp = head;

    while (temp != NULL)
    {
        data.roll = temp->roll;
        strcpy(data.name, temp->name);
        data.percentage = temp->percentage;

        fwrite(&data, sizeof(data), 1, fp);

        temp = temp->next;
    }

    fclose(fp);

    printf("Records Saved Successfully\n");
}

void stud_load(void)
{
    FILE *fp;
    ST *newnode, *temp;
    StudentData data;

    fp = fopen("student.dat", "r");

    if (fp == NULL)
    {
        return;
    }

    while (fread(&data, sizeof(data), 1, fp) == 1)
    {
        newnode = malloc(sizeof(ST));

        if (newnode == NULL)
        {
            printf("Memory Allocation Failed\n");
            break;
        }

        newnode->roll = data.roll;
        strcpy(newnode->name, data.name);
        newnode->percentage = data.percentage;
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newnode;
        }
    }

    fclose(fp);
}

