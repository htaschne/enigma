#include <iostream>
#include <stack>
#include <set>
#include <vector>

int main() {
  using namespace std;

  auto react = [&] (const vector<char> &v) {
    stack<char> st;
    for (auto &ch : v) {
      if (st.size() == 0) {
        st.push(ch);
        continue;
      }

      if ((st.top() == toupper(ch) || st.top() == tolower(ch)) && st.top() != ch)
        st.pop();
      else
        st.push(ch);

    }
    return (int) st.size() - 1;
  };

  auto filter = [&] (vector<char>& v, char needle) {
    vector<char> new_v;
    for (int i = 0; i < v.size(); ++i) {
      if (v[i] == needle || v[i] == toupper(needle) || v[i] == tolower(needle)) continue;
      new_v.push_back(v[i]);
    }
    return new_v;
  };

  vector<char> v; for (char ch; scanf("%c", &ch) != EOF;) v.push_back(ch);

  // part I
  printf("%d\n", react(v));

  set<char> seen;
  int best = numeric_limits<int>::max();
  for (auto &ch : v) {
    if (!seen.count(ch)) {
      seen.insert(ch); seen.insert(toupper(ch)); seen.insert(tolower(ch));
      auto current_v = filter(v, ch);
      best = min(best, react(current_v));
    }
  }

  printf("%d\n", best);
  return 0;
}
