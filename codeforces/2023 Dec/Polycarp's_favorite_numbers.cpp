#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    sort(v.begin(),v.end(),greater<int>());
    int nearest = 0;
    int s = INT_MAX;
    int flag=0;
    vector<int>all;
    for(int i=0;i<n;i++){
        int s = log2(v[i]);
        while(s!=0){
            nearest = pow(2,s);
            //cout<<nearest<<" ";
            //cout<<v[i]<<" "<<nearest<<endl;
            if(v[i]%nearest==0){
                flag=1;
                //cout<<nearest<<"\n";
                all.push_back(nearest);
                break;
            }
            else{
                s--;
            }
        }
        
    }
    if(flag==0){
        cout<<1<<" "<<n;
        return 0;
    }
    sort(all.begin(),all.end(),greater<int>());
    nearest=all[0];
    
    
    int count=0;
    for(int i=0;i<n;i++){
        if(v[i]%nearest==0){
            count++;
        }
    }
    cout<<nearest<<" "<<count;
    return 0;

}