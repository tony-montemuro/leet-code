// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        //Binary Search to find search space; linear search to find first bad version
        int l = 1, mid;
        while (true) {
            mid = l + (n-l)/2;
            if (isBadVersion(mid) == true) {
                int i = l;
                while (i < mid && !isBadVersion(i)) {
                    ++i;
                }
                return i;
            } else l = mid+1;
        }
    }
};
