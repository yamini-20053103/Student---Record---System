#include "header.h"

void stud_sort(void)
{
    ST *temp, *nextnode;
    int i, j;
    char choice;
    int roll;
    char name[50];
    float percentage;

    if (head == NULL)
    {
        printf("No Records Found\n");
        return;
    }

    printf("N/n : Sort by Name\n");
    printf("P/p : Sort by Percentage\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &choice);

    if (choice != 'N' && choice != 'n' &&
        choice != 'P' && choice != 'p')
    {
        printf("Invalid Choice\n");
        return;
    }

    for (temp = head; temp != NULL; temp = temp->next)
    {
        for (nextnode = temp->next; nextnode != NULL;
             nextnode = nextnode->next)
        {
            int swap = 0;

            if (choice == 'N' || choice == 'n')
            {
                if (strcmp(temp->name, nextnode->name) > 0)
                    swap = 1;
            }
            else
            {
                if (temp->percentage > nextnode->percentage)
                    swap = 1;
            }

            if (swap)
            {
                roll = temp->roll;
                temp->roll = nextnode->roll;
                nextnode->roll = roll;

                strcpy(name, temp->name);
                strcpy(temp->name, nextnode->name);
                strcpy(nextnode->name, name);

                percentage = temp->percentage;
                temp->percentage = nextnode->percentage;
                nextnode->percentage = percentage;
            }
        }
    }

    printf("Records Sorted Successfully\n");

    stud_show();
}

