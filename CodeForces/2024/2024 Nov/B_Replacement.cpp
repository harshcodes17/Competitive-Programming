#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ldb long double

//////////////////////////////////////////////

void solve(){
    int n,k;
    cin>>n>>k;

    vector<int>a(n);
    for(auto &i:a)      cin>>i;

    int l=0,r=0;
    while(r<n && a[r]<=k){
        r++;
    }

    if(r==n){
        cout<<0<<endl;
        return;
    }

    int idx= r;
    int ans= r+1;
    r++;

    while(r<n){
        if(a[r]!=a[idx] && a[r]>k){
            l= idx+1;
            idx= r;
        }

        ans= max(ans, r-l+1);

        r++;
    }

    cout<< ans <<endl;
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        solve();
    }
    return 0;
}