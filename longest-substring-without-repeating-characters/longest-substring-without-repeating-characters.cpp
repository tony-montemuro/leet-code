class Solution {
public:
    bool isNonRepeating(char curr, std::queue<char> q) {
        // This function will essentially search through queue for a match
        // if found, repeating character detected: return false. Otherwise, return true.
        for (int i = 0; i < q.size(); i++) {
            char top = q.front();
            if (curr == q.front()) return false;
            q.pop();
            q.push(top);
        }
        return true;
    }
    
    int lengthOfLongestSubstring(std::string s) {
        //Declare variables: lower index i, upper index j, max
        int i = 0, j = 0, max = s.size() > 0 ? 1 : 0;
        
        // queue used to check for repeating characters [use unordered_set for better performance]
        std::queue<char> substr;
        while (i < s.size() && j < s.size()) {
            // Case 1: Repeating character not found: add the character at upper index to
            // the queue, and increment upper index. Update max if necessary
            if (isNonRepeating(s[j], substr)) {
                substr.push(s[j++]);
                if (j-i > max) max = j-i;
                
            // Case 2: Repeating character found: remove the character at lower index from
            // the queue, and inrecement the lower index
            } else {
                substr.pop();
                ++i;
            }
        }
        return max;
    }
};
