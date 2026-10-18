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
  ll n;
  cin >> n;
  int p;
  cin >> p;
  map<ll, ll> dp;
  for (int i = 0;; i++) {
    ll val = (1 << i);
    if (val + p > n) {
      break;
    }
    dp[val + p] = 1;
  }
  auto it = dp.begin();
  for (auto i = it; i != dp.end(); i++) {
    for (auto j = (i); j != dp.end(); j++) {
      if (i->first + j->first <= n) {
        if (dp.find(i->first + j->first) == dp.end()) {
          dp[i->first + j->first] = dp[i->first] + dp[j->first];
        } else {
          dp[i->first + j->first] =
              min(dp[i->first + j->first], dp[i->first] + dp[j->first]);
        }
      }
    }
  }
  auto g = dp.find(n);
  if (g == dp.end()) {
    cout << -1 << nline;
    return;
  }
  cout << dp[n] << nline;
  return;
}

int main() {
  fastio();
  cout << fixed << setprecision(10);

  int t = 1;
  while (t--) {
    solve();
  }

  return 0;
}
