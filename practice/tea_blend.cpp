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

bool isPerfectSquare(long long n) {
  if (n < 0)
    return false;

  long long root = static_cast<long long>(std::round(std::sqrt(n)));
  return root * root == n;
}

ll non_square(ll n) {
  ll res = 1;
  for (long long p = 2; p * p * p <= n; p++) {
    int cnt = 0;
    while (n % p == 0) {
      n /= p;
      cnt++;
    }
    if (cnt & 1)
      res *= p;
  }
  long long s = (long long)sqrtl((long double)n);
  while (s * s > n)
    s--;
  while ((s + 1) * (s + 1) <= n)
    s++;
  if (s * s != n)
    res *= n;
  return res;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a)
    cin >> x;
  map<ll, ll> mp;
  for (int i = 0; i < n; i++) {
    mp[non_square(a[i])]++;
  }
  ll ans = 0;
  ll prod = 1;
  set<ll> st;
  for (int i = 0; i < n; i++) {
    ll num = a[i];
    while (num > 1) {
      ll div = spf[a[i]];
      if (st.find(div))
        st.erase(div);
      else
        st.insert(div);
      while (num % div == 0)
        num /= div;
    }
    ll prod = 1;

    ans += mp[prod];
  }
  cout << ans << nline;
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
