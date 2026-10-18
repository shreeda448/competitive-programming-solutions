#include <bits/stdc++.h>
#include <map>
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
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (auto &y : a)
    cin >> y;
  vector<int> g(n);
  for (int i = 0; i < n; i++) {
    g[i] = gcd(a[i], x);
  }
  map<int, ll> mp;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j * j <= g[i]; j++) {
      if (g[i] % j == 0) {
        if (j != 1)
          mp[j] += 1LL * a[i];
        if (g[i] / j != 1)
          mp[g[i] / j] += 1LL * a[i];
        if (j * j == g[i]) {
          mp[j] -= a[i];
        }
      }
    }
  }
  ll mx = 0;
  for (auto &[k, v] : mp) {
    mx = max(mx, v);
  }
  cout << mx << nline;
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
