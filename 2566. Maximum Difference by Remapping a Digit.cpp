class Solution {
public:
    int remap(string numStr, char fromDigit, char toDigit) {
        for (char &ch : numStr) {
            if (ch == fromDigit)
                ch = toDigit;
        }
        return stoi(numStr);
    }

    int minMaxDifference(int num) {
        string numStr = to_string(num);
        int maxVal = num;
        int minVal = num;

        for (char from = '0'; from <= '9'; ++from) {
            for (char to = '0'; to <= '9'; ++to) {
                int changed = remap(numStr, from, to);
                maxVal = max(maxVal, changed);
                minVal = min(minVal, changed);
            }
        }
        return maxVal - minVal;
    }
};