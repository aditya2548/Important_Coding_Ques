typedef long long ll;
bool possible(const vector<int> &A, int B, ll mid){
    ll sum=0;
    ll counter = 1;
    for(int i=0; i<A.size(); i++){
        if(sum+(ll)A[i] >mid){
            sum = A[i];
            counter++;
            if(counter>B){
                return false;
            }
        }else{
            sum+=(ll)A[i];
        }
    }
    return true;
}
ll books(vector<int> &A, int B) {
    
    int n = A.size();
    // if(n<B){
    //     return -1;
    // }
    ll sum = 0;
    int mx = INT_MIN;
    for(int i=0; i<n; i++){
        mx = max(mx, A[i]);
        sum += (ll)A[i];
    }
    if(n==B){
        return mx;
    }
    ll res = -1;
    ll start = (ll)mx, end = sum;
    while(start<=end){
        ll mid = start+(end-start)/2;
        // cout<<mid<<endl;
        if(possible(A,B,mid) == true){
            res = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return res% 10000003;
}

int Solution::paint(int A, int B, vector<int> &C) {
    return (B* books(C,A))% 10000003;
}
