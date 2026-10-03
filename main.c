#include <stdio.h>
#include <string.h>

#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

#define BUDGET_CAPACITY 10

static int readIntegerInRange(const char *prompt, int min, int max)
{
    int value;
    char extra;
    char line[128];

    while (1)
    {
        printf("%s", prompt);
        if (fgets(line, sizeof(line), stdin) == NULL)
        {
            return min;
        }

        if (sscanf(line, "%d %c", &value, &extra) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        if (value < min || value > max)
        {
            printf("Invalid choice. Enter a value from %d to %d.\n", min, max);
            continue;
        }

        return value;
    }
}

static void employeeMenu(void)
{
    int choice;

    do
    {
        printf("\n--- EMPLOYEE MANAGEMENT ---\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Back\n");

        choice = readIntegerInRange("Enter choice: ", 1, 4);

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
    } while (choice != 4);
}

static void budgetMenu(Budget budgets[], int *budgetCount)
{
    int choice;

    do
    {
        printf("\n--- BUDGET MANAGEMENT ---\n");
        printf("1. Add Budget\n");
        printf("2. Display Budgets\n");
        printf("3. Update Spending\n");
        printf("4. Back\n");

        choice = readIntegerInRange("Enter choice: ", 1, 4);

        if (choice == 1)
        {
            *budgetCount = addBudget(budgets, *budgetCount);
        }
        else if (choice == 2)
        {
            displayBudgets(budgets, *budgetCount);
        }
        else if (choice == 3)
        {
            updateSpending(budgets, *budgetCount);
        }
    } while (choice != 4);
}

static void supplierMenu(int ids[], char names[][STR_LEN], char emails[][STR_LEN],
                         char telephones[][STR_LEN], char towns[][STR_LEN], int *count)
{
    int choice;
    int foundIndex;
    char searchName[STR_LEN];

    do
    {
        printf("\n--- SUPPLIER MANAGEMENT ---\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier by Name\n");
        printf("4. Compare/Search Supplier Info\n");
        printf("5. Back\n");

        choice = readIntegerInRange("Enter choice: ", 1, 5);

        if (choice == 1)
        {
            *count = addSupplier(ids, names, emails, telephones, towns, *count);
        }
        else if (choice == 2)
        {
            displaySuppliers(ids, names, emails, telephones, towns, *count);
        }
        else if (choice == 3)
        {
            if (*count == 0)
            {
                printf("No suppliers registered yet.\n");
                continue;
            }

            printf("Enter supplier name to search: ");
            if (fgets(searchName, sizeof(searchName), stdin) == NULL)
            {
                continue;
            }
            removeNewline(searchName);

            foundIndex = searchSupplierByName(names, *count, searchName);
            if (foundIndex == -1)
            {
                printf("Supplier not found.\n");
            }
            else
            {
                printf("Found Supplier -> ID: %d | Name: %s | Email: %s | Phone: %s | Town: %s\n",
                       ids[foundIndex], names[foundIndex], emails[foundIndex], telephones[foundIndex], towns[foundIndex]);
            }
        }
        else if (choice == 4)
        {
            compareAndSearchSupplier(ids, names, emails, telephones, towns, *count);
        }
    } while (choice != 5);
}

static void assetMenu(void)
{
    int choice;

    do
    {
        printf("\n--- ASSET MANAGEMENT ---\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset\n");
        printf("4. Back\n");

        choice = readIntegerInRange("Enter choice: ", 1, 4);

        if (choice == 1)
        {
            addAsset();
        }
        else if (choice == 2)
        {
            displayAssets();
        }
        else if (choice == 3)
        {
            searchAsset();
        }
    } while (choice != 4);
}

int main(void)
{
    int mainChoice;
    Budget budgets[BUDGET_CAPACITY];
    int budgetCount = 0;

    int supplierIDs[MAX_SUPPLIERS];
    char supplierNames[MAX_SUPPLIERS][STR_LEN] = {{0}};
    char supplierEmails[MAX_SUPPLIERS][STR_LEN] = {{0}};
    char supplierTelephones[MAX_SUPPLIERS][STR_LEN] = {{0}};
    char supplierTowns[MAX_SUPPLIERS][STR_LEN] = {{0}};
    int supplierCount = 0;

    budgetCount = loadFromFile(budgets);

    do
    {
        printf("\n=====================================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
        printf("=====================================\n");
        printf("1. Employee Management\n");
        printf("2. Budget Management\n");
        printf("3. Supplier Management\n");
        printf("4. Asset Management\n");
        printf("5. Reports\n");
        printf("6. Exit\n");

        mainChoice = readIntegerInRange("Enter choice: ", 1, 6);

        if (mainChoice == 1)
        {
            employeeMenu();
        }
        else if (mainChoice == 2)
        {
            budgetMenu(budgets, &budgetCount);
        }
        else if (mainChoice == 3)
        {
            supplierMenu(supplierIDs, supplierNames, supplierEmails, supplierTelephones, supplierTowns, &supplierCount);
        }
        else if (mainChoice == 4)
        {
            assetMenu();
        }
        else if (mainChoice == 5)
        {
            displayAllReports(budgets, budgetCount,
                              supplierIDs, supplierNames, supplierEmails,
                              supplierTelephones, supplierTowns, supplierCount);
        }
    } while (mainChoice != 6);

    saveToFile(budgets, budgetCount);
    printf("Goodbye.\n");
    return 0;
}
