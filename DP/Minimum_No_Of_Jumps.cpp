class Solution {
public:
    int jump(vector<int>& nums) {
        int l=nums[0],m=INT_MIN,ans=1;
        if(nums.size()==1)
            return 0;
        for(int i=1;i<nums.size();i++)
        {
              m=max(m,i+nums[i]);
            if(l>=nums.size()-1)
                return ans;
            else if(i>=l)
            {
                ans++;
                l=m;
                m=0;
            }
          
                
        }
        
        return ans;
    }
};