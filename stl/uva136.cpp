#include <iostream>
#include <queue>
#include <set>
#define LL long long int
using namespace std;

int main(int argc, char *argv[]) {
  set<LL> s;
  int cnt = 1;
  std::priority_queue<LL, vector<LL>, greater<LL>> pq;
  pq.push(1);
  while (cnt != 1500) {
    LL front = pq.top();
    pq.pop();
    cnt++;
    int coff[3] = {2, 3, 5};
    for (int i = 0; i < 3; i++) {
      if (!s.count(front * coff[i])) {
        pq.push(front * coff[i]);
        s.insert(front * coff[i]);
      }
    }
  }

  cout << "The 1500'th ugly number is " << pq.top() << '.' << endl;
  return 0;
}
