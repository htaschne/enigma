
#include <fstream>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

void parseInput(string filename, int *xa, int *ya, int *xb, int *yb,
		int *size_x, int *size_y, vector<string> &lines) {

	fstream input(filename);
	bool foundA = false;
	bool foundB = false;

	int j = 0;
	for (std::string line; getline(input, line);) {
		if (!foundA || !foundB) {
			for (int i = 0; i < line.size(); i++) {
				if (line[i] == 'A') {
					*xa = i;
					*ya = j;
					foundA = true;
				} else if (line[i] == 'B') {
					*xb = i;
					*yb = j;
					foundB = true;
				}
			}
		}
		lines.push_back(line);
		j++;
	}
	*size_y = lines.size();
	*size_x = lines[0].size();
}

vector<tuple<int, int, char>> neighborhood(int x, int y, int size_x, int size_y,
		vector<string> &lines) {
	vector<tuple<int, int, char>> ret;
	if (x - 1 > 0      && lines[y][x - 1] != '#') ret.push_back(make_tuple(x - 1, y, lines[y][x - 1]));
	if (x + 1 < size_x && lines[y][x + 1] != '#') ret.push_back(make_tuple(x + 1, y, lines[y][x + 1]));
	if (y - 1 > 0      && lines[y - 1][x] != '#') ret.push_back(make_tuple(x, y - 1, lines[y - 1][x]));
	if (y + 1 < size_y && lines[y + 1][x] != '#') ret.push_back(make_tuple(x, y + 1, lines[y + 1][x]));
	return ret;
}

int bfs(int x, int y, int size_x, int size_y, vector<string> &lines) {
	set<tuple<int, int, char>> seen;

	auto neighbors = neighborhood(x, y, size_x, size_y, lines);
	vector<tuple<int, int, char>> Q;
	for (auto &p : neighbors)
		Q.push_back(p);

	int depth = 1;
	while (Q.size() != 0) {
		vector<tuple<int, int, char>> new_Q;
		for (int i = 0; i < Q.size(); i++) {
			auto n = Q[i];
			if (get<2>(n) == 'B') {
				cout << get<0>(n) << " " << get<1> (n) << endl;
				return depth;
			}
			if (seen.count(n))
				continue;
			seen.insert(n);
			auto neighbors_n = neighborhood(get<0>(n), get<1>(n), size_x, size_y, lines);
			for (auto &nn : neighbors_n)
				new_Q.push_back(nn);
		}
		depth++;
		Q = new_Q;
	}
	return -1; // could not find 'B' from 'A'
}

int main(int argc, char **argv) {
	std::string filename = argc > 1 ? argv[1] : "0.in";

	int xa; int ya; int xb; int yb; int size_x; int size_y; vector<string> lines;
	parseInput(filename, &xa, &ya, &xb, &yb, &size_x, &size_y, lines);

	int resp = bfs(xa, ya, size_x, size_y, lines);
	cout << "\033[32m" << resp << "\033[0m" << endl;
}
