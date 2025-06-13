class Solution {
public:
    
    bool canFormPairs(vector<int>& nums, int p, int maxDiff) {
        int count = 0;
        int i = 1;
        while (i < nums.size()) {
            
            if (nums[i] - nums[i - 1] <= maxDiff) {
                count++;
                i += 2; 
            } else {
                i++; 
            }
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end()); 

        int low = 0, high = nums[nums.size() - 1] - nums[0];
        int answer = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canFormPairs(nums, p, mid)) {
                answer = mid;     
                high = mid - 1;   
            } else {
                low = mid + 1;     
            }
        }

        return answer;
    }
};