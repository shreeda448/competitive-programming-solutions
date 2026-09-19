#include <bits/stdc++.h>
#include <unistd.h>
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
  vector<int> a(n);
  cin >> a;
  vector<int> b(n);
  cin >> b;
  for (int i = 0; i < n; i++) {
    a[i]--;
    b[i]--;
  }
  int firstIdx = -1, lastIdx = n;
  for (int i = 0; i < n; i++) {
    if (a[i] > b[i]) {
      cout << -1 << nline;
      return;
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      firstIdx = i;
      break;
    }
  }

  for (int i = n - 1; i >= 0; i--) {
    if (a[i] != b[i]) {
      lastIdx = i;
      break;
    }
  }
  if (firstIdx == -1) {
    cout << 0 << " " << 1 << nline;
    cout << nline;
    return;
  }
  int maxB = -1;
  for (int i = firstIdx; i < lastIdx; i++) {
    maxB = max(maxB, b[i]);
    if (maxB <= i) {
      cout << -1 << nline;
      return;
    }
  }
  int minA = 1e9;
  for (int i = lastIdx; i > firstIdx; i--) {
    minA = min(minA, a[i]);
    if (minA > i) {
      cout << -1 << nline;
      return;
    }
  }
  set<int> vis;
  for (int i = firstIdx; i < n;) {
    vis.insert(i);
    if (i == b[i] - 1) {
      break;
    } else {
      i = b[i] - 1;
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i] && vis.find(i) == vis.end()) {
      cout << -1 << nline;
      return;
    }
  }
  int ops = 0;
  vector<int> op;
  for (auto it : vis) {
    int val = b[it] - a[it];
    ops += (val + 1);
    for (int i = 0; i < val; i++) {
      op.pb(1);
    }
    op.pb(2);
  }
  cout << ops << " " << firstIdx + 1 << nline;
  for (int i = 0; i < ops; i++) {
    cout << op[i] << " ";
  }
  cout << nline;
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
