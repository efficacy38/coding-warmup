#include <cctype>
#include <iostream>
#include <set>
#include <sstream>
#include <string>

using namespace std;

set<string> dict;

int main(int argc, char *argv[]) {

  string s, buf;
  stringstream ss;

  while (cin >> s) {
    ss.clear();
    for (int i = 0; i < s.length(); i++) {
      if (!isalpha(s[i])) {
        s[i] = ' ';
      } else {
        s[i] = tolower(s[i]);
      }
    }

    ss.str(s);
    while (ss >> buf)
      dict.insert(buf);
  }

  for (auto s : dict) {
    cout << s << endl;
  }
}
