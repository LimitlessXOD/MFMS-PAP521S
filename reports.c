#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "assets.h"

/*
    These variables are created in employees.c.
    extern allows us to use them in this file.
*/
extern int employeeIDs[MAX_EMPLOYEES];
extern char employeeNames[MAX_EMPLOYEES][NAME_LEN];
extern char employeeDepartments[MAX_EMPLOYEES][NAME_LEN];
extern double basicSalaries[MAX_EMPLOYEES];
extern double housingAllowances[MAX_EMPLOYEES];
extern double transportAllowances[MAX_EMPLOYEES];
extern double taxes[MAX_EMPLOYEES];
extern int employeeCount;

/*
    These variables are created in assets.c.
    extern allows us to use them in this file.
*/
extern Asset assets[];
extern int assetCount;


/* Employee Report */
void employeeReport(void)
{
    int i;
    double grossSalary;
    double totalSalary = 0;
    double highestSalary = 0;
    double lowestSalary = 0;
    double averageSalary;

    printf("\n========================================\n");
    printf("              EMPLOYEE REPORT\n");
    printf("========================================\n");

    if (employeeCount == 0)
    {
        printf("No employees registered.\n");
        return;
    }

    for (i = 0; i < employeeCount; i++)
    {
        grossSalary = calculateGrossSalary(
            basicSalaries[i],
            housingAllowances[i],
            transportAllowances[i]
        );

        totalSalary = totalSalary + grossSalary;

        if (i == 0)
        {
            highestSalary = grossSalary;
            lowestSalary = grossSalary;
        }

        if (grossSalary > highestSalary)
        {
            highestSalary = grossSalary;
        }

        if (grossSalary < lowestSalary)
        {
            lowestSalary = grossSalary;
        }
    }

    averageSalary = totalSalary / employeeCount;

    printf("Total Employees: %d\n", employeeCount);
    printf("Average Gross Salary: N$ %.2f\n", averageSalary);
    printf("Highest Gross Salary: N$ %.2f\n", highestSalary);
    printf("Lowest Gross Salary: N$ %.2f\n", lowestSalary);
}


/* Budget Report */
void budgetReport(Budget budgets[], int count)
{
    int i;
    int exceededCount = 0;
    double totalAllocated = 0;
    double totalSpent = 0;
    double remainingBudget;

    printf("\n========================================\n");
    printf("               BUDGET REPORT\n");
    printf("========================================\n");

    if (count == 0)
    {
        printf("No budget records found.\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        totalAllocated = totalAllocated + budgets[i].allocated;
        totalSpent = totalSpent + budgets[i].spent;
    }

    remainingBudget = totalAllocated - totalSpent;

    printf("Total Allocated Budget: N$ %.2f\n", totalAllocated);
    printf("Total Expenditure: N$ %.2f\n", totalSpent);
    printf("Remaining Budget: N$ %.2f\n", remainingBudget);

    printf("\nDepartments Exceeding Budget:\n");

    for (i = 0; i < count; i++)
    {
        if (budgets[i].spent > budgets[i].allocated)
        {
            printf("- %s\n", budgets[i].name);
            exceededCount++;
        }
    }

    if (exceededCount == 0)
    {
        printf("No departments have exceeded their budget.\n");
    }
}


/* Supplier Report */
void supplierReport(
    int ids[],
    char names[][STR_LEN],
    char emails[][STR_LEN],
    char telephones[][STR_LEN],
    char towns[][STR_LEN],
    int count
)
{
    int i;

    printf("\n========================================\n");
    printf("              SUPPLIER REPORT\n");
    printf("========================================\n");

    if (count == 0)
    {
        printf("No suppliers registered.\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        printf("Supplier ID: %d\n", ids[i]);
        printf("Name: %s\n", names[i]);
        printf("Email: %s\n", emails[i]);
        printf("Telephone: %s\n", telephones[i]);
        printf("Town/Location: %s\n", towns[i]);
    }
}


/* Asset Report */
void assetReport(void)
{
    int i;
    double totalAssetValue = 0;

    printf("\n========================================\n");
    printf("                ASSET REPORT\n");
    printf("========================================\n");

    if (assetCount == 0)
    {
        printf("No assets registered.\n");
        return;
    }

    for (i = 0; i < assetCount; i++)
    {
        printf("\nAsset %d\n", i + 1);
        printf("Asset ID: %d\n", assets[i].id);
        printf("Asset Name: %s\n", assets[i].name);
        printf("Asset Type: %s\n", assets[i].type);
        printf("Purchase Value: N$ %.2f\n", assets[i].purchaseValue);
        printf("Department: %s\n", assets[i].department);
        printf("Condition: %s\n", assets[i].condition);

        totalAssetValue = totalAssetValue + assets[i].purchaseValue;
    }

    printf("\nTotal Asset Value: N$ %.2f\n", totalAssetValue);
}