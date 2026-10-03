#include <stdio.h>
#include <string.h>
#include "assets.h"

Asset assets[MAX_ASSETS];
int assetCount = 0;

void addAsset(void)
{
     if (assetCount >= MAX_ASSETS)
     {
        printf("Asset limit reached.\n");
        return;
     }

     printf("Enter Asset ID: ");
     if (scanf("%d", &assets[assetCount].id) != 1 || assets[assetCount].id <= 0)
     {
        printf("Invalid asset ID.\n");
        return;
     }

     printf("Enter Asset name: ");
     scanf(" %49[^\n]", assets[assetCount].name);

     printf("Enter Asset type: ");
     scanf(" %29[^\n]", assets[assetCount].type);

     printf("Enter Purchase value: ");
     if (scanf("%lf", &assets[assetCount].purchaseValue) != 1 || assets[assetCount].purchaseValue < 0)
     {
        printf("Invalid purchase value.\n");
        return;
     }

     printf("Enter Department: ");
     scanf(" %49[^\n]", assets[assetCount].department);

     printf("Enter Condition: ");
     scanf(" %29[^\n]", assets[assetCount].condition);

     assetCount++;

     printf("Asset added successfully.\n");

}

void displayAssets(void)
{
    int i;

    if (assetCount == 0)
    {
        printf("No assets available.\n");
        return;
    }

    for (i = 0; i < assetCount; i++)
    {

        printf("\nAsset ID: %d\n", assets[i].id);
        printf("Asset Name: %s\n", assets[i].name);
        printf("Asset Type: %s\n", assets[i].type);
        printf("Purchase Value: %.2f\n", assets[i].purchaseValue);
        printf("Department: %s\n", assets[i].department);
        printf("Condition: %s\n", assets[i].condition);

    }
}

void searchAsset(void)
{
    int id;
    int i;
    int found = 0;

    printf("Enter Asset ID to search: ");
    if (scanf("%d", &id) != 1 || id <= 0)
    {
        printf("Invalid asset ID.\n");
        return;
    }

    for (i = 0; i < assetCount; i++)
    {
        if (assets[i].id == id)
        {
          
            printf("\nAsset ID: %d\n", assets[i].id);
            printf("Asset Name: %s\n", assets[i].name);
            printf("Asset Type: %s\n", assets[i].type);
            printf("Purchase Value: %.2f\n", assets[i].purchaseValue);
            printf("Department: %s\n", assets[i].department);
            printf("Condition: %s\n", assets[i].condition);

            found = 1;
            break;

        }
    }

    if (found == 0)
    {

        printf("Asset not found.\n");

    }
}