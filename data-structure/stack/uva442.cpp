#include <cctype>
#include <iostream>
#include <stack>
#define MAXN 26 + 5

using namespace std;

pair<int, int> sizes[MAXN];

int main(int argc, char *argv[]) {

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    int r, c;
    cin >> s >> r >> c;
    sizes[s[0] - 'A'] = make_pair(r, c);
  }

  string expr;
  while (cin >> expr) {
    stack<pair<int, int>> matrixs;
    bool isErr = false;
    int cnt = 0;

    for (int i = 0; i < expr.length(); i++) {
      if (isalpha(expr[i])) {
        matrixs.push(sizes[(expr[i] - 'A')]);
      };

      if (expr[i] == ')') {
        pair<int, int> b = matrixs.top();
        matrixs.pop();
        pair<int, int> a = matrixs.top();
        matrixs.pop();

        if (a.second != b.first) {
          // cout << a.first << ' ' << a.second << ' ' << b.first << ' '
          //      << b.second << endl;
          isErr = true;
          break;
        }

        cnt += a.first * a.second * b.second;

        matrixs.push(make_pair(a.first, b.second));
      }
    }

    if (isErr)
      cout << "error" << endl;
    else
      cout << cnt << endl;
  }

  return 0;
}
