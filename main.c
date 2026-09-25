#include <stdio.h>
#include "common.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { /* discard */ }
}

void readLine(char *buffer, int size) {
    if (fgets(buffer, size, stdin) != NULL) {
        int len = 0;
        while (buffer[len] != '\0') len++;
        if (len > 0 && buffer[len - 1] == '\n') buffer[len - 1] = '\0';
    } else {
        buffer[0] = '\0';
    }
}

static void displayMenu(void) {
    printf("\n========================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main(void) {
    int choice;

    printf("Welcome to the Municipal Financial Management System (MFMS)\n");

    do {
        displayMenu();

        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("Invalid input. Please enter a number between 1 and 6.\n");
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1: employeeMenu(); break;
            case 2: budgetMenu(); break;
            case 3: supplierMenu(); break;
            case 4: assetMenu(); break;
            case 5: reportsMenu(); break;
            case 6: printf("\nExiting MFMS. Goodbye!\n"); break;
            default: printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}
