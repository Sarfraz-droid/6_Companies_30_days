#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string longestPrefix(string s)
    {
        string ans = "";
        vector<int> dp(s.size(), 0);
        int i = 0, j = 1;
        while (j < s.size())
        {
            if (s[i] == s[j])
            {
                dp[j] = i + 1;
                i++;
                j++;
            }
            else if (i)
            {
                i = dp[i - 1];
            }
            else
            {
                j++;
            }
        }
        ans = s.substr(0, i);
        return ans;
    }
};