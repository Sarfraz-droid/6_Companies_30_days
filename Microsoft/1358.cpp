#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.size();
        int i = 0, j = 0;
        vector<int> mp(3);
        int count = 0;

        while (i <= j && i < n && j < n)
        {
            mp[s[j] - 'a']++;
            while (mp[0] > 0 && mp[1] > 0 && mp[2] > 0)
            {
                count += n - j;
                mp[s[i] - 'a']--;
                i++;
            }
            j++;
        }

        return count;
    }
};