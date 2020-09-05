
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void printarray(int *arr) {
  int size = sizeof(arr)/ sizeof(arr[0]);
  printf("[");
  for (int i = 0; i < size - 1; ++i)
    printf("%d, ", arr[i]);
  printf("%d]\n", arr[size - 1]);
}

int main() {

  int *arr = malloc(sizeof(int) * 6);

  for (int i = 0; i < 6; ++i)
    arr[i] = i + 1;

  int *crop_arr = malloc(sizeof(int) * 5);

}

