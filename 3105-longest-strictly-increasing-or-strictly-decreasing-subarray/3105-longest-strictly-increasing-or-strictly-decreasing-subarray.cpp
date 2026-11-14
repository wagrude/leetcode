class Solution {
public:
    int longestMonotonicSubarray(std::vector<int>& nums) {
        int inc = 1, dec = 1, maxLength = 1;

        for (size_t i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] > nums[i]) {
                inc++;
                dec = 1;
            } else if (nums[i + 1] < nums[i]) {
                dec++;
                inc = 1;
            } else {
                inc = 1;
                dec = 1;
            }
            maxLength = max(maxLength, max(inc, dec));
        }

        return maxLength;
    }
};