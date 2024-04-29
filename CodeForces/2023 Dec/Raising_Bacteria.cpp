#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int ans=0;
    int c = __builtin_popcount(n);
    if(c==1){
        cout<<1;
    }
    else{
        for(int i=0;i<32;i++){
            if(((1<<i)&n)>0){
                ans++;
            }
        }
        cout<<ans;
    }
    return 0;

}