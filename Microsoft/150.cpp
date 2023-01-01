#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;

        int n = tokens.size();

        for (int i = 0; i < n; i++)
        {
            string token = tokens[i];

            if (token == "+")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a + b);
            }
            else if (token == "-")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b - a);
            }
            else if (token == "/")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b / a);
            }
            else if (token == "*")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a * b);
            }
            else
            {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};