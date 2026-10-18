#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vpl = vector<pll>;
using mll = map<ll, ll>;
using pq_max = priority_queue<ll>;
using pq_min = priority_queue<ll, vll, greater<ll>>;
using pq_pmax = priority_queue<pll>;
using pq_pmin = priority_queue<pll, vpl, greater<pll>>;

#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) static_cast<ll>((x).size())

#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define per(i, a, b) for (ll i = (a); i >= b; --i)
#define each(x, a) for (auto &x : a)
#define read_vll(a, n)                                                         \
  vll a(n);                                                                    \
  each(x, a) cin >> x;

#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define cyr                                                                    \
  cout << "YES\n";                                                             \
  return
#define cnr                                                                    \
  cout << "NO\n";                                                              \
  return
#define alice cout << "Alice\n"
#define bob cout << "Bob\n"

constexpr ll LINF = 1e18 + 9;
constexpr ll MOD = 1e9 + 7;

template <typename T> inline bool chmin(T &a, const T &b) {
  return b < a ? a = b, true : false;
}
template <typename T> inline bool chmax(T &a, const T &b) {
  return a < b ? a = b, true : false;
}

template <typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p) {
  return is >> p.first >> p.second;
}
template <typename T> istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v)
    is >> x;
  return is;
}

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  return os << p.first << " " << p.second;
}
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
  for (size_t i = 0; i < v.size(); ++i)
    os << v[i] << (i + 1 == v.size() ? "" : " ");
  return os;
}

ll binpow(ll base, ll exp, ll mod = MOD) {
  ll res = 1;
  base %= mod;
  while (exp > 0) {
    if (exp & 1)
      res = (__int128)res * base % mod;
    base = (__int128)base * base % mod;
    exp >>= 1;
  }
  return res;
}

ll modInverse(ll n, ll mod = MOD) { return binpow(n, mod - 2, mod); }

ll isPrime(ll x) {
  for (ll d = 2; d * d <= x; d++) {
    if (x % d == 0)
      return false;
  }
  return x >= 2;
}

ull nCr(ll n, ll k) {
  if (k < 0 || k > n)
    return 0;
  if (k == 0 || k == n)
    return 1;

  k = min(k, n - k);

  ull result = 1;
  rep(i, 1, k + 1) {
    result *= (n - i + 1);
    result /= i;
  }

  return result;
}

constexpr ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
constexpr ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
constexpr ll ceil_div(ll a, ll b) { return (a + b - 1) / b; }

ll min_idx(const vll &v) { return distance(v.begin(), min_element(all(v))); }
ll max_idx(const vll &v) { return distance(v.begin(), max_element(all(v))); }

void solve() {}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
