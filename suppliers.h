#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#include<stdio.h>
#include <string.h>

#define MAX_SUPPLIERS 50
#define STR_LEN 100

void displayMenu(void);

void removeNewline(char str[]);

int addSupplier(int ids[],char names[][STR_LEN], char emails[][STR_LEN], char telephones[][STR_LEN], char towns[][STR_LEN], int count);

void displaySuppliers(const int ids[], const char names[][STR_LEN], const char emails[][STR_LEN], const char telephones[][STR_LEN], const char towns[][STR_LEN], int count);

int searchSupplierByName(const char names[][STR_LEN], int count, const char searchName[]);

void compareAndSearchSupplier(const int ids[], const char names[][STR_LEN], const char emails[][STR_LEN], const char telephones[][STR_LEN], const char towns[][STR_LEN], int count);

#endif//SUPPLIER_H
