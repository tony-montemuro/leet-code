class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Brute force method
        bool isFound = false;
        std::vector<int> v(2);
        int i = 0, j;
        while (!isFound) {
            j = i + 1;
            while (!isFound && j < nums.size()) {
                if (nums[i] + nums[j] == target) {
                    v[0] = i, v[1] = j;
                    isFound = true;
                }
                ++j;
            }
            ++i;
        }
        return v;
    }
};
