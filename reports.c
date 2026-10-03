#include <stdio.h>

#include "reports.h"
#include "employees.h"
#include "assets.h"

void generateEmployeeReport(void)
{
    int i;
    double totalGross = 0.0;
    double gross;
    double highest;
    double lowest;

    printf("\n===== EMPLOYEE REPORT =====\n");
    if (employeeCount == 0)
    {
        printf("No employees registered.\n");
        return;
    }

    highest = calculateGrossSalary(basicSalaries[0], housingAllowances[0], transportAllowances[0]);
    lowest = highest;

    for (i = 0; i < employeeCount; i++)
    {
        gross = calculateGrossSalary(basicSalaries[i], housingAllowances[i], transportAllowances[i]);
        totalGross += gross;

        if (gross > highest)
        {
            highest = gross;
        }

        if (gross < lowest)
        {
            lowest = gross;
        }
    }

    printf("Total Employees: %d\n", employeeCount);
    printf("Average Gross Salary: %.2f\n", totalGross / employeeCount);
    printf("Highest Gross Salary: %.2f\n", highest);
    printf("Lowest Gross Salary: %.2f\n", lowest);
}

void generateBudgetReport(const Budget list[], int count)
{
    int i;
    double totalAllocated = 0.0;
    double totalSpent = 0.0;
    int overBudgetFound = 0;

    printf("\n===== BUDGET REPORT =====\n");
    if (count == 0)
    {
        printf("No budget records available.\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        totalAllocated += list[i].allocated;
        totalSpent += list[i].spent;
    }

    printf("Total Allocated: %.2f\n", totalAllocated);
    printf("Total Spent: %.2f\n", totalSpent);
    printf("Remaining Balance: %.2f\n", totalAllocated - totalSpent);

    printf("Departments Over Budget:\n");
    for (i = 0; i < count; i++)
    {
        if (list[i].spent > list[i].allocated)
        {
            printf("- %s (Deficit: %.2f)\n", list[i].name, list[i].spent - list[i].allocated);
            overBudgetFound = 1;
        }
    }

    if (!overBudgetFound)
    {
        printf("- None\n");
    }
}

void generateSupplierReport(const int ids[],
                            const char names[][STR_LEN],
                            const char emails[][STR_LEN],
                            const char telephones[][STR_LEN],
                            const char towns[][STR_LEN],
                            int count)
{
    printf("\n===== SUPPLIER REPORT =====\n");
    displaySuppliers(ids, names, emails, telephones, towns, count);
}

void generateAssetReport(void)
{
    printf("\n===== ASSET REPORT =====\n");
    displayAssets();
}

void displayAllReports(const Budget budgets[], int budgetCount,
                       const int supplierIDs[],
                       const char supplierNames[][STR_LEN],
                       const char supplierEmails[][STR_LEN],
                       const char supplierTelephones[][STR_LEN],
                       const char supplierTowns[][STR_LEN],
                       int supplierCount)
{
    generateEmployeeReport();
    generateBudgetReport(budgets, budgetCount);
    generateSupplierReport(supplierIDs, supplierNames, supplierEmails, supplierTelephones, supplierTowns, supplierCount);
    generateAssetReport();
}
