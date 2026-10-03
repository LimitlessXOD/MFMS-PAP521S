#ifndef REPORTS_H
#define REPORTS_H

#include "budget.h"
#include "suppliers.h"

void generateEmployeeReport(void);
void generateBudgetReport(const Budget list[], int count);
void generateSupplierReport(const int ids[],
                            const char names[][STR_LEN],
                            const char emails[][STR_LEN],
                            const char telephones[][STR_LEN],
                            const char towns[][STR_LEN],
                            int count);
void generateAssetReport(void);
void displayAllReports(const Budget budgets[], int budgetCount,
                       const int supplierIDs[],
                       const char supplierNames[][STR_LEN],
                       const char supplierEmails[][STR_LEN],
                       const char supplierTelephones[][STR_LEN],
                       const char supplierTowns[][STR_LEN],
                       int supplierCount);

#endif
