#include <cstdlib>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int v;
  Node *left, *right;
  bool have_value;
  Node() : have_value(false), left(NULL), right(NULL) {}
};

Node *root;
bool failed = false;

bool bfs(vector<int> &ans) {
  queue<Node *> q;
  q.push(root);
  while (!q.empty()) {
    Node *curRoot = q.front();
    q.pop();
    // cout << "!" << curRoot->v << endl;
    if (!curRoot->have_value) {
      // cout << "failed";
      return true;
    } else {
      ans.push_back(curRoot->v);
    }

    if (curRoot->left)
      q.push(curRoot->left);
    if (curRoot->right)
      q.push(curRoot->right);
  }

  return false;
}

int main(int argc, char *argv[]) {
  while (!cin.eof()) {
    string s;
    root = new Node();
    failed = false;
    while (cin >> s && s != "()") {
      int commaPos = s.find(',', 1);
      int v = atoi(s.substr(1, commaPos - 1).c_str());
      Node *curRoot = root;
      for (int i = commaPos + 1; i < s.length() - 1; i++) {
        // cout << s[i] << '|';
        if (s[i] == 'L') {
          if (curRoot->left == NULL) {
            curRoot->left = new Node();
          }
          curRoot = curRoot->left;
        } else if (s[i] == 'R') {
          if (curRoot->right == NULL) {
            curRoot->right = new Node();
          }
          curRoot = curRoot->right;
        }
      }

      if (curRoot->have_value) {
        failed = true;
      } else {
        curRoot->have_value = true;
        curRoot->v = v;
      }
      // cout << '?' << v << endl;
    }
    if (cin.eof())
      break;

    vector<int> ans;
    // cout << ">> 1" << endl;
    bool failed2 = bfs(ans);
    if (failed || failed2) {
      // cout << ">> 2" << endl;
      cout << "not complete" << endl;
    } else {
      // cout << ">> 3 " << failed << endl;
      for (int i = 0; i < ans.size(); i++) {
        if (i != 0)
          cout << ' ';
        cout << ans[i];
      }
      cout << endl;
    }
    // cout << "----------------" << endl;
  }
  return 0;
}
