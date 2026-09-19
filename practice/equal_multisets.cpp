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
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  cin >> a;
  vector<ll> b(n);
  cin >> b;
  for (int i = 0; i < n - k; i++) {
    if (a[i] == b[i] || b[i] == -1) {
      continue;
    } else {
      cout << "NO" << nline;
      return;
    }
  }
  for (int i = n - 1; i >= k; i--) {
    if (a[i] == b[i] || b[i] == -1) {
      continue;
    } else {
      cout << "NO" << nline;
      return;
    }
  }
  int wildcard = 0;
  vector<int> freq_a(n + 1);
  vector<int> freq_b(n + 1);
  for (int i = n - k; i <= k - 1; i++) {
    if (b[i] == -1) {
      wildcard++;
    } else {
      freq_b[b[i]]++;
      if (freq_b[b[i]] > 1) {
        cout << "NO" << nline;
        return;
      }
    }
    freq_a[a[i]]++;
  }
  for (int i = n - k; i <= k - 1; i++) {
    if (freq_b[a[i]] == 0) {
      wildcard -= freq_a[a[i]];
    }
    if (wildcard < 0) {
      cout << "NO" << nline;
      return;
    }
  }
  cout << "YES" << nline;
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
