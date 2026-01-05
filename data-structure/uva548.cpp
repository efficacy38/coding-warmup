#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>

#define MAXN 10000 + 10
int in_order[MAXN], post_order[MAXN], childl[MAXN], childr[MAXN];
int n;
int best_sum;
int best_leaf;

using namespace std;
stringstream ss;

bool readlist(int *arr) {
  string s;
  int tmp;
  n = 0;
  getline(cin, s);
  ss.clear();
  ss.str(s);
  while (ss >> tmp) {
    arr[n++] = tmp;
  }

  return n > 0;
}

int build(int in_order_l, int in_order_r, int post_order_l, int post_order_r) {
  // empty tree
  if (in_order_l >= in_order_r) {
    return 0;
  }

  // cout << "||" << in_order_l << ' ' << in_order_r << ' ' << post_order_l << '
  // '
  //      << post_order_r << endl;

  int in_order_root = in_order_l;
  // find root(post order)
  for (; in_order_root < in_order_r; in_order_root++) {
    if (in_order[in_order_root] == post_order[post_order_r - 1]) {
      break;
    }
  }

  int cnt = in_order_root - in_order_l;

  // cout << "||" << in_order_l << ' ' << in_order_r << ' ' << post_order_l << '
  // '
  //      << post_order_r << ' ' << post_order[post_order_r - 1] << endl;
  //
  // cout << "|||" << in_order_l << ' ' << in_order_root << ' ' << in_order_l +
  // 1
  //      << ' ' << in_order_r << endl;

  childl[post_order[post_order_r - 1]] =
      build(in_order_l, in_order_root, post_order_l, post_order_l + cnt);
  childr[post_order[post_order_r - 1]] = build(
      in_order_root + 1, in_order_r, post_order_l + cnt, post_order_r - 1);

  return post_order[post_order_r - 1];
}

void dfs(int root, int weight) {
  // Leaf node
  if (childl[root] == 0 && childr[root] == 0) {
    int current_sum = weight + root;
    if (current_sum < best_sum ||
        (current_sum == best_sum && root < best_leaf)) {
      best_sum = current_sum;
      best_leaf = root;
    }
    return;
  }

  // Recurse on children
  if (childl[root] != 0) {
    dfs(childl[root], weight + root);
  }
  if (childr[root] != 0) {
    dfs(childr[root], weight + root);
  }
}

int main(int argc, char *argv[]) {
  while (readlist(in_order)) {
    readlist(post_order);
    int root = build(0, n, 0, n);
    best_sum = INT_MAX;
    best_leaf = INT_MAX;
    dfs(root, 0);
    cout << best_leaf << endl;
  }

  return 0;
}
