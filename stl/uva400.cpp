#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
vector<string> fns;

int main(int argc, char *argv[]) {
  int n;
  while (cin >> n) {
    fns.clear();
    string s;
    int maxL = 0;
    for (int i = 0; i < n; i++) {
      cin >> s;
      fns.push_back(s);
      maxL = max(maxL, int(s.length()));
    }

    for (int i = 0; i < 60; i++)
      cout << '-';
    cout << endl;

    int colCnt = 62 / (maxL + 2);
    int rowCnt = fns.size() / colCnt;
    if (fns.size() % colCnt)
      rowCnt++;

    sort(fns.begin(), fns.end());
    for (int i = 0; i < rowCnt; i++) {
      for (int j = 0; j < colCnt; j++) {
        if (j * rowCnt + i < fns.size()) {
          if (j != 0) {
            cout << "  ";
          }
          cout << fns[j * rowCnt + i];
          for (int k = fns[j * rowCnt + i].length(); k < maxL; k++) {
            cout << ' ';
          }
        }
      }
      cout << endl;
    }
  }
  return 0;
}
