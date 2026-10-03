#include <stdio.h>
#include "employees.h"

int main()
{
    int choice;

    do
    {
        printf("\n=====================================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
        printf(" Employee Module\n");
        printf("=====================================\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        // Perform the chosen action
        if (choice == 1)
        {
            addEmployee();
        }
        else if (choice == 2)
        {
            displayEmployees();
        }
        else if (choice == 3)
        {
            searchEmployee();
        }
        else if (choice == 4)
        {
            printf("Goodbye.\n");
        }
        else
        {
            printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}