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
  int n;
  cin >> n;
  int q;
  cin >> q;
  vector<int> a(n);
  cin >> a;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] % 3 == 0 || a[i] % 5 == 0) {
      cnt++;
    }
  }
  cout << cnt << " ";
  while (q--) {
    int p, x;
    cin >> p >> x;
    if (a[p - 1] % 3 == 0 || a[p - 1] % 5 == 0) {
      if (x % 3 == 0 || x % 5 == 0) {
        cout << cnt << " ";
      } else {
        cnt--;
        cout << cnt << " ";
      }
    } else {
      if (x % 3 == 0 || x % 5 == 0) {
        ++cnt;
        cout << cnt << " ";
      } else {
        cout << cnt << " ";
      }
    }
    a[p - 1] = x;
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
