class Solution {
public:
    // Count the number of products <= mid
    long long countLessEqual(vector<int>& nums1, vector<int>& nums2, long long mid) {
        int n1 = nums1.size(), n2 = nums2.size();
        long long count = 0;

        for (int i = 0; i < n1; ++i) {
            long long a = nums1[i];
            if (a == 0) {
                if (mid >= 0) count += n2;
            } else if (a > 0) {
                int l = 0, r = n2 - 1, pos = -1;
                while (l <= r) {
                    int m = l + (r - l) / 2;
                    if (a * (long long)nums2[m] <= mid) {
                        pos = m;
                        l = m + 1;
                    } else {
                        r = m - 1;
                    }
                }
                count += (pos + 1);
            } else { // a < 0
                int l = 0, r = n2 - 1, pos = n2;
                while (l <= r) {
                    int m = l + (r - l) / 2;
                    if (a * (long long)nums2[m] <= mid) {
                        pos = m;
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                }
                count += (n2 - pos);
            }
        }

        return count;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long left = -1e10, right = 1e10, ans = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (countLessEqual(nums1, nums2, mid) >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};