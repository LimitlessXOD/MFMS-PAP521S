#include <stdio.h>

#ifndef BUDGET_H

#define BUDGET_H

typedef struct Budget Budget;

struct Budget {
char name[50];
double allocated;
double spent;
};

void addBudget(Budget list[], int count);

void displayBudgets(Budget list[], int count);

void updateSpending(Budget list[], int count);

void checkStatus(double allocated, double spent);

//File Functions

void saveToFile(Budget list[], int count);

int loadFromFile(Budget list[]);

#endif