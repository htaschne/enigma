
#include <set>
#include <map>
#include <vector>
#include <iostream>

class warrior {
public:
  int64_t fortune;
  std::string name;
  warrior(std::string n, int64_t f) {
    fortune = f;
    name = n;
  }
};

void explore(std::string target_name, int64_t amount, std::map<std::string, std::vector<warrior>> &list_sons, std::string &name, int64_t *best) {
  if (list_sons[target_name].size() == 0) {
    if (amount > *best) {
      *best = amount;
      name = target_name;
    }
    return;
  }

  int64_t part = amount / list_sons[target_name].size();
  for (auto &son : list_sons[target_name])
    explore(son.name, son.fortune + part, list_sons, name, best);
}

int main() {
  int64_t n;
  std::cin >> n;

  std::set<std::string> sons;
  std::set<std::string> parents;
  std::map<std::string, std::vector<warrior>> list_sons;
  std::string p; std::string f; int64_t l;

  while (std::cin >> p >> f >> l) {
    parents.insert(p);
    sons.insert(f);
    list_sons[p].push_back(warrior(f, l));
  }

  std::string root;
  for (auto& p : parents)
    if (!sons.count(p))
      root = p;
  int64_t best = 0;
  std::string name = "";
  explore(root, n, list_sons, name, &best);
  std::cout << name << ": " << best << std::endl;
}
