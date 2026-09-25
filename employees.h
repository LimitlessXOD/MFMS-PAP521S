#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include "common.h"

typedef struct {
    int   employeeID;
    char  name[MAX_NAME_LEN];
    char  department[MAX_NAME_LEN];
    float basicSalary;
    float housingAllowance;
    float transportAllowance;
} Employee;

void employeeMenu(void);

void addEmployee(void);
void displayEmployees(void);
void searchEmployee(void);
void calculateSalaryInfo(void);

/* Exposed so reports.c can compute stats without duplicating data. */
int getEmployeeCount(void);
Employee *getEmployees(void);

#endif
