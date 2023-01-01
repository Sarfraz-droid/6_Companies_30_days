#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string getHint(string s1, string s2)
    {

        unordered_map<int, int> mp1;
        int b = 0, c = 0;

        int n = s1.size();

        for (int i = 0; i < n; i++)
        {
            if (s1[i] == s2[i])
            {
                b++;
            }
            else
                mp1[s1[i]]++;
            // mp2[s2[i]].push_back(i);
        }

        for (int i = 0; i < n; i++)
        {
            if (s1[i] == s2[i])
                continue;
            else
            {
                // cout<<s2[i]<<" "<<mp1[s2[i]].size()<<endl;
                if (mp1[s2[i]] != 0)
                {
                    c++;
                    mp1[s2[i]]--;
                }
            }
        }

        return to_string(b) + "A" + to_string(c) + "B";
    }
};