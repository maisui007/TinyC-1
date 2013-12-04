/* ##################################################################
# 
# Omar Osorio Medina 1360426
# Marcos Rivas R 1181599
# Tomás Perez Posada 1184912
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
  int controlIf=TRUE;
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

  %type<value>  single_dec   
  %type<st> variable factor term simple_exp exp block stmt_seq stmt m n
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

m           : /*epsilon*/   {
                              $$->p_line.quad = quad;
                            }
            ;

n           : /*epsilon*/   {
                              char t[BUFFER_SIZE];
                              sprintf(t, "%d", quad);
                              char* s = (char*)malloc(sizeof(char)*strlen(t) + 1);
                              strcpy(s,t);
                              $$->p_line.next_list = s;
                              lines[quad].quad = quad;
                              lines[quad].operation = "-";
                              lines[quad].arg1 = "-";
                              lines[quad].arg2 = "-";
                              lines[quad].destination = "S.next";
                              quad++;
                            }
            ;

stmt_seq  : stmt_seq m stmt {
                              // Incompletas:
                              // S -> begin L end
                              // S -> A
                              // S -> L1; M S
                              // L -> S
                            }  
            | /*epsilon*/   {
                              
                            }
            ;

stmt        : IF exp THEN m stmt          {

                                            $$ = $2;
                                            if($2->p_line.false_list){
                                              mergeWithNextList($2,FALSE_LIST, $5,$$);
                                            }
                                            generateCodeCond($2,$2->p_line.destination,$$);
                                            backpatch_list($2,TRUE_LIST,$4->p_line.quad);

                                            int index = $2->p_line.quad+1;
                                            lines[index].quad = index;
                                            lines[index].operation = "-";
                                            lines[index].arg1 = "-";
                                            lines[index].arg2 = "-";
                                            lines[index].destination = "S.next";

                                          };
       | IF exp THEN m stmt n ELSE m stmt {
                                              $$ = $2;

                                              if($6->p_line.next_list){
                                                mergeWithNextList($6,NEXT_LIST,$9,$$);
                                              }

                                              if($5->p_line.next_list){
                                                mergeWithNextList($5,NEXT_LIST,$$,$$);
                                              }

                                              generateCodeCond($2,$2->p_line.destination,$$);
                                              backpatch_list($2,TRUE_LIST,$4->p_line.quad);
                                              backpatch_list($2,FALSE_LIST,$8->p_line.quad);

                                              int index = $2->p_line.quad+1;
                                              lines[index].quad = index;
                                              lines[index].operation = "-";
                                              lines[index].arg1 = "-";
                                              lines[index].arg2 = "-";

                                          }
        | WHILE m exp DO m stmt           {

                                              $$ = $3;
                                              mergeWithNextList($3,FALSE_LIST,$$,$$);
                                          
                                              generateCodeCond($3,$3->p_line.destination,$$);
                                          
                                              backpatch_list($3,TRUE_LIST,$5->p_line.quad);

                                              int index = $3->p_line.quad+1;
                                              lines[index].quad = index;
                                              lines[index].operation = "-";
                                              lines[index].arg1 = "-";
                                              lines[index].arg2 = "-";
                                              lines[index].destination = "S.next";

                                              index = getQuadWhile();
                                              lines[index].quad = index;
                                              lines[index].operation = "-";
                                              lines[index].arg1 = "-";
                                              lines[index].arg2 = "-";
                                              char ts[BUFFER_SIZE];
                                              sprintf(ts, "%d",$2->p_line.quad);
                                              char* s = (char*)malloc(sizeof(char)*strlen(ts) + 1);
                                              strcpy(s,ts);
                                              lines[index].destination = s;

                                              quad = index+1;
                                          }
            | variable ASSIGN exp SEMI    { //the variable and expression is the same
                                            
                                            SymbolTable * t = getValue(st, $1->name);

                                            ///// Conversión de Tipos
                                            if($1 -> type == $3 -> type){
                                              if($1 -> type == T_FLOAT){
                                                t -> val.fvalue  = $3 -> val.fvalue;
                                              }else if($1 -> type == T_INTEGER){
                                                t -> val.ivalue  = $3 -> val.ivalue;
                                              }
                                            //the variable and expression not the same  
                                            }else{
                                              yyerror("#Warning 4, implicit casting between int and float ");
                                              //check if term is int and factor is float
                                              if($1 -> type == T_INTEGER && $3 -> type == T_FLOAT){
                                                t -> val.ivalue  = (int)$3 -> val.fvalue;
                                                //check if term is float and factor is int
                                              }else if($1 -> type == T_FLOAT && $3 -> type == T_INTEGER){
                                                t -> val.fvalue  = (float)$3 -> val.ivalue;
                                              }
                                            }              
                              
                                            // Generación de Código
                                            generateCode("=",t,$3,"-",$$);

                                            //printf("%d %s %s %s %s\n", $$->p_line.quad, $$->p_line.operation, $$->p_line.arg1, $$->p_line.arg2, $$->p_line.destination);

                                            //Reutilizar variables temporales
                                            if($3->name != NULL && $3->name[0] == 't'){
                                              tempIndex = 0;
                                            }                                  
                                          }
            | variable EQUALSM1 exp SEMI       {}
            | variable EQUALSP1 exp SEMI       {}

            | PLUS1 variable SEMI              {
                                                  SymbolTable * t = getValue(st, $2->name);
                                                  if($2 -> type == T_FLOAT){
                                                      t -> val.fvalue  += 1.0;
                                                  }else{
                                                      t -> val.ivalue  += 1;
                                                  }     
                                                }

            | variable PLUS1 SEMI              {
                                                  SymbolTable * t = getValue(st, $1->name);
                                                  if($1 -> type == T_FLOAT){
                                                      t -> val.fvalue  += 1.0;
                                                  }else{
                                                      t -> val.ivalue  += 1;
                                                  }      
                                                }

            | MINUS1 variable SEMI             {
                                                  SymbolTable * t = getValue(st, $2->name);
                                                  if($2 -> type == T_FLOAT){
                                                      t -> val.fvalue  -= 1.0;
                                                  }else{
                                                      t -> val.ivalue  -= 1;
                                                  }  
                                                }

            | variable MINUS1 SEMI              {
                                                 SymbolTable * t = getValue(st, $1->name);
                                                  if($1 -> type == T_FLOAT){
                                                      t -> val.fvalue  -= 1.0;
                                                  }else{
                                                      t -> val.ivalue  -= 1;
                                                  }  
                                                }
            | READ LPAREN variable RPAREN SEMI {}
            | WRITE LPAREN exp RPAREN SEMI     {}
            | PRINTF LPAREN STRING RPAREN SEMI {}
            | block                            {  }
            ;

block       : LBRACE stmt_seq RBRACE        {
                                              $$ = $2;
                                            }
            ;

exp         : simple_exp LT simple_exp      {
                                              // Code Generation
                                              putNextQuad($$,TRUE_LIST,0);
                                              putNextQuad($$,FALSE_LIST,1);

                                              generateCode("<",$1,$3,"goto",$$);
                                              strcat($$->p_line.code,"\ngoto");
                                              quad++;

                                            }
            | simple_exp EQ simple_exp      {
                                              // Code Generation
                                              putNextQuad($$,TRUE_LIST,0);
                                              putNextQuad($$,FALSE_LIST,1);

                                              generateCode("==",$1,$3,"goto",$$);
                                              strcat($$->p_line.code,"\ngoto");
                                              quad++;
                                            }
            | simple_exp MT simple_exp      {
                                              // Code Generation
                                              putNextQuad($$,TRUE_LIST,0);
                                              putNextQuad($$,FALSE_LIST,1);

                                              generateCode(">",$1,$3,"goto",$$);
                                              strcat($$->p_line.code,"\ngoto");
                                              quad++;
                                            }
            | simple_exp LOE simple_exp     {
                                              // Code Generation
                                              putNextQuad($$,TRUE_LIST,0);
                                              putNextQuad($$,FALSE_LIST,1);

                                              generateCode("<=",$1,$3,"goto",$$);
                                              strcat($$->p_line.code,"\ngoto");
                                              quad++;
                                            } 
            | simple_exp ITSNOT simple_exp  {
                                              // Code Generation
                                              putNextQuad($$,TRUE_LIST,0);
                                              putNextQuad($$,FALSE_LIST,1);

                                              generateCode(">=",$1,$3,"goto",$$);
                                              strcat($$->p_line.code,"\ngoto");
                                              quad++;
                                            }
            | simple_exp                    {$$ = $1;}
            ;

simple_exp  : simple_exp PLUS term    {
                                        // same type
                                        if($1 -> type == $3 -> type){
                                          if($3 -> type == T_FLOAT){
                                            // the types are floating
                                            //$$ -> val.fvalue = ($1 -> val.fvalue + $3 -> val.fvalue);
                                            $$ -> type = T_FLOAT;
                                          }else{
                                            // the types are integer
                                            //$$ -> val.ivalue = ($1 -> val.ivalue + $3 -> val.ivalue);
                                            $$ -> type = T_INTEGER;
                                          }
                                        }else{
                                          //the types are not the same
                                          yyerror("Warning, implicit casting between int and float ");
                                          //check if term is int and factor is float
                                          if($1 -> type == T_INTEGER && $3 -> type == T_FLOAT){
                                            //$$ -> val.fvalue = ((float)($1 -> val.ivalue) + $3 -> val.fvalue);
                                            $$ -> type = T_FLOAT;
                                            //check if term is float and factor is int
                                          }else if($1 -> type == T_FLOAT && $3 -> type == T_INTEGER){
                                            //$$ -> val.fvalue = ($1 -> val.fvalue + (float)($3 -> val.ivalue));
                                            $$ -> type = T_FLOAT;
                                          }
                                        }

                                        //Code Generation
                                        newTemp("+",$1,$3,$$);
                                        //printf("%d %s %s %s %s\n", $$->p_line.quad, $$->p_line.operation, $$->p_line.arg1, $$->p_line.arg2, $$->p_line.destination);
                                      }


            | simple_exp MINUS term   {
                                        // same type
                                        if($1 -> type == $3 -> type){
                                          if($3 -> type == T_FLOAT){
                                            // the types are floating
                                            //$$ -> val.fvalue = ($1 -> val.fvalue - $3 -> val.fvalue);
                                            $$ -> type = T_FLOAT;
                                          }else{
                                            // the types are integer
                                            //$$ -> val.ivalue = ($1 -> val.ivalue - $3 -> val.ivalue);
                                            $$ -> type = T_INTEGER;
                                          }
                                        }else{
                                          //the types are not the same
                                          yyerror("Warning, implicit casting between int and float ");
                                          //check if term is int and factor is float
                                          if($1 -> type == T_INTEGER && $3 -> type == T_FLOAT){
                                            //$$ -> val.fvalue = ((float)($1 -> val.ivalue) - $3 -> val.fvalue);
                                            $$ -> type = T_FLOAT;
                                            //check if term is float and factor is int
                                          }else if($1 -> type == T_FLOAT && $3 -> type == T_INTEGER){
                                            //$$ -> val.fvalue = ($1 -> val.fvalue - (float)($3 -> val.ivalue));
                                            $$ -> type = T_FLOAT;
                                          }
                                        }

                                        //Generación Código
                                        newTemp("-",$1,$3,$$);
                                        //printf("%d %s %s %s %s\n", $$->p_line.quad, $$->p_line.operation, $$->p_line.arg1, $$->p_line.arg2, $$->p_line.destination);
                                      }

            | term                    {
                                        $$ = $1;
                                      }
            ;

term        : term TIMES factor   { //equal types
                                    if($1 -> type == $3 -> type){
                                      if($3 -> type == T_FLOAT){
                                        // the types are floating
                                        //$$ -> val.fvalue = ($1 -> val.fvalue * $3 -> val.fvalue);
                                        $$ -> type = T_FLOAT;
                                      }else{
                                        // the types are integer
                                        //$$ -> val.ivalue = ($1 -> val.ivalue * $3 -> val.ivalue);
                                        $$ -> type = T_INTEGER;
                                      }
                                    }else{
                                      //the types are not the same
                                      yyerror("Warning, implicit casting between int and float ");
                                      //check if term is int and factor is float
                                      if($1 -> type == T_INTEGER && $3 -> type == T_FLOAT){
                                        //$$ -> val.fvalue = ($1 -> val.ivalue * $3 -> val.fvalue);
                                        $$ -> type = T_FLOAT;
                                        //check if term is float and factor is int
                                      }else if($1 -> type == T_FLOAT && $3 -> type == T_INTEGER){
                                        //$$ -> val.fvalue = ($1 -> val.fvalue * $3 -> val.ivalue);
                                        $$ -> type = T_FLOAT;
                                      }
                                    }

                                    //Generación Código
                                        newTemp("*",$1,$3,$$);
                                        //printf("%d %s %s %s %s\n", $$->p_line.quad, $$->p_line.operation, $$->p_line.arg1, $$->p_line.arg2, $$->p_line.destination);
                                  }
            | term DIV factor     {
                                    if($1 -> type == $3 -> type){
                                      //equal types
                                      if($3 -> type == T_FLOAT){
                                        // the types are floating
                                        if($3 -> val.fvalue == 0.0){
                                          yyerror("#Error, division by 0,");
                                          return 1;
                                        }else{
                                          //$$ -> value      = ($1 -> value / $3 -> value);
                                          //$$ -> val.fvalue = ($1 -> val.fvalue / $3 -> val.fvalue);
                                        }
                                        // both are integers
                                      }else{
                                        if($3 -> val.ivalue == 0){
                                          yyerror("#Error, division by 0,");
                                          return 1;
                                        }else{
                                          yyerror("Division between two ints, implicit casting to float");
                                          //$$ -> value      = ($1 -> value / $3 -> value);
                                          //$$ -> val.fvalue = ((float)$1 -> val.ivalue / (float)$3 -> val.ivalue);
                                          $$ -> type = T_FLOAT;  
                                        }
                                        
                                      }
                                    }else{
                                      //the types are not the same
                                      yyerror("#term 1, Warning, implicit casting between int and float ");
                                      //check if term is int and factor is float
                                      if($1 -> type == T_INTEGER && $3 -> type == T_FLOAT){
                                        //$$ -> value      = ($1 -> value / $3 -> value);
                                        //$$ -> val.fvalue = ((float)$1 -> val.ivalue / $3 -> val.fvalue);
                                        $$ -> type = T_FLOAT;
                                        //check if term is float and factor is int
                                      }else if($1 -> type == T_FLOAT && $3 -> type == T_INTEGER){
                                        //$$ -> value      = ($1 -> value / $3 -> value);
                                        //$$ -> val.fvalue = ($1 -> val.fvalue / (float)$3 -> val.ivalue);
                                        $$ -> type = T_FLOAT;
                                      }
                                    }

                                    //Generación Código
                                    newTemp("/",$1,$3,$$);
                                    //printf("%d %s %s %s %s\n", $$->p_line.quad, $$->p_line.operation, $$->p_line.arg1, $$->p_line.arg2, $$->p_line.destination);
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

                                    //Code Generation
                                    //t->name = NULL
                                    char ts[BUFFER_SIZE];
                                    sprintf(ts, "%d",t->val.ivalue);
                                    char* s = (char*)malloc(sizeof(char)*strlen(ts) + 1);
                                    strcpy(s,ts);
                                    t->name = s;
                                    
                                    $$ = t;
                                    
                                  }
            | FLOAT_NUM           {
                                    
                                    SymbolTable *t = (SymbolTable*)malloc(sizeof(SymbolTable));
                                    t -> val.fvalue = $1;
                                    t -> value = $1;
                                    t -> type  = T_FLOAT;

                                    //Code Generation
                                    //t-> name = NULL;
                                    char ts[BUFFER_SIZE];
                                    sprintf(ts, "%f",t->val.fvalue);
                                    char* s = (char*)malloc(sizeof(char)*strlen(ts) + 1);
                                    strcpy(s,ts);
                                    t->name = s;

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

                                    #ifdef DEBUG
                                    printf("%s\n", $1->name);
                                    #endif

                                    t->name = $1->name;

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

// Code Generation

void putNextQuad(SymbolTable* arg, int list , int increment){
  char tempBuffer[BUFFER_SIZE];
  sprintf(tempBuffer,"%d ", quad + increment);
  char* tempString = (char*)malloc(sizeof(char)*strlen(tempBuffer) + 1);
  strcpy(tempString,tempBuffer);

  if(list == TRUE_LIST){
    arg->p_line.true_list = tempString;
  } else if(list == FALSE_LIST) {
    arg->p_line.false_list = tempString;
  } else if(list == NEXT_LIST) {
    arg->p_line.next_list = tempString;
  }
}

void generateCode(char* op, SymbolTable* arg1,SymbolTable* arg2, char* dest, SymbolTable* top) {
   top->p_line.quad = quad;

   lines[quad].quad = quad;
   lines[quad].operation = op;
   lines[quad].arg1 = arg1->name;
   lines[quad].arg2 = arg2->name;
   lines[quad].destination = dest;
   quad++;

   top->p_line.operation = op;
   top->p_line.arg1 = arg1->name;
   top->p_line.arg2 = arg2->name;
   top->p_line.destination = dest;

   char tempBuffer[BUFFER_SIZE];
   sprintf(tempBuffer,"%s %s %s %s", op, arg1->name, arg2->name, dest);
   char* tempString = (char*)malloc(sizeof(char)*strlen(tempBuffer) + 1);
   strcpy(tempString,tempBuffer);
   top->p_line.code = tempString;

   top->p_line.next_list = NULL;   
}

void generateCodeCond(SymbolTable* arg, char* dest, SymbolTable* top){
  int index = arg->p_line.quad;
  lines[index].quad = index;
  lines[index].operation = arg->p_line.operation;
  lines[index].arg1 = arg->p_line.arg1;
  lines[index].arg2 = arg->p_line.arg2;
  lines[index].destination = arg->p_line.destination;

  top->p_line.quad = index;
  top->p_line.operation = arg->p_line.operation;
  top->p_line.arg1 = arg->p_line.arg1;
  top->p_line.arg2 = arg->p_line.arg2;
  top->p_line.destination = arg->p_line.destination;

  char tempBuffer[BUFFER_SIZE];
  sprintf(tempBuffer,"%s %s %s %s", arg->p_line.operation, arg->p_line.arg1, arg->p_line.arg2, dest);
  char* tempString = (char*)malloc(sizeof(char)*strlen(tempBuffer) + 1);
  strcpy(tempString,tempBuffer);
  top->p_line.code = tempString;

  top->p_line.next_list = NULL;  

  quad++;
}

void newTemp(char* op, SymbolTable* arg1, SymbolTable* arg2, SymbolTable* top) {
  
  
  lines[quad].quad = quad;
  lines[quad].operation = op;
  lines[quad].arg1 = arg1->name;
  lines[quad].arg2 = arg2->name;

  top->p_line.quad = quad;
  char tempBuffer[BUFFER_SIZE];
  sprintf(tempBuffer,"%s %s %s t%d", op, arg1->name, arg2->name,tempIndex);
  char* tempString = (char*)malloc(sizeof(char)*strlen(tempBuffer) + 1);
  strcpy(tempString,tempBuffer);
  char t[BUFFER_SIZE];
  tempIndex++;
  sprintf(t, "t%d", tempIndex-1);
  char* s = (char*)malloc(sizeof(char)*strlen(t) + 1);
  strcpy(s,t);
  top->name = s;
  top->p_line.operation = op;
  top->p_line.arg1 = arg1->name;
  top->p_line.arg2 = arg2->name;
  top->p_line.code = tempString;
  top->p_line.destination = s;
  
  lines[quad].destination = s;

  quad++;
}

void backpatch_list(SymbolTable* e, int list, int nQuad){
  char *strToken = "";
  char t[BUFFER_SIZE];
  sprintf(t, "%d", nQuad);
  char* s = (char*)malloc(sizeof(char)*strlen(t) + 1);
  strcpy(s,t);
  
  if(list == FALSE_LIST){
    strToken = strtok(e->p_line.false_list," ");
  } else if(list == TRUE_LIST){
    strToken = strtok(e->p_line.true_list," ");
  } else if(list == NEXT_LIST){
    strToken = strtok(e->p_line.next_list," ");
  }

  while(strToken != NULL){
      int i = atoi(strToken);
      lines[i].destination = s;   
      strToken = strtok(NULL," ");
    }
}

void mergeWithNextList(SymbolTable* arg1, int l1, SymbolTable* arg2, SymbolTable* top) {
  char t[BUFFER_SIZE];

  if(arg2->p_line.next_list == NULL){
    if(l1 == FALSE_LIST)
      sprintf(t, "%s", arg1->p_line.false_list);
    else if(l1 == TRUE_LIST)
      sprintf(t, "%s", arg1->p_line.true_list);
    else if(l1 == NEXT_LIST)
      sprintf(t, "%s", arg1->p_line.next_list);
  } else if(l1 == FALSE_LIST) {
    sprintf(t, "%s %s", arg1->p_line.false_list,arg2->p_line.next_list);
  } else if(l1 == TRUE_LIST) {
    sprintf(t, "%s %s", arg1->p_line.true_list,arg2->p_line.next_list);
  } else if(l1 == NEXT_LIST) {
    sprintf(t, "%s %s", arg1->p_line.next_list,arg2->p_line.next_list);
  }
  char* s = (char*)malloc(sizeof(char)*strlen(t) + 1);
  strcpy(s,t);
  top->p_line.next_list = s;
}

void printLines(){
  int i;

  i = 1;
  while(lines[i].quad){
    printf("%d %s %s %s %s\n",lines[i].quad, lines[i].operation, lines[i].arg1, lines[i].arg2, lines[i].destination);    
    i++;
  }

}

int getQuadWhile(){
  int i = 1;
  while(lines[i].quad){
   i++;
  }
  return i;
}

int main (){
  st = initSymbolTable();

  if(yyparse() == 0){
    printf("No errors\n");
    //showTable(st);
    printLines();
  }
  
  return 0;
}

