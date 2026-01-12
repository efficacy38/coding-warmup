#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

#define MAXN 100 + 5

using namespace std;
int idx[MAXN][MAXN];
string buf[MAXN];
int n, m, cnt = 0;

void dfs(int y, int x, int id) {
  if (y < 0 || y >= m || x < 0 || x >= n) {
    return;
  }

  if (buf[y][x] == '@' && idx[y][x] == 0) {
    idx[y][x] = id;
    for (int dx = -1; dx <= 1; dx++) {
      for (int dy = -1; dy <= 1; dy++) {
        if (dx == 0 && dy == 0)
          continue;

        dfs(y + dy, x + dx, id);
      }
    }
  }
}

int main(int argc, char *argv[]) {
  while (cin >> m >> n && m != 0 && n != 0) {
    cin.get();
    cnt = 0;
    for (int i = 0; i < m; i++) {
      getline(cin, buf[i]);
      // cout << buf[i] << endl;
    }
    memset(idx, 0, sizeof(idx));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (buf[i][j] == '@' && idx[i][j] == 0) {
          dfs(i, j, ++cnt);
        };
      }
    }
    cout << cnt << endl;
  }
}
