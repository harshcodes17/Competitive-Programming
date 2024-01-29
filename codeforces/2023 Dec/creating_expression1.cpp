#include <bits/stdc++.h>

using namespace std;

bool helper(int index,int val,vector<int>& v,int x,int n){
    if(index==n){
        return val==x;
    }
    bool ans1 = helper(index+1,val+v[index],v,x,n);
    bool ans2 = helper(index+1,val-v[index],v,x,n);
    return ans1 || ans2;
}

int main(){
    int n,x;
    cin>>n>>x;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    if(helper(1,v[0],v,x,n)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    
    return 0;

}