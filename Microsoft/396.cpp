#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int n = nums.size();
        int maxVal = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < n; i++)
        {
            maxVal += i * nums[i];
        }
        int lastpos = maxVal;

        for (int i = 1; i < n; i++)
        {
            int change = sum - n * nums[n - i];
            int nextpos = lastpos + change;
            lastpos = nextpos;
            maxVal = max(maxVal, nextpos);
        }

        return maxVal;
    }
};