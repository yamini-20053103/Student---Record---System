
#include "header.h"

void stud_show(void)
{
    ST *temp;

    if (head == NULL)
    {
        printf("No Records Found\n");
        return;
    }

    temp = head;

    printf("\n----------------------------------------\n");
    printf("Roll No\tName\t\tPercentage\n");
    printf("----------------------------------------\n");

    while (temp != NULL)
    {
        printf("%d\t\t%s\t\t%.2f\n",
               temp->roll,
               temp->name,
               temp->percentage);

        temp = temp->next;
    }

    printf("----------------------------------------\n");
}

