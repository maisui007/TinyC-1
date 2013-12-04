# TinyC


## Integrantes

* Marcos Rivas Rivas
* Omar Osorio M
* Tomás Perez P

## Descripción

Este proyecto implementa un compilador hecho con C para crear un subconjunto de C llamado TinyC.
El proyecto implementa el scanner y el parser.

## Estructuras

El stack de Bison cuenta con la siguiente estructura:

**NOTAS: la variable `float value` es una variable temporal que se está usando para pruebas, al final del proyecto se debe quitar**
```
%union{
  int type;         // Contiene el tipo de variable que se está manipulando
  int ivalue;       // Almacena los valores enteros de una variable o expresión
  float value;      // Almacena los valores flotantes de una variable o expresión
  string name;      // Contiene el nombre de la variable
  SymbolTable * st; // Apuntador a la tabla de símbolos
}
```
Para la tabla de símbolos se tienen estas dos estructuras:
```
typedef union _values{
	int ivalue;        // Almacena los valores enteros
	float fvalue;      // Almacena los valores flotantes
}values;
```
La estructura values almacena los valores de las variables según su tipo. Puede ampliarse a más en un futuro
```
typedef struct _symbolTable{
    string name;    // Nombre la variable
    int type;       // Tipo de la variable
    float value;    // Variable temporal
    values val;     // Estructura con los valores según el tipo de variable
}SymbolTable;       
```
Esta es la tabla de símbolos, la cual tiene un nombre, un tipo, y una estructura de valores.
```
**NOTAS: la variable `float value` es una variable temporal que se está usando para pruebas, al final del proyecto se debe quitar**
<<<<<<< HEAD
=======

>>>>>>> 04feeaaba14c1fc70ea6d458efe9690792aeb9f8
```

Para la generación de código se utiliza un struct de apuntadores que van guardando línea por linea el código que se va reconociendo.

```
typedef struct _line{
  int quad;               // El renglón actual
  string operation;       // Operador
  string arg1;            // Argumento 1
  string arg2;            // Argumento 2
  string destination;     // Destino
  string code;            // Código concatenado
  string true_list;       // True List de la Expresión
  string false_list;      // False List de la Expresión
  string next_list;       // Next List de la Expresión
}Line;
```

Cabe mencionar que todo el código que se va generando, se va guardando en un arreglo de structs del tipo _line y al finalizar el análisis se imprime la tabla de código con el formato de un quad.

```
"No. quad"  "Operador"  "Argumento1"  "Argumento2"  "Destino"
```
Por ejemplo la expresión:

```
while (a < b) do
b:= a;
```

Se vería de esta manera:

```
3 < a b 5            //if a < b goto 5
4 - - - S.next       //goto S.next
5 = b a -            //a = b
6 - - - 3            //goto 3
```