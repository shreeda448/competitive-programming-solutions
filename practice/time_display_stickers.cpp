#include <bits/stdc++.h>
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
  int low = 0, high = (n / 3);
  int ans = 0;
  int zero = 0, one = 0, five = 0, nine = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      zero++;
    }
    if (s[i] == '1') {
      one++;
    }
    if (s[i] - '0' <= 5) {
      five++;
    }
    if (s[i] - '0' <= 9) {
      nine++;
    }
  }
  while (low <= high) {
    int mid = (high - low) / 2 + low;
    bool possible = false;
    for (int x = 0; x <= mid; x++) {
      int z1 = zero, o1 = one, f1 = five, n1 = nine;
      int y = mid - x;
      if (z1 < x) {
        continue;
      } else {
        z1 -= x;
        f1 -= x;
        n1 -= x;
      }
      if (o1 < y) {
        continue;
      } else {
        o1 -= y;
        f1 -= y;
        n1 -= y;
      }
      if (z1 + o1 < y) {
        continue;
      } else {
        f1 -= y;
        n1 -= y;
      }
      if (f1 < x + y) {
        continue;
      } else {
        f1 -= x + y;
        n1 -= (x + y);
      }
      if (n1 < 2 * x + y) {
        continue;
      } else {
        n1 -= 2 * x + y;
      }
      possible = true;
    }
    if (possible) {
      ans = max(ans, mid);
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  cout << ans << nline;
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
