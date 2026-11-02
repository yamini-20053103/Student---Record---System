
#include "header.h"

void stud_mod(void)
{
    ST *temp;
    char choice, field, name[50];
    int roll, found = 0;
    float percentage;

    if (head == NULL)
    {
        printf("No Records Found\n");
        return;
    }

    printf("R/r : Roll Number\n");
    printf("N/n : Name\n");
    printf("P/p : Percentage\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &choice);

    if (choice == 'R' || choice == 'r')
    {
        printf("Enter Roll Number: ");
        scanf("%d", &roll);
    }
    else if (choice == 'N' || choice == 'n')
    {
        printf("Enter Name: ");
        scanf(" %[^\n]", name);

        temp = head;

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

        if (!found)
        {
            printf("Name Not Found\n");
            return;
        }

        printf("Enter Roll Number to Modify: ");
        scanf("%d", &roll);
    }
    else if (choice == 'P' || choice == 'p')
    {
        printf("Enter Percentage: ");
        if (scanf("%f", &percentage) != 1)
        {
            printf("Invalid Percentage\n");
            while (getchar() != '\n');
            return;
        }

        temp = head;

        while (temp != NULL)
        {
            if (temp->percentage == percentage)
            {
                printf("%d\t%s\t%.2f\n",
                       temp->roll, temp->name,
                       temp->percentage);
                found = 1;
            }

            temp = temp->next;
        }

        if (!found)
        {
            printf("Percentage Not Found\n");
            return;
        }

        printf("Enter Roll Number to Modify: ");
        scanf("%d", &roll);
    }
    else
    {
        printf("Invalid Choice\n");
        return;
    }

    temp = head;

    while (temp != NULL && temp->roll != roll)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Roll Number Not Found\n");
        return;
    }

    printf("N/n : Modify Name\n");
    printf("P/p : Modify Percentage\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &field);

    if (field == 'N' || field == 'n')
    {
        printf("Enter New Name: ");
        scanf(" %49[^\n]", temp->name);

        printf("Name Modified Successfully\n");
    }
    else if (field == 'P' || field == 'p')
    {
        printf("Enter New Percentage: ");

        if (scanf("%f", &percentage) != 1 ||
            percentage < 0 || percentage > 100)
        {
            printf("Invalid Percentage\n");
            while (getchar() != '\n');
            return;
        }

        temp->percentage = percentage;

        printf("Percentage Modified Successfully\n");
    }
    else
    {
        printf("Invalid Choice\n");
    }
}

