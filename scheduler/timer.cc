
#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <map>
#include <set>

using namespace std;

// globals
vector<vector<string>> order;
map<string, vector<string>> dep;
set<string> departures;
set<string> arrivals;
map<string, int> times;


// FIXME: talvez isso devesse ser uma ordenacao topologica
// ja que preenche a pilha da qual a gente retirna na ordem
// em que foram inseridos os elemntos
void dfs(string target, int depth) {
  cout << depth << " " << target << endl;
  order[depth].push_back(target);
  for (auto &n : dep[target])
    dfs(n, depth + 1);
}

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
    dep[name_pre].push_back(name_pos);
    departures.insert(name_pre);
    arrivals.insert(name_pos);
  }

  set<string> roots;
  for (auto &pr : departures) {
    if (!arrivals.count(pr)) {
      roots.insert(pr);
      break;
    }
  }

  // for (auto &r : roots) cout << r.name << " " << r.time << endl;
  for (auto &r : roots)
    dfs(r, 0);

  // // dfs working proof!
  // for (auto it = tt.begin(); it != tt.end(); ++it) {
  //   auto procs = it->second;
  //   for (auto ti = procs.begin(); ti != procs.end(); ++ti)
  //     cout << it->first << " " << ti->name << endl;
  // }


  // MIN
  int N = procs;
  stack<string> S;
  cout << order.size() << endl;
  for (int i = 0; i < order.size(); ++i) {
    cout << i << endl;
  }

}
