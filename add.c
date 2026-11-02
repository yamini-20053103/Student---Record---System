#include "header.h"

void stud_add(void)
{
    ST *newnode, *temp;
    int roll, found;

    newnode = malloc(sizeof(ST));

    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    roll = 1;

    while (1)
    {
        found = 0;
        temp = head;

        while (temp != NULL)
        {
            if (temp->roll == roll)
            {
                found = 1;
                break;
            }
            temp = temp->next;
        }

        if (found == 0)
            break;

        roll++;
    }

    newnode->roll = roll;

    printf("Enter Student Name: ");
    scanf(" %[^\n]", newnode->name);

    printf("Enter Percentage: ");

    if (scanf("%f", &newnode->percentage) != 1 ||
        newnode->percentage < 0 ||
        newnode->percentage > 100)
    {
        printf("Invalid Percentage\n");
        while (getchar() != '\n');
        free(newnode);
        return;
    }

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

    printf("Student Added Successfully\n");
    printf("Assigned Roll Number: %d\n", roll);
}

