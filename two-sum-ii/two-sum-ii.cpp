class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        //Initialize two pointers
        int l = 0, r = numbers.size()-1;
        
        //Now, find sum. Take advantage of fact list is sorted for quick O(n) solution
        while (true) {
            int sum = numbers[l]+numbers[r];
            if (sum == target) {
                return {l+1, r+1};
            }
            else if (sum > target) r--;
            else l++;
        }
    }
};
