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
  string s;
  cin >> s;
  vector<int> inv(n);
  vector<int> ze(n);
  int z = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '0') {
      z++;
      if (i == n - 1) {
        ze[i] = 1;
      } else {
        ze[i] = 1 + ze[i + 1];
        inv[i] = inv[i + 1];
      }
    } else {
      if (i != n - 1) {
        ze[i] = ze[i + 1];
        inv[i] = inv[i + 1] + z;
      }
    }
  }
  if (inv[0] & 1) {
    cout << "Alice" << nline;
    return;
  }
  for (int i = 0; i < n - 1; i++) {
    int invR = inv[i + 1];
    int c = (i + 1 - ze[0] - ze[i + 1]) * (ze[i + 1]);
    int invL = inv[0] - invR - c;
    if (invL % 2 != invR % 2) {
      cout << "Alice" << nline;
      return;
    }
  }
  cout << "Bob" << nline;
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
