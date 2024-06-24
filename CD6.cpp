#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct Symbol {
    char name[50];
    char type[50];
    int scope;
    struct Symbol* next;
} Symbol;

Symbol* symbolTable[TABLE_SIZE];

// Hash function to map names to table indices
unsigned int hash(const char* name) {
    unsigned int hashValue = 0;
    while (*name) {
        hashValue = (hashValue << 5) + *name++;
    }
    return hashValue % TABLE_SIZE;
}

// Function to add a new symbol to the symbol table
void addSymbol(const char* name, const char* type, int scope) {
    unsigned int index = hash(name);
    Symbol* newSymbol = (Symbol*)malloc(sizeof(Symbol));
    strcpy(newSymbol->name, name);
    strcpy(newSymbol->type, type);
    newSymbol->scope = scope;
    newSymbol->next = symbolTable[index];
    symbolTable[index] = newSymbol;
    printf("Symbol added: %s, Type: %s, Scope: %d\n", name, type, scope);
}

// Function to remove a symbol from the symbol table
void removeSymbol(const char* name) {
    unsigned int index = hash(name);
    Symbol* current = symbolTable[index];
    Symbol* prev = NULL;
    
    while (current != NULL && strcmp(current->name, name) != 0) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Symbol not found: %s\n", name);
        return;
    }
    
    if (prev == NULL) {
        symbolTable[index] = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
    printf("Symbol removed: %s\n", name);
}

// Function to retrieve a symbol's information
Symbol* getSymbol(const char* name) {
    unsigned int index = hash(name);
    Symbol* current = symbolTable[index];
    
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void printSymbolTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Symbol* current = symbolTable[i];
        if (current != NULL) {
            printf("Index %d:\n", i);
            while (current != NULL) {
                printf("  Name: %s, Type: %s, Scope: %d\n", current->name, current->type, current->scope);
                current = current->next;
            }
        }
    }
}

int main() {
    memset(symbolTable, 0, sizeof(symbolTable));
    
    addSymbol("x", "int", 1);
    addSymbol("y", "float", 2);
    addSymbol("z", "char", 1);
    addSymbol("x", "double", 3); // Adding a symbol with the same name but different scope/type

    printf("\nSymbol Table:\n");
    printSymbolTable();

    printf("\nRetrieving symbol 'y':\n");
    Symbol* symbol = getSymbol("y");
    if (symbol) {
        printf("Found: Name: %s, Type: %s, Scope: %d\n", symbol->name, symbol->type, symbol->scope);
    } else {
        printf("Symbol not found\n");
    }

    printf("\nRemoving symbol 'x' with scope 1:\n");
    removeSymbol("x");
    
    printf("\nSymbol Table after removal:\n");
    printSymbolTable();
    
    return 0;
}
