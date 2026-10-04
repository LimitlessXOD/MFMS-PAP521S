#include <stdio.h>
#include <string.h>

#include "suppliers.h"


// Get a valid number from the user
int getInteger(const char message[]){
    int number;
    int result;
    char input[STR_LEN];

    while(1){
        printf("%s", message);
        if (fgets(input, sizeof(input), stdin) == NULL){
            return -1;
        }
        result=sscanf(input, "%d", &number);

        if(result==1){
            return number;
        }
        printf("Invalid input. Please enter a number.\n");

    }

}

 //Function to display the Menu
 void displayMenu(void)
{
    printf("\n========================================\n");
    printf("        SUPPLIER MANAGEMENT MODULE\n");
    printf("========================================\n");
    printf("1. Add Supplier\n");
    printf("2. Display Supplier\n");
    printf("3. Search Supplier by Name\n");
    printf("4. Compare/Search Supplier Info\n");
    printf("5. Exit\n");
    printf("========================================\n");

    }
    //Function to remove the new line character 
    void removeNewline(char str[]){
        str[strcspn(str, "\n")]='\0';

}
// Function to check the email
int isValidEmail(const char email[]){
    return strchr(email, '@')!=NULL;

}
//Function to add a new supplier 
int addSupplier(int ids[], char names[][STR_LEN], char emails[][STR_LEN], char telephones[][STR_LEN], char towns[][STR_LEN], int count){
    if(count>=MAX_SUPPLIERS){
        printf("\nSupplier storage is full.\n");
    return count;
}

printf("\n--- ADD NEW SUPPLIER ---\n");
ids[count]=getInteger("Enter Supplier ID: ");
if (ids[count]<=0){
printf("Invalid Supplier ID. Must be a positive number.\n");
return count;

}
printf("Enter Supplier Name: ");

if(fgets(names[count], STR_LEN, stdin)==NULL){
    return count;

}
removeNewline(names[count]);

if(strlen(names[count])==0){
    printf("Supplier name cannot be empty.\n");
    return count;
}

//Ask for a valid email
do{
    printf("Enter Email:");
    if(fgets(emails[count], STR_LEN,stdin)==NULL){
        return count;
    }
    removeNewline(emails[count]);
    if(!isValidEmail(emails[count])){
        printf("Invalid email. Email must contain @. Try again.\n");
    }
}while(!isValidEmail(emails[count]));

printf("Enter Telephone number: ");
if(fgets(telephones[count], STR_LEN, stdin)==NULL){
    return count;
}
removeNewline(telephones[count]);

printf("Enter Town/Location: ");
if(fgets(towns[count], STR_LEN, stdin)==NULL){
    return count;

}
removeNewline(towns[count]);
printf("\nSupplier added successfully!\n");
return count+1;
}

//Function to display all registered suppliers
void displaySuppliers(const int ids[], const char names[][STR_LEN], const char emails[][STR_LEN], const char telephones[][STR_LEN], const char towns[][STR_LEN], int count){

    if(count==0){
        printf("\nNo suppliers registered yet.\n");
        return;
    }

    printf("\n--------------------------------------------------------------------------------------------\n");
    printf("%-8s | %-18s | %-22s | %-15s | %-15s\n", 
            "ID", "Name", "Email", "Telephone", "Town");
    printf("\n-------------------------------------------------------------------------------------------\n");

    for(int i=0; i<count; i++){
        printf("%-8d | %-18s | %-22s | %-15s | %-15s\n",
                ids[i], names[i], emails[i], telephones[i], towns[i]);
    }

    printf("-------------------------------------------------------------------------------------------------");
}

// Fuction to search for supplier by name
int searchSupplierByName(const char names[][STR_LEN], int count, const char searchName[]){

    for(int i=0; i<count; i++){

        if( strcmp(names[i], searchName)==0){
            return i;

        }
    }
    return -1;
}
//Function to compare and serch supplier information
void compareAndSearchSupplier(const int ids[], const char names[][STR_LEN], const char emails[][STR_LEN], const char telephones[][STR_LEN], const char towns[][STR_LEN], int count){

    if(count==0){
        printf("\nNo suppliers available for comparison.\n");
        return;
    }
    int subChoice;
    printf("\n--- COMPARE/DETAILED SEARCH ---\n");
    printf("1. Search Suppliers by Town/Location\n");
    printf("2. Display Name and Email String Lengths\n");

    subChoice=getInteger("Enter choice: ");

    if( subChoice ==-1){
        return;
    }
    if(subChoice ==1){
        char searchTown[STR_LEN];
        int matchCount = 0;

        printf("Enter Town to search: ");
        if(fgets(searchTown, sizeof(searchTown), stdin)==NULL){
            return;

        }
        removeNewline(searchTown);
        printf("\nSuppliers located in %s:\n", searchTown);
        

        for(int i=0; i<count; i++){
            if (strcmp(towns[i], searchTown)==0){
                printf("ID: %d | Name: %s | Phone: %s\n", ids[i], names[i], telephones[i]);
                matchCount++;
            }
            }
            if(matchCount == 0){
                printf("No suppliers found in %s.\n", searchTown);
            }
        }else if(subChoice == 2){
                printf("\n--- SUPPLIER STRING LENGTH ANALYSIS ---\n");

                for(int i=0;i <count; i++){
                    printf("ID: %d | Name: %s | Name Length: %zu | Email Length: %zu\n", ids[i], names[i], strlen(names[i]), strlen(emails[i]));

                }

            }else {
                printf("\nInvalid option. Please select 1 or 2");

            }

    }