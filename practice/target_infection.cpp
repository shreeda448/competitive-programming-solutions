#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Fast I/O
#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

// Type Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;

// Constants
const int MOD = 1e9 + 7;
const ll INF = 1e18;

// Macros
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define nline "\n"
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)

// Typedefs
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) {
  for (int i = 0; i < sz(v); ++i)
    out << v[i] << (i == sz(v) - 1 ? "" : " ");
  return out;
}

ll f(ll s, ll m, vector<ll> &r, vector<ll> &l, vector<ll> &pref) {
  long long e = s + m - 1;
  int i = lower_bound(r.begin(), r.end(), s) - r.begin();
  int j = upper_bound(l.begin(), l.end(), e) - l.begin() - 1;
  if (i > j)
    return 0;
  long long ans = pref[j + 1] - pref[i];
  ans -= max(0LL, s - l[i]);
  ans -= max(0LL, r[j] - e);
  return ans;
}

void solve() {
  int n;
  ll m, k;
  cin >> n >> m >> k;
  vector<ll> l(n), r(n), pref(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
    pref[i + 1] = pref[i] + r[i] - l[i] + 1;
  }
  long long mx = -1, pos = 0;
  for (int i = 0; i < n; i++) {
    ll cur = f(l[i], m, r, l, pref);
    if (cur > mx) {
      mx = cur;
      pos = l[i];
    }
  }
  if (k > mx) {
    cout << -1 << '\n';
    return;
  }
  if (k == mx) {
    cout << pos << '\n';
    return;
  }
  ll low = pos;
  ll high = r.back() + 1;
  while (high - low > 1) {
    ll mid = low + (high - low) / 2;
    if (f(mid, m, r, l, pref) > k)
      low = mid;
    else
      high = mid;
  }
  cout << high << nline;
  return;
}

int main() {
  fastio();
  cout << fixed << setprecision(10);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
