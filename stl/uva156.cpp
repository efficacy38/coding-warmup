#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
map<string, int> cnt;
vector<string> words;

string repr(string &s) {
  string ans = s;
  for (int i = 0; i < s.length(); i++) {
    ans[i] = tolower(ans[i]);
  }

  sort(ans.begin(), ans.end());

  return ans;
}

int main(int argc, char *argv[]) {

  string s;
  while (cin >> s) {
    if (s[0] == '#')
      break;
    words.push_back(s);
    string r = repr(s);
    if (!cnt.count(r)) {
      cnt[r] = 0;
    }
    cnt[r]++;
  }

  vector<string> ans;
  for (auto s : words) {
    if (cnt[repr(s)] == 1) {
      ans.push_back(s);
    }
  }

  sort(ans.begin(), ans.end());

  for (auto s : ans) {
    cout << s << endl;
  }

  return 0;
}
