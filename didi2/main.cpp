#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <stdio.h>
using namespace std;

const int MAX_N = 1000;
int main()
{

    int n;
    int total;
    int cost;
    cin >> n >> total >> cost;
    int times = total / cost;
    int aNums[MAX_N];
    int bNums[MAX_N];
    for (int i = 0; i < n; i++)
    {
        cin >> aNums[n - i - 1] ;
    }
    for (int i = 0; i < n; i++)
    {
       cin >> bNums[n - i - 1] ;
    }

    int dp[MAX_N][MAX_N];

    int rest = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (aNums[i - 1] == bNums[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] == 1)
                {
                    if (i + j - 2 < rest)
                    {
                        rest = i + j - 2;
                    }
                }
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    if (rest + dp[n][n] > times)
    {
        dp[n][n] -= rest + dp[n][n] - times;
    }

    cout << (dp[n][n] > 0 ? dp[n][n] : 0);
}
