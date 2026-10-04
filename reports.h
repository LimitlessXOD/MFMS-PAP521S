#ifndef REPORTS_H
#define REPORTS_H

#include "budget.h"
#include "suppliers.h"

void employeeReport(void);

void budgetReport(Budget budgets[], int count);

void supplierReport(
    int ids[],
    char names[][STR_LEN],
    char emails[][STR_LEN],
    char telephones[][STR_LEN],
    char towns[][STR_LEN],
    int count
);

void assetReport(void);

#endif