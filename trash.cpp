#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
typedef long long ll;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
    }

    ll max_len = 0;
    ll l = 0, r = 0;
    while (r < n) {
        vector<ll> temp;
        for (ll i = l; i <= r; ++i) {
            temp.push_back(v[i]);
        }
        sort(temp.rbegin(), temp.rend());
        if(temp.size()==1){
            maxi
        }

        if (k<max_val && k>=second_max_val){
            max_len = max(max_len, r - l + 1);
            r++;
        }
        else{
            l++;
            if(l>r){
                r=l;
            }
        }
    }

    cout << max_len << endl;
}

int32_t main() {
    fastio();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}