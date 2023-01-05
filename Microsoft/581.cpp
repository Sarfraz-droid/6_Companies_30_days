
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        vector<int> arr = nums;
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int start = -1, end = -1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != nums[i])
            {
                if (start == -1)
                    start = i;
                else
                    end = i;
            }
        }

        if (start == -1 || end == -1)
            return 0;

        return end - start + 1;
    }
};