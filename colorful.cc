
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <chrono>
#include <thread>
#include <set>

using namespace std;

#define clear() printf("\033[H\033[J")
#define gotoxy(x, y) printf("\033[%d;%dH", (y), (x))

void parseInput(string filename, int *xa, int *ya, int *xb, int *yb,
        int *size_x, int *size_y, vector<string> &lines) {
    std::fstream input(filename);

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
    if ( x - 1 > 0      && lines[y][x - 1] != '#' )  ret.push_back(make_tuple(x - 1, y, lines[y][x - 1]));
    if ( x + 1 < size_x && lines[y][x + 1] != '#' )  ret.push_back(make_tuple(x + 1, y, lines[y][x + 1]));
    if ( y - 1 > 0      && lines[y - 1][x] != '#' )  ret.push_back(make_tuple(x, y - 1, lines[y - 1][x]));
    if ( y + 1 < size_y && lines[y + 1][x] != '#' )  ret.push_back(make_tuple(x, y + 1, lines[y + 1][x]));
    return ret;
}

int bfs(int x, int y, int size_x, int size_y, vector<string> &lines) {
    set<tuple<int, int, char>> seen;
    auto neighbors = neighborhood(x, y, size_x, size_y, lines);
    vector<tuple<int, int, char>> Q;
    for (auto &p : neighbors)
        Q.push_back(p);

    clear();
    for (auto &line : lines) {
        for (auto &ch : line) {
            if (ch == '.') cout << "\033[0;37m" << ch << "\033[0m";
            else if (ch == 'B') cout << "\033[5;31m" << ch << "\033[0m";
            else           cout << ch;
        }
        cout << endl;
    }

    int depth = 1;
    while (Q.size() != 0) {
        vector<tuple<int, int, char>> to_color;
        vector<tuple<int, int, char>> new_Q;
        for (int i = 0; i < Q.size(); i++) {
            auto n = Q[i];
            if (get<2>(n) == 'B') {
                //cout << get<0>(n) << " " << get<1> (n) << endl;
                gotoxy(get<0>(n) + 1, get<1>(n) + 1);
                cout << "\033[31m" << get<2>(n) << "\033[0m";
                gotoxy(1, size_y + 1);
                return depth;
            }
            if (seen.count(n))
                continue;
            seen.insert(n);
            if (get<2> (n) == '.')
                to_color.push_back(n);
            auto neighbors_n = neighborhood(get<0>(n), get<1>(n), size_x, size_y, lines);
            for (auto &nn : neighbors_n)
                new_Q.push_back(nn);
        }

        for (auto &e : to_color) {
            int xx = get<0>(e) + 1;
            int yy = get<1>(e) + 1;
            gotoxy(xx, yy);
            cout << "\033[35m" << get<2>(e) << "\033[0m" << endl;
            gotoxy(1, size_y + 1);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        depth++;
        Q = new_Q;
    }
    return -1; // could not find 'B' from 'A'
}

int main(int argc, char **argv) {
    // filename
    std::string filename = argc > 1 ? argv[1] : "0.in";
    // var declarations
    int xa; int ya; int xb; int yb; int size_x; int size_y; vector<string> lines;

    parseInput(filename, &xa, &ya, &xb, &yb, &size_x, &size_y, lines);

    int resp = bfs(xa, ya, size_x, size_y, lines);
    //cout << "\033[32m" << resp << "\033[0m" << endl;
    cout << resp << endl;
}
