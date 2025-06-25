class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> result;
        int n = nums.size();

        
        vector<int> keyIndices;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == key) {
                keyIndices.push_back(i);
            }
        }

        
        for (int i = 0; i < n; ++i) {
            for (int j : keyIndices) {
                if (abs(i - j) <= k) {
                    result.push_back(i);
                    break; 
                }
            }
        }

        return result;
    }
};