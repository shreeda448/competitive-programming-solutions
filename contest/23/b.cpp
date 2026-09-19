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
  vector<int> a(n);
  cin >> a;
  vector<int> c;
  vector<int> s;
  rep(i, 0, n) {
    if (c.empty() || a[i] != c.back()) {
      c.pb(a[i]);
      s.pb(1);
    } else {
      s.back()++;
    }
  }
  int c_sz = sz(c);
  bool ok = false;
  rep(i, 0, c_sz - 1) {
    if (s[i] >= 2 && s[i + 1] >= 2) {
      ok = true;
      break;
    }
  }
  if (ok) {
    cout << c_sz + 2 << nline;
    return;
  }
  ok = false;
  rep(i, 0, c_sz) {
    if (s[i] >= 2) {
      bool r_ok = false;
      bool l_ok = false;
      if ((i < c_sz - 1) && (i + 1 == c_sz - 1 || c[i] != c[i + 2])) {
        r_ok = true;
      }
      if ((i > 0) && (i == 1 || c[i] != c[i - 2])) {
        l_ok = true;
      }
      if (r_ok || l_ok) {
        ok = true;
        break;
      }
    }
  }
  if (ok) {
    cout << c_sz + 1 << nline;
    return;
  }
  cout << c_sz << nline;
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
