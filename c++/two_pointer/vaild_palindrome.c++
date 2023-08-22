class Solution {
public:
    bool isPalindrome(string s) {
         int i = 0;
        int j = s.size() - 1;
        
        while (i < j) {
            while (i < j && !isalnum(s[i])) {  // Skip non-alphanumeric characters from the left
                i++;
            }
            while (i < j && !isalnum(s[j])) {  // Skip non-alphanumeric characters from the right
                j--;
            }
            
            if (tolower(s[i]) != tolower(s[j])) {  // Compare characters (case-insensitive)
                return false;
            }
            
            i++;
            j--;
        }
        
        return true;  // If we didn't find any mismatch, it's a palindrome
    
        
    }
};