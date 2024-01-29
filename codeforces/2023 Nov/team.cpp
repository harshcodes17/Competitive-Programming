#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    int count = 0;
    while(t--){
        int a[3];
        cin>>a[0]>>a[1]>>a[2];
        int c=0;
        for(int i=0;i<3;i++){
            if(a[i]==1){
                c++;
            }
        }
        if(c>=2){
            count++;
        }
    }
    cout<<count;
    return 0;

}