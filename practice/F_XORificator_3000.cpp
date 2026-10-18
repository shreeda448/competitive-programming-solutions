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

ll pref_xor(ll n) {
  ll p = -1;
  if (n % 4 == 0) {
    p = n;
  } else if (n % 4 == 1) {
    p = 1;
  } else if (n % 4 == 2) {
    p = n + 1;
  } else if (n % 4 == 3) {
    p = 0;
  }
  return p;
}

ll exclude(ll n, ll k, ll i) {
  if (n < k) {
    return 0;
  }
  ll m = (n - k) >> i;
  ll res = pref_xor(m) << i;
  if ((m + 1) & 1)
    res ^= k;
  return res;
}

void solve() {
  ll l, r, i, k;
  cin >> l >> r >> i >> k;
  ll ans = (pref_xor(r) ^ pref_xor(l - 1));
  ll g = (1LL << i);
  // number of elements in the range [l,r] such that j%(2^i) = k
  // in range 0 to b x (2^i - 1) there are b elements and if c < 2^i -1 then
  // +1 if c>=k else 0
  // num in [0, n] = (n/(2^i - 1)) + (n % (2^i -1 )>=k)
  // num = num in [0,r] - num in [0,l-1]
  ll ans1 = exclude(r, k, i) ^ exclude(l - 1, k, i);
  cout << (ans ^ ans1) << nline;
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
