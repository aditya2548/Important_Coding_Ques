int Solution::solve(vector<int> &A)
{
    unordered_map<int,int> m;
    for(int i=1;i<A.size();i++)
    {
        if(A[i]==A[0])
        {
            return A[0];
        }
    }
    vector<int> ans;
    for(int i=1;i<A.size();i++)
    {
        if(m[A[i]]>0)
        {
            //cout<<i<<endl;
            ans.push_back(m[A[i]]);
        }
        else
        {
            m[A[i]]=i;
        }
    }
    if(ans.empty())
    {
        return -1;
    }
    int min=INT_MAX;
    for(int i=0;i<ans.size();i++)
    {
        //cout<<ans[i]<<endl;
        if(ans[i]<=min)
        {
            min = ans[i];
        }
    }
    return A[min];
}
