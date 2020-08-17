#include <cstdio>
#include <array>
#include <map>
#include <limits>

using namespace std;

template<class T>
T operator+(const T& a1, const T& a2) {
  T a;
  a[0] = a1[0] + a2[0];
  a[1] = a1[1] + a2[1];
  return a;
}

int main() {
  map<char, array<int, 2>> value = { {'L', {-1, 0}}, {'R', {1,  0}},
                                     {'U', { 0, 1}}, {'D', {0, -1}} }; 
  map<array<int, 2>, int> w1;
  array<int, 2> pos = { 0, 0 };
  array<int, 2> next;
  int qt, dist = 0; char dir;
  while (scanf("%c%d,", &dir, &qt) == 2) {
    next = value[dir];
    while (qt--) {
      pos = pos + next;
      dist++;
      if (!w1.count(pos)) w1[pos] = dist;
    }
  }

  pos = { 0, 0 }; dist = 0;
  int min = numeric_limits<int>::max();
  while (scanf("%c%d,", &dir, &qt) == 2) {
    next = value[dir];
    while (qt--) {
      pos = pos + next;
      dist++;
      if (w1.count(pos) && w1[pos] + dist < min)
        min = w1[pos] + dist;
    }
  }
  printf("%d\n", min);
}
