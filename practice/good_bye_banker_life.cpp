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

// Vector IO
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

int po2(int n) {
  int res = 1;
  while (res * 2 <= n) {
    res *= 2;
  }
  return res;
}

vector<ll> f(int n, ll k) {
  if (n == 1) {
    return {k};
  }
  if (n == 2) {
    return {k, k};
  }
  vector<ll> res(n);
  int p = po2(n);
  int q = n - p;
  if (q == 0) {
    return vector<ll>(n, k);
  }
  vector<ll> r = f(q, k);
  int g = (int)r.size();
  for (int i = 0; i < g; i++) {
    res[i] = r[i];
  }
  int j = 1;
  while (j <= g) {
    res[n - j] = r[g - j];
    j++;
  }
  return res;
}

void solve() {
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> res = f(n, k);
  for (auto x : res) {
    cout << x << " ";
  }
  cout << nline;
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
