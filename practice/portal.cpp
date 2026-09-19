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
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> p(n + 2);
  for (int i = 0; i < n + 2; i++) {
    if (i == x || i == y + 1) {
      continue;
    }
    cin >> p[i];
  }
  vector<int> res(n + 2);
  int mn = n + 1;
  int idx = -1;
  for (int i = x + 1; i < y + 1; i++) {
    if (mn > p[i]) {
      idx = i;
    }
    mn = min(mn, p[i]);
  }
  rotate(p.begin() + x + 1, p.begin() + idx, p.begin() + y + 1);
  if (p[0] > mn) {
    for (int i = x + 1; i < y + 1; i++) {
      cout << p[i] << " ";
    }
    for (int i = 0; i < x; i++) {
      cout << p[i] << " ";
    }
    for (int i = y + 2; i < n + 2; i++) {
      cout << p[i] << " ";
    }
  } else {
    int idx1 = -1;
    bool first = false;
    for (int i = 0; i < x; i++) {
      if (p[i] > mn) {
        idx1 = i;
        first = true;
        break;
      } else {
        cout << p[i] << " ";
      }
    }
    if (idx1 == -1) {
      for (int i = y + 2; i < n + 2; i++) {
        if (p[i] > mn) {
          idx1 = i;
          break;
        } else {
          cout << p[i] << " ";
        }
      }
    }
    for (int i = x + 1; i < y + 1; i++) {
      cout << p[i] << " ";
    }
    if (idx1 != -1) {
      if (first) {
        for (int i = idx1; i < x; i++) {
          cout << p[i] << " ";
        }
        for (int i = y + 2; i < n + 2; i++) {
          cout << p[i] << " ";
        }
      } else {
        for (int i = idx1; i < n + 2; i++) {
          cout << p[i] << " ";
        }
      }
    }
  }
  cout << nline;
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
