#include <iostream>
#include <climits>
#include <cstring>
#include <time.h>
using namespace std;
long long int dp[10001][10001];
long long int gameStrategy(int i,int j,long long int a[]){
    //base case
    if(j==i+1){
        return max(a[i],a[j]);
    }
    //look up
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    //rec case
    dp[i][j]=max(a[i]+min(gameStrategy(i+2,j,a),gameStrategy(i+1,j-1,a)),a[j]+min(gameStrategy(i+1,j-1,a),gameStrategy(i,j-2,a)));
    return dp[i][j];
}

int main(){
    long long int n;
    cin>>n;
    long long int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    memset(dp,-1,sizeof dp);
    cout<<gameStrategy(0,n-1,a)<<endl;
   
}