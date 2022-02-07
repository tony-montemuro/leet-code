class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //Special Case: If k is 0, simply return
        if (k == 0) return;
      
        //Otherwise, perform rotation
        int ctr = 0, curr = 0, begin = 0, tempL = nums[0], size = nums.size(), tempR;
        do {
            tempR = nums[(curr+k) % size];
            nums[(curr+k) % size] = tempL;
            tempL = tempR;
            curr = (curr + k) % size;
            ++ctr;
          
            //This statement will be true in the case when size is even and k is even
            if (curr == begin && ctr < nums.size()) {
                begin++;
                curr = begin;
                tempL = nums[curr];
            }
        } while (ctr < nums.size());
        return;
    }
};
