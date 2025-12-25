#include <cstring>
#include <iostream>
#define MAXD 20

using namespace std;

bool state[(1 << MAXD) + 5];

int main(int argc, char *argv[]) {

  int n, D, I;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> D >> I;
    memset(state, 0, sizeof(state));

    int lastK;
    for (int i = 0; i < I; i++) {
      int k = 1;
      for (int d = 0; d < D - 1; d++) {
        state[k] = !state[k];
        if (state[k]) {
          k = 2 * k;
        } else {
          k = 2 * k + 1;
        }

        lastK = k;
      }
    }

    cout << lastK << endl;
  }

  // consume last -1
  cin >> n;

  return 0;
}
