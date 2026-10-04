#include <stdio.h>
#include <string.h>
#include "employees.h"

// storing employee stuff in arrays, coz no structs yet
int employeeIDs[MAX_EMPLOYEES];
char employeeNames[MAX_EMPLOYEES][NAME_LEN];
char employeeDepartments[MAX_EMPLOYEES][NAME_LEN];
double basicSalaries[MAX_EMPLOYEES];
double housingAllowances[MAX_EMPLOYEES];
double transportAllowances[MAX_EMPLOYEES];
double taxes[MAX_EMPLOYEES];

int employeeCount = 0;   // how many we got so far


// checking the gross, basic plus the allowances
double calculateGrossSalary(double basic, double housing, double transport)
{
    return basic + housing + transport;
}


// checking the net, gross minus tax
double calculateNetSalary(double gross, double tax)
{
    return gross - tax;
}


// checking the ID is not already used
int isDuplicateID(int id)
{
    int i;

    for (i = 0; i < employeeCount; i++)
    {
        if (employeeIDs[i] == id)
        {
            return 1;
        }
    }

    return 0;
}


// checking where the employee sits in the array, -1 if not there
int findEmployeeIndex(int id)
{
    int i;

    for (i = 0; i < employeeCount; i++)
    {
        if (employeeIDs[i] == id)
        {
            return i;
        }
    }

    return -1;
}


// checking the list is not full before adding
void addEmployee()
{
    int id;
    char name[NAME_LEN];
    char department[NAME_LEN];
    double basic, housing, transport, tax;
    double gross, net;

    if (employeeCount >= MAX_EMPLOYEES)
    {
        printf("\n[ERROR] Employee limit reached.\n");
        return;
    }

    printf("\n--- ADD NEW EMPLOYEE ---\n");

    printf("Enter employee ID: ");
    scanf("%d", &id);

    // checking the ID is a positive number
    if (id <= 0)
    {
        printf("[ERROR] ID must be a positive number.\n");
        return;
    }

    // checking the ID isnt a duplicate
    if (isDuplicateID(id) == 1)
    {
        printf("[ERROR] Employee ID %d already exists.\n", id);
        return;
    }

    // cant use spaces here, scanf stops, gonna fix with fgets later
    printf("Enter employee name: ");
    scanf("%49s", name);

    printf("Enter employee department: ");
    scanf("%49s", department);

    printf("Enter basic salary: ");
    scanf("%lf", &basic);

    printf("Enter housing allowance: ");
    scanf("%lf", &housing);

    printf("Enter transport allowance: ");
    scanf("%lf", &transport);

    printf("Enter tax deduction: ");
    scanf("%lf", &tax);

    // checking none of the salary values is negative
    if (basic < 0 || housing < 0 || transport < 0 || tax < 0)
    {
        printf("[ERROR] Salary values cannot be negative.\n");
        return;
    }

    // ok all fine, saving it now
    employeeIDs[employeeCount] = id;
    strcpy(employeeNames[employeeCount], name);
    strcpy(employeeDepartments[employeeCount], department);
    basicSalaries[employeeCount] = basic;
    housingAllowances[employeeCount] = housing;
    transportAllowances[employeeCount] = transport;
    taxes[employeeCount] = tax;

    employeeCount++;

    gross = calculateGrossSalary(basic, housing, transport);
    net = calculateNetSalary(gross, tax);

    printf("\n[SUCCESS] Employee added.\n");
    printf("Gross Salary: %.2f\n", gross);
    printf("Net Salary: %.2f\n", net);
}


// checking if there is anyone to show, then printing the table
void displayEmployees()
{
    int i;
    double gross, net;

    if (employeeCount == 0)
    {
        printf("\nNo employees have been captured yet.\n");
        return;
    }

    printf("\n========== EMPLOYEE REPORT ==========\n");
    printf("%-8s %-15s %-15s %-12s %-12s\n", "ID", "Name", "Department", "Gross", "Net");
    printf("-------------------------------------\n");

    for (i = 0; i < employeeCount; i++)
    {
        gross = calculateGrossSalary(basicSalaries[i],
                                     housingAllowances[i],
                                     transportAllowances[i]);
        net = calculateNetSalary(gross, taxes[i]);

        printf("%-8d %-15s %-15s %-12.2f %-12.2f\n",
               employeeIDs[i],
               employeeNames[i],
               employeeDepartments[i],
               gross,
               net);
    }

    printf("-------------------------------------\n");
    printf("Total employees: %d\n", employeeCount);
    printf("=====================================\n");
}


// checking if there is anyone to search first, then looking for the ID
void searchEmployee()
{
    int id, index;
    double gross, net;

    if (employeeCount == 0)
    {
        printf("\nNo employees available to search.\n");
        return;
    }

    printf("\n--- SEARCH EMPLOYEE ---\n");
    printf("Enter employee ID to search: ");
    scanf("%d", &id);

    index = findEmployeeIndex(id);

    // checking we actually found someone
    if (index == -1)
    {
        printf("[NOT FOUND] No employee with ID %d.\n", id);
        return;
    }

    gross = calculateGrossSalary(basicSalaries[index],
                                 housingAllowances[index],
                                 transportAllowances[index]);
    net = calculateNetSalary(gross, taxes[index]);

    printf("\n--- EMPLOYEE FOUND ---\n");
    printf("ID: %d\n", employeeIDs[index]);
    printf("Name: %s\n", employeeNames[index]);
    printf("Department: %s\n", employeeDepartments[index]);
    printf("Basic Salary: %.2f\n", basicSalaries[index]);
    printf("Housing Allowance: %.2f\n", housingAllowances[index]);
    printf("Transport Allowance: %.2f\n", transportAllowances[index]);
    printf("Gross Salary: %.2f\n", gross);
    printf("Tax: %.2f\n", taxes[index]);
    printf("Net Salary: %.2f\n", net);
}