#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        /* code */
    int n,x;
    cin>>n>>x;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>d;
    d.push_back(v[0]);
    for(int i=0;i<n-1;i++){
        int diff = v[i+1]-v[i];
        d.push_back(diff);
    }
    int var = (x-v[n-1])*2;
    d.push_back(var);
    sort(d.begin(),d.end(),greater<int>());
    
    cout<<d[0]<<endl;
    }
    
    return 0;

}