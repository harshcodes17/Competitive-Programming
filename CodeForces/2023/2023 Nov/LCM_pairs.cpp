#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    sort(v.begin(),v.end());
    long long cnt = 0;
    unordered_map<long long,long long>mp;

    for(int i=n-1;i >= 0;i--){
        
        for(int j=v[i];j<=v[n-1];j+=v[i]){
            cnt+=mp[j];
        }
        mp[v[i]]++;
    }
    cout<<cnt;
    
    return 0;

}