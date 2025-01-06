#include <bits/stdc++.h>

using namespace std;

vector<string>allstrings;


void backtrack(int index,int n,string curr,vector<int>& m){
    if(index==n){
        allstrings.push_back(curr);
        return;
    }
    for(int i=0;i<26;i++){
        if(m[i]>0){
            m[i]--;
            backtrack(index+1,n,curr+char('a'+i),m);
            m[i]++;
        }
    }



}

int main(){
    int n;
    string s;
    cin>>s;
    n=s.length();
    vector<int>m(26);
    for(auto& i:s){
        m[i-'a']++;
    }
    backtrack(0,n,"",m);
    cout<<allstrings.size()<<endl;
    for(auto& ss:allstrings){
        cout<<ss<<endl;
    }
    return 0;

}