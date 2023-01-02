#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> ans;
    vector<vector<int>> dp;
    int n;

    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        n = nums.size();
        sort(nums.begin(), nums.end());
        dp.resize(n + 1, vector<int>());

        for (int i = 0; i < n; i++)
        {
            dp[i].push_back(nums[i]);
            int j = i - 1;
            int pos = -1;
            while (j >= 0)
            {
                if (nums[j] % nums[i] == 0 || nums[i] % nums[j] == 0)
                {
                    if (pos == -1 || dp[pos].size() < dp[j].size())
                        pos = j;
                }
                j--;
            }

            if (pos != -1)
            {
                for (auto x : dp[pos])
                {
                    dp[i].push_back(x);
                }
            }
            if (ans.size() < dp[i].size())
            {
                ans = dp[i];
            }
        }

        return ans;
    }
};