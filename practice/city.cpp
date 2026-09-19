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

// vector IO
template <typename T> istream &operator>>(istream &in, vector<T> &v) {
  for (auto &x : v)
    in >> x;
  return in;
}
template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) {
  for (int i = 0; i < sz(v); ++i)
    out << v[i] << (i == sz(v) - 1 ? "" : " ");
  return out;
}
void solve() {
  int n;
  cin >> n;
  vector<ll> h(n);
  for (auto &x : h)
    cin >> x;
  vector<ll> H(n);
  for (int i = 1; i < n - 1; i++) {
    ll newH = max(h[i - 1], h[i + 1]);
    H[i] = max(h[i], newH + 1);
  }
  ll res = 0;
  for (int i = 1; i < n - 1; i += 2) {
    res += H[i] - h[i];
  }
  if (n % 2 == 0) {
    vector<ll> pref(n);
    vector<ll> suf(n);
    for (int i = 1; i < n - 1; i++) {
      if (i == 1) {
        pref[i] = H[i] - h[i];
      } else {
        pref[i] = (i % 2) ? H[i] - h[i] + pref[i - 1] : pref[i - 1];
      }
    }
    for (int i = n - 2; i > 0; i--) {
      if (i == n - 2) {
        suf[i] = H[i] - h[i];
      } else {
        suf[i] = (i % 2) ? suf[i + 1] : suf[i + 1] + H[i] - h[i];
      }
    }
    for (int i = 1; i < n - 1; i += 2) {
      res = min(res, pref[i - 1] + suf[i + 1]);
    }
  }
  cout << res << nline;
  return;
}

int main() {
  fastio();
  cout << fixed << setprecision(10); // Standardize floating point precision
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
