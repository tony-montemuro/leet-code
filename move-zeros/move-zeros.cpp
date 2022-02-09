class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZero = 0;
        // This will essentially replace all zeros BEFORE the trailing zeros
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[nonZero] = nums[i];
                nonZero++;
            }
        }
        
        // Any remaining elements should be zero
        for (nonZero; nonZero < nums.size(); nonZero++) {
            nums[nonZero] = 0;
        }
    } 
};
