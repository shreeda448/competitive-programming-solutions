#include <algorithm>
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

int front(string s, int k) {
  int n = s.length();
  int bal = 0, best = 0, cnt = 0;
  for (char c : s) {
    if (c == '(') {
      bal++;
    } else {
      if (cnt == k)
        break;
      cnt++;
      bal--;
    }
    best = max(best, bal);
  }
  return min(best + k, (n / 2));
}

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> c(n + 1);
  vector<int> bal(n + 1);
  for (int i = 0; i < n; i++) {
    c[i + 1] = c[i] + (s[i] == ')');
    bal[i + 1] = (i + 1 - 2 * c[i + 1]);
  }
  int val = 0;
  int lo = 0;
  for (int r = 1; r <= n; r++) {
    while (c[r] - c[lo] > k)
      lo++;
    int mn = INT_MAX;
    for (int m = lo; m < r; m++) {
      mn = min(mn, bal[m]);
    }
    val = max(val, bal[r] - mn);
  }
  cout << max(val, front(s, k)) << nline;
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
