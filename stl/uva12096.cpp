#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <vector>

using namespace std;

vector<set<int>> setCache;
// map id of set to an id
map<set<int>, int> IDcache;

int getID(set<int> s) {
  if (IDcache.count(s))
    return IDcache[s];

  setCache.push_back(s);
  IDcache[s] = setCache.size() - 1;
  return IDcache[s];
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t, n;
  cin >> t;

  while (t--) {
    cin >> n;
    string op;
    stack<int> s;
    while (n--) {
      cin >> op;
      if (op[0] == 'P') {
        int id = getID(set<int>());
        // cout << "debug: " << id << " " << setCache[id].size() << endl;
        s.push(id);
      } else if (op[0] == 'D') {
        s.push(s.top());
      } else {
        set<int> tmp;
        set<int> x1 = setCache[s.top()];
        s.pop();
        set<int> x2 = setCache[s.top()];
        s.pop();

        if (op[0] == 'U') {
          set_union(x1.begin(), x1.end(), x2.begin(), x2.end(),
                    inserter(tmp, tmp.begin()));
        } else if (op[0] == 'I') {
          set_intersection(x1.begin(), x1.end(), x2.begin(), x2.end(),
                           inserter(tmp, tmp.begin()));
        } else if (op[0] == 'A') {
          tmp = x2;
          tmp.insert(getID(x1));
        }
        s.push(getID(tmp));
      }
      cout << setCache[s.top()].size() << endl;
    }
    cout << "***" << endl;
  }

  return 0;
}
