#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int MAXN = 10; // Adjust this value based on the problem constraints
map<ll, vector<vector<ll>>> precomputed;

ll calculate_sum(const vector<ll>& v) {
    ll n = v.size();
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        ll mini = v[i];
        for (int j = i; j < n; j++) {
            mini = min(mini, v[j]);
            sum += mini;
        }
    }
    return sum;
}

void precompute() {
    for (int n = 1; n <= MAXN; n++) {
        vector<ll> v(n);
        iota(v.begin(), v.end(), 1);
        ll target_sum = calculate_sum(v);
        vector<vector<ll>> ans;
        do {
            if (calculate_sum(v) == target_sum) {
                ans.pb(v);
            }
        } while (next_permutation(v.begin(), v.end()));
        precomputed[target_sum] = ans;
    }
}

void solve() {
    ll n, k;
    cin >> n >> k;
    if(precomputed[n].size() < k) {
        cout << -1 << '\n';
    }
    else {
        for (auto x : precomputed[n][k - 1]) {
            cout << x << " ";
        }
        cout << '\n';
    }
}

int main() {
    ios;
    #ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("/Users/sreejith/Desktop/output.txt", "w", stdout);
    #endif

    precompute();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}