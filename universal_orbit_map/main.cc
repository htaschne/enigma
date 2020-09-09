#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

set<string> seen;
void explore(map<string, vector<string>> &G, string target, int depth) {
	if (seen.count(target)) return;
	seen.insert(target);
	for (auto &pt : G[target]) {
		if (pt == "SAN") {
			cout << --depth << endl;
			exit(0);
		}
		explore(G, pt, depth+1);
	}
}

int main() {
	map<string, vector<string>> G;
	string line, pre, pos;
	while (cin >> line) {
		size_t p = line.find(")");
		pre = line.substr(0, p);
		pos = line.substr(p+1, line.size()-1);
		G[pre].push_back(pos);
		G[pos].push_back(pre);
	}
	explore(G, "YOU", 0);
}
