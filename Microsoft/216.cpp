#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;
    void combination(int k, int n, vector<int> temp, int pos)
    {
        if (k == 0 && n == 0)
        {
            ans.push_back(temp);
        }

        if (n < 0)
            return;

        for (int i = pos + 1; i <= 9; i++)
        {
            temp.push_back(i);
            combination(k - 1, n - i, temp, i);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> temp;
        combination(k, n, temp, 0);

        return ans;
    }
};