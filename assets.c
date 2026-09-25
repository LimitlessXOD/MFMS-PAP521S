#include <stdio.h>
#include <string.h>
#include "assets.h"

static Asset assets[MAX_ASSETS];
static int assetCount = 0;

int getAssetCount(void) { return assetCount; }
Asset *getAssets(void) { return assets; }

static int assetIdExists(int id) {
    for (int i = 0; i < assetCount; i++) {
        if (assets[i].assetID == id) return 1;
    }
    return 0;
}

void addAsset(void) {
    if (assetCount >= MAX_ASSETS) {
        printf("\nAsset register is full.\n");
        return;
    }

    Asset a;
    int id;

    printf("\n--- Add Asset ---\n");
    printf("Asset ID: ");
    while (scanf("%d", &id) != 1 || id <= 0 || assetIdExists(id)) {
        clearInputBuffer();
        if (assetIdExists(id))
            printf("That ID is already used. Enter a unique positive Asset ID: ");
        else
            printf("Invalid ID. Enter a positive whole number: ");
    }
    clearInputBuffer();
    a.assetID = id;

    printf("Asset Name: ");
    readLine(a.name, MAX_NAME_LEN);
    while (strlen(a.name) == 0) {
        printf("Name cannot be empty. Asset Name: ");
        readLine(a.name, MAX_NAME_LEN);
    }

    printf("Asset Type (e.g. Vehicle, Computer, Building): ");
    readLine(a.type, MAX_NAME_LEN);

    printf("Purchase Value: N$");
    while (scanf("%f", &a.purchaseValue) != 1 || a.purchaseValue < 0) {
        clearInputBuffer();
        printf("Value cannot be negative. Purchase Value: N$");
    }
    clearInputBuffer();

    printf("Department: ");
    readLine(a.department, MAX_NAME_LEN);

    printf("Condition (e.g. New, Good, Fair, Poor): ");
    readLine(a.condition, 30);

    assets[assetCount++] = a;
    printf("\nAsset added successfully. (Total assets: %d)\n", assetCount);
}

static void printAssetRow(Asset *a) {
    printf("ID: %-5d Name: %-15s Type: %-12s Value: N$%-10.2f Dept: %-12s Condition: %s\n",
           a->assetID, a->name, a->type, a->purchaseValue, a->department, a->condition);
}

void displayAssets(void) {
    printf("\n--- Asset Register ---\n");
    if (assetCount == 0) {
        printf("No assets on record.\n");
        return;
    }
    for (int i = 0; i < assetCount; i++) {
        printAssetRow(&assets[i]);
    }
}

void searchAsset(void) {
    if (assetCount == 0) {
        printf("\nNo assets on record.\n");
        return;
    }

    int choice;
    printf("\nSearch by: 1. Asset ID  2. Name  3. Type\nChoice: ");
    while (scanf("%d", &choice) != 1 || choice < 1 || choice > 3) {
        clearInputBuffer();
        printf("Enter 1, 2 or 3: ");
    }
    clearInputBuffer();

    int found = 0;

    if (choice == 1) {
        int id;
        printf("Enter Asset ID: ");
        while (scanf("%d", &id) != 1) {
            clearInputBuffer();
            printf("Enter a valid numeric ID: ");
        }
        clearInputBuffer();
        for (int i = 0; i < assetCount; i++) {
            if (assets[i].assetID == id) {
                printAssetRow(&assets[i]);
                found = 1;
                break;
            }
        }
    } else {
        char term[MAX_NAME_LEN];
        printf("Enter search text: ");
        readLine(term, MAX_NAME_LEN);
        for (int i = 0; i < assetCount; i++) {
            const char *field = (choice == 2) ? assets[i].name : assets[i].type;
            if (strstr(field, term) != NULL) {
                printAssetRow(&assets[i]);
                found = 1;
            }
        }
    }

    if (!found) printf("No matching asset found.\n");
}

void assetMenu(void) {
    int choice;
    do {
        printf("\n--- Asset Management ---\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1: addAsset(); break;
            case 2: displayAssets(); break;
            case 3: searchAsset(); break;
            case 4: printf("Returning to Main Menu...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);
}
