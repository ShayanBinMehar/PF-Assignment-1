#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPECIES 10
#define MAX_SUPPLIES 10

typedef struct {
    char **supplies;
    int supplyCount;
} Species;

Species *inventory[MAX_SPECIES];
int speciesCount = 0;

void initializeInventory(int numSpecies) {
    for (int i = 0; i < numSpecies; i++) {
        inventory[i] = (Species *)malloc(sizeof(Species));
        inventory[i]->supplies = (char **)malloc(MAX_SUPPLIES * sizeof(char *));
        inventory[i]->supplyCount = 0;
    }
    speciesCount = numSpecies;
}

void addSupply(int speciesIndex, const char *supply) {
    if (speciesIndex < speciesCount && inventory[speciesIndex]->supplyCount < MAX_SUPPLIES) {
        inventory[speciesIndex]->supplies[inventory[speciesIndex]->supplyCount] = strdup(supply);
        inventory[speciesIndex]->supplyCount++;
    } else {
        printf("Cannot add supply. Check species index or supply limit.\n");
    }
}

void updateSupply(int speciesIndex, int supplyIndex, const char *newSupply) {
    if (speciesIndex < speciesCount && supplyIndex < inventory[speciesIndex]->supplyCount) {
        free(inventory[speciesIndex]->supplies[supplyIndex]);
        inventory[speciesIndex]->supplies[supplyIndex] = strdup(newSupply);
    } else {
        printf("Invalid species or supply index.\n");
    }
}

void removeSpecies(int speciesIndex) {
    if (speciesIndex < speciesCount) {
        for (int i = 0; i < inventory[speciesIndex]->supplyCount; i++) {
            free(inventory[speciesIndex]->supplies[i]);
        }
        free(inventory[speciesIndex]->supplies);
        free(inventory[speciesIndex]);
        for (int i = speciesIndex; i < speciesCount - 1; i++) {
            inventory[i] = inventory[i + 1];
        }
        speciesCount--;
    } else {
        printf("Invalid species index.\n");
    }
}

void displayInventory() {
    for (int i = 0; i < speciesCount; i++) {
        printf("Species %d Supplies:\n", i);
        for (int j = 0; j < inventory[i]->supplyCount; j++) {
            printf(" - %s\n", inventory[i]->supplies[j]);
        }
    }
}

void freeInventory() {
    for (int i = 0; i < speciesCount; i++) {
        for (int j = 0; j < inventory[i]->supplyCount; j++) {
            free(inventory[i]->supplies[j]);
        }
        free(inventory[i]->supplies);
        free(inventory[i]);
    }
}

int main() {
    initializeInventory(3);
    addSupply(0, "Dog Food");
    addSupply(0, "Leash");
    addSupply(1, "Cat Food");
    addSupply(2, "Parrot Food");
    displayInventory();
    
    updateSupply(0, 1, "New Leash");
    displayInventory();
    
    removeSpecies(1);
    displayInventory();
    
    freeInventory();
    return 0;
}
