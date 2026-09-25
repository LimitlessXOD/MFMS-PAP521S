#ifndef ASSETS_H
#define ASSETS_H

#include "common.h"

typedef struct {
    int   assetID;
    char  name[MAX_NAME_LEN];
    char  type[MAX_NAME_LEN];
    float purchaseValue;
    char  department[MAX_NAME_LEN];
    char  condition[30];
} Asset;

void assetMenu(void);

void addAsset(void);
void displayAssets(void);
void searchAsset(void);

int getAssetCount(void);
Asset *getAssets(void);

#endif
