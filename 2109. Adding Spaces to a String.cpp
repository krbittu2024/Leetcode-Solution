class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.length();
        int spaceIdx = 0;
        string result = "";

        
        for (int i = 0; i < n; ++i) {
            
            if (spaceIdx < spaces.size() && spaces[spaceIdx] == i) {
                result += " ";  
                ++spaceIdx;     
            }
            result += s[i]; 
        }

        return result;
    }
};