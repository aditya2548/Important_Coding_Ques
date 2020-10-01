int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    if(n==0)    return 1;
    for(int i = 0; i<n ; i++){
        if(A[i]>n || A[i]<0){
            A[i]=0;
        }
    }
    //  Using method of encoding two numbers in one

    for(int i=0; i<n; i++){
        if((A[i]%(n+2))>0){
            A[(A[i]%(n+2))-1] += (n+2) ;
        }
    }
    for(int i=0; i<n; i++){
        if(A[i]/(n+2)==0)   return i+1;
    }
    return n+1;
    
}
