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

bool check(ll mid, vector<pair<ll, ll>> &A) {
  ll n = 1;
  ll ex = 0;
  ll p = mid;
  for (ll i = 0; i < A.size(); i++) {
    if (p - A[i].first + (63 - __builtin_clzll(n)) > 60) {
      return false;
    }
    n <<= (p - A[i].first - 1);
    if (!A[i].first) {
      ex += A[i].second;
      break;
    }
    if (A[i].second > n) {
      ex += A[i].second - n;
    } else {
      n = (n << 1) - A[i].second;
    }
    p = A[i].first;
  }
  return (ex >= n);
}

void solve() {
  long long N;
  cin >> N;
  vector<pair<long long, long long>> A;
  long long lo = 0;
  long long hi = 1000000100;
  for (long long i = 0; i < N; i++) {
    long long a, b;
    cin >> a >> b;
    A.push_back({a, b});
    lo = max(lo, a);
  }
  sort(A.rbegin(), A.rend());
  if (A.back().first) {
    A.push_back({0, 0});
  }
  while (lo < hi) {
    long long mid = (lo + hi + 1) / 2;
    if (check(mid, A)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  cout << lo << endl;
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
