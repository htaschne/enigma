
#include <stdio.h>
#include <stdlib.h>

typedef struct interval {
  int64_t lower;
  int64_t upper;
} interval;

int comp(const void *a, const void *b) {
  interval *p = (interval*) a;
  interval *q = (interval*) b;
  return p->lower - q->lower;
}

int main() {
  int64_t n;
  // HACK: get the number of lines in the input. 
  scanf("%lld", &n);

  interval *intervals = (interval*) malloc(sizeof(interval) * n);
  int64_t lower; int64_t upper;
  for (int i = 0; scanf("%lld-%lld", &lower, &upper) != EOF; ++i) {
    interval *it = (interval*) malloc(sizeof(interval));
    it->lower = lower;
    it->upper = upper;
    intervals[i] = *(it);
  }

  // sort the intervals by their lower bound.
  qsort(intervals, n, sizeof(interval), comp);

  int64_t current_lower = intervals[0].lower;
  int64_t current_upper = intervals[0].upper;
  int changed = 0;
  for (int i = 1; i < n; ++i) {
    if (current_upper >= intervals[i].lower) {
      if (current_upper < intervals[i].upper) {
        current_upper = intervals[i].upper;
        changed = 1;
      }
    } else {
      printf("%lld-%lld\n", current_lower, current_upper);
      current_lower = intervals[i].lower;
      current_upper = intervals[i].upper;
      changed = 0;
    }
  }

  // print the last interval, if it exists.
  if (changed) printf("%lld-%lld\n", current_lower, current_upper);
}
