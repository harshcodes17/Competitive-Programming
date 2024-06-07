#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fastio ios::sync_with_stdio(0); cin.tie(0);

bool checker(ll mid, const vl &v) {
    ll sum = 0;
    vl mul(v.size());

    for (int i = 0; i < v.size(); ++i) {
        mul[i] = (mid + v[i] - 1) / v[i];
        sum += mul[i];
    }

    for (int i = 0; i < v.size(); ++i) {
        if (mul[i] * v[i] <= sum) {
            return false;
        }
    }
    return true;
}

int32_t main() {
    fastio

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vl v(n);
        for (ll &x : v) cin >> x;
        ll lcmm=v[0];
        for(auto x:v){
            lcmm = lcm(lcmm,x);
        }
        ll add =0 ;
        for(auto x:v){
            add+=lcmm/x;
        }
        if(add<=lcmm){
            cout<<-1<<endl;
            return;
        }

        ll l = 1, r = 1e4;
        vl ans(n);
        ll lmid = 0;
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (checker(mid, v)) {
                lmid = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        for (int i = 0; i < n; ++i) {
                    ans[i] = (lmid + v[i] - 1) / v[i];
                }
        for(auto x:ans){
            cout<<x<<" ";
        }   
        cout<<"\n";
    }

    return 0;
}
