#include <iostream>
#include <vector>

using namespace std;

#define MAXN 25 + 5
vector<int> piles[MAXN];
int n;

int find_block(int v, int &pile, int &height) {
  for (int p = 0; p < n; p++) {
    for (int h = 0; h < piles[p].size(); h++) {
      if (v == piles[p][h]) {
        pile = p;
        height = h;
        return 0;
      }
    }
  }

  return -1;
}

void clear_above(int p, int h) {
  for (int i = h + 1; i < piles[p].size(); i++) {
    int b = piles[p][i];
    piles[b].push_back(b);
  }

  piles[p].resize(h + 1);
}

void pile_onto(int pa, int ha, int pb) {
  for (int i = ha; i < piles[pa].size(); i++) {
    piles[pb].push_back(piles[pa][i]);
  }

  piles[pa].resize(ha);
}

void print_ans() {
  for (int i = 0; i < n; i++) {
    cout << i << ":";
    for (int j = 0; j < piles[i].size(); j++) {
      cout << " " << piles[i][j];
    }

    cout << endl;
  }
}

int main(int argc, char *argv[]) {
  cin >> n;
  string op1, op2;
  int a, b, pa, pb, ha, hb;
  for (int i = 0; i < n; i++)
    piles[i].push_back(i);

  while (cin >> op1) {
    if (op1 == "quit")
      break;
    cin >> a >> op2 >> b;

    // cout << op1 << ' ' << a << ' ' << op2 << ' ' << b << endl;
    find_block(a, pa, ha);
    find_block(b, pb, hb);

    if (pa == pb)
      continue;

    if (op1 == "move")
      clear_above(pa, ha);
    if (op2 == "onto")
      clear_above(pb, hb);

    pile_onto(pa, ha, pb);
    // print_ans();
  }

  print_ans();

  return 0;
}
