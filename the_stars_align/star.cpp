#include <stdio.h>
#include <vector>
#include <iostream>
#include <tuple>
#include <map>

int MIN =  -(2e31);
int MAX = (2e31) -1;

using namespace std;

int main() {
  // position=< 9,  1> velocity=< 0,  2>
  int x1, y1, vx, vy;
  map<pair<int, int>, pair<int, int>> points;
  while ( scanf("position=< %d, %d> velocity=< %d, %d> ", &x1, &y1, &vx, &vy) == 4 ) { 
    auto point = make_pair(x1, y1);
    auto vel = make_pair(vx, vy);
    points[point] = vel;
  }

  cout << points.size() << endl; // imprime 0 :(
  // show_points(points); // fixme!

  int t=0;
  while (true) {
    // simula
    map<pair<int, int>, int> atual;
    for ( auto [coord, vel] : points ) {
      atual[make_pair(coord.first + vel.first*t, coord.second + vel.second*t)] = 1;
    }

    // calcula retangulo de interesse
    int x_max = MIN, y_max = MIN, x_min = MAX, y_min = MAX;
    for ( auto [coord, vel] : atual ) {
      x_max = max(coord.first, x_max);
      x_min = min(coord.first, x_min);
      y_max = max(coord.second, y_max);
      y_min = min(coord.second, y_min);
    }

    int l1 = x_max - x_min;
    int l2 = y_max - y_min;
    if (l1 * l2 < 100 * 100) {
      //printação
      for ( int y = y_min; y <= y_max; y++ ) {
        for ( int x = x_min; x <= x_max; x++ ) {
          auto point = make_tuple(x, y);
          if (atual.count(point)) {
            cout << "#";
          } else {
            cout << ".";
          }
        }
        cout << endl;
      }
    }

    t++;

  }

  // g++ -std=c++17 star.cpp && ./a.out < 1.in

}
