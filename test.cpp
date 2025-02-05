#include <bits/stdc++.h>
using namespace std;

#define FORI for (int i = 0; i < n; i++)
#define FORJ for (int j = 0; j < n; j++)
#define FOR(a,x) for (int a = 0; a < x; a++)
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl
#define pb emplace_back
#define endl "\n"
#define int long long
#define all(v) v.begin(), v.end()
typedef long long ll;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin>>t;
    while (t--) {
        int n ;
        cin>>n;
        vector <int> nums(n);
        FORI cin>>nums[i];
        int xorr = 0;
        FORI 
        {
            xorr^= nums[i];
        }
        if (n & 1) cout<<xorr<<endl;
        else if (xorr==0) cout<<0<<endl;
        else cout<<-1<<endl;
    }

    return 0;
}