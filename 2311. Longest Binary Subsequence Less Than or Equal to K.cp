class Solution {
public:
    int longestSubsequence(string s, int k) {
        int count = 0;
        long long value = 0;
        long long power = 1;
        int n = s.size();

        
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                count++; 
            } else {
                if (power <= k && value + power <= k) {
                    value += power;
                    count++;
                }
            }
            
            if (power <= k) {
                power *= 2;
            }
        }

        return count;
    }
};