#include <algorithm>
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
#define nline "\n"

const int INF = 1e9 + 7;

void solve() {
  string s, t;
  cin >> s >> t;
  int n = s.length();
  int m = t.length();
  vector<vector<int>> occur(26);
  for (int i = 0; i < n; i++) {
    occur[s[i] - 'A'].push_back(i);
  }
  vector<int> idx(26, -1);
  for (int i = 0; i < 26; i++) {
    idx[i] = occur[i].size() - 1;
  }
  int min_idx = INF;
  for (int i = m - 1; i >= 0; i--) {
    int curCharIdx = t[i] - 'A';
    if (idx[curCharIdx] < 0) {
      cout << "NO" << nline;
      return;
    }
    int cur = occur[curCharIdx][idx[curCharIdx]];
    if (cur > min_idx) {
      cout << "NO" << nline;
      return;
    }
    min_idx = min(min_idx, cur);
    idx[curCharIdx]--;
  }
  cout << "YES" << nline;
  return;
}

int main() {
  fastio();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
