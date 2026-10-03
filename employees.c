#include <stdio.h>
#include <string.h>
#include "employees.h"

// Arrays to store employee information
// We use parallel arrays because we have not learned structures yet
int employeeIDs[MAX_EMPLOYEES];
char employeeNames[MAX_EMPLOYEES][NAME_LEN];
char employeeDepartments[MAX_EMPLOYEES][NAME_LEN];
double basicSalaries[MAX_EMPLOYEES];
double housingAllowances[MAX_EMPLOYEES];
double transportAllowances[MAX_EMPLOYEES];
double taxes[MAX_EMPLOYEES];

// Tracks how many employees have been captured
int employeeCount = 0;

// calculateGrossSalary
// Gross = Basic + Housing + Transport
double calculateGrossSalary(double basic, double housing, double transport)
{
    return basic + housing + transport;
}

// calculateNetSalary
// Net = Gross - Tax
double calculateNetSalary(double gross, double tax)
{
    return gross - tax;
}

// isDuplicateID
// Checks whether an ID already exists in the system
// Returns 1 if duplicate, 0 if not
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

// findEmployeeIndex
// Returns the position of the employee in the array
// Returns -1 if the employee is not found
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

// addEmployee
// Prompts the user for employee details
// Validates input and stores the record
void addEmployee()
{
    int id;
    char name[NAME_LEN];
    char department[NAME_LEN];
    double basic;
    double housing;
    double transport;
    double tax;
    double gross;
    double net;

    // Check if the array is full
    if (employeeCount >= MAX_EMPLOYEES)
    {
        printf("\n[ERROR] Employee limit reached.\n");
        return;
    }

    printf("\n--- ADD NEW EMPLOYEE ---\n");

    // Ask for employee ID
    printf("Enter employee ID: ");
    scanf("%d", &id);

    // Validate the ID
    if (id <= 0)
    {
        printf("[ERROR] ID must be a positive number.\n");
        return;
    }

    // Check for duplicate ID
    if (isDuplicateID(id) == 1)
    {
        printf("[ERROR] Employee ID %d already exists.\n", id);
        return;
    }

    // Ask for employee name (single word only)
    printf("Enter employee name: ");
    scanf("%49s", name);
    printf("Enter employee department: ");
    scanf("%49s", department);

    // Ask for salary details
    printf("Enter basic salary: ");
    scanf("%lf", &basic);

    printf("Enter housing allowance: ");
    scanf("%lf", &housing);

    printf("Enter transport allowance: ");
    scanf("%lf", &transport);

    printf("Enter tax deduction: ");
    scanf("%lf", &tax);

    // Validate that salary values are not negative
    if (basic < 0 || housing < 0 || transport < 0 || tax < 0)
    {
        printf("[ERROR] Salary values cannot be negative.\n");
        return;
    }

    // Store the record in the arrays
    employeeIDs[employeeCount] = id;
    strcpy(employeeNames[employeeCount], name);
    strcpy(employeeDepartments[employeeCount], department);
    basicSalaries[employeeCount] = basic;
    housingAllowances[employeeCount] = housing;
    transportAllowances[employeeCount] = transport;
    taxes[employeeCount] = tax;

    // Increase the employee count
    employeeCount++;

    // Calculate gross and net salary
    gross = calculateGrossSalary(basic, housing, transport);
    net = calculateNetSalary(gross, tax);

    printf("\n[SUCCESS] Employee added.\n");
    printf("Gross Salary: %.2f\n", gross);
    printf("Net Salary: %.2f\n", net);
}

// displayEmployees
// Shows all captured employees in a report format
void displayEmployees()
{
    int i;
    double gross;
    double net;

    // Check if there is nothing to display
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

// searchEmployee
// Asks the user for an ID and displays the matching record
void searchEmployee()
{
    int id;
    int index;
    double gross;
    double net;

    // Check if there is anything to search
    if (employeeCount == 0)
    {
        printf("\nNo employees available to search.\n");
        return;
    }

    printf("\n--- SEARCH EMPLOYEE ---\n");
    printf("Enter employee ID to search: ");
    scanf("%d", &id);

    // Find the employee
    index = findEmployeeIndex(id);

    // If not found
    if (index == -1)
    {
        printf("[NOT FOUND] No employee with ID %d.\n", id);
        return;
    }

    // Calculate salary details
    gross = calculateGrossSalary(basicSalaries[index],
                                 housingAllowances[index],
                                 transportAllowances[index]);
    net = calculateNetSalary(gross, taxes[index]);

    // Display the record
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