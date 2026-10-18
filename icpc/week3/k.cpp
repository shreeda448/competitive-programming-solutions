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
  string s;
  cin >> s;
  ll len = s.length();
  int n = len / 2;
  vector<ll> f(26);
  for (ll i = 0; i < len; i++) {
    f[s[i] - 'a']++;
  }
  ll uniq = 0;
  ll mx = 0;
  char c;
  for (ll i = 0; i < 26; i++) {
    if (f[i] > 0) {
      uniq++;
      if (mx < f[i]) {
        c = i + 'a';
      }
      mx = max(mx, f[i]);
    }
  }
  if (uniq == 1) {
    cout << "NO" << nline;
    return;
  }
  if (uniq >= 2 && mx <= n) {
    cy;
    string res = "";
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < f[i]; j++) {
        res += 'a' + i;
      }
    }
    cout << res << nline;
    return;
  }
  if (uniq == 2 && mx >= len - 2) {
    cn;
    return;
  }
  cy;
  string res = "";
  for (ll i = 0; i < n; i++) {
    res += c;
  }
  for (ll i = 0; i < 26; i++) {
    if (f[i] == mx || f[i] == 0) {
      continue;
    } else {
      res += 'a' + i;
      f[i]--;
      break;
    }
  }
  for (ll i = 0; i < mx - n; i++) {
    res += c;
  }
  for (ll i = 0; i < 26; i++) {
    if (f[i] == mx || f[i] == 0) {
      continue;
    } else {
      for (ll j = 0; j < f[i]; j++) {
        res += 'a' + i;
      }
    }
  }
  cout << res << nline;
  return;
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
