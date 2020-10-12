
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  auto filename = argc > 1 ? argv[1] : "0.in";

  vector<string> G;
  auto parse_input = [&]() {
    string line;
    fstream input(filename);
    getline(input, line);
    char from = line[0];
    char to = line[2];

    // cout << from << " " << to << endl;

    int fx, fy, tx, ty, j = 0;
    bool foundF = false, foundT = false;
    while (getline(input, line)) {
      if (!foundF || !foundT) {
        for (int i = 0; i < line.size(); i++) {
          if (line[i] == from) {
            fx = i;
            fy = j;
            foundF = true;
          } else if (line[i] == to) {
            tx = i;
            ty = j;
            foundT = true;
          }
        }
      }
      G.push_back(line);
      j++;
    }
  };
  parse_input();
  // for (auto &line : G) cout << line << endl;
}
