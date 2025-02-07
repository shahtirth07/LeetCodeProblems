class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int xorResult = 0;

        for (int i = 0; i <= n; ++i)
        {
            xorResult ^= i;
        }
        for (int num : nums)
        {
            xorResult ^= num;
        }

        return xorResult;
    }
};
