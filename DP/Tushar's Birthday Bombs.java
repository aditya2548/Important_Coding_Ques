public class Solution {
    public ArrayList<Integer> solve(int A, ArrayList<Integer> B) 
    {
        int min=Integer.MAX_VALUE;
        int ind=-1;
        
        for(int i=0;i<B.size();i++)
        {
            if(B.get(i)<min)
            {
                min=B.get(i);
                ind=i;
            }
        }
        
        ArrayList<Integer> al=new ArrayList<Integer>();
        
        int n=A/min;
        int val=min*n;
        
        if(val==A)
        {
            for(int i=0;i<n;i++)
            {
                al.add(ind);
            }
            
            return al;
        }
        else
        {
            int j=0;
            
            while(val<=A && j<=ind)
            {
                int tmp=val-min+B.get(j);
                
                while(tmp<=A && al.size()<n)
                {
                    tmp=tmp-min+B.get(j);
                    al.add(j);
                }
                
                val=tmp+min-B.get(j);
                
                j++;
                
                
            }
        }
        
        return al;
    }
}
