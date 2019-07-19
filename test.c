#include "registro.h"
#include <limits.h>
#include <stdlib.h>

void printArray(Array V, Index n) {

  for (i = 1; i <= n; i++)
    printf("%d ", V[i].code);
  putchar('\n');
}

void copyArray(Array source, Array destination, Index n) {

  for (i = 1; i <= n; i++)
    destination[i] = source[i];
}

void verifyArray(Array V, Index n, Index k) {

  for (i = 2; i <= k; i++) {
    if (V[i].code < V[i - 1].code) {
      printf("ERRO: ");
      printArray(V, n);
      exit(1);
    }
  }
  printf("OK  : ");
  printArray(V, n);
}

void runTest(void) {

  int TEMP;
  n = MAX_TAM;

  for (i = 1; i <= n; i++) {
    arrayA[i].code = 1 + (int)(AMPLITUDE * rand() / (RAND_MAX + 1.0));
    arrayB[i].code = arrayA[i].code;
  }

  printf("Original : ");
  printArray(arrayA, n);

  printf("selectionSortPartial com k = ");
  scanf("%d", &TEMP);
  getchar();
  k = TEMP;
  selectionSortPartial(arrayB, n, k);
  verifyArray(arrayB, n, k);
  copyArray(arrayA, arrayB, n);

  printf("insertionSortPartial (sem preservar restante do vetor) com k = ");
  scanf("%d", &TEMP);
  getchar();
  k = TEMP;
  insertionSortPartial(arrayB, n, k);
  verifyArray(arrayB, n, k);
  copyArray(arrayA, arrayB, n);

  printf("insertionSortPartial (preserva restante do vetor) com k = ");
  scanf("%d", &TEMP);
  getchar();
  k = TEMP;
  insertionSortPartial2(arrayB, n, k);
  verifyArray(arrayB, n, k);
  copyArray(arrayA, arrayB, n);

  printf("QuicksortParcial com k = ");
  scanf("%d", &TEMP);
  getchar();
  k = TEMP;
  QuickSortParcial(arrayB, MAX_TAM, k);
  verifyArray(arrayB, n, k);
  copyArray(arrayA, arrayB, n);

  printf("Heapsort com k =  ");
  scanf("%d", &TEMP);
  getchar();
  k = TEMP;
  HeapsortParcial(arrayB, n, k);
  printf("A parte ordenada estao final do :\n");
  printArray(arrayB, n);
  copyArray(arrayA, arrayB, n);
}
