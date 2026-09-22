#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
int spf[MAXN];

void precompute() {
    for (int i = 1; i < MAXN; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> dp(n + 1, 0);
    for (int i = k + 1; i <= n; i++) {
        long long ops = 1e18;
        int temp = i;
        while (temp > 1) {
            int p = spf[temp];
            ops = min(ops, 1 + (long long)p * dp[i / p]);
            while (temp % p == 0) {
                temp /= p;
            }
        }
        dp[i] = ops;
    }
    long long tot = 0;
    for (int i = 0; i < n; i++) {
        tot += dp[a[i]];
    }
    cout << tot << "\n";
}

int main() {
    precompute();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
