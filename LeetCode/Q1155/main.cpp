#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
const int MOD = 1000000007;
int numRollsToTarget(int d, int f, int target)
{
    int dp[31][1001];
    int min1 = min(f, target);
    for (int i = 1; i <= min1; i++)
    {
        dp[1][i] = 1;
    }
    int targetMax = d * f;
    for (int i = 2; i <= d; i++)
    {
        for (int j = i; j <= targetMax; j++)
        {
            for (int k = 1; j - k >= 0 && k <= f; k++)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
            }
        }
    }

    int main()
    {
        cout << numRollsToTarget(1, 6, 3);
        system("pause");
    }