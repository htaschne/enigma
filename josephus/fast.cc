#include <bits/stdc++.h>

using namespace std;

bool done(vector<char> s) {
  for (size_t i = 0; i < s.size(); ++i)
    if (s[i] == '1')
      return false;
  return true;
}

bool simula(vector<char> s, int knife_pos, int jump) {
  if (done(s)) return true;

  size_t kill_pos = (size_t)(knife_pos + jump) % s.size();
  if (s[kill_pos] == '1') {
    cout << "pre: " << s << " ";
    s.erase(s.begin()+(int)kill_pos); // is this equivalent to s = s[:killpos] + s[killpos+1:]?
    cout << "pos: " << s << "\n";
    return simula(s,(int)(kill_pos % s.size()), jump);
  }
  return false;
}

int main() {
  string line;
  cin >> line;
  vector<char> L (line.size());
  for (int i = 0; i < line.size(); ++i) L.push_back(line[i]);

  int jump = 0;
  bool res = false;
  while (!res) {
    res = simula(L, 0, jump);
    jump++;
  }
  cout << --jump << endl;
}
