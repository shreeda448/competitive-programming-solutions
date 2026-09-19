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
  if (n == 1 && s[0] == '0') {
    cout << -1 << nline;
    return;
  }
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == 0 && s[i + 1] == 0) {
      cout << -1 << nline;
      return;
    }
  }
  vector<int> val(n);
  int cur = (s[0] == '+') ? 1 : (s[0] == '0' ? 0 : -1);
  map<char, int> mp;
  mp['+'] = 0;
  mp['0'] = 1;
  mp['-'] = 2;
  int curst = (s[0] == '+') ? 0 : (s[0] == '0' ? 1 : 2);
  for (int i = 0; i < n; i++) {
    int p = mp[s[i]];
    if (curst == mp[s[i]]) {
      val[i] = cur;
      if (p == 0) {
        cur++;
      } else if (p == 1) {
        cur = 0;
      } else {
        --cur;
      }
    } else {
      curst = p;
      if (p == 0) {
        val[i] = 1;
        cur = 2;
      } else if (p == 1) {
        val[i] = 0;
        cur = 0;
      } else {
        val[i] = -1;
        cur = -2;
      }
    }
  }
  int mx = val[0];
  for (int i = 1; i < n; i++) {
    mx = max(mx, abs(val[i] - val[i - 1]));
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
