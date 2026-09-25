#include <stdio.h>
#include <string.h>
#include "suppliers.h"

static Supplier suppliers[MAX_SUPPLIERS];
static int supplierCount = 0;

int getSupplierCount(void) { return supplierCount; }
Supplier *getSuppliers(void) { return suppliers; }

static int supplierIdExists(int id) {
    for (int i = 0; i < supplierCount; i++) {
        if (suppliers[i].supplierID == id) return 1;
    }
    return 0;
}

void addSupplier(void) {
    if (supplierCount >= MAX_SUPPLIERS) {
        printf("\nSupplier list is full.\n");
        return;
    }

    Supplier s;
    int id;

    printf("\n--- Add Supplier ---\n");
    printf("Supplier ID: ");
    while (scanf("%d", &id) != 1 || id <= 0 || supplierIdExists(id)) {
        clearInputBuffer();
        if (supplierIdExists(id))
            printf("That ID is already used. Enter a unique positive Supplier ID: ");
        else
            printf("Invalid ID. Enter a positive whole number: ");
    }
    clearInputBuffer();
    s.supplierID = id;

    printf("Supplier Name: ");
    readLine(s.name, MAX_NAME_LEN);
    while (strlen(s.name) == 0) {
        printf("Name cannot be empty. Supplier Name: ");
        readLine(s.name, MAX_NAME_LEN);
    }

    printf("Email: ");
    readLine(s.email, MAX_NAME_LEN);

    printf("Telephone Number: ");
    readLine(s.phone, 20);

    printf("Town/Location: ");
    readLine(s.location, MAX_NAME_LEN);

    suppliers[supplierCount++] = s;
    printf("\nSupplier added successfully. (Total suppliers: %d)\n", supplierCount);
}

static void printSupplierRow(Supplier *s) {
    printf("ID: %-5d Name: %-20s Email: %-25s Tel: %-15s Location: %s\n",
           s->supplierID, s->name, s->email, s->phone, s->location);
}

void displaySuppliers(void) {
    printf("\n--- Supplier List ---\n");
    if (supplierCount == 0) {
        printf("No suppliers on record.\n");
        return;
    }
    for (int i = 0; i < supplierCount; i++) {
        printSupplierRow(&suppliers[i]);
    }
}

void searchSupplier(void) {
    if (supplierCount == 0) {
        printf("\nNo suppliers on record.\n");
        return;
    }

    int choice;
    printf("\nSearch by: 1. Supplier ID  2. Name  3. Location\nChoice: ");
    while (scanf("%d", &choice) != 1 || choice < 1 || choice > 3) {
        clearInputBuffer();
        printf("Enter 1, 2 or 3: ");
    }
    clearInputBuffer();

    int found = 0;

    if (choice == 1) {
        int id;
        printf("Enter Supplier ID: ");
        while (scanf("%d", &id) != 1) {
            clearInputBuffer();
            printf("Enter a valid numeric ID: ");
        }
        clearInputBuffer();
        for (int i = 0; i < supplierCount; i++) {
            if (suppliers[i].supplierID == id) {
                printSupplierRow(&suppliers[i]);
                found = 1;
                break;
            }
        }
    } else {
        char term[MAX_NAME_LEN];
        printf("Enter search text: ");
        readLine(term, MAX_NAME_LEN);
        for (int i = 0; i < supplierCount; i++) {
            const char *field = (choice == 2) ? suppliers[i].name : suppliers[i].location;
            if (strstr(field, term) != NULL) {
                printSupplierRow(&suppliers[i]);
                found = 1;
            }
        }
    }

    if (!found) printf("No matching supplier found.\n");
}

void supplierMenu(void) {
    int choice;
    do {
        printf("\n--- Supplier Management ---\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1: addSupplier(); break;
            case 2: displaySuppliers(); break;
            case 3: searchSupplier(); break;
            case 4: printf("Returning to Main Menu...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);
}
