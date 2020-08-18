
#include <iostream>
#include <vector>
#include <map>

using namespace std;

// globals
int size_x; int size_y;
vector<string> lines;
map<char, pair<int, int>> special_keys;

// parsing input into globals
void readmap() {
  string line;
  int y = 0;
  while (cin >> line) {
    lines.push_back(line);
    for (int x = 0; x < line.size(); ++x)
      if (line[x] != '.') special_keys[line[x]] = make_pair(x, y);

    y++;
  }
  size_x = lines[0].size();
  size_y = lines.size();
}

// dp?
void solve(int px, int py) {
}

int main() {
  readmap();
  auto[start_x, start_y] = special_keys['@'];
  solve(start_x, start_y);
  printf("@: { %d, %d }\n", start_x + 1, start_y + 1);
}
