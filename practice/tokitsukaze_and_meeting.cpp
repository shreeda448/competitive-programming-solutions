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

void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int start = -1;
  int cnt = 0;
  vector<bool> curgrp(m);
  vector<int> pref(n * m + 1);
  for (int i = 1; i <= n * m; i++) {
    pref[i] = pref[i - 1] + (s[i - 1] == '1');
  }
  int col = 0;
  cnt = 0;
  vector<int> r(n * m + 1);
  for (int i = 1; i <= n * m; ++i) {
    int ans = 0;
    int curMod = (i % m);
    if (s[i - 1] == '1') {
      if (!curgrp[curMod])
        col++;
      curgrp[curMod] = true;
    }
    int row = 0;
    if (i - m > 0) {
      row += r[i - m];
      r[i] = r[i - m];
    }
    int val = pref[i];
    if (i - m >= 0) {
      val -= pref[i - m];
    }
    val = (val == 0 ? 0 : 1);
    row += val;
    r[i] += val;
    ans = row + col;
    cout << ans << " ";
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
