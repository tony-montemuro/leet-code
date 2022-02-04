class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, mid;
        while (l <= r) {
            mid = (l+r)/2;
            if (nums.at(mid) == target) return mid;
            else if (target < nums.at(mid)) r = mid-1;
            else l = mid+1;
        }
        return -1;
    }
};
