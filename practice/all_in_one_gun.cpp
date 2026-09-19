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
  int n;
  ll h, k;
  cin >> n >> h >> k;
  vector<ll> a(n);
  ll sum = 0;
  for (auto &x : a) {
    cin >> x;
    sum += x;
  }
  // prefix sum, prefix min, suffix max
  vector<ll> prefix_sum(n);
  vector<ll> prefix_min(n);
  vector<ll> suffix_max(n);
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      prefix_min[i] = a[i];
      prefix_sum[i] = a[i];
      suffix_max[n - 1 - i] = a[n - 1 - i];
    } else {
      prefix_min[i] = min(prefix_min[i - 1], a[i]);
      prefix_sum[i] = a[i] + prefix_sum[i - 1];
      suffix_max[n - 1 - i] = max(suffix_max[n - i], a[n - 1 - i]);
    }
  }
  ll res = (h / sum) * (n + k);
  if (h % sum == 0) {
    res -= k;
  } else {
    h = (h % sum);
    ll low = 1, high = n;
    ll mn = n;
    while (low <= high) {
      ll mid = (high - low) / 2 + low;
      if (max(prefix_sum[mid - 1], prefix_sum[mid - 1] - prefix_min[mid - 1] +
                                       suffix_max[mid]) >= h) {
        mn = min(mn, mid);
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    res += mn;
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
    solve();
  }
  return 0;
}
