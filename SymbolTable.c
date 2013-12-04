#include "lex.yy.c"


void yyerror (char *string){
  printf ("%s at line %d \n",string, yylineno);
}

SymbolTable* initSymbolTable(){
    SymbolTable* newTable = (SymbolTable*)malloc(sizeof(SymbolTable)* size);
    //tabla = (SymbolTable*)malloc(sizeof(SymbolTable)* size);
    return newTable;
}
void checkTableSize(SymbolTable* table){
    if(emptyItems == 1){
        #ifdef DEBUG
        printf("Full table\n");
        #endif
        resizeSymbolTable(table);
    }else{
      #ifdef DEBUG
      printf("Table still has space: %d\n", emptyItems);
      #endif
    }
}
void controlarColision(char* symbol, int type, SymbolTable * table, int index){
  //checkTableSize(table);
  #ifdef DEBUG
  printf("I'm going to look a new position for value %s type: %d \n", symbol, type);
  #endif
    while(table[index].name != NULL || index < size - 1){
      if(table[index].name == symbol){
            printf("Element found. No adding the symbol\n");
            return;
      }
        index++;      
        if(index >= size -1){
          index = 0;
        }
        #ifdef DEBUG
        printf("Search at index: %d from %d\n", index, size-1);
        #endif
        if(table[index].name == NULL){
            #ifdef DEBUG
            printf("At index %d there is an empty space \n", index);
            #endif
            table[index].name = symbol;
            table[index].type = type;
            emptyItems--;
            #ifdef DEBUG
            printf("Symbol inserted \n");
            #endif
            return;
        }else{
          #ifdef DEBUG
          printf("Cell full \n");
          #endif
        }
    }
}

SymbolTable* putValue(char* symbol, int type, SymbolTable*table){
    int hash = 0;
    int index;
    char * temp = symbol;

    #ifdef DEBUG
    printf("Table size: %d\n", size);
    printf("Symbol to insert: %s type: %d \n", symbol, type);
    #endif
    while(*temp){
        hash += (int)*(temp);
        temp++;
    }
    index = hash % size;
    
    if(table[index].name == NULL){
        char* newSymbol = (char*)malloc(sizeof(char)* strlen(symbol) + 1);
        strcpy(newSymbol, symbol);
        table[index].name = newSymbol;
        table[index].type = type;
        table[index].value = 0.0;
        #ifdef DEBUG
        printf("Inserted value: %s type: %d i: %d\n", newSymbol, type, index);
        #endif
        emptyItems--;
        checkTableSize(table);
        return table;
    }else{
        if(strcmp (table[index].name, symbol) == 0){
          #ifdef DEBUG
          printf("That symbol already exists!!!! \n");
          #endif
            return table;
        }else{
            //colision
            #ifdef DEBUG
            printf("\n\n***Colission at index %d\n", index);
            #endif
            controlarColision(symbol, type,  table, index);
            checkTableSize(table);
            return table;
        }
    }
    
    return NULL;
}
void resizeSymbolTable(SymbolTable * table){
    int oldsize = size;
    int i;
    string value;
    int type;
    size *= 2;
    emptyItems = size;
    SymbolTable * newST = (SymbolTable*)malloc(sizeof(SymbolTable)* size);
    #ifdef DEBUG
    printf("Double the size of the table\n");
    #endif
    for(i=0; i< oldsize; i++){
        type = table[i].type;
        value = table[i].name;
        if(value != NULL){
            putValue(value, type, newST);
        }
    }
    free(st);
    st = (SymbolTable*)malloc(sizeof(SymbolTable)* size);
    emptyItems = size;
    for(i=0; i< size; i++){
        value = newST[i].name;
        type = newST[i].type;
        if(value != NULL){
            putValue(value, type, st);
        }
    }
    free(newST);
}

char* getType(int value){
  switch(value){
    case 1:
    return "int";
    break;
    case 2:
    return "float";
  }

  return NULL;
}

int findValue(SymbolTable*table, string symbol){
  int i;
  for(i=0; i< size; i++){
    if(table[i].name != NULL){
      if(strcmp(table[i].name, symbol) == 0){
        return 0;
      }
    }
  }
  return 1;
}
SymbolTable * getValue(SymbolTable*table, string symbol){
  int i;
  for(i=0; i< size; i++){
    if(table[i].name != NULL){
      if(strcmp(table[i].name, symbol) == TRUE){
        return &table[i];
      }
    }
  }
  return NULL;
}

void showTable(SymbolTable*tabla){
    int i;
#ifdef DEBUG
    printf("\nSymbol Table\n");
#endif
    for(i=0; i< size; i++){
      //if(tabla[i].name != NULL){
        if(tabla[i].type == T_INTEGER){
          printf("Index: %3d   name: %3s   type: int value: %d\n", i, tabla[i].name,tabla[i].val.ivalue);  
        }else if(tabla[i].type == T_FLOAT){
          printf("Index: %3d   name: %3s   type: float value: %f\n", i, tabla[i].name, tabla[i].val.fvalue);
        }else{
          printf("Index: %3d   name: %3s   type: NULL \n", i, tabla[i].name);
        }
        
      //}
    }
}