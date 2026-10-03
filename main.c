#include <stdio.h>

 #include "budget.h"

int main() {
    struct Budget list[10];

    int count = 0;

    int choice;

    do {
        printf("\n=== MUNICIPAL BUDGET MENU ===\n");

        printf("1. Add Department Budget\n");

        printf("2. Display All Budgets\n");

        printf("3. Add Extra Spending\n");

        printf("4. Save to File\n");

        printf("5. Load from File\n");

        printf("6. Exit\n");

        printf("Enter your choice (1-6): ");

        scanf("%d", &choice);

        switch (choice) {

        case 1:

            addBudget(list, count);

            count++;

            break;

        case 2:

            displayBudgets(list, count);

            break;

        case 3:

            updateSpending(list, count);

            break;

        case 4:

            saveToFile(list, count);

            break;

        case 5:

            count = loadFromFile(list);

            break;

        case 6:

            printf("Goodbye!\n");

            break;

        default:

            printf("Invalid choice! Try again.\n");

            break;
        }

    } while (choice != 6);

    return 0;
}