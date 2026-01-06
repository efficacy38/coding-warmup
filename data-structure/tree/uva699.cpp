#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;
stringstream ss;
map<int, int> sum;

int read() {
  int tmp;
  if (ss >> tmp) {
    return tmp;
  } else {
    string s;
    getline(cin, s);
    ss.clear();
    ss.str(s);
    ss >> tmp;
    return tmp;
  }
}

void build(int pos, int root) {
  int left, right;

  left = read();
  if (left != -1) {
    build(pos - 1, left);
  }

  right = read();
  if (right != -1) {
    build(pos + 1, right);
  }

  if (!sum.count(pos)) {
    sum[pos] = 0;
  }

  sum[pos] += root;
}

int main(int argc, char *argv[]) {
  string s;
  int kase = 0;
  int root;
  while ((root = read()) != -1) {
    sum.clear();
    build(0, root);

    cout << "Case " << ++kase << ":" << endl;
    for (auto it = sum.begin(); it != sum.end(); it++) {
      if (it != sum.begin()) {
        cout << ' ';
      }

      cout << it->second;
    }
    cout << endl << endl;
  }

  return 0;
}
