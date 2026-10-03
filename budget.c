#include <stdio.h>
#include <string.h>
#include "budget.h"

/* Function to print if spent too much or still have money */
void checkStatus(double allocated, double spent) {
    double balance = allocated - spent;
    
    if (balance > 0) {
        printf("Status: Within Budget. Balance left: %.2f\n", balance);
    } 
    else if (balance < 0) {
        printf("Status: Over Budget! Deficit: %.2f\n", -balance);
    } 
    else {
        printf("Status: Exactly on budget.\n");
    }
}

/* Add a department budget */
int addBudget(struct Budget list[], int count) {
    if (count >= 10) {
        printf("Error: List is full!\n");
        return count;
    }

    printf("\nEnter Department Name: ");
    if (scanf("%49s", list[count].name) != 1) {
        printf("Invalid department name.\n");
        return count;
    }

    printf("Enter Allocated Budget: ");
    if (scanf("%lf", &list[count].allocated) != 1 || list[count].allocated < 0) {
        printf("Invalid allocated budget amount.\n");
        return count;
    }

    printf("Enter Current Spent Amount: ");
    if (scanf("%lf", &list[count].spent) != 1 || list[count].spent < 0) {
        printf("Invalid spent amount.\n");
        return count;
    }

    printf("Department added successfully!\n");
    return count + 1;
}

/* Display all budgets */
void displayBudgets(struct Budget list[], int count) {
    int i;
    
    if (count == 0) {
        printf("\nNo budget records found.\n");
        return;
    }

    printf("\n--- BUDGET LIST ---\n");
    for (i = 0; i < count; i++) {
        printf("Department: %s\n", list[i].name);
        printf("Allocated: %.2f\n", list[i].allocated);
        printf("Spent: %.2f\n", list[i].spent);
        checkStatus(list[i].allocated, list[i].spent);
        printf("-------------------\n");
    }
}

/* Find department and add extra expenses */
void updateSpending(struct Budget list[], int count) {
    char search[50];
    double extra;
    int i;
    int found = 0;

    if (count == 0) {
        printf("No records to update.\n");
        return;
    }

    printf("Enter Department Name to update: ");
    scanf("%s", search);

    for (i = 0; i < count; i++) {
        if (strcmp(list[i].name, search) == 0) {
            printf("Found department! Current spent: %.2f\n", list[i].spent);
            printf("Enter extra spending to add: ");
            if (scanf("%lf", &extra) != 1 || extra < 0) {
                printf("Invalid spending amount.\n");
                return;
            }
            
            list[i].spent = list[i].spent + extra;
            printf("New total spent: %.2f\n", list[i].spent);
            checkStatus(list[i].allocated, list[i].spent);
            found = 1;

break;
}
}

if (found == 0) {

printf("Department not found.\n");

}
}

/* Save data to a text file */

void saveToFile(struct Budget list[], int count) {

FILE *fp;

int i;

fp = fopen("budgets.txt", "w");

if (fp == NULL) {

printf("Error opening file for writing.\n");

return;

}

for (i = 0; i < count; i++) {

fprintf(fp, "%s %.2f %.2f\n", list[i].name, list[i].allocated, list[i].spent);

}

fclose(fp);

printf("Saved %d records to file.\n", count);

}

/* Load data from a text file */

int loadFromFile(struct Budget list[]) {

FILE *fp;

int count = 0;

fp = fopen("budgets.txt", "r");

if (fp == NULL) {

printf("No existing file found.\n");

return 0;

}

while (count < 10 && fscanf(fp, "%49s %lf %lf", list[count].name, &list[count].allocated, &list[count].spent) == 3) {

count++;

}

fclose(fp);

printf("Loaded %d records from file.\n", count);

return count;

}