#include <iostream>
#include <vector>
#include <map>
#include <set>

int main() {
  using namespace std;

  class warrior {
  public:
    int64_t fortune;
    string name;
    warrior(string n, int64_t f) {
      fortune = f;
      name = n;
    }
  };

  int64_t n;
  cin >> n;

  set<string> sons;
  set<string> parents;
  map<string, vector<warrior>> list_sons;
  string p; string f; int64_t l;

  while (cin >> p >> f >> l) {
    parents.insert(p);
    sons.insert(f);
    list_sons[p].push_back(warrior(f, l));
  }

  string root;
  for (auto& pp : parents)
    if (!sons.count(pp))
      root = pp;

  int64_t best = 0;
  string name = "";


  struct {
  void operator()(string target_name, int64_t amount, map<string, vector<warrior>> &list_sons, string &name, int64_t *best) {
    if (list_sons[target_name].size() == 0) {
      if (amount > *best) {
        *best = amount;
        name = target_name;
      }
      return;
    }

    int64_t part = amount / list_sons[target_name].size();
    for (auto &son : list_sons[target_name])
      (*this) (son.name, son.fortune + part, list_sons, name, best);
  };

  } explore;

  explore(root, n, list_sons, name, &best);

  cout << name << ": " << best << endl;
}
