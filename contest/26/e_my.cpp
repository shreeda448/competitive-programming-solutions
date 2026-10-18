#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
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
vector<int> prime_factors(int n) {
  vector<int> f;
  while (n % 2 == 0) {
    f.push_back(2);
    n /= 2;
  }
  for (int i = 3; i * i <= n; i += 2) {
    while (n % i == 0) {
      f.push_back(i);
      n /= i;
    }
  }
  if (n > 1) {
    f.push_back(n);
  }
  return f;
}

const int MAXN = 2e5 + 1;
long long dp[MAXN];

void pre() {
  for (int i = 0; i < MAXN; i++) {
    dp[i] = -1;
  }
}

long long f(int k, int bound) {
  if (bound >= k) {
    return 0;
  }
  long long res = LLONG_MAX;
  vector<int> t = prime_factors(k);
  if (t.size() == 1 && t[0] == k) {
    return 1;
  }
  set<int> unique_primes(t.begin(), t.end());

  for (int prime : unique_primes) {
    int quotient = k / prime;
    ll l;
    if (dp[quotient] == -1) {
      l = f(quotient, bound);
      dp[quotient] = l;
    } else {
      l = dp[quotient];
    }
    res = min(res, 1LL + prime * l);
  }
  return res;
}

void solve() {
  int n, k;
  cin >> n >> k;
  set<int> a;
  map<int, int> freq;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.insert(x);
    freq[x]++;
  }
  auto it = a.upper_bound(k);
  if (it == end(a)) {
    cout << 0 << nline;
    return;
  }
  ll res = 0;

  for (auto i = it; i != end(a); ++i) {
    long long l;
    if (dp[*i] == -1) {
      l = f(*i, k);
    } else {
      l = dp[*i];
    }
    res += freq[*i] * l;
  }
  cout << res << nline;
  return;
}

int main() {
  fastio();
  cout << fixed << setprecision(10); // Standardize floating point precision
  int t = 1;
  cin >> t;
  while (t--) {
    pre();
    solve();
  }
  return 0;
}
