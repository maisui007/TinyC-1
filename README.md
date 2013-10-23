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

