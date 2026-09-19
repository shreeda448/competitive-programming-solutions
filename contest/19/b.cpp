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
  string s;
  cin >> s;
  ll ans = 0;
  int min_freq = 3e5;
  int cnt = 0, cur = s[0];
  vector<int> ind;
  for (int i = 0; i < n; i++) {
    if (s[i] == cur) {
      cnt++;
    } else {
      if (i != 1) {
        min_freq = min(min_freq, cnt);
      }
      if (cnt == 1 && i != 1) {
        ind.push_back(i - 1);
      }
      cnt = 1;
      cur = s[i];
      ans++;
    }
  }
  if (cnt > 0) {
    ans++;
  }
  if (min_freq == 1) {
    ans--;
  }
  bool possible = false;
  for (auto i : ind) {
    if (s[i - 1] == s[i + 1]) {
      possible = true;
      break;
    }
  }
  if (possible) {
    ans--;
  }
  cout << ans << nline;
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
