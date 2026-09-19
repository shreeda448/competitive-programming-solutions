#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <locale>
#include <numeric>
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
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  vector<ll> a(x);
  cin >> a;
  vector<ll> b(y);
  cin >> b;
  vector<ll> full;
  for (int i = 0; i < x; i++) {
    full.push_back(a[i]);
  }
  for (int i = 0; i < y; i++) {
    full.push_back(b[i]);
  }
  sort(rall(full));
  full.erase(unique(full.begin(), full.end()), full.end());
  ll ans = 0;
  ll c_col = 0;
  ll c_row = 0;
  ll tot = 0;
  for (auto g : full) {
    if (tot == n + m - 1) {
      break;
    }
    bool ok_a = binary_search(all(a), g);
    bool ok_b = binary_search(all(b), g);
    if (ok_a && ok_b) {
      ans += g;
      tot++;
    } else if (ok_a) {
      if (c_row < n) {
        ans += g;
        c_row++;
        tot++;
      }
    } else {
      if (c_col < m) {
        ans += g;
        c_col++;
        tot++;
      }
    }
  }
  cout << ans << nline;
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
