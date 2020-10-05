int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int x= A[0], y=B[0];
    int count = 0;
    
    for(int i = 1 ;i<A.size(); i++){
       int diagonal = min(abs(A[i]-A[i-1]),abs(B[i]-B[i-1]));
           count = count + diagonal + (abs(A[i]-A[i-1])-diagonal) + (abs(B[i]-B[i-1]) - diagonal);
      
    }
    return count;
}
