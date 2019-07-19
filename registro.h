#ifndef REGISTRO_H_INCLUDED
#define REGISTRO_H_INCLUDED

#include<limits.h>
#include<stdlib.h>

#define MAX_TAM 100
#define AMPLITUDE 999.0

typedef int Code;

typedef struct Register {
     Code code;
     /* outros componentes */
} Register;

typedef int  Index;

typedef Register Array[MAX_TAM + 1];

Array arrayA, arrayB;
Index i, n, k;

#endif // REGISTRO_H_INCLUDED
