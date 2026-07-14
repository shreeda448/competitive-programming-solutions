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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a)
    cin >> x;
  int maxLen = 0;
  map<int, vector<vector<int>>> groups;
  for (int i = 0; i < n; i++) {
    int cur = a[i];
    int len = 1;
    int idx = i;
    for (int j = i + 1; j < n; j++) {
      if (a[j] == cur + j - i) {
        len++;
        idx = j;
      } else {
        break;
      }
      // cout << "i = " << i << " j = " << j << " a[j] = " << a[j]
      //      << " len = " << len << nline;
    }
    vector<int> temp = {i, idx, cur};
    groups[len].pb(temp);
    maxLen = max(maxLen, len / 2);
  }
  for (auto &[key, val] : groups) {
    for (int i = 0; i < val.size(); i++) {
      for (int j = 0; j < val.size(); j++) {
        if (val[i][1] < val[j][0] || val[i][0] > val[j][1]) {
          if (val[i][2] < val[j][2]) {
            if (val[i][2] + key - 1 == val[j][2]) {
              maxLen = max(maxLen, key);
            }
          } else if (val[i][2] > val[j][2]) {
            if (val[j][2] + key - 1 == val[i][2]) {
              maxLen = max(maxLen, key);
            }
          }
        }
      }
    }
  }
  cout << maxLen << nline;
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
