int Solution::solve(int n, vector<int> &B) {
    int cnt[n] = {0},res=0;
    int s=0, ss=0;
    for(int i=n-1;i>=0;i--){
        s+=B[i];
    }
    if(s%3!=0)  return 0;
    s/=3;
    
    for(int i=n-1; i>=0; i--){
        ss+=B[i];
        if(ss==s)   cnt[i] = 1;
    }
    for(int i=n-2; i>=0; i--){
        cnt[i] += cnt[i+1];
    }
    ss=0;
    for(int i=0; i<n-2; i++){
        ss+=B[i];
        if(ss==s){
            res+=cnt[i+2];
        }
    }
    return res;
}
