#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.length();
    vector<int>v;
    for(int i=0;i<n;i++){
        if(i%2==0){
            v.push_back(s[i]-'0');
        }
    }
    sort(v.begin(),v.end());
    int index=0;
    for(int i=0;i<n;i++){
        if(i%2==0){
            cout<<v[index];
            index++;
        }
        else{
            cout<<"+";
        }
    }
    return 0;

}