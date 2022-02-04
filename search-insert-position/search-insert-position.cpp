class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //Binary search
        int l = 0, r = nums.size()-1, mid;
        while (l <= r) {
            mid = (l+r)/2;
            if (nums.at(mid) == target) return mid;
            else if (target < nums.at(mid)) r = mid-1;
            else l = mid+1;
        }
        // Special Case when l is negative: this means element must be 0-th index
        // Otherwise, just the average of l and r
        return l > 0 ? (l+r)/2 + 1 : 0;
    }
};
