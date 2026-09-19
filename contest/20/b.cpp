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
  ll c;
  cin >> c;
  vector<ll> a(n);
  for (auto &x : a)
    cin >> x;
  ll score = 0;
  sort(a.begin(), a.end());
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] < c && cnt < (n / 2)) {
      cnt++;
    } else if ((a[i] < c && cnt >= (n / 2)) || a[i] >= c) {
      score += a[i] - c;
    }
  }
  cout << score << nline;
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
