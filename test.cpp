#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
    cin>>s;

    int a=0,b=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='A'){
            a++;
        }
        else{
            b++;
        }
    }

    if(a>b){
        cout<<'A'<<"\n";
    }
    else{
        cout<<'B'<<"\n";
    }

    }
    return 0;

}