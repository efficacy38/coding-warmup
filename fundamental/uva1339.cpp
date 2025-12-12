#include <cstring>
#include <iostream>
#include <string>

using namespace std;
int osc[26], nsc[26];

int main() {
  string os, ns;
  while (cin >> os >> ns) {
    memset(osc, 0, sizeof(osc));
    memset(nsc, 0, sizeof(nsc));
    bool isPossible = true;
    for (int i = 0; i < os.length(); i++) {
      osc[(os[i] - 'A')]++;
      nsc[(ns[i] - 'A')]++;
    }

    for (int i = 0; i < 26; i++) {
      bool isFound = false;
      for (int j = 0; j < 26; j++) {
        // cout << i << ' ' << j << ' ' << osc[i] << ' ' << nsc[j] << endl;
        if (osc[i] == nsc[j]) {
          nsc[j] = 0;
          isFound = true;
          break;
        }
      }
      if (!isFound) {
        isPossible = false;
        break;
      }
    }

    if (isPossible) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
