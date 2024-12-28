class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> sum(n - k + 1, 0);

        sum[0] = 0;
        for (int i = 0; i < k; ++i) {
            sum[0] += nums[i];
        }

        for (int i = 1; i <= n - k; ++i) {
            sum[i] = sum[i - 1] - nums[i - 1] + nums[i + k - 1];
        }
        for (int i = 1; i <= n - k; ++i) {
            sum[i] = sum[i - 1] - nums[i - 1] + nums[i + k - 1];
        }
        vector<int> left(n - k + 1, 0);
        vector<int> right(n - k + 1, n - k);
        for (int i = 1; i <= n - k; ++i) {
            if (sum[i] > sum[left[i - 1]]) {
                left[i] = i;
            } else {
                left[i] = left[i - 1];
            }
        }
        for (int i = n - k - 1; i >= 0; --i) {
            if (sum[i] >= sum[right[i + 1]]) {
                right[i] = i;
            } else {
                right[i] = right[i + 1];
            }
        }
        int maxSum = 0;
        vector<int> result(3);
        for (int i = k; i <= n - 2 * k; ++i) {
            int leftIdx = left[i - k];
            int rightIdx = right[i + k];
            int currentSum = sum[leftIdx] + sum[i] + sum[rightIdx];
            
            if (currentSum > maxSum) {
                maxSum = currentSum;
                result = {leftIdx, i, rightIdx};
            }
        }
        
        return result;
    }
};