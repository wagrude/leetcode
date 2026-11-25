class Solution {
private:
    const long long M1 = 1000000007;
    const long long M2 = 1000000009;
    long long B1, B2;

    bool hasUniqueSubarray(int L, const vector<int>& nums) {
        int n = nums.size();

        long long P1 = 1, P2 = 1;
        for (int i = 0; i < L; ++i) {
            P1 = (P1 * B1) % M1;
            P2 = (P2 * B2) % M2;
        }

        long long h1 = 0, h2 = 0;
        for (int i = 0; i < L; ++i) {
            h1 = (h1 * B1 + nums[i]) % M1;
            h2 = (h2 * B2 + nums[i]) % M2;
        }

        vector<pair<long long, long long>> hashes;
        hashes.reserve(n - L + 1);
        hashes.push_back({h1, h2});

        for (int i = L; i < n; ++i) {
            h1 = (h1 * B1 + nums[i]) % M1;
            h1 = (h1 - (nums[i - L] * P1) % M1 + M1) % M1;

            h2 = (h2 * B2 + nums[i]) % M2;
            h2 = (h2 - (nums[i - L] * P2) % M2 + M2) % M2;

            hashes.push_back({h1, h2});
        }

        sort(hashes.begin(), hashes.end());

        int m = hashes.size();
        for (int i = 0; i < m; ++i) {
            bool left_diff = (i == 0 || hashes[i] != hashes[i - 1]);
            bool right_diff = (i == m - 1 || hashes[i] != hashes[i + 1]);
            if (left_diff && right_diff) {
                return true;
            }
        }
        return false;
    }

public:
    int smallestUniqueSubarray(vector<int>& nums) {
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        B1 = 100005 + rng() % 50000;
        B2 = 150005 + rng() % 50000;

        int low = 1, high = nums.size();
        int ans = nums.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (hasUniqueSubarray(mid, nums)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};