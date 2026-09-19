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
  int q;
  cin >> q;
  vector<vector<int>> p(2, vector<int>(n));
  cin >> p[0];
  rep(i, 0, n) { p[1][p[0][i] - 1] = i + 1; }
  bool first = true;
  rep(i, 0, q) {
    int j;
    cin >> j;
    if (j == 1) {
      int x, y;
      cin >> x >> y;
      if (first) {
        swap(p[1][p[0][x - 1] - 1], p[1][p[0][y - 1] - 1]);
        swap(p[0][x - 1], p[0][y - 1]);
      } else {
        swap(p[0][p[1][x - 1] - 1], p[0][p[1][y - 1] - 1]);
        swap(p[1][x - 1], p[1][y - 1]);
      }
    } else {
      first = !first;
    }
  }
  if (first) {
    cout << p[0] << nline;
    return;
  } else {
    cout << p[1] << nline;
    return;
  }
}

int main() {
  fastio();
  cout << fixed << setprecision(10); // Standardize floating point precision
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
