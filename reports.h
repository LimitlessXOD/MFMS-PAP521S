#ifndef REPORTS_H
#define REPORTS_H

#include "budget.h"
#include "suppliers.h"

/* Employee report */
void employeeReport(void);

/* Budget report */
void budgetReport(Budget budgets[], int count);

/* Supplier report */
void supplierReport(
    int ids[],
    char names[][STR_LEN],
    char emails[][STR_LEN],
    char telephones[][STR_LEN],
    char towns[][STR_LEN],
    int count
);

/* Asset report */
void assetReport(void);

#endif