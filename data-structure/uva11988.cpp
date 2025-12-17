#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 100000 + 5

char s[MAXN];
// point of list's next node
int next[MAXN];

int main(int argc, char *argv[]) {
  while (scanf("%s", s + 1) == 1) {
    // cur -> scan cursor
    // last -> current scan cursor end
    int cur, last;
    cur = last = 0;
    next[cur] = 0;

    // s[0] is virtual node
    size_t n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
      char ch = s[i];

      if (ch == '[') {
        cur = 0;
      } else if (ch == ']') {
        cur = last;
      } else {
        next[i] = next[cur];
        next[cur] = i;
        if (cur == last)
          last = i;

        // move cursor to current char
        cur = i;
      }
    }

    for (int i = next[0]; i != 0; i = next[i]) {
      printf("%c", s[i]);
    }
    printf("\n");
  }

  return 0;
}
