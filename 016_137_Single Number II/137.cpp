/* Solution 1: XOR with two variables */
class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int ones = 0;
        int twos = 0;

        for (const int num : nums) {
            ones = ones ^ (num & ~twos);
            twos = twos ^ (num & ~ones);
        }

        return ones;
    }
};

/* Solution 2: modulo by 3 (32-bit systems) */
class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int ans = 0;

        for (int i = 0; i < 32; ++i) {
            int sum = 0;
            for (const int num : nums)
                sum += num >> i & 1;
            sum %= 3;
            ans |= sum << i;
        }

        return ans;
    }
};