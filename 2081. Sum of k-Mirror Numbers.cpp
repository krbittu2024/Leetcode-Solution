class Solution {
public:
    
    bool isPalindrome(const string& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

   
    string toBaseK(long long num, int k) {
        string res;
        while (num > 0) {
            res += (char)((num % k) + '0');
            num /= k;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    
    void generatePalindromes(vector<long long>& result, int k, int n) {
        int len = 1;
        while ((int)result.size() < n) {
            int halfLen = (len + 1) / 2;
            long long start = pow(10, halfLen - 1), end = pow(10, halfLen);
            for (long long i = start; i < end && result.size() < n; ++i) {
                string left = to_string(i);
                string palStr = left;
                if (len % 2 == 1) palStr.pop_back();
                reverse(left.begin(), left.end());
                palStr += left;
                long long num = stoll(palStr);
                if (isPalindrome(toBaseK(num, k))) {
                    result.push_back(num);
                }
            }
            len++;
        }
    }

    long long kMirror(int k, int n) {
        vector<long long> mirrors;
        generatePalindromes(mirrors, k, n);
        long long sum = 0;
        for (auto num : mirrors) sum += num;
        return sum;
    }
};