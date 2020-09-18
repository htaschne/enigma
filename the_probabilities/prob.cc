
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

map<string, vector<string>> G;
map<string, double> costs;

string parseInput(string filename) {
    set<string> arr;
    set<string> dep;
    string line;
    fstream input(filename);
    while (getline(input, line)) {
        string current = "";
        vector<string> tokens;

        bool changed = false;
        for (char ch : line) {
            if (ch == ' ') {
                tokens.push_back(current);
                current = "";
                changed = false;
            } else {
                changed = true;
                current += ch;
            }
        }
        if (changed) tokens.push_back(current);

        // b : ba 25 bb 35 b 40
        auto pre = tokens[0];
        dep.insert(pre);
        for (size_t i = 2; i < tokens.size(); i = i + 2) {
            G[pre].push_back(tokens[i]);
            costs[tokens[i]] = (double) stoi(tokens[i+1]) / 100.0;
            arr.insert(tokens[i]);
        }
    }
    input.close();

    set<string> res;
    set_difference(dep.begin(), dep.end(),
                   arr.begin(), arr.end(), inserter(res, res.end()));

    string root = *(res.begin());
    return root;
}

double best = 0; string namebest;
void explore(string target) {
    if (G[target].size() == 0) {
        if (costs[target] > best) {
            best = costs[target];
            namebest = target;
        }
        return;
    }

    for (auto &ch : G[target]) {
        costs[ch] *= costs[target];
        explore(ch);
    }
}

int main(int argc, char *argv[]) {
    string filename = argc > 2 ? argv[1] : "0.in";
    auto root = parseInput(filename);
    costs[root] = 1.0;
    explore(root);
    cout << namebest << ": " << (best * 100) << "%" << endl;
    return 0;
}
