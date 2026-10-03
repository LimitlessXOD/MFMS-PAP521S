#include <stdio.h>
#include <string.h>
#include "assets.h"

#define MAX_ASSETS 100

Asset assets[MAX_ASSETS];
int assetCount = 0;

void addAsset(Asset asset) {
    if (assetCount < MAX_ASSETS) {
        assets[assetCount] = asset;
        assetCount++;
    }
}
