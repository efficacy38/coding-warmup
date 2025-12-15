#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#define MAXN 10000 + 5
#define MAXM 10 + 5

int table[MAXN][MAXM];
using namespace std;

vector<string> fieldCache;
map<string, int> idCache;

int getId(string s) {
  if (!idCache.count(s)) {
    fieldCache.push_back(s);
    idCache[s] = fieldCache.size() - 1;
  }

  return idCache[s];
}

int main(int argc, char *argv[]) {
  int n, m;
  while (cin >> n >> m) {
    idCache.clear();
    fieldCache.clear();
    memset(table, 0, sizeof(table));
    getchar();

    string s;

    for (int i = 0; i < n; i++) {
      getline(cin, s);
      // cout << "|" << s << "|" << endl;
      int lastIdx = 0;
      for (int j = 0; j < m; j++) {
        // cout << "debug0: " << lastIdx << endl;
        size_t curPeriodIdx = s.find(",", lastIdx + 1);
        // cout << "debug1: " << lastIdx << ' ' << curPeriodIdx << endl;
        // cout << "debug2: " << s.substr(lastIdx, curPeriodIdx - lastIdx) << '
        // '
        //      << lastIdx << ' ' << curPeriodIdx << endl;
        // cout << "debug3: " << i << ' ' << j << endl;
        table[i][j] = getId(s.substr(lastIdx, curPeriodIdx - lastIdx));
        lastIdx = curPeriodIdx + 1;
      }
    }

    // enumerate 2 col, map row
    bool isPNF = false;
    for (int i = 0; i < m && !isPNF; i++) {
      for (int j = i + 1; j < m && !isPNF; j++) {
        map<pair<int, int>, int> tableCache;
        for (int k = 0; k < n && !isPNF; k++) {
          auto valuePair = make_pair(table[k][i], table[k][j]);
          if (tableCache.count(valuePair)) {
            // cout << "valuePair: " << fieldCache[valuePair.first] << ' '
            //      << fieldCache[valuePair.second] << endl;
            isPNF = true;
            cout << "NO" << endl;
            cout << tableCache[valuePair] + 1 << ' ' << k + 1 << endl;
            cout << i + 1 << ' ' << j + 1 << endl;
          }
          tableCache[valuePair] = k;
        }
      }
    }

    if (!isPNF) {
      cout << "YES" << endl;
    }
  }

  return 0;
}
