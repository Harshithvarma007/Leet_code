class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false; // Anagrams must have the same length
        }
        
        vector<int> hashmap(128, 0); // Assuming ASCII characters
        
        for (char c : s) {
            hashmap[c]++;
        }
        
        for (char c : t) {
            hashmap[c]--;
        }
        
        for (int count : hashmap) {
            if (count != 0) {
                return false; // If any count is not 0, the strings are not anagrams
            }
        }
        
        return true;
    }
};
