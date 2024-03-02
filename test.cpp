#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    ll coins[] = {1, 3, 6, 10, 15};
    ll dp[16] = {0};
    for (ll i = 1; i < 16; ++i) {
        dp[i] = i;
        for (ll j = 1; j < 5; ++j) {
            if (i >= coins[j]) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    ll ans = n / 15 * 2;
    n %= 15;
    ans += dp[n];
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}