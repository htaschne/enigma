
#include <iostream>
#include <stack>

int main() {
  std::stack<char> st;
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

  printf("%ld\n", st.size()-1);
  return 0;
}
