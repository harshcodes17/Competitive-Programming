#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){

        string s;
        cin>>s;
        if(s.length()<=10){
            cout<<s<<endl;
        }
        else{
            int num = s.length()-2;
            cout<<s[0]<<num<<s[s.length()-1];
            cout<<endl;
        }
    }
    return 0;

}