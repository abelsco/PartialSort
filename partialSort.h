#ifndef PARTIALSORT_H_INCLUDED
#define PARTIALSORT_H_INCLUDED

#include "registro.h"

void selectionSortPartial(Array arrayA, Index n, Index k);

void insertionSortPartial(Array arrayA, Index n, Index k);

void insertionSortPartial2(Array arrayA, Index n, Index k);

void partition(Array arrayA, Index Esq, Index Dir, Index *i, Index *j);

void Ordena(Array arrayA, Index Esq, Index Dir, Index k) ;

void QuickSortParcial(Array arrayA, Index n, Index k) ;

void Refaz(Index Esq, Index Dir, Register *arrayA);

void build(Register *arrayA, Index n) ;

void HeapsortParcial(Register *arrayA, Index n, Index k);

#endif // PARTIALSORT_H_INCLUDED
