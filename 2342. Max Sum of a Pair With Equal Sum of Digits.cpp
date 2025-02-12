class Solution {
    public:
       
        int sum_of_digits(int num) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            return sum;
        }
    
        int maximumSum(vector<int>& nums) {
            unordered_map<int, vector<int>> digit_sum_map;
            
         
            for (int num : nums) {
                int digit_sum = sum_of_digits(num);
                digit_sum_map[digit_sum].push_back(num);
            }
    
            int max_sum = -1;
    
          
            for (auto& entry : digit_sum_map) {
                vector<int>& group = entry.second;
                if (group.size() > 1) {
                   
                    sort(group.rbegin(), group.rend());
                    max_sum = max(max_sum, group[0] + group[1]);
                }
            }
    
            return max_sum;
        }
    };