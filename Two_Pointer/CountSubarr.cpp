int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int sum = 0;
    int res=0;
    // for(int i=0; i<n; i++){
    //     sum = 0;
    //     for(int j=i; j<n; j++){
    //         sum+=A[j];
    //         if(sum<B){
    //             res++;
    //         }else{
    //             break;
    //         }
    //     }
    // }
    int i=0,j=0;
    while(j<n){
        res += j-i+1;
        sum+=A[j++];
        while(sum>=B){
            sum-=A[i++];
        }
    }
    return res;
}
