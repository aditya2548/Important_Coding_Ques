vector<int> Solution::maxone(vector<int> &A, int B) {
    int count =0, l = 0,r = 0,size,max_size = 0, ml = 0;
    while(r<A.size()){
        if(count<=B){
            if(A[r] == 0){
                count++;
            }
            r++;
        }
        if(count>B){
                if(A[l]==0) count--;
                l++;
        }
           size = r-l;
            if(max_size < size){
                max_size = size;
                ml = l;
            }
    }
    
    vector<int> res;
    for(int i = ml; i<ml+max_size;i++){
        res.push_back(i);
    }
    return res;
}
