#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int count = 0;
    int c = v[k-1]; 
    for(int i=0;i<n;i++){
        if(v[i]>=c && c!=0){
            count++;
        }
        else if(c==0 && v[i]>c){
            count++;
        }
        
    }
    cout<<count<<endl;
    return 0;

}