#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    set<char>se;
    for(auto& c:s){
        se.insert(c);
    }
    if(se.size()%2==0){
        cout<<"CHAT WITH HER!";
    }
    else{
        cout<<"IGNORE HIM!";
    }
    return 0;

}