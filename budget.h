#ifndef BUDGET_H
#define BUDGET_H

#include "common.h"

typedef struct {
    char  department[MAX_NAME_LEN];
    float allocatedBudget;
    float expenditure;
} Budget;

void budgetMenu(void);

void addBudget(void);
void displayBudgets(void);
void calculateBudgetStatus(void);

int getBudgetCount(void);
Budget *getBudgets(void);

#endif
