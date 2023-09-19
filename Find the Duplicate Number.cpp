class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0,fast=0;
        while (true){
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast)
                break;
        }
        fast=0;
        while(true){
            slow=nums[slow];
            fast=nums[fast];
            if(slow==fast)
                return slow;
        }
        return 0;
    }
};
