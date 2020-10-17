#include <iostream>
using namespace std;

int max_ans(int tlength,int price[],int dp[]){
    //base case
    if(tlength==0){
        return 0;
    }

    //lookup
    if(dp[tlength]!=0){
        return dp[tlength];
    }
    //rec case
    int ans=0;
    for(int i=1;i<=tlength;i++){
        int current_profit=price[i]+max_ans(tlength-i,price,dp);
        ans=max(ans,current_profit);
    }
    return  dp[tlength]=ans;
}
int max_profitBU(int len,int price[]){
    int dp[len+1]={0};
    for(int i=1;i<=len;i++){
        for(int cut=1;cut<=i;cut++){
            dp[i]=max(dp[i],price[cut]+dp[i-cut]);
        }
    }
    return dp[len];
}

int main(){
    int rodlen;
    cin>>rodlen;
    int price[rodlen];
    int dp[rodlen+1]={0};
    for(int i=1;i<=rodlen;i++){
        cin>>price[i];
    }
    cout<<max_profitBU(rodlen,price)<<endl;
}