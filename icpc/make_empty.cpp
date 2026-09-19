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
  vector<int> p(n);
  cin >> p;
  bool inc = false, dec = false;
  vector<int> in;
  vector<int> de;
  for (int i = 1; i <= n; i++) {
    if (i <= (n / 2)) {
      if (p[i - 1] <= (n / 2)) {
        inc = true;
        in.pb(p[i - 1]);
      } else {
        dec = true;
        de.pb(p[i - 1]);
      }
    } else {
      if (p[i - 1] > (n / 2)) {
        inc = true;
        in.pb(p[i - 1]);
      } else {
        dec = true;
        de.pb(p[i - 1]);
      }
    }
  }
  int cnt = 0;
  if (inc)
    cnt++;
  if (dec)
    cnt++;
  cout << cnt << nline;
  if (!in.empty()) {
    cout << (int)in.size() << " ";
  }
  for (int b : in) {
    cout << b << " ";
  }
  if (!in.empty())
    cout << nline;

  if (!de.empty()) {
    cout << (int)de.size() << " ";
  }
  for (int b : de) {
    cout << b << " ";
  }
  if (!de.empty())
    cout << nline;
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
