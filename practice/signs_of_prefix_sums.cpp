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
const int INF = 1e9;

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

pair<int, int> get_segment(char c) {
  if (c == '0')
    return {3, 3};
  if (c == '-')
    return {0, 2};
  return {4, 6};
}

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (s[0] == '0') {
    cout << -1 << nline;
    return;
  }
  for (int i = 1; i < n; i++) {
    if (s[i] == '0' && s[i - 1] == '0') {
      cout << -1 << nline;
      return;
    }
  }
  for (int i = 0; i < n - 3; i++) {
    string g = s.substr(i, 4);
    if (g == "-++-" || g == "+--+") {
      cout << 3 << nline;
      return;
    }
  }
  ll cost = 1;
  ll sum = 0;
  if (s[0] == '+')
    sum = 1;
  else
    sum = -1;
  for (ll i = 1; i < n; i++) {
    if (s[i] == '0') {
      if (abs(sum) != 1)
        cost = 2;
    }
    if (s[i] == '+') {
      if (sum < 0)
        cost = 2;
      if (sum > 1)
        sum--;
      else
        sum++;
    }
    if (s[i] == '-') {
      if (sum > 0)
        cost = 2;
      if (sum < -1)
        sum++;
      else
        sum--;
    }
  }
  cout << cost << nline;
  // int k = 3;
  // vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, INF));
  // dp[0][k] = 0;
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < 2 * k + 1; j++) {
  //     if (dp[i][j] == INF)
  //       continue;
  //     auto [l, r] = get_segment(s[i]);
  //     for (int b = l; b <= r; b++) {
  //       if (b == j)
  //         continue;
  //       dp[i + 1][k] = min(dp[i + 1][k], max(dp[i][j], abs(b - j)));
  //     }
  //   }
  // }
  // int ans = *min_element(all(dp[n]));
  // if (ans == INF)
  //   ans = -1;
  // cout << ans << nline;
  // return;
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
