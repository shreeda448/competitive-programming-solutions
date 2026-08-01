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
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  map<ll, ll> present_right;
  map<ll, ll> present_left;
  for (auto &x : a) {
    cin >> x;
    present_right[x]++;
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll x = a[i];
    present_right[x]--;
    if (x % k == 0) {
      ll left_el = x / k;
      ll right_el = x * k;
      ans += present_left[left_el] * present_right[right_el];
    }
    present_left[x]++;
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
