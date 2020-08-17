
#include <cstdio>
#include <array>

using namespace std;

template<class T>
T operator+(const T& a1, const T& a2) {
  T a;
  a[0] = a1[0] + a2[0];
  a[1] = a1[1] + a2[1];
  return a;
}

int main() {

  array<int, 2> pos = { 0, 0 };
  array<int, 2> next = { 1, 0 };
  pos = pos + next;
  printf("{ %d, %d }\n", pos[0], pos[1]); 
}
