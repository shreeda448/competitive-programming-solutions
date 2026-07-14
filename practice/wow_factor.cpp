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
  string s;
  cin >> s;
  int n = s.length();
  vector<pair<int, int>> v_blocks;
  int cnt_o = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'v') {
      cnt++;
      if (i == n - 1) {
        v_blocks.push_back({n, cnt});
      }
    } else {
      cnt_o++;
      v_blocks.push_back({i, cnt});
      cnt = 0;
    }
  }
  cnt_o = s[n - 1] == 'v' ? cnt_o + 1 : cnt_o;
  if (cnt_o == 0 || v_blocks.empty()) {
    cout << 0 << "\n";
    return;
  }
  vector<ll> prefix_v(cnt_o);
  for (int i = 0; i < cnt_o; i++) {
    int w_pairs = max(0, v_blocks[i].second - 1);
    if (i == 0) {
      prefix_v[i] = w_pairs;
    } else {
      prefix_v[i] = prefix_v[i - 1] + w_pairs;
    }
  }
  ll ans = 0;
  int idx = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'o') {
      ll left = 0, right = 0;
      left = max(left, prefix_v[idx]);
      right = max(right, prefix_v.back() - prefix_v[idx]);
      ans += left * right;
      idx++;
    }
  }
  cout << ans << nline;
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
