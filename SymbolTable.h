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
#define T_ERROR 3
#define T_EMPTY 4
typedef char*string;

typedef union _values{
	int ivalue;
	float fvalue;
}values;

// Code Generation
#define BUFFER_SIZE 30
typedef struct _line{
	int quad;
	string operation;
	string arg1;
	string arg2;
	string destination;
	string code;
	string true_list;
	string false_list;
	string next_list;
}Line;
// endRegion Code Generation

typedef struct _symbolTable{
    string name;
    int type;
    float value;
    values val;
    Line p_line;
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


// Code Generation
enum lists{
	FALSE_LIST,
	TRUE_LIST,
	NEXT_LIST
};
int tempIndex = 0;
int quad = 1;
void generateCode(char* op, SymbolTable* arg1,SymbolTable* arg2, char* dest, SymbolTable* top);
void newTemp(char* op, SymbolTable* arg1, SymbolTable* arg2, SymbolTable* top);
void putNextQuad(SymbolTable* arg, int list ,int increment);
void backpatch_list(SymbolTable* e, int listm, int nQuad);
void mergeWithNextList(SymbolTable* arg1, int l1, SymbolTable* arg2, SymbolTable* top);
void generateCodeCond(SymbolTable* arg, char* dest, SymbolTable* top);
void printLines(void);
int getQuadWhile(void);

struct _line lines[100];

#endif /* defined(__SymbolTable__) */
