
///
/// Author: neyo suoya
/// Date: August 10th, 2020
/// Toy implementation for quicksort.
///   reference: https://en.wikipedia.org/wiki/Quicksort

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 100000

int64_t c;
int64_t cc;

void swap(int A[], int *i, int *j) {
  if (i == j) return;
  *i ^= *j;
  *j ^= *i;
  *i ^= *j;
}

int partition(int A[], int lo, int hi) {
  int pivot = A[hi];
  int i = lo;
  for (int j = lo; j < hi; ++j)
    if (A[j] < pivot) {
      swap(A, &A[i], &A[j]);
      i++;
    }
  swap(A, &A[i], &A[hi]);
  return i;
}

void _sort(int A[], int lo, int hi) {
  c++;
  if (lo < hi) {
    int p = partition(A, lo, hi);
    _sort(A, lo, p - 1);
    _sort(A, p + 1, hi);
  }
}

void sort(int A[]) {
  _sort(A, 0, SIZE - 1);
}

void show(int A[]) {
  printf("[");
  for (int i = 0; i < SIZE - 1; ++i)
    printf("%d, ", A[i]);
  printf("%d]\n", A[SIZE - 1]);
}

void bbsort(int A[]) {
  for (int i = 0; i < SIZE; ++i)
    for (int j = 0; j < SIZE; ++j)
      if (A[i] > A[j]) {
        cc++;
        swap(A, &A[i], &A[j]);
      }
}

int main() {
  c = 0; cc = 0;
  int *sarr = (int*) malloc(sizeof(int) * SIZE);
  int *barr = (int*) malloc(sizeof(int) * SIZE);

  srand(time(NULL)); int r;
  for (int i = 0; i < SIZE; ++i) {
    r = rand();
    sarr[i] = r;
    barr[i] = r;
  }

  // sort data
  printf("sort: ");
  sort(sarr);
  printf("%lld\n", c);

  // bsort data
  printf("bsort: ");
  bbsort(barr);
  printf("%lld\n", cc);
}
