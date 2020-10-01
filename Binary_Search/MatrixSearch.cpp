int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int m = A.size(),n = A[0].size();
    
    int i=n-1,j=0;
    while(i>=0 &&  j<m){
        // cout<<i<<" "<<j<<endl;
        if(A[j][i] == B){
            return 1;
        }else if(A[j][i] < B){
            j++;
        }else{
            i--;
        }
    }
    return 0;
}
