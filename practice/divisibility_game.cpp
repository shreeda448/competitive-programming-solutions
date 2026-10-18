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
  vector<int> a(n);
  for (auto &x : a)
    cin >> x;
  vector<int> b(m);
  for (auto &x : b)
    cin >> x;
  int alice = 0, bob = 0, aorb = 0;
  map<int, int> fr;
  for (int i = 0; i < n; i++) {
    for (int j = a[i]; j <= n + m; j += a[i]) {
      fr[j]++;
    }
  }
  for (int i = 0; i < m; i++) {
    auto it = fr.find(b[i]);
    if (it == fr.end()) {
      bob++;
    } else {
      int q = n - it->second;
      if (q == 0) {
        alice++;
      } else {
        aorb++;
      }
    }
  }
  if (alice > bob) {
    aorb -= alice - bob;
    if (aorb < 0) {
      cout << "Alice" << nline;
      return;
    }
    bob = alice;
  } else {
    aorb -= bob - alice;
    if (aorb < 0) {
      cout << "Bob" << nline;
      return;
    }
  }
  if (aorb & 1) {
    cout << "Alice" << nline;
    return;
  } else {
    cout << "Bob" << nline;
    return;
  }
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
