class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        // Trivial Case: s2 is smaller than s1. Permutation of s1 cannot exist, return false.
        if (s2.size() < s1.size()) return false;
        
        // Initialize variables: left index, right index, maps to track frequencies of characters
        // in each string
        int l = 0, r = s1.size()-1;
        std::map<char, int> s1CharCounts, s2CharCounts;
        for (int i = 0; i < s1.size(); i++) {
            s1CharCounts[s1[i]]++;
            s2CharCounts[s2[i]]++;
        }
        
        // Using sliding window method, go through each window of s1.size() in s2, compare character frequencies
        // of s1 and the window. If equal, it's a permutation, return true. If loop runs all the way through
        // no permutation is found. Return false.
        while (r < s2.size()) {
            if (s1CharCounts == s2CharCounts) return true;
            s2CharCounts[s2[l]] == 1 ? s2CharCounts.erase(s2[l]) : s2CharCounts[s2[l]]--;
            ++l;
            ++r;
            s2CharCounts[s2[r]]++;
        }
        return false;
    }
};
