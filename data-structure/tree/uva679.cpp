#include <cstring>
#include <iostream>
#define MAXD 20

using namespace std;

int main(int argc, char *argv[]) {

  int n, D, I;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> D >> I;
    int k = 1;
    for (int j = 0; j < D - 1; j++) {
      if (I % 2) {
        k = 2 * k;
        I = (I + 1) / 2;
      } else {
        k = 2 * k + 1;
        I /= 2;
      }
    }

    cout << k << endl;
  }

  return 0;
}
