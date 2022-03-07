class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while (i <= j) {
            while (i < j && (!std::isalpha(s[i]) && !std::isdigit(s[i]))) ++i;
            while (i < j && (!std::isalpha(s[j]) && !std::isdigit(s[j]))) --j;
            if (std::tolower(s[i]) != std::tolower(s[j])) return false;
            ++i;
            --j;
        }
        return true;
    }
};
