#include "header.h"

ST *head = NULL;

int main()
{
    char choice, ch;

    stud_load();

    while (1)
    {
        printf("\n**** STUDENT RECORD MENU ****\n");
        printf("A/a : Add New Record\n");
        printf("D/d : Delete a Record\n");
        printf("S/s : Show the List\n");
        printf("M/m : Modify a Record\n");
        printf("V/v : Save\n");
        printf("T/t : Sort the List\n");
        printf("E/e : Exit\n");

        printf("Enter Your Choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
            case 'A':
            case 'a':
                stud_add();
                break;

            case 'D':
            case 'd':
                stud_del();
                break;

            case 'S':
            case 's':
                stud_show();
                break;

            case 'M':
            case 'm':
                stud_mod();
                break;

            case 'V':
            case 'v':
                stud_save();
                break;

            case 'T':
            case 't':
                stud_sort();
                break;

            case 'E':
            case 'e':
                printf("S/s : Save and Exit\n");
                printf("E/e : Exit Without Saving\n");
                printf("Enter Your Choice: ");
                scanf(" %c", &ch);

                if (ch == 'S' || ch == 's')
                {
                    stud_save();
                    printf("Saved and Exiting...\n");
                    return 0;
                }
                else if (ch == 'E' || ch == 'e')
                {
                    printf("Exiting Without Saving...\n");
                    return 0;
                }
                else
                {
                    printf("Invalid Choice\n");
                }
                break;

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}

