#ifndef EMPLOYEES_H
#define EMPLOYEES_H

// Maximum number of employees the system can store
#define MAX_EMPLOYEES 100

// Maximum length of an employee name
#define NAME_LEN 50

// Function declarations (prototypes)
void addEmployee();
void displayEmployees();
void searchEmployee();

// Salary calculation functions
double calculateGrossSalary(double basic, double housing, double transport);
double calculateNetSalary(double gross, double tax);

// Helper functions
int findEmployeeIndex(int id);
int isDuplicateID(int id);

#endif