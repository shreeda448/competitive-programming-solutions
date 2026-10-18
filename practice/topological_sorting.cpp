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

int dfs(int v, vector<vector<int>> &adj, vector<int> &color, vector<int> &ans) {
  color[v] = 1;
  for (int u : adj[v]) {
    if (color[u] == 1) {
      return -1;
    }
    if (color[u] == 0) {
      if (dfs(u, adj, color, ans) == -1) {
        return -1;
      }
    }
  }
  color[v] = 2;
  ans.push_back(v);
  return 0;
}

vector<int> top_sort(int n, vector<vector<int>> &adj) {
  vector<int> color(n, 0);
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (color[i] == 0) {
      if (dfs(i, adj, color, ans) == -1) {
        return {-1};
      }
    }
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  vector<int> res = top_sort(n, adj);
  if (res.size() == 1 && res.front() == -1) {
    cout << "Sandro fails" << nline;
    return;
  }
  for (int i = 0; i < n; i++) {
    cout << res[i] + 1 << " ";
  }
  cout << nline;
  return;
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
