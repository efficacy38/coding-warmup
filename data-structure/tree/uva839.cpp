#include <iostream>

using namespace std;

bool balanced = false;
int solve() {
  int w1, d1, w2, d2;
  cin >> w1 >> d1 >> w2 >> d2;

  if (w1 == 0) {
    w1 = solve();
  }
  if (w2 == 0) {
    w2 = solve();
  }

  if (w1 * d1 != w2 * d2) {
    balanced = false;
  }

  return w1 + w2;
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    balanced = true;
    solve();
    if (balanced) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }

    if (i != n - 1) {
      cout << endl;
    }
  };
  return 0;
}
