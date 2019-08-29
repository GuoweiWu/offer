#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <stack>
#include <vector>
using namespace std;

const int max_n = 100001;
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp;
    for (size_t i = 0; i <= m; i++)
    {
        vector<int> m;
        for (size_t j = 0; j <= n; j++)
        {

            m.push_back(0);
        }
        dp.push_back(m);
    }

    dp[0][1] = 1;
    dp[1][0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1];
        }
    }
    return dp[m][n];
}

int main()
{
    cout<< uniquePaths(3,2);
    system("pause");
}