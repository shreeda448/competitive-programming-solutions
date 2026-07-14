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

ll n, k;

const int INF = 1e9 + 7;

bool isValid(ll num) { return num >= 1 && num <= k; }

void solve() {
  cin >> n >> k;
  ll ans = INF;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      vector<ll> valid_numbers;
      valid_numbers.push_back(ans);
      if (isValid(i)) {
        valid_numbers.push_back(n / i);
      }
      if (isValid(n / i)) {
        valid_numbers.push_back(i);
      }
      ans = *min_element(valid_numbers.begin(), valid_numbers.end());
    }
  }
  cout << ans << nline;
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
