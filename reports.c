#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "common.h"

void employeeReport(void) {
    int count = getEmployeeCount();
    printf("\n--- Employee Report ---\n");
    if (count == 0) {
        printf("No employees on record.\n");
        return;
    }

    Employee *emp = getEmployees();
    float total = 0, highest, lowest;
    highest = lowest = emp[0].basicSalary + emp[0].housingAllowance + emp[0].transportAllowance;

    for (int i = 0; i < count; i++) {
        float salary = emp[i].basicSalary + emp[i].housingAllowance + emp[i].transportAllowance;
        total += salary;
        if (salary > highest) highest = salary;
        if (salary < lowest) lowest = salary;
    }

    printf("Total Employees: %d\n", count);
    printf("Average Salary:  N$%.2f\n", total / count);
    printf("Highest Salary:  N$%.2f\n", highest);
    printf("Lowest Salary:   N$%.2f\n", lowest);
}

void budgetReport(void) {
    int count = getBudgetCount();
    printf("\n--- Budget Report ---\n");
    if (count == 0) {
        printf("No budgets on record.\n");
        return;
    }

    Budget *b = getBudgets();
    float totalAllocated = 0, totalExpenditure = 0;

    printf("Departments exceeding budget:\n");
    int anyExceeded = 0;
    for (int i = 0; i < count; i++) {
        totalAllocated += b[i].allocatedBudget;
        totalExpenditure += b[i].expenditure;
        if (b[i].expenditure > b[i].allocatedBudget) {
            printf("  - %s (over by N$%.2f)\n", b[i].department,
                   b[i].expenditure - b[i].allocatedBudget);
            anyExceeded = 1;
        }
    }
    if (!anyExceeded) printf("  None.\n");

    printf("\nTotal Allocated Budget: N$%.2f\n", totalAllocated);
    printf("Total Expenditure:      N$%.2f\n", totalExpenditure);
    printf("Remaining Budget:       N$%.2f\n", totalAllocated - totalExpenditure);
}

void supplierReport(void) {
    int count = getSupplierCount();
    printf("\n--- Supplier Report ---\n");
    if (count == 0) {
        printf("No suppliers on record.\n");
        return;
    }
    printf("Total Suppliers Registered: %d\n\n", count);
    displaySuppliers();
}

void assetReport(void) {
    int count = getAssetCount();
    printf("\n--- Asset Report ---\n");
    if (count == 0) {
        printf("No assets on record.\n");
        return;
    }

    Asset *a = getAssets();
    float totalValue = 0;
    for (int i = 0; i < count; i++) totalValue += a[i].purchaseValue;

    printf("Total Assets Registered: %d\n", count);
    printf("Total Asset Value:       N$%.2f\n\n", totalValue);
    displayAssets();
}

void reportsMenu(void) {
    int choice;
    do {
        printf("\n--- Reports ---\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1: employeeReport(); break;
            case 2: budgetReport(); break;
            case 3: supplierReport(); break;
            case 4: assetReport(); break;
            case 5: printf("Returning to Main Menu...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);
}
