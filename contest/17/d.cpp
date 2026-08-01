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

const long long MOD = 998244353;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n - 1);
  for (auto &x : a)
    cin >> x;
  vector<pair<int, int>> blocks;
  for (int i = 0; i < n - 1; i++) {
    if (blocks.empty() || blocks.back().first != a[i]) {
      blocks.pb({a[i], 1});
    } else {
      blocks.back().second++;
    }
  }
  int mx = 0;
  int peak = -1;
  for (int i = 0; i < (int)blocks.size(); i++) {
    if (blocks[i].first > mx) {
      mx = blocks[i].first;
      peak = i;
    }
  }
  if (mx != n - 1) {
    cout << 0 << nline;
    return;
  }
  bool possible = true;
  for (int i = peak; i < (int)blocks.size() - 1; i++) {
    if (blocks[i].first <= blocks[i + 1].first) {
      possible = false;
    }
  }
  for (int i = 0; i < peak; i++) {
    if (blocks[i].first >= blocks[i + 1].first) {
      possible = false;
    }
  }
  if (!possible) {
    cout << 0 << nline;
    return;
  }
  vector<int> freq(n);
  for (auto b : blocks) {
    freq[b.first] = b.second;
  }
  ll ans = 2;
  ll places = freq[n - 1] - 1;
  for (int i = n - 2; i >= 1; i--) {
    if (freq[i] > 0) {
      places += (freq[i] - 1);
    } else {
      if (places <= 0) {
        ans = 0;
        break;
      }
      ans = (ans * places) % MOD;
      places--;
    }
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
