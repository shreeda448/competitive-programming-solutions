#include <bits/stdc++.h>
#include <unordered_map>
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
  vector<ll> a(n);
  for (auto &x : a)
    cin >> x;
  unordered_map<int, int> mp;
  for (int i = 0; i < n; i++) {
    if (mp.find(a[i] - 1) == mp.end()) {
      mp[a[i]] = 1;
    } else {
      int cur = mp[a[i] - 1];
      int m = mp[a[i] - 1];
      if (mp.find(a[i]) == mp.end()) {
        mp[a[i]] = cur + 1;
      } else if (m < cur + 1) {
        mp[a[i]] = cur + 1;
      }
    }
  }
  int mx = 0;
  int vl = 0;
  for (auto &[k, v] : mp) {
    if (mx < v) {
      mx = v;
      vl = k;
    }
  }
  vector<int> res;
  int c = vl - mx + 1;
  for (int i = 0; i < n; i++) {
    if (a[i] == c) {
      res.pb(i + 1);
      c++;
    }
  }
  cout << res.size() << nline;
  for (auto x : res) {
    cout << x << " ";
  }
  cout << nline;
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
