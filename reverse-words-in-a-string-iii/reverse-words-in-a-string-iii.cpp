class Solution {
public:
    std::string reverseWords(std::string s) {
        //Declare variables
        int l = 0, r, space = 0, prevSpace = -1;
        
        // Idea: Find the spaces between words
        while (space < s.size()) {
            while (space < s.size() && s[space] != ' ') {
                ++space;
            }
            l = prevSpace+1;
            r = space-1;
            
            //Reverse String
            while (l < r) {
                std::swap(s[l++], s[r--]);
            }
            
            //Prepare for next word
            prevSpace = space;
            ++space;
        }
        return s;
    }
};
