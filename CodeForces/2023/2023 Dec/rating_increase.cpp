#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int flag=0;
        vector<string>v;
        for(int i=1;i<s.length();i++){
            string temp="";
            temp = s.substr(0,i);
            string temp1 = "";
            temp1 = s.substr(i,s.length()-1);
            // cout<<temp<<" "<<temp1<<endl;
            if(stoi(temp1)>stoi(temp) && (temp[0]!='0' && temp1[0]!='0')){
                flag=1;
                cout<<temp<<" "<<temp1;
                break;
            }
        }
        if(flag==1){
            cout<<endl;
        }
        else if(flag==0){
            cout<<-1<<endl;
        }
        
    }
    return 0;

}