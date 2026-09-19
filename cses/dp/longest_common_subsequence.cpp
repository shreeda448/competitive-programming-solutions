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
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  vector<ll> b(m);
  cin >> a;
  cin >> b;
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  vector<vector<pair<int, int>>> par(n + 1, vector<pair<int, int>>(m + 1));
  auto maxi = [&](int i, int j, int i2, int j2, int cost) {
    if (dp[i][j] + cost > dp[i2][j2]) {
      dp[i2][j2] = dp[i][j] + cost;
      par[i2][j2] = {i, j};
    }
  };
  rep(i, 0, n + 1) {
    rep(j, 0, m + 1) {
      if (i != n && j != m) {
        maxi(i, j, i + 1, j + 1, a[i] == b[j]);
      }
      if (i != n) {
        maxi(i, j, i + 1, j, 0);
      }
      if (j != m) {
        maxi(i, j, i, j + 1, 0);
      }
    }
  }
  cout << dp[n][m] << nline;
  int x = n, y = m;
  vector<int> path;
  while (x > 0 || y > 0) {
    auto [i2, j2] = par[x][y];
    if (i2 + 1 == x && j2 + 1 == y && a[i2] == b[j2]) {
      path.push_back(a[i2]);
    }
    x = i2;
    y = j2;
  }
  reverse(path.begin(), path.end());
  for (int x : path) {
    cout << x << " ";
  }
  cout << nline;
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
