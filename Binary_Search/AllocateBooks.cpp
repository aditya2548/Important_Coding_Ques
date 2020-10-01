typedef long long ll;
int possible(const vector<int> &A, int B, ll mid){
    int sum=0;
    int counter = 1;
    for(int i=0; i<A.size(); i++){
        if(sum+A[i] >mid){
            sum = A[i];
            counter++;
            if(counter>B){
                return false;
            }
        }else{
            sum+=A[i];
        }
    }
    return true;
}
int Solution::books(vector<int> &A, int B) {
    
    int n = A.size();
    if(n<B){
        return -1;
    }
    ll sum = 0;
    int mx = INT_MIN;
    for(int i=0; i<n; i++){
        mx = max(mx, A[i]);
        sum += (ll)A[i];
    }
    if(n==B){
        return mx;
    }
    int res = -1;
    ll start = (ll)mx, end = sum;
    while(start<=end){
        ll mid = start+(end-start)/2;
        if(possible(A,B,mid) == true){
            res = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return res;
}
