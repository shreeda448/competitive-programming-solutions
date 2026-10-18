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

// anc[i][j] = 2^j th ancestor of ith node
// anc[i][j] = anc[anc[i][j-1]][j-1]

// void ancestor(vector<vector<int>> &anc, int &root) {
//   int n = anc.size();
//   vector<bool> vis(n, true);
//   int cnt = 0;
//   for (int j = 1; j <= n; j++) {
//     for (int i = 0; i < n; i++) {
//       if (vis[i]) {
//         anc[i].pb(anc[anc[i][j - 1]][j - 1]);
//         if (anc[i][j] == 0) {
//           vis[i] = false;
//           cnt++;
//         }
//       }
//     }
//     if (cnt == n) {
//       break;
//     }
//   }
// }

int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p) {
  tin[v] = ++timer;
  up[v][0] = p;
  for (int i = 1; i <= l; ++i)
    up[v][i] = up[up[v][i - 1]][i - 1];

  for (int u : adj[v]) {
    if (u != p)
      dfs(u, v);
  }

  tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
  if (is_ancestor(u, v))
    return u;
  if (is_ancestor(v, u))
    return v;
  for (int i = l; i >= 0; --i) {
    if (!is_ancestor(up[u][i], v))
      u = up[u][i];
  }
  return up[u][0];
}

void preprocess(int root) {
  tin.resize(n + 1);
  tout.resize(n + 1);
  timer = 0;
  l = ceil(log2(n));
  up.assign(n + 1, vector<int>(l + 1));
  dfs(root, root);
}

void solve() {
  cin >> n;
  vector<int> p(n - 1);
  cin >> p;
  int m;
  cin >> m;
  vector<int> a(m);
  cin >> a;
  timer = 0;
  tin.clear();
  tout.clear();
  up.clear();
  adj.resize(n + 1);
  for (int i = 0; i <= n; i++) {
    adj[i].resize(0);
  }
  for (int i = 0; i < n - 1; i++) {
    adj[i + 2].push_back(p[i]);
    adj[p[i]].push_back(i + 2);
  }
  preprocess(1);
  vector<pair<int, int>> tt;
  for (int i = 0; i < m; i++) {
    tt.push_back({tin[a[i]], a[i]});
  }
  sort(all(tt));
  map<int, set<int>> mp;
  for (int i = 0; i < m - 1; i++) {
    int l = lca(tt[i].second, tt[i + 1].second);
    mp[l].insert(tt[i].second, tt[i + 1].second);
  }
  set<int> st;
  for (auto &[k, v] : mp) {
    int y = v.size();
    for (auto x : v) {
      st.insert(x);
    }
  }
  cout << st.size() << " ";
  for (auto x : st) {
    cout << x << " ";
  }
  cout << nline;
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
