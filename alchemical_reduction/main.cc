
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {

  auto react = [&] (vector<char> v) {
    stack<char> st;
    for (char ch; scanf("%c", &ch) != EOF;) {
      if (st.size() == 0) {
        st.push(ch);
        continue;
      }

      if ((st.top() == toupper(ch) || st.top() == tolower(ch)) && st.top() != ch)
        st.pop();
      else
        st.push(ch);

    }
    return st.size() - 1;
  };

  vector<char> v;
  for (auto& e : v) cin >> e;

  printf("%ld\n", react(v));
  return 0;
}
