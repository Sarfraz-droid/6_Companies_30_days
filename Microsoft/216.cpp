#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;
    void combination(int k, int n, vector<int> vis, vector<int> temp, int pos)
    {
        if (k == 0 && n == 0)
        {
            ans.push_back(temp);
        }

        if (n < 0)
            return;

        for (int i = pos + 1; i <= 9; i++)
        {
            if (vis[i])
                continue;
            vis[i] = 1;
            temp.push_back(i);
            combination(k - 1, n - i, vis, temp, i);
            temp.pop_back();
            vis[i] = 0;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> temp;
        vector<int> vis(10);
        combination(k, n, vis, temp, 0);

        return ans;
    }
};