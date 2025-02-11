class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1) return 1;
        
        int longest = 1; 
        int inc = 1; 
        int dec = 1;  
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                
                inc++;
                dec = 1; 
            } else if (nums[i] < nums[i - 1]) {
               
                dec++;
                inc = 1;  
            } else {
                
                inc = 1;
                dec = 1;
            }
            
            
            longest = max(longest, max(inc, dec));
        }
        
        return longest;
    }
};