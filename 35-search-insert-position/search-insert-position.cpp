class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();  // [l, r)
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) {
                r = mid;            // go left (mid can be answer)
            } else {
                l = mid + 1;        // go right
            }
        }
        return l; // lower_bound index
    }
};
