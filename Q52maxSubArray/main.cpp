#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <stack>
#include <vector>
using namespace std;

int max_n = 1001;
int maxSubArray(vector<int> &nums)
{
    
    int max_ending_here = nums[0];
    int res = nums[0];
    for (size_t i = 1; i < nums.size(); i++)
    {
        max_ending_here = max(nums[i],max_ending_here + nums[i]);
        res = max(res,max_ending_here);
    }
    return res;
}

int main()
{
}