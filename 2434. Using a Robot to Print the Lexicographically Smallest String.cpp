class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> minChar(n);

       
        minChar[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            minChar[i] = min(s[i], minChar[i + 1]);
        }

        string result;
        stack<char> t;

        
        for (int i = 0; i < n; ++i) {
            t.push(s[i]);

            
            while (!t.empty() && (i == n - 1 || t.top() <= minChar[i + 1])) {
                result += t.top();
                t.pop();
            }
        }

        return result;
    }
};