class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        if(x==0)
            return true;
        int count=0;
        int copy=x;
        vector<int> ans;
        while(x>0)
        {
            ans.push_back(x%10);
            count++;
            x/=10;
        }
        long long int res=0;
        for(int i=0;i<count-1;i++)
        {
            res+=ans[i];
            res*=10;
        }
        res+=ans[count-1];
        if(copy==res)
            return true;
        return false;
    }
};
