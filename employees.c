#include <stdio.h>
#include <string.h>
#include "employees.h"

static Employee employees[MAX_EMPLOYEES];
static int employeeCount = 0;

int getEmployeeCount(void) { return employeeCount; }
Employee *getEmployees(void) { return employees; }

static int employeeIdExists(int id) {
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].employeeID == id) return 1;
    }
    return 0;
}

void addEmployee(void) {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("\nEmployee list is full. Cannot add more employees.\n");
        return;
    }

    Employee e;
    int id;

    printf("\n--- Add Employee ---\n");

    printf("Employee ID: ");
    while (scanf("%d", &id) != 1 || id <= 0 || employeeIdExists(id)) {
        clearInputBuffer();
        if (employeeIdExists(id))
            printf("That ID is already in use. Enter a unique positive Employee ID: ");
        else
            printf("Invalid ID. Enter a positive whole number: ");
    }
    clearInputBuffer();
    e.employeeID = id;

    printf("Name: ");
    readLine(e.name, MAX_NAME_LEN);
    while (strlen(e.name) == 0) {
        printf("Name cannot be empty. Name: ");
        readLine(e.name, MAX_NAME_LEN);
    }

    printf("Department: ");
    readLine(e.department, MAX_NAME_LEN);
    while (strlen(e.department) == 0) {
        printf("Department cannot be empty. Department: ");
        readLine(e.department, MAX_NAME_LEN);
    }

    printf("Basic Salary: N$");
    while (scanf("%f", &e.basicSalary) != 1 || e.basicSalary < 0) {
        clearInputBuffer();
        printf("Salary cannot be negative. Basic Salary: N$");
    }

    printf("Housing Allowance: N$");
    while (scanf("%f", &e.housingAllowance) != 1 || e.housingAllowance < 0) {
        clearInputBuffer();
        printf("Cannot be negative. Housing Allowance: N$");
    }

    printf("Transport Allowance: N$");
    while (scanf("%f", &e.transportAllowance) != 1 || e.transportAllowance < 0) {
        clearInputBuffer();
        printf("Cannot be negative. Transport Allowance: N$");
    }
    clearInputBuffer();

    employees[employeeCount++] = e;
    printf("\nEmployee added successfully. (Total employees: %d)\n", employeeCount);
}

static void printEmployeeRow(Employee *e) {
    float total = e->basicSalary + e->housingAllowance + e->transportAllowance;
    printf("ID: %-5d Name: %-20s Dept: %-15s Total Salary: N$%.2f\n",
           e->employeeID, e->name, e->department, total);
}

void displayEmployees(void) {
    printf("\n--- Employee List ---\n");
    if (employeeCount == 0) {
        printf("No employees on record.\n");
        return;
    }
    for (int i = 0; i < employeeCount; i++) {
        printEmployeeRow(&employees[i]);
    }
}

void searchEmployee(void) {
    if (employeeCount == 0) {
        printf("\nNo employees on record.\n");
        return;
    }

    int choice;
    printf("\nSearch by: 1. Employee ID  2. Name\nChoice: ");
    while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
        clearInputBuffer();
        printf("Enter 1 or 2: ");
    }
    clearInputBuffer();

    int found = 0;

    if (choice == 1) {
        int id;
        printf("Enter Employee ID: ");
        while (scanf("%d", &id) != 1) {
            clearInputBuffer();
            printf("Enter a valid numeric ID: ");
        }
        clearInputBuffer();
        for (int i = 0; i < employeeCount; i++) {
            if (employees[i].employeeID == id) {
                printEmployeeRow(&employees[i]);
                found = 1;
                break;
            }
        }
    } else {
        char name[MAX_NAME_LEN];
        printf("Enter Name (or part of it): ");
        readLine(name, MAX_NAME_LEN);
        for (int i = 0; i < employeeCount; i++) {
            if (strstr(employees[i].name, name) != NULL) {
                printEmployeeRow(&employees[i]);
                found = 1;
            }
        }
    }

    if (!found) printf("No matching employee found.\n");
}

void calculateSalaryInfo(void) {
    if (employeeCount == 0) {
        printf("\nNo employees on record.\n");
        return;
    }

    int id;
    printf("\nEnter Employee ID for salary breakdown: ");
    while (scanf("%d", &id) != 1) {
        clearInputBuffer();
        printf("Enter a valid numeric ID: ");
    }
    clearInputBuffer();

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].employeeID == id) {
            Employee *e = &employees[i];
            float total = e->basicSalary + e->housingAllowance + e->transportAllowance;
            printf("\n--- Salary Breakdown: %s ---\n", e->name);
            printf("Basic Salary:        N$%.2f\n", e->basicSalary);
            printf("Housing Allowance:   N$%.2f\n", e->housingAllowance);
            printf("Transport Allowance: N$%.2f\n", e->transportAllowance);
            printf("TOTAL:               N$%.2f\n", total);
            return;
        }
    }
    printf("Employee ID not found.\n");
}

void employeeMenu(void) {
    int choice;
    do {
        printf("\n--- Employee Management ---\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Calculate Salary Info\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: calculateSalaryInfo(); break;
            case 5: printf("Returning to Main Menu...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);
}
