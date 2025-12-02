#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;
int n, k, m, visit[20];
int a, b;

void go(int p, int step, int times) {
  for (int i = 0; i < times; i++) {
    do {
      p = (p + step + n - 1) % n + 1;
    } while (visit[p]);
  }
}

int main(int argc, char *argv[]) {
  while (cin >> n >> k >> m && n != 0 && k != 0 && m != 0) {
    memset(visit, 0, sizeof(visit));
    bool isFirst = true;
    int remaining = n;

    a = 1, b = n;
    while (remaining != 0) {
      if (isFirst) {
        isFirst = false;
      } else {
        cout << ',';
      }

      a = go(a, 1, m);
      b = go(b, -1, n);

      cout << setw(3) << a;
      remaining--;
      if (a == b) {
        cout << setw(3) << b;
        remaining--;
      }
    }

    cout << endl;
  }
  return 0;
}
