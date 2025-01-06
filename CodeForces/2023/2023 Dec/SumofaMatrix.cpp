#include <bits/stdc++.h>

using namespace std;
void sumofmatrix(vector<vector<int>>& a,vector<vector<int>>& b,int i,int j,int rows,int cols){
    if(i>=rows){
        return;
    }

    else if(j==cols-1){
        cout<<a[i][j]+b[i][j]<<endl;
        sumofmatrix(a,b,i+1,0,rows,cols);
        return;
    }
    
    cout<<a[i][j]+b[i][j]<<" ";
    sumofmatrix(a,b,i,j+1,rows,cols);
    
    


}


int main(){
    int rows,columns;
    cin>>rows>>columns;
    vector<vector<int>>a(rows,vector<int>(columns,0));
    vector<vector<int>>b(rows,vector<int>(columns,0));

    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cin>>b[i][j];
        }
    }
    sumofmatrix(a,b,0,0,rows,columns);
    
    return 0;

}