#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
    cin>>s;
    int num = s[1]-'0';
    char c=s[0];
    for(int i=1;i<=8;i++){
        if(i==num){
            continue;
        }
        cout<<c<<i<<endl;
    }
    for(char i='a';i<='h';i++){
        if(i==c){
            continue;
        }
        cout<<i<<num<<endl;
    }
    }
    return 0;

}