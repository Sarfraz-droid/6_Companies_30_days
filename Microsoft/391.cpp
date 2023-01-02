#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isRectangleCover(vector<vector<int>> &rect)
    {
        map<pair<int, int>, int> mp;
        int n = rect.size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            mp[{rect[i][0], rect[i][1]}]++;
            mp[{rect[i][0], rect[i][3]}]--;
            mp[{rect[i][2], rect[i][3]}]++;
            mp[{rect[i][2], rect[i][1]}]--;
        }

        for (auto x : mp)
        {
            if (x.second != 0)
            {
                if (abs(x.second) != 1)
                    return false;

                count++;
            }
        }

        return count == 4;
    }
};