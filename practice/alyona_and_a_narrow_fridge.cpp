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
  ll h;
  cin >> n >> h;
  vector<ll> a(n);
  for (auto &x : a)
    cin >> x;
  ll ans = 0;
  ll low = 1;
  ll high = n;

  while (low <= high) {
    ll mid = (low + high) / 2;

    vector<ll> temp(a.begin(), a.begin() + mid);

    sort(temp.rbegin(), temp.rend());

    ll required_height = 0;
    for (int i = 0; i < mid; i += 2) {
      required_height += temp[i];
    }

    if (required_height <= h) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
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
