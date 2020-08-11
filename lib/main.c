
#include <stdio.h>

#include "sort.h"

int int_comp(void *a, void *b) {
  int* p = (int*) a;
  int* q = (int*) b;
  return *p - *q;
}

int main() {
  int arr[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
  sort(arr, int_comp);
}


