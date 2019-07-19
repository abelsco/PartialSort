#include "partialSort.h"

void selectionSortPartial(Array arrayA, Index n, Index k) {
  Index i, j, min;
  Register x;

  for (i = 1; i <= k; i++) {
    min = i;
    for (j = i + 1; j <= n; j++)
      if (arrayA[j].code < arrayA[min].code)
        min = j;
    x = arrayA[min];
    arrayA[min] = arrayA[i];
    arrayA[i] = x;
  }
}

void insertionSortPartial(Array arrayA, Index n, Index k) {
  /*-- Nao preserva o restante do vetor --*/
  Index i, j;
  Register x;

  for (i = 2; i <= n; i++) {
    x = arrayA[i];
    if (i > k)
      j = k;
    else
      j = i - 1;
    arrayA[0] = x; /* sentinela */
    while (x.code < arrayA[j].code) {
      arrayA[j + 1] = arrayA[j];
      j--;
    }
    arrayA[j + 1] = x;
  }
}

void insertionSortPartial2(Array arrayA, Index n, Index k) {
  /*-- Preserva o restante do vetor --*/
  Index i, j;
  Register x;

  for (i = 2; i <= n; i++) {
    x = arrayA[i];
    if (i > k) {
      j = k;
      if (x.code < arrayA[k].code)
        arrayA[i] = arrayA[k];
    } else
      j = i - 1;
    arrayA[0] = x; /* sentinela */

    while (x.code < arrayA[j].code) {
      if (j < k) {
        arrayA[j + 1] = arrayA[j];
      }
      j--;
    }
    if (j < k)
      arrayA[j + 1] = x;
  }
}

void partition(Array arrayA, Index Esq, Index Dir, Index *i, Index *j) {
  Register x, w;
  *i = Esq;
  *j = Dir;
  x = arrayA[(*i + *j) / 2]; /* obtem o pivo x */

  do {
    while (x.code > arrayA[*i].code)
      (*i)++;
    while (x.code < arrayA[*j].code)
      (*j)--;
    if (*i <= *j) {
      w = arrayA[*i];
      arrayA[*i] = arrayA[*j];
      arrayA[*j] = w;
      (*i)++;
      (*j)--;
    }
  } while (*i <= *j);
}

void Ordena(Array arrayA, Index Esq, Index Dir, Index k) {
  Index i, j;
  partition(arrayA, Esq, Dir, &i, &j);

  if (j - Esq >= k - 1) {
    if (Esq < j)
      Ordena(arrayA, Esq, j, k);
    return;
  }
  if (Esq < j)
    Ordena(arrayA, Esq, j, k);
  if (i < Dir)
    Ordena(arrayA, i, Dir, k);
}

void QuickSortParcial(Array arrayA, Index n, Index k) {
  Ordena(arrayA, 1, n, k);
}

void Refaz(Index Esq, Index Dir, Register *vetorA) {
  Index i = Esq;
  int j;
  Register x;

  j = i * 2;
  x = vetorA[i];

  while (j <= Dir) {
    if (j < Dir) {
      if (vetorA[j].code > vetorA[j + 1].code)
        j++;
    }
    if (x.code <= vetorA[j].code)
      break;
    vetorA[i] = vetorA[j];
    i = j;
    j = i * 2;
  }
  vetorA[i] = x;
}

void Constroi(Register *vetorA, Index n) {
  Index Esq;
  Esq = n / 2 + 1;

  while (Esq > 1) {
    Esq--;
    Refaz(Esq, n, vetorA);
  }
}

/*-- Coloca menor em vetorA[n], segundo menor em vetorA[n-1],...,    --*/
/*-- k-esimo em vetorA[n-k]                                       --*/
void HeapsortParcial(Register *vetorA, Index n, Index k) {
  Index Esq = 1;
  Index Dir;
  Register x;
  long Aux = 0;
  Constroi(vetorA, n); /* constroi o heap */
  Dir = n;

  while (Aux < k) {
    /* ordena o vetor */
    x = vetorA[1];
    vetorA[1] = vetorA[n - Aux];
    vetorA[n - Aux] = x;
    Dir--;
    Aux++;
    Refaz(Esq, Dir, vetorA);
  }
}
