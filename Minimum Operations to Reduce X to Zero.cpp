class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long total_sum=0;
        for(auto it : nums)
            total_sum+=it;
        if(total_sum<x) return -1;
        int maxlen=-1,currsum=0;
        for(int l=0,r=0;r<nums.size();r++){
            currsum+=nums[r];
            while(l<=r && currsum > total_sum-x)
                currsum-=nums[l++];
            if(currsum==total_sum-x)
                maxlen=max(maxlen,r-l+1);
        }
        return maxlen == -1 ? -1 : nums.size()-maxlen;
    }
};
