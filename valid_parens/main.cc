#include <iostream>
#include <stack>

using namespace std;

class Solution {
  public:
    bool isValid(string s) {
      if (s.length() == 0) return true;
      stack<char> st;
      for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
          st.push(s[i]);
          continue;
        }
        if (st.empty()) {
          return false;
        }
        char c = st.top();
        st.pop();
        if (c == '(' && s[i] != ')') return false;
        if (c == '[' && s[i] != ']') return false;
        if (c == '{' && s[i] != '}') return false;
      }
      return st.empty();
    }
};

int main() {
  string str; cin >> str;
  Solution sol;
  auto s = (sol.isValid(str) == true) ? "true" : "false";
  cout << s << endl;
}
