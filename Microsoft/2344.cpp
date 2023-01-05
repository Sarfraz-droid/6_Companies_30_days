#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, vector<int> &numsDivide)
    {
        int n = nums.size();
        int nd = numsDivide.size();

        unordered_map<int, int> mp;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
            if (mp[nums[i]] == 1)
            {
                pq.push(nums[i]);
            }
        }
        int count = 0;
        while (!pq.empty())
        {
            int val = pq.top();
            pq.pop();
            bool isValid = true;

            for (int i = 0; i < nd; i++)
            {
                if (numsDivide[i] % val != 0)
                {
                    isValid = false;
                    break;
                }
            }

            if (isValid)
                return count;
            count += mp[val];
        }

        return -1;
    }
};