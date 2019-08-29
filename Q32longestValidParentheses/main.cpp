#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <stack>
#include <vector>
using namespace std;

const int max_n = 100001;
int longestValidParentheses(string s)
{
    vector<int> dp(s.size());
    for (int i = 0; i < dp.size(); i++)
    {
        dp[i] = 0;
    }

    int result = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            dp[i] = 0;
        }
        else if (s[i] == ')')
        {
            if (s[i - 1] == '(')
            {
                if (i > 2)
                {
                    result = max(dp[i] = dp[i - 2] + 2, result);
                }
                else
                {
                    result = max(dp[i] = 2, result);
                }
            }
            else if (i - 1 >= 0 && i - dp[i - 1] - 1 >= 0)
                if (s[i - dp[i - 1] - 1] == '(')
                {
                    if (i - dp[i - 1] - 2 >= 0)
                    {
                        result = max(dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2], result);
                    }
                    else
                    {
                        result = max(dp[i] = dp[i - 1] + 2, result);
                    }
                }
        }
    }
    return result;
}

int main()
{

    cout << longestValidParentheses(")(((((()())()()))()(()))(");
    system("pause");
}