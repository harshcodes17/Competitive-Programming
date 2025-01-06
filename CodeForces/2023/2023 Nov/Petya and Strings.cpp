#include <bits/stdc++.h>

using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
    for(auto& x:a){
        x=tolower(x);
        

    }
    for(auto& y:b){
        y=tolower(y);
    }
    
    int ans = 0;
    for(int i=0;i<a.length();i++){
        if(a[i]==b[i]){
            continue;
        }
        else{
            ans = a[i]-b[i];
            break;
        }
    }
    if(ans>0)cout<<1;
    else if(ans<0)cout<<-1;
    else cout<<0;
    
    return 0;

}