#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;
int n, k, m, visit[20];
int a, b;

int solve(int *visit) {
  for (int i = 0; i < k; i++) {
    if (i != 0)
      a = (a + 1) % n;

    while (visit[a]) {
      a = (a + 1) % n;
    };
  }

  for (int i = 0; i < m; i++) {
    if (i != 0)
      b = (b - 1 + n) % n;

    while (visit[b]) {
      b = (b - 1 + n) % n;
    };
  }

  visit[a] = 1;
  visit[b] = 1;

  if (a == b) {
    cout << setw(3) << a + 1;
    return 1;
  } else {
    cout << setw(3) << a + 1 << setw(3) << b + 1;
    return 2;
  }
}

int main(int argc, char *argv[]) {
  while (cin >> n >> k >> m && n != 0 && k != 0 && m != 0) {
    memset(visit, 0, sizeof(visit));
    bool isFirst = true;
    int remaining = n;

    a = 0, b = n - 1;
    // solve A from 0, B from N - 1
    while (remaining != 0) {
      if (isFirst) {
        isFirst = false;
      } else {
        cout << ',';
      }
      remaining -= solve(visit);
    }

    cout << endl;
  }
  return 0;
}
