bool comp(int a, int b){
    string x = to_string(a);
    string y = to_string(b);
    return y.append(x) < x.append(y);
}
string Solution::largestNumber(const vector<int> &A) {
    vector<int> v;
    for(int i=0;i<A.size();i++){
        v.push_back(A[i]);
    }
    sort(v.begin(), v.end(),comp);
    if(v[0] == 0)   return "0";
    

    string res;
    for(int i = 0 ; i<A.size() ; i++){
        res.append(to_string(v[i]));
    }
    return res;
    
}
