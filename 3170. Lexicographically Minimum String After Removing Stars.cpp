class Solution {
public:
    string clearStars(string s) {
        vector<char> stack;
        vector<vector<int>> charPos(26); 

        for (char c : s) {
            if (c != '*') {
                stack.push_back(c);
                charPos[c - 'a'].push_back(stack.size() - 1);
            } else {
               
                for (int i = 0; i < 26; ++i) {
                    if (!charPos[i].empty()) {
                        
                        int idxToRemove = charPos[i].back();
                        charPos[i].pop_back();
                        stack[idxToRemove] = '#'; 
                        break;
                    }
                }
            }
        }

        
        string result;
        for (char c : stack) {
            if (c != '#') result += c;
        }

        return result;
    }
};