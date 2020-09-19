#include <vector>
#include <cstdio>
#include <stack>
#include <set>

int main() {
  using namespace std;

  auto react = [&](const vector<char> &v, const char x) {
    stack<char> st;
    for (auto &ch : v) {
      if (ch == toupper(x) || ch == tolower(x)) continue;
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

  vector<char> v; for (char ch; scanf("%c", &ch) != EOF;) v.push_back(ch);

  // part I
  printf("%d\n", react(v, '\0'));

  set<char> seen;
  int best = numeric_limits<int>::max();
  for (auto &ch : v) {
    if (!seen.count(ch)) {
      seen.insert(ch); seen.insert(toupper(ch)); seen.insert(tolower(ch));
      best = min(best, react(v, ch));
    }
  }

  printf("%d\n", best);
  return 0;
}
