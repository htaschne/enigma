#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
    using namespace std;

    class interval {
    public:
        int64_t lower;
        int64_t upper;
        interval(int64_t a, int64_t b) {
            lower = a; upper = b;
        }
    };

    // reading all intervals from input to a vector of intervals
    vector<interval> intervals; int64_t lower; int64_t upper;
    while (scanf("%lld-%lld", &lower, &upper) != EOF) {
        interval it (lower, upper);
        intervals.push_back(it);
    }

    // sort the intervals by their lower bound.
    sort(intervals.begin(), intervals.end(), [] (interval a, interval b){
        return a.lower < b.lower;
    });

    // keep trying to join intervals. if it's not possible than print
    // the current interval and start with the next one.
    // i.e. [ [1-3], [3-10], [11-13], [11-14] ];
    // will merge [1-10] and print and than do the same and print [11-14].
    bool changed = false;
    auto current_lower = intervals[0].lower;
    auto current_upper = intervals[0].upper;
    for (int i = 1; i < (int) intervals.size(); ++i) {
        if (current_upper >= intervals[i].lower) {
            if (current_upper < intervals[i].upper) {
                current_upper = intervals[i].upper;
                changed = true;
            }
        } else {
            printf("%lld-%lld\n", current_lower, current_upper);
            current_lower = intervals[i].lower;
            current_upper = intervals[i].upper;
            changed = false;
        }
    }

    // print the last interval, if it exists.
    if (changed) printf("%lld-%lld\n", current_lower, current_upper);
}
