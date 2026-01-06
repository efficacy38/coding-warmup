#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;
stringstream ss;
#define MAXN 1000 + 5
int target[MAXN];
stack<int> s;

int main() {
  int n, A, B;
  string str;
  stringstream ss;
  int case_ = 0;
  while (cin >> n) {
    if (n == 0)
      break;
    cin.get();

    while (getline(cin, str) && str[0] != '0') {
      ss.clear();
      ss.str(str);
      for (int i = 1; i <= n; i++) {
        ss >> target[i];
      }

      int ok = 1;
      A = B = 1;
      while (B <= n) {
        if (target[B] == A) {
          A++;
          B++;
        } else if (!s.empty() && s.top() == target[B]) {
          s.pop();
          B++;
        } else if (A <= n) {
          s.push(A++);
        } else {
          ok = 0;
          while (!s.empty())
            s.pop();
          break;
        }
      }
      cout << (ok ? "Yes\n" : "No\n");
    }
    cout << '\n';
  }
}
