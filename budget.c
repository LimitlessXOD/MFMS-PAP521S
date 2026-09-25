#include <stdio.h>
#include <string.h>
#include "budget.h"

static Budget budgets[MAX_DEPARTMENTS];
static int budgetCount = 0;

int getBudgetCount(void) { return budgetCount; }
Budget *getBudgets(void) { return budgets; }

static int findDepartment(const char *dept) {
    for (int i = 0; i < budgetCount; i++) {
        if (strcmp(budgets[i].department, dept) == 0) return i;
    }
    return -1;
}

void addBudget(void) {
    if (budgetCount >= MAX_DEPARTMENTS) {
        printf("\nDepartment budget list is full.\n");
        return;
    }

    char dept[MAX_NAME_LEN];
    printf("\n--- Add Department Budget ---\n");
    printf("Department: ");
    readLine(dept, MAX_NAME_LEN);
    while (strlen(dept) == 0) {
        printf("Department cannot be empty. Department: ");
        readLine(dept, MAX_NAME_LEN);
    }

    if (findDepartment(dept) != -1) {
        printf("That department already has a budget entry. Use option to enter expenditure instead.\n");
        return;
    }

    float allocated;
    printf("Allocated Budget: N$");
    while (scanf("%f", &allocated) != 1 || allocated < 0) {
        clearInputBuffer();
        printf("Budget cannot be negative. Allocated Budget: N$");
    }
    clearInputBuffer();

    strcpy(budgets[budgetCount].department, dept);
    budgets[budgetCount].allocatedBudget = allocated;
    budgets[budgetCount].expenditure = 0.0f;
    budgetCount++;

    printf("Budget added for %s.\n", dept);
}

void displayBudgets(void) {
    printf("\n--- Department Budgets ---\n");
    if (budgetCount == 0) {
        printf("No budgets on record.\n");
        return;
    }
    for (int i = 0; i < budgetCount; i++) {
        float remaining = budgets[i].allocatedBudget - budgets[i].expenditure;
        printf("Department: %-15s Allocated: N$%-12.2f Expenditure: N$%-12.2f Remaining: N$%.2f\n",
               budgets[i].department, budgets[i].allocatedBudget,
               budgets[i].expenditure, remaining);
    }
}

void calculateBudgetStatus(void) {
    if (budgetCount == 0) {
        printf("\nNo budgets on record.\n");
        return;
    }

    char dept[MAX_NAME_LEN];
    printf("\nEnter department to record expenditure against: ");
    readLine(dept, MAX_NAME_LEN);

    int idx = findDepartment(dept);
    if (idx == -1) {
        printf("Department not found. Add its budget first.\n");
        return;
    }

    float amount;
    printf("Enter expenditure amount to add: N$");
    while (scanf("%f", &amount) != 1 || amount < 0) {
        clearInputBuffer();
        printf("Expenditure cannot be negative. Amount: N$");
    }
    clearInputBuffer();

    budgets[idx].expenditure += amount;
    float remaining = budgets[idx].allocatedBudget - budgets[idx].expenditure;

    printf("\nDepartment: %s\n", budgets[idx].department);
    printf("Allocated Budget: N$%.2f\n", budgets[idx].allocatedBudget);
    printf("Total Expenditure: N$%.2f\n", budgets[idx].expenditure);
    printf("Remaining Budget: N$%.2f\n", remaining);
    printf("Status: %s\n", remaining >= 0 ? "WITHIN BUDGET" : "EXCEEDED BUDGET");
}

void budgetMenu(void) {
    int choice;
    do {
        printf("\n--- Budget Management ---\n");
        printf("1. Add Department Budget\n");
        printf("2. Record Expenditure / Check Status\n");
        printf("3. Display All Budgets\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1: addBudget(); break;
            case 2: calculateBudgetStatus(); break;
            case 3: displayBudgets(); break;
            case 4: printf("Returning to Main Menu...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);
}
