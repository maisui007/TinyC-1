/* ##################################################################
# 
# Marcos Rivas R 1181599
#
# File name: tinyC.y   
#
# Description:  Bison file
#
#   
####################################################################
*/
%{
  #include <stdio.h>
  #include <string.h>
  #include "SymbolTable.h"
  void yyerror (char *string);
  extern int yylineno;
%}
%union{
  int type;
  int ivalue;
  float value;
  string name;
  SymbolTable * st;
}
  
  %token <value> INTEGER FLOAT 
  %token <name> ID 

  %type<value>  single_dec stmt  
  %type<st> variable factor term simple_exp exp
  %type<type> type


  %token VOID


  %token STRING

  %token PRINTF
  
  %token IF
  %token THEN
  %token ELSE
  %token WHILE
  %token DO
  %token READ
  %token WRITE
  
  %token NUMBER
  
  %token SEMI
  %token LPAREN
  %token RPAREN
  %token LBRACE
  %token RBRACE
  %token LBRACKET
  %token RBRACKET
  %token LT
  %token MT
  %token LOE
  %token MOE
  %token ASSIGN
  %token EQUALITY
  %token ITSNOT
  %token PLUS1
  %token MINUS1
  %token EQUALSM1
  %token EQUALSP1
  %token MOD
  %token EQ


  %token <value>FLOAT_NUM
  %token <ivalue>INT_NUM
  

  %left PLUS
  %left MINUS
  %left TIMES
  %left DIV


%%

program : var_dec stmt_seq
        ;

var_dec : var_dec single_dec
              | /*epsilon*/
              ;

single_dec  : type ID SEMI {
                              if(findValue(st, $2) == FALSE){
                                putValue($2, $1, st);
                              }else{
                                printf("Variable '%s' declared before\n", $2);
                                yyerror("Error");
                                return FALSE;
                              }

                            }
              ;

type          : INTEGER  {$$ = T_INTEGER;}
              | FLOAT    {$$ = T_FLOAT;}
              ;

stmt_seq    : stmt_seq stmt  
            | /*epsilon*/
            ;

stmt        : IF exp THEN stmt
            | IF exp THEN stmt ELSE stmt
            | WHILE exp DO stmt
            | variable ASSIGN exp SEMI    { //the variable and expression is the same
                                            SymbolTable * t = getValue(st, $1->name);
                                            if($1 -> type == $3 -> type){
                                              if($1 -> type == T_FLOAT){
                                                //$1 -> val.fvalue = $3 -> val.fvalue;
                                                t -> val.fvalue  = $3 -> val.fvalue;
                                              }else if($1 -> type == T_INTEGER){
                                                //$1 -> val.ivalue = $3 -> val.ivalue;
                                                t -> val.ivalue  = $3 -> val.ivalue;
                                              }
                                            //the variable and expression not the same  
                                            }else{
                                              yyerror("#Warning 4, implicit casting between int and float ");
                                              //check if term is int and factor is float
                                              if($1 -> type == T_INTEGER && $3 -> type == T_FLOAT){
                                                //$$ -> value      = ($1 -> value + $3 -> value);
                                                //$1 -> val.ivalue = (int)$3 -> val.fvalue;
                                                t -> val.ivalue  = (int)$3 -> val.fvalue;
                                                //check if term is float and factor is int
                                              }else if($1 -> type == T_FLOAT && $3 -> type == T_INTEGER){
                                                //$$ -> value      = ($1 -> value + $3 -> value);
                                                //$1 -> val.fvalue = (float)$3 -> val.ivalue;
                                                t -> val.fvalue  = (float)$3 -> val.ivalue;
                                              }
                                            }
                                            /*if(findValue(st, $1->name) == FALSE){
                                              printf("No variable '%s' declared before\n", $1->name);
                                              yyerror("Error");
                                              return FALSE;
                                            }else{
                                              //operation
                                              SymbolTable * t1 = getValue(st, $1->name);
                                              t1 -> value = $3->value;
                                            }
                                            */
                                            
                                          }
            | variable EQUALSM1 exp SEMI       {/*
                                                if(findValue(st, $1->name) == FALSE){
                                                  printf("No variable '%s' declared before\n", $1->name);
                                                  yyerror("Error");
                                                  return FALSE;
                                                }else{
                                                  //operation
                                                  if($1->type == T_INTEGER){ //int
                                                    $1 -> value = (int)($1 -> value - $3->value);
                                                  }else{
                                                    $1 -> value = ($1 -> value - $3->value);
                                                  }
                                                }*/
                                              }
            | variable EQUALSP1 exp SEMI       {/*
                                                  if(findValue(st, $1->name) == FALSE){
                                                    printf("No variable '%s' declared before\n", $1->name);
                                                    yyerror("Error");
                                                    return FALSE;
                                                  }else{
                                                    //operation
                                                    if($1->type == T_INTEGER){ //int
                                                      $1 -> value = (int)($1 -> value + $3->value);
                                                    }else{
                                                      $1 -> value = ($1 -> value + $3->value);
                                                    }
                                                  }*/
                                                }
            | PLUS1 variable SEMI              {}
            | variable PLUS1 SEMI              {}
            | MINUS1 variable SEMI             {}
            | variable MINUS1 SEMI              {}
            | READ LPAREN variable RPAREN SEMI {}
            | WRITE LPAREN exp RPAREN SEMI     {}
            | PRINTF LPAREN STRING RPAREN SEMI {}
            | block
            ;

block       : LBRACE stmt_seq RBRACE
            ;

exp         : simple_exp LT simple_exp      {}
            | simple_exp EQ simple_exp      {}
            | simple_exp MT simple_exp      {}
            | simple_exp LOE simple_exp     {} 
            | simple_exp ITSNOT simple_exp  {}
            | simple_exp                    {$$ = $1;}
            ;

simple_exp  : simple_exp PLUS term    {
                                        // same type
                                        if($1 -> type == $3 -> type){
                                          if($3 -> type == T_FLOAT){
                                            // the types are floating
                                            $$ -> value      = ($1 -> value + $3 -> value);
                                            $$ -> val.fvalue = ($1 -> val.fvalue + $3 -> val.fvalue);
                                            $$ -> type = T_FLOAT;
                                          }else{
                                            // the types are integer
                                            $$ -> value      = ($1 -> value + $3 -> value);
                                            $$ -> val.ivalue = ($1 -> val.ivalue + $3 -> val.ivalue);
                                            $$ -> type = T_INTEGER;
                                          }
                                        }else{
                                          //the types are not the same
                                          yyerror("Warning 3, implicit casting between int and float ");
                                          //check if term is int and factor is float
                                          if($1 -> type == T_INTEGER && $3 -> type == T_FLOAT){
                                            $$ -> value      = ($1 -> value + $3 -> value);
                                            $$ -> val.fvalue = ((float)($1 -> val.ivalue) + $3 -> val.fvalue);
                                            $$ -> type = T_FLOAT;
                                            //check if term is float and factor is int
                                          }else if($1 -> type == T_FLOAT && $3 -> type == T_INTEGER){
                                            $$ -> value      = ($1 -> value + $3 -> value);
                                            $$ -> val.fvalue = ($1 -> val.fvalue + (float)($3 -> val.ivalue));
                                            $$ -> type = T_FLOAT;
                                          }
                                        }
                                      }


            | simple_exp MINUS term   {
                                        // same type
                                        if($1 -> type == $3 -> type){
                                          if($3 -> type == T_FLOAT){
                                            // the types are floating
                                            $$ -> value      = ($1 -> value - $3 -> value);
                                            $$ -> val.fvalue = ($1 -> val.fvalue - $3 -> val.fvalue);
                                            $$ -> type = T_FLOAT;
                                          }else{
                                            // the types are integer
                                            $$ -> value      = ($1 -> value - $3 -> value);
                                            $$ -> val.ivalue = ($1 -> val.ivalue - $3 -> val.ivalue);
                                            $$ -> type = T_INTEGER;
                                          }
                                        }else{
                                          //the types are not the same
                                          yyerror("Warning 2, implicit casting between int and float ");
                                          //check if term is int and factor is float
                                          if($1 -> type == T_INTEGER && $3 -> type == T_FLOAT){
                                            $$ -> value      = ($1 -> value - $3 -> value);
                                            $$ -> val.fvalue = ((float)($1 -> val.ivalue) - $3 -> val.fvalue);
                                            $$ -> type = T_FLOAT;
                                            //check if term is float and factor is int
                                          }else if($1 -> type == T_FLOAT && $3 -> type == T_INTEGER){
                                            $$ -> value      = ($1 -> value - $3 -> value);
                                            $$ -> val.fvalue = ($1 -> val.fvalue - (float)($3 -> val.ivalue));
                                            $$ -> type = T_FLOAT;
                                          }
                                        }
                                      }

            | term                    {
                                        $$ = $1;
                                      }
            ;

term        : term TIMES factor   { //equal types
                                    if($1 -> type == $3 -> type){
                                      if($3 -> type == T_FLOAT){
                                        // the types are floating
                                        $$ -> value      = ($1 -> value * $3 -> value);
                                        $$ -> val.fvalue = ($1 -> val.fvalue * $3 -> val.fvalue);
                                        $$ -> type = T_FLOAT;
                                      }else{
                                        // the types are integer
                                        $$ -> value      = ($1 -> value * $3 -> value);
                                        $$ -> val.ivalue = ($1 -> val.ivalue * $3 -> val.ivalue);
                                        $$ -> type = T_INTEGER;
                                      }
                                    }else{
                                      //the types are not the same
                                      yyerror("Warning 1, implicit casting between int and float ");
                                      //check if term is int and factor is float
                                      if($1 -> type == T_INTEGER && $3 -> type == T_FLOAT){
                                        $$ -> value      = ($1 -> value * $3 -> value);
                                        $$ -> val.fvalue = ($1 -> val.ivalue * $3 -> val.fvalue);
                                        $$ -> type = T_FLOAT;
                                        //check if term is float and factor is int
                                      }else if($1 -> type == T_FLOAT && $3 -> type == T_INTEGER){
                                        $$ -> value      = ($1 -> value * $3 -> value);
                                        $$ -> val.fvalue = ($1 -> val.fvalue * $3 -> val.ivalue);
                                        $$ -> type = T_FLOAT;
                                      }
                                    }
                                    /*if($1 -> type != $3 -> type){
                                      yyerror("Warning, implicit casting between int and float ");
                                      $$ -> type = T_FLOAT;
                                      $$ -> value = (float)($1->value * $3->value);
                                    }else{
                                      $$ -> type = $1->type;
                                      if($1->type == T_INTEGER){
                                        $$ -> value = (int)($1->value * $3->value);
                                      }else{
                                        $$ -> value = ($1->value * $3->value);
                                      }
                                      
                                    }
                                    */
                                  }
            | term DIV factor     {
                                    if($1 -> type == $3 -> type){
                                      //equal types
                                      if($3 -> type == T_FLOAT){
                                        // the types are floating
                                        if($3 -> val.fvalue == 0.0){
                                          yyerror("#term 2, Error, division by 0,");
                                          return 1;
                                        }else{
                                          $$ -> value      = ($1 -> value / $3 -> value);
                                          $$ -> val.fvalue = ($1 -> val.fvalue / $3 -> val.fvalue);
                                        }
                                        // both are integers
                                      }else{
                                        yyerror("Division between two ints, implicit casting to float");
                                        $$ -> value      = ($1 -> value / $3 -> value);
                                        $$ -> val.fvalue = ((float)$1 -> val.ivalue / (float)$3 -> val.ivalue);
                                        $$ -> type = T_FLOAT;
                                      }
                                    }else{
                                      //the types are not the same
                                      yyerror("#term 1, Warning, implicit casting between int and float ");
                                      //check if term is int and factor is float
                                      if($1 -> type == T_INTEGER && $3 -> type == T_FLOAT){
                                        $$ -> value      = ($1 -> value / $3 -> value);
                                        $$ -> val.fvalue = ((float)$1 -> val.ivalue / $3 -> val.fvalue);
                                        $$ -> type = T_FLOAT;
                                        //check if term is float and factor is int
                                      }else if($1 -> type == T_FLOAT && $3 -> type == T_INTEGER){
                                        $$ -> value      = ($1 -> value / $3 -> value);
                                        $$ -> val.fvalue = ($1 -> val.fvalue / (float)$3 -> val.ivalue);
                                        $$ -> type = T_FLOAT;
                                      }
                                    }
                                    /*if($3 -> value == 0.0){
                                      yyerror("Error, division by 0,");
                                      return 1;
                                    }else{
                                      if($1 -> type != $3 -> type){
                                        yyerror("Warning, implicit casting between int and float ");
                                        $$ -> type = T_FLOAT;
                                        $$ -> value = (float)($1 -> value / $3 -> value);
                                      }else{
                                        $$ -> type = $1->type;
                                        $$ -> value = ($1 -> value / $3 -> value);
                                      } 
                                    }
                                    */
                                  }
            | factor              {$$ = $1;}
            ;

factor      : LPAREN exp RPAREN   {
                                    $$ = $2;
                                  }
            | INT_NUM             {
                                    SymbolTable *t = (SymbolTable*)malloc(sizeof(SymbolTable));
                                    t -> value = $1;

                                    t -> val.ivalue = $1;
                                    
                                    t -> type  = T_INTEGER;
                                    $$ = t;
                                    
                                  }
            | FLOAT_NUM           {
                                    
                                    SymbolTable *t = (SymbolTable*)malloc(sizeof(SymbolTable));
                                    t -> val.fvalue = $1;
                                    t -> value = $1;
                                    t -> type  = T_FLOAT;
                                    $$ = t;
                                  }
            | variable            {//se regresa el valor de la variable
                                    SymbolTable *t = (SymbolTable*)malloc(sizeof(SymbolTable));

                                    t -> type  = $1 -> type;
                                    t -> value = $1 -> value;

                                    if($1 -> type == T_FLOAT){
                                      t -> val.fvalue = $1 -> val.fvalue;
                                    }else if($1 -> type == T_INTEGER){
                                      t -> val.ivalue = $1 -> val.ivalue;
                                    }

                                    
                                    $$ = t;
                                  }
            ;

variable : ID                     {//variable contiene el nombre de la variable
                                    if(findValue(st, $1) == TRUE){
                                      SymbolTable *t = getValue(st, $1);
                                      $$ = t;
                                    }else{
                                      printf("#variable, No variable '%s' declared before\n", $1);
                                      yyerror("Error");
                                      return FALSE;
                                    }
                                  }

%%

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


int main (){
  st = initSymbolTable();
  if(yyparse() == 0){
    printf("No errors\n");
    showTable(st);
  }
  
  return 0;
  
}

