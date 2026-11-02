#include "header.h"

void stud_del(void)
{
    ST *temp, *prev;
    char choice, name[50];
    int roll, found = 0;

    if (head == NULL)
    {
        printf("No Records Found\n");
        return;
    }

    printf("R/r : Delete using Roll Number\n");
    printf("N/n : Delete using Name\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &choice);

    if (choice == 'R' || choice == 'r')
    {
        printf("Enter Roll Number: ");
        scanf("%d", &roll);
    }
    else if (choice == 'N' || choice == 'n')
    {
        printf("Enter Student Name: ");
        scanf(" %49[^\n]", name);

        temp = head;

        printf("\nRoll No\tName\tPercentage\n");

        while (temp != NULL)
        {
            if (strcmp(temp->name, name) == 0)
            {
                printf("%d\t%s\t%.2f\n",
                       temp->roll, temp->name,
                       temp->percentage);
                found = 1;
            }

            temp = temp->next;
        }

        if (found == 0)
        {
            printf("Name Not Found\n");
            return;
        }

        printf("Enter Roll Number to Delete: ");
        scanf("%d", &roll);
    }
    else
    {
        printf("Invalid Choice\n");
        return;
    }

    temp = head;
    prev = NULL;

    while (temp != NULL)
    {
        if (temp->roll == roll)
        {
            if (prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;

            free(temp);

            printf("Record Deleted Successfully\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Roll Number Not Found\n");
}

