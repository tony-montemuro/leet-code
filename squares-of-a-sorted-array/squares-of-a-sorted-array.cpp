class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        std::stack<int> negatives;
        std::vector<int> squared;
        int i = 0;
        while (i < nums.size() && nums[i] < 0) {
            negatives.push(nums[i]);
            ++i;
        }
        for (i; i < nums.size(); i++) {
            while (!negatives.empty() && std::abs(negatives.top()) < nums[i]) {
                squared.push_back(negatives.top()*negatives.top());
                negatives.pop();
            }
            squared.push_back(nums[i]*nums[i]);
        }
        while (!negatives.empty()) {
            squared.push_back(negatives.top()*negatives.top());
            negatives.pop();
        }
        return squared;
    }
};
