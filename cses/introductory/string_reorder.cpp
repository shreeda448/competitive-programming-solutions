#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
#define ll long long
#define pb push_back
#define mp make_pair

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  vector<int> freq(26);
  for (char c : s) {
    freq[c - 'A']++;
  }
  string answer;
  while ((int)answer.length() < n) {
    bool anything = false;
    for (int i = 0; i < 26; i++) {
      if (freq[i] > 0 && (answer.empty() || answer.back() != ('A' + i))) {
        freq[i]--;
        answer += ('A' + i);
        int suffix = n - answer.length();
        bool can_finish = true;
        for (int j = 0; j < 26; j++) {
          if (i != j) {
            if (freq[j] > (suffix + 1) / 2) {
              can_finish = false;
              break;
            }
          } else {
            if (freq[j] > suffix / 2) {
              can_finish = false;
              break;
            }
          }
        }
        if (can_finish) {
          anything = true;
          break;
        } else {
          freq[i]++;
          answer.pop_back();
        }
      }
    }
    if (!anything) {
      break;
    }
  }
  if (answer.empty()) {
    cout << -1 << "\n";
    return;
  }
  cout << answer << "\n";
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
