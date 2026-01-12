#include <cstring>
#include <iostream>
#include <string>

using namespace std;
bool buf[32][32];
int cur;
string t1, t2;

void build(string &s, int x, int y, int size) {
  if (s[cur++] == 'p') {
    build(s, x + size / 2, y, size / 2);
    build(s, x, y, size / 2);
    build(s, x, y + size / 2, size / 2);
    build(s, x + size / 2, y + size / 2, size / 2);
  } else if (s[cur - 1] == 'f') {
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++) {
        buf[y + i][x + j] = true;
      }
  }
}

void print() {
  for (int i = 0; i < 32; i++) {
    for (int j = 0; j < 32; j++) {
      if (buf[i][j]) {
        cout << "*";
      } else {
        cout << "_";
      }
    }
    cout << endl;
  }
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n--) {
    memset(buf, 0, sizeof(buf));
    cin >> t1 >> t2;
    cur = 0;
    build(t1, 0, 0, 32);
    cur = 0;
    build(t2, 0, 0, 32);
    int cnt = 0;
    for (int i = 0; i < 32; i++) {
      for (int j = 0; j < 32; j++) {
        if (buf[i][j]) {
          cnt++;
        }
      }
    }
    cout << "There are " << cnt << " black pixels." << endl;
  }
  return 0;
}
