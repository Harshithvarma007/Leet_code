class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;  // Note the correct spelling: unordered_map
        
        for (const string& word : strs) {
            string sortedWord = word;  // Create a copy of the word to sort
            sort(sortedWord.begin(), sortedWord.end());  // Use the sort function to sort the characters
            
            hashmap[sortedWord].push_back(word);
        }
        
        vector<vector<string>> result;
        
        for (const auto& list : hashmap) {
            result.push_back(list.second);
        }
        
        return result;
    }
};
