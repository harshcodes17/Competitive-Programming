#include <bits/stdc++.h>

using namespace std;

int helper(int i,int j,int &rows,int &cols,vector<vector<int>>& mat){
    if(i==rows-1 && j==cols-1){
        return mat[i][j];
    }
    if(i<rows-1){
        if(j<cols-1){
            return max(helper(i+1,j,rows,cols,mat)+mat[i][j],helper(i,j+1,rows,cols,mat)+mat[i][j]);
        }
        else{
            return helper(i+1,j,rows,cols,mat)+mat[i][j];
        }
    }
    else{
        return helper(i,j+1,rows,cols,mat)+mat[i][j];
    }
}

int main(){
    int rows,cols;
    cin>>rows>>cols;
    vector<vector<int>>mat(rows,vector<int>(cols,0));
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>mat[i][j];
        }
    }
    int sum=0;
    sum = helper(0,0,rows,cols,mat);
    cout<<sum;
    return 0;

}