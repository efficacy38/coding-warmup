#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

#define MAXM 10000 + 5
int marbles[MAXM];

int main(int argc, char *argv[]) {
  int n, q;
  int r = 0;
  while (cin >> n >> q) {
    if (n == 0 && q == 0)
      break;
    memset(marbles, 0, sizeof(marbles));
    int marble;
    for (int i = 0; i < n; i++) {
      cin >> marble;
      marbles[i] = marble;
    }

    sort(marbles, marbles + n);

    cout << "CASE# " << ++r << ":" << endl;
    int qv;
    // lowerbound
    for (int i = 0; i < q; i++) {
      cin >> qv;
      int pos = lower_bound(marbles, marbles + n, qv) - marbles;
      if (pos < n && marbles[pos] == qv) {
        cout << qv << " found at " << pos + 1 << endl;
      } else {
        cout << qv << " not found" << endl;
      }
    }
  }
}
