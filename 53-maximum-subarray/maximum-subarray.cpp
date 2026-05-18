class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestEnding = nums[0];
        int res = nums [0];
        int maxSum= INT_MIN;
        for (int i=1;i<nums.size();i++){
            int v1,v2;
          v1 = bestEnding + nums[i];
          v2 = nums[i];
          bestEnding = max(v1,v2);
           res=max(res,bestEnding);
        }
        return res;
    }
};