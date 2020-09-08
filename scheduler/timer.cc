#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <cassert>

using namespace std;

class proc {
public:
  int time;
  string name;
  proc(string n, int t) {
    name = n;
    time = t;
  }
};

// globals
map<string, vector<string>> G;
set<string> departures;
set<string> arrivals;
map<string, int> times;

int main() {
  int procs;
  scanf("# Proc %d", &procs);
  // printf("# Proc %d\n", procs);

  string pre, arr, pos;
  while (cin >> pre >> arr >> pos) {
    // read and save first process
    size_t pos_pre = pre.find("_");
    string name_pre = pre.substr(0, pos_pre);
    int time_pre = stoi(pre.substr(pos_pre+1));
    times[name_pre] = time_pre;

    // read and save second process
    size_t pos_pos = pos.find("_");
    string name_pos = pos.substr(0, pos_pos);
    int time_pos = stoi(pos.substr(pos_pos+1));
    times[name_pos] = time_pos;

    // dependencies_map[first_process] += child_process
    G[name_pre].push_back(name_pos);
    departures.insert(name_pre);
    arrivals.insert(name_pos);
  }

  set<string> roots;
  for (auto &pr : departures) {
    if (!arrivals.count(pr)) {
      roots.insert(pr);
    }
  }

  auto comp = [](proc a, proc b) { return a.time > b.time; };
  priority_queue<proc, vector<proc>, decltype(comp)> pq (comp);
  for (auto &root : roots)
    pq.push(proc(root, times[root]));

  int ETA = 0, n = procs;
  vector<proc> atuais;
  while (!pq.empty()) {
    // cout << pq.top().name << " " << pq.top().time << endl; pq.pop();
    while (n--) {
      // there's a free processor. put it to work!
      proc top = pq.top(); pq.pop();
      atuais.push_back(top);

      // push children process into the priority queue.
      for (auto &p : G[top.name])
        pq.push(proc(p, times[p]));
    }

    assert(atuais.size() == procs);
    auto bool_comp = [](proc a, proc b) { return a.time > b.time; };
    int min_val = (min_element(atuais.begin(), atuais.end(), bool_comp))->time;

    ETA += min_val;

    // distribute min_val across all procs in atuais
    // at least one of the cores will be released.

  }

}

