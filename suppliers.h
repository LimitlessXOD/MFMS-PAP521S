#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#include "common.h"

typedef struct {
    int  supplierID;
    char name[MAX_NAME_LEN];
    char email[MAX_NAME_LEN];
    char phone[20];
    char location[MAX_NAME_LEN];
} Supplier;

void supplierMenu(void);

void addSupplier(void);
void displaySuppliers(void);
void searchSupplier(void);

int getSupplierCount(void);
Supplier *getSuppliers(void);

#endif
