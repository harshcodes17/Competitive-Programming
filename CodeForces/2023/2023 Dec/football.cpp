#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;

    int counter=1;
    int c2=1;

    for(int i=0;i<s.length()-1;i++){
        if(s[i+1]==s[i] && s[i]=='1'){
            counter++;
            if(counter==7){
                cout<<"YES\n";
                return 0;
                break;
            }
        }
        else if(s[i+1]==s[i] && s[i]=='0'){
            c2++;
            if(c2==7){
                cout<<"YES\n";
                return 0;
                break;

            }
        }
        else if(s[i+1]!=s[i]){
            c2=1;
            counter=1;
        }
    }
    //cout<<c2<<" "<<counter;
    cout<<"NO\n";

    return 0;

}