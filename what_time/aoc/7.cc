
#include <bits/stdc++.h>

using namespace std;

int main() {
  char D, A;
  set<char> arrivals;
  set<char> departures;
  set<pair<char, char>> edges;
  // printf("loading stdin into arrivals, departures and edges..\n");
  while ( scanf("Step %c must be finished before step %c can begin.\n", &D, &A) == 2 ) {
    // printf("%c %c\n", D, A);
    edges.insert(make_pair(D, A));
    arrivals.insert(A);
    departures.insert(D);
  }
  set<char> S; // roots. nodes no one points to.
  set_difference(departures.begin(), departures.end(),
                 arrivals.begin(), arrivals.end(),
                 inserter(S, S.begin()));
  set<char> all;
  set_union(arrivals.begin(), arrivals.end(),
            departures.begin(), departures.end(),
            back_inserter(all));
  // TOPOSORT
  vector<char> L(all.size());
  auto it = S.begin();
  while ( !S.empty() ) {
    char n = *it;
    L.emplace_back(*n);
    cout << n << endl;
    ++it;
    if (it == S.end()) it = S.begin();
  }

  // print all elements in L.
  for (char e : L) cout << e; cout << endl;

  return 0;
}
