#include <iostream>
#include <map>
#include <queue>

using namespace std;

int N;

int main(int argc, char *argv[]) {
  int cnt = 0;
  while (cin >> N && N) {
    queue<int> teamq;
    vector<queue<int>> memberqs;
    map<int, int> teamCache;
    for (int i = 0; i < N; i++) {
      int cnt;
      cin >> cnt;
      memberqs.push_back(queue<int>());

      while (cnt--) {
        int teamate;
        cin >> teamate;
        teamCache[teamate] = i;
      }
    }

    cout << "Scenario #" << ++cnt << endl;
    string op;
    while (cin >> op && op != "STOP") {
      if (op[0] == 'E') {
        int teamate;
        cin >> teamate;
        int memberQueueId = teamCache[teamate];
        if (memberqs[memberQueueId].size() == 0) {
          teamq.push(memberQueueId);
        }
        memberqs[memberQueueId].push(teamate);
        // cout << "enqueue " << teamate << " " << memberQueueId << endl;
      } else {
        int memberQueueID = teamq.front();
        cout << memberqs[memberQueueID].front() << endl;
        // cout << memberqs[memberQueueID].front() << "memberQueueID "
        //      << memberQueueID << endl;
        memberqs[memberQueueID].pop();

        if (memberqs[memberQueueID].size() == 0) {
          teamq.pop();
        }
      }
    }
    cout << endl;
  }

  return 0;
}
