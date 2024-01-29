#include <bits/stdc++.h>

using namespace std;

int helper(int index,int maxw,int n,int wei[],int val[]){
    if(index==n){
        return 0;
    }
    if(maxw>=wei[index]){
        return max(helper(index+1,maxw,n,wei,val),helper(index+1,maxw-wei[index],n,wei,val)+val[index]);
    }
    else{
        return helper(index+1,maxw,n,wei,val);
    }

     
} 

int main(){
    int n,w;
    cin>>n>>w;
    int weight[n],values[n];
    for(int i=0;i<n;i++){
        cin>>weight[i]>>values[i];
    }
    int ans=helper(0,w,n,weight,values);
    cout<<ans;
    return 0;

}