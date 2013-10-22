//
//  SymbolTable.h
//  Entrevista
//
//  Created by Marcos Rivas on 24/09/13.
//  Copyright (c) 2013 Marcos Rivas. All rights reserved.
//

#ifndef __SymbolTable__
#define __SymbolTable__

#include <stdio.h>
#include <stdlib.h>

#define FALSE 1
#define TRUE 0
#define T_INTEGER 1
#define T_FLOAT 2
typedef char*string;

typedef union _values{
	int ivalue;
	float fvalue;
}values;
typedef struct _symbolTable{
    char* name;
    int type;
    float value;
}SymbolTable;




int size = 3;
int emptyItems = 3;

SymbolTable * st;
SymbolTable* putValue(char* symbol, int type,SymbolTable*table);
SymbolTable* initSymbolTable();
void checkTableSize(SymbolTable* table);
void controlarColision(char* symbol,int type, SymbolTable * table, int index);
void resizeSymbolTable(SymbolTable*table);
void showTable(SymbolTable*tabla);
char* getType(int value);
SymbolTable * getValue(SymbolTable*table, string symbol);
int findValue(SymbolTable*table,string symbol);

#endif /* defined(__SymbolTable__) */
