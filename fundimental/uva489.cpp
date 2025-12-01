#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int round = 0;
  while (cin >> round) {
    if (round == -1) {
      break;
    }
    string s1, s2;
    int cnt[26], cntTimes, cnt1;
    cntTimes = 0, cnt1 = 0;
    memset(cnt, 0, sizeof(cnt));
    cin >> s1 >> s2;

    for (int i = 0; i < s1.length(); i++) {
      if (cnt[(s1[i] - 'a')] == 0) {
        cnt1++;
      }
      cnt[(s1[i] - 'a')]++;
    }

    for (int i = 0; i < s2.length(); i++) {
      if (cnt[s2[i] - 'a'] == 0) {
        cntTimes++;
      }

      if (cnt[s2[i] - 'a'] > 0) {
        cnt1--;
      }

      cnt[s2[i] - 'a'] = -1;
      if (cnt1 == 0) {
        break;
      }
    }

    cout << "Round " << round << endl;
    if (cntTimes > 6) {
      cout << "You lose." << endl;
    } else {
      bool isChicken = false;
      for (int i = 0; i < sizeof(cnt) / sizeof(cnt[0]); i++) {
        if (cnt[i] > 0) {
          isChicken = true;
          break;
        }
      }
      if (isChicken)
        cout << "You chickened out." << endl;
      else
        cout << "You win." << endl;
    }
  }
}
