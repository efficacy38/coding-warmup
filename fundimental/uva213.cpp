#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

// no 111 so 0 - 6, 8 is the max length
#define MAXLEN 8
int code[MAXLEN][1 << MAXLEN];

char readchar() {
  for (;;) {
    char c = getchar();
    if (c != '\n' && c != '\r') {
      return c;
    }
  }
}

bool readcodes() {
  memset(code, 0, sizeof(code));
  code[1][0] = readchar();

  for (int len = 2; len < MAXLEN; len++) {
    for (int i = 0; i < (1 << len) - 1; i++) {
      char ch = getchar();
      if (ch == EOF)
        return 0;
      if (ch == '\n' || ch == '\r')
        return 1;

      code[len][i] = ch;
    }
  }

  return 1;
}

int readint(int len) {
  int v = 0;
  while (len--) {
    char c = readchar();
    v = v * 2 + (c - '0');
  }

  return v;
}

int printcode() {
  for (int len = 1; len < MAXLEN; len++) {
    for (int j = 0; j < (1 << len) - 1; j++) {
      if (code[len][j] == 0)
        return 0;
      printf("code[%d][%d] = %c\n", len, j, code[len][j]);
    }
  }
  return 1;
}

int main(int argc, char *argv[]) {

  // 1. generate table, read codes
  while (readcodes()) {

    // printcode();
    // 2. get the len, print value directly
    for (;;) {
      int len = readint(3);
      // printf("\n -- %d --\n", len);
      if (len == 0)
        break;

      for (;;) {
        int v = readint(len);
        // printf("v: %d\n", v);
        if (v == (1 << len) - 1)
          break;
        // print decoded value
        putchar(code[len][v]);
      }
    }

    putchar('\n');
  }

  return 0;
}
