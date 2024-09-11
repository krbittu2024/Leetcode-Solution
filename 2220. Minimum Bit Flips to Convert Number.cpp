class Solution {
public:
    int minBitFlips(unsigned start, int goal) {
        return popcount(start ^ goal);
    }
};