#include <bits/stdc++.h>
#include <vector>
using namespace std;

// fast i/o
#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

// type aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;

// constants
const int mod = 1e9 + 7;
const ll inf = 1e18;

// macros
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define nline "\n"
#define cy cout << "yes\n"
#define cn cout << "no\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)

// typedefs
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

// vector io
template <typename t> istream &operator>>(istream &in, vector<t> &v) {
  for (auto &x : v)
    in >> x;
  return in;
}
template <typename t> ostream &operator<<(ostream &out, const vector<t> &v) {
  for (int i = 0; i < sz(v); ++i)
    out << v[i] << (i == sz(v) - 1 ? "" : " ");
  return out;
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int num = (n * m) / k;
  vector<int> freq(k, num);
  int cur = 1;
  vector<vector<int>> grid(n, vector<int>(m));
  for (int i = 0; i < n + m - 1; i += 2) {
    for (int row = 0; row < n; row++) {
      int col = i - row;
      if (col >= 0 && col < m && cur <= k && freq[cur - 1] > 0) {
        grid[row][col] = cur;
        freq[cur - 1]--;
        if (freq[cur - 1] == 0) {
          cur++;
        }
      }
    }
  }
  for (int i = 1; i < n + m - 1; i += 2) {
    for (int row = 0; row < n; row++) {
      int col = i - row;
      if (col >= 0 && col < m && cur <= k && freq[cur - 1] > 0) {
        grid[row][col] = cur;
        freq[cur - 1]--;
        if (freq[cur - 1] == 0) {
          cur++;
        }
      }
    }
  }
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < m; col++) {
      cout << grid[row][col] << " ";
    }
    cout << nline;
  }
}

int main() {
  fastio();
  cout << fixed << setprecision(10); // standardize floating point precision
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
