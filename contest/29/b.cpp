#include <bits/stdc++.h>
#include <climits>
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

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  cin >> a;
  if (n == 1) {
    cout << "yes" << nline;
    cout << 1 << " " << 1 << nline;
    return;
  }
  int cnt = 0;
  vector<int> in;
  bool inc = true;
  for (int i = 0; i < n - 1; i++) {
    if ((a[i] > a[i + 1]) && inc) {
      cnt++;
      in.pb(i);
      inc = false;
    }
    if (a[i] < a[i + 1] && !inc) {
      in.pb(i);
      inc = true;
    }
  }
  if (cnt > 2) {
    cout << "no" << nline;
    return;
  }
  if (cnt == 0) {
    cout << "yes" << nline;
    cout << 1 << " " << 1 << nline;
    return;
  }
  if (cnt == 1 && in.size() == 1) {
    in.pb(n - 1);
  }
  for (int i = in[0]; i <= (in[1] + in[0]) / 2; i++) {
    swap(a[i], a[in[1] + in[0] - i]);
  }
  bool ok = true;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] > a[i + 1]) {
      ok = false;
      break;
    }
  }
  if (ok) {
    cout << "yes" << nline;
    for (auto x : in) {
      cout << x + 1 << " ";
    }
    cout << nline;
    return;
  }
  cout << "no" << nline;
  return;
}

int main() {
  fastio();
  cout << fixed << setprecision(10);

  int t = 1;
  while (t--) {
    solve();
  }

  return 0;
}
