#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
  public:
    bool isValid(string s) {
      map<pair<char, int> , int> levels;
      bool okparens = false, okbrackts = false, okcurlys = false;
      int level = 0;
      for (char &ch : s) {
        if (ch == '(') {
          auto p = make_pair(ch, level);
          okparens = false;
          if (levels[p] < 0) return false;
          levels[p]++;
          level++;
        }   
        if (ch == '[') {
          auto p = make_pair(ch, level);
          okbrackts = false;
          if (levels[p] < 0) return false;
          levels[p]++;
          level++;
        }   
        if (ch == '{') {
          auto p = make_pair(ch, level);
          okcurlys = false;
          if (levels[p] < 0) return false;
          levels[p]++;
          level++;
        }   


        else if (ch == ')') {
          auto p = make_pair('(', level-1);
          levels[p]--;
          level--;
        }   
        else if (ch == ']') {
          auto p = make_pair('[', level-1);
          levels[p]--;
          level--;
        }   
        else if (ch == '}') {
          auto p = make_pair('{', level-1);
          levels[p]--;
          level--;
        }   
      }   

      for (auto [k, v] : levels)
        if (v != 0)
          return false;
      return true;
    }   
};


int main() {
  string str; cin >> str;
  Solution sol;
  auto s = (sol.isValid(str) == true) ? "true" : "false";
  cout << s << endl;
}
