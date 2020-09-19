#include <set>
#include <vector>
#include <stack>
#include <iostream>

auto main() -> int {
  using namespace std;

  // given a polymer it reacts all it's units, possibly making it smaller.
  // also it skips all polymer's units that equal the unit parameter.
  auto react = [&](const vector<char> &polymer, const char unit) {
    stack<char> st;
    for (auto &un : polymer) {
      if (un == toupper(unit) || un == tolower(unit)) continue;
      if (st.size() == 0) {
        st.push(un);
        continue;
      }
      // checks if the current unit will react with the top of the stack.
      // either top = X and unit = x or top = x and unit = X. otherwise it's false
      bool react_with_top = st.top() != un && (st.top() == toupper(un) || st.top() == tolower(un));
      if (react_with_top) {
        st.pop();
      } else {
        st.push(un);
      }

    }
    return st.size();
  };

  // read the whole line (polymer) into the vector.
  vector<char> polymer; for (char unit; cin >> unit;) polymer.push_back(unit);

  // part I
  // react the input polymer and compute it's size.
  // to react a polymer is to delete all pairs xX and Xx in it.
  cout << react(polymer, '\0') << endl;

  // Part II
  // generate all polymer's variations by deliting, at each iteration, one of
  // the units type (say all the a's and A's) and find the one with the smallest size.
  set<char> reacted;
  auto best = polymer.size(); // worst case there's no reaction to be excecuted
  for (auto &un : polymer) {
    if (!reacted.count(un)) {
      reacted.insert(toupper(un)); reacted.insert(tolower(un));
      best = min(best, react(polymer, un));
    }
  }
  cout << best << endl;
}
