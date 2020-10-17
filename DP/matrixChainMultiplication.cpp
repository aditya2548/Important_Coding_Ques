#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int minCost(int a[],int n){
    int dp[n][n];
    memset(dp,0,sizeof dp);
    for(int i=1;i<n;i++){
        int r=0;int c=i;
        while(c<n||r<n){
            int val=INT_MAX;
            for(int p=r;p<c;p++){
                val=min(val,dp[r][p]+dp[p+1][c]+a[r]*a[p+1]*a[c+1]);
            }
            dp[r][c]=val;
            r++;c++;
        }
    }
    return dp[0][n-1];
}

int main(){
    
}