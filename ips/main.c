
#include <stdio.h>
#include <stdlib.h>

typedef struct interval {
    int64_t lower;
    int64_t upper;
} interval;

int comp(const void *a, const void *b) {
    const interval *p = (const interval*) a;
    const interval *q = (const interval*) b;
    return p->lower - q->lower;
}

int64_t countlines(char *filename) {
    int64_t lines = 0;

    FILE *fp = fopen(filename,"r");
    if (!fp) {
        fprintf(stderr, "could not open the file: %s", filename);
        return lines;
    }

    while (!feof(fp)) {
        if (fgetc(fp) == '\n') {
            lines++;
        }
    }

    fclose(fp);
    return lines;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "error: expected file. usage: cat [filename] | ./a.out [filename]");
        return 1;
    }

    int64_t n = countlines(argv[1]);
    if (n == 0) {
        fprintf(stderr, "invalid input. 0 lines found\n");
        return 2;
    }

    int64_t lower; int64_t upper;
    interval *intervals = (interval*) malloc(sizeof(interval) * n);
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
