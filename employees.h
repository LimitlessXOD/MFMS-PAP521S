#ifndef EMPLOYEES_H
#define EMPLOYEES_H

// max employees the system can hold, no more after this
#define MAX_EMPLOYEES 100

// longest name we allow
#define NAME_LEN 50

// employee menu stuff
void addEmployee();
void displayEmployees();
void searchEmployee();

// the salary calcs
double calculateGrossSalary(double basic, double housing, double transport);
double calculateNetSalary(double gross, double tax);

// small helpers used inside the employee file
int findEmployeeIndex(int id);
int isDuplicateID(int id);

#endif