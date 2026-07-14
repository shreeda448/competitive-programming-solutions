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
  vector<pair<int, int>> ab(n);
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ab[a[i] - 1].first = i + 1;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    ab[b[i] - 1].second = i + 1;
  }
  sort(ab.begin(), ab.end());
  vector<int> prefix_max(n);
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      prefix_max[i] = ab[i].second;
    } else {
      prefix_max[i] = max(prefix_max[i - 1], ab[i].second);
    }
  }
  vector<bool> fined(n, false);
  ll ans = 0;
  for (int i = n - 1; i > 0; i--) {
    if (ab[i].second < prefix_max[i - 1] && !fined[i]) {
      fined[i] = true;
      ans++;
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
