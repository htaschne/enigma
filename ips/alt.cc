#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
    using namespace std;

    // reading all intervals from input to a vector of intervals
    int64_t lower, upper;
    vector<pair<int64_t, int64_t>> intervals;
    while (scanf("%lld-%lld", &lower, &upper) != EOF) {
        intervals.push_back(make_pair(lower, upper));
    }

    // sort the intervals by their lower bound.
    sort(intervals.begin(), intervals.end());

    bool changed = false;
    auto current_lower = intervals[0].first;
    auto current_upper = intervals[0].second;
    for (size_t i = 1; i < intervals.size(); ++i) {
        if (current_upper >= intervals[i].first &&
                (current_upper = max(current_upper, intervals[i].second))) {
            changed = true;
        } else {
            printf("%lld-%lld\n", current_lower, current_upper);
            current_lower = intervals[i].first;
            current_upper = intervals[i].second;
            changed = false;
        }
    }

    // print the last interval, if it exists.
    if (changed) printf("%lld-%lld\n", current_lower, current_upper);
}
