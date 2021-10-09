vector<int> Solution::plusOne(vector<int> &A) {
   int n=A.size(),c=0;
   vector<int>ans;
     c=(1+A[n-1])/10;
    ans.push_back((1+A[n-1])%10);
    for(int i=n-2;i>=0;i--)
    {
        ans.push_back((c+A[i])%10);
        c=(A[i]+c)/10;
    }
    if(c)
    {
        ans.push_back(c);
    }
    int x=ans.size();
    for(int i=0;i<x/2;i++)
    {  
        swap(ans[i],ans[x-i-1]);
    }
    while(ans[0]==0)
    {
        ans.erase(ans.begin());
    }
    return ans;
} 
   