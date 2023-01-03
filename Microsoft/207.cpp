#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool helper(vector<bool> &visit, unordered_map<int, vector<int>> &mp, int i)
    {
        if (visit[i])
            return false;

        if (mp[i].size() == 0)
            return true;
        visit[i] = true;
        for (auto x : mp[i])
        {
            if (!helper(visit, mp, x))
                return false;
        }
        visit[i] = false;
        mp[i].clear();

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, vector<int>> mp;

        for (auto x : prerequisites)
        {
            mp[x[0]].push_back(x[1]);
        }

        vector<bool> visit(numCourses, false);

        for (int i = 0; i < numCourses; i++)
        {
            if (!helper(visit, mp, i))
                return false;
        }

        return true;
    }
};