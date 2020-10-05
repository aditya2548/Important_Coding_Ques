void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    set<int> row;
    set<int> col;
    
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < A[i].size(); j++){
            if(A[i][j] == 0){
                row.insert(i);
                col.insert(j);
            }
        }
    }
    
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < A[i].size(); j++){
            if(row.find(i) != row.end() || col.find(j) != col.end()){
                A[i][j] = 0;
            }
        }
    }    
}
