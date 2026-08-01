#include <bits/stdc++.h>
using namespace std;

#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
#define ll long long
#define nline "\n"

void solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto &x : a)
    cin >> x;

  map<ll, int> freq;
  map<int, set<ll>> inv_freq;

  for (int i = 0; i < n; i++) {
    int old_f = freq[a[i]];
    if (old_f > 0) {
      inv_freq[old_f].erase(a[i]);
      if (inv_freq[old_f].empty()) {
        inv_freq.erase(old_f);
      }
    }
    freq[a[i]]++;
    inv_freq[freq[a[i]]].insert(a[i]);

    if (i >= k) {
      ll drop_val = a[i - k];
      int current_f = freq[drop_val];

      inv_freq[current_f].erase(drop_val);
      if (inv_freq[current_f].empty()) {
        inv_freq.erase(current_f);
      }

      freq[drop_val]--;
      if (freq[drop_val] > 0) {
        inv_freq[freq[drop_val]].insert(drop_val);
      } else {
        freq.erase(drop_val);
      }
    }

    if (i >= k - 1) {
      auto mode = inv_freq.rbegin();
      auto &m = mode->second;
      cout << *m.begin() << " ";
    }
  }
  cout << nline;
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
