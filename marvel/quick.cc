
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct Node {
	int x;
	int y;
	int f_cost;
	Node (int a, int b, int c) {
		x = a;
		y = b;
		f_cost = c;
	}
} Node;

struct Comp {
	bool operator()(const Node a, const Node b) {
		return a.f_cost > b.f_cost;
	}
};

inline int dist(int xa, int ya, int xb, int yb) {
	return (abs(xa - xb) + abs(ya - yb)) + 1;
}

vector<Node*> getSurround(Node* u, int tx, int ty, int size_x, int size_y, char** M) {
	vector<Node*> v;
	int x = u->x;
	int y = u->y;

	if ( x - 1 > 0      && M[y][x - 1] != '#' )  v.push_back(new Node(x - 1, y, dist(x - 1, y, tx, ty)));
	if ( x + 1 < size_x && M[y][x + 1] != '#' )  v.push_back(new Node(x + 1, y, dist(x + 1, y, tx, ty)));
	if ( y - 1 > 0      && M[y - 1][x] != '#' )  v.push_back(new Node(x, y - 1, dist(x, y - 1, tx, ty)));
	if ( y + 1 < size_y && M[y + 1][x] != '#' )  v.push_back(new Node(x, y + 1, dist(x, y + 1, tx, ty)));

	return v;
}

int main() {

	int size_x; int size_y; int xa; int ya; int xb; int yb;
	cin >> size_x >> size_y;
	char **M = new char* [size_y];
	for (int i = 0; i < size_y; i++) {
		M[i] = new char[size_x];
	}

	char ch;
	for (int y = 0; y < size_y; y++) {
		int x;
		for (x = 0; x < size_x; x++) {
			cin >> ch;
			M[y][x] = ch;
			if (ch == 'A') {
				xa = x;
				ya = y;
			} else if (ch == 'B') {
				xb = x;
				yb = y;
			}
		}
	}


	// g cost = dist from start node
	// h cost = dist from end   node
	// f cost = g + h                     <<<< comp func for priority_queue

	priority_queue<Node, vector<Node>, Comp> Q;
	auto surround = getSurround( new Node(xa, ya, 0), xb, yb, size_x, size_y, M );
	for (auto &ss : surround) {
		Q.push(*ss);
	}

	cout << Q.top().x << " " << Q.top().y << " " << Q.top().f_cost << endl; Q.pop();
	cout << Q.top().x << " " << Q.top().y << " " << Q.top().f_cost << endl; Q.pop();
	cout << Q.top().x << " " << Q.top().y << " " << Q.top().f_cost << endl; Q.pop();
	cout << Q.top().x << " " << Q.top().y << " " << Q.top().f_cost << endl; Q.pop();
}

