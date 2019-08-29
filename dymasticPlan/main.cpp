#include <iostream>
#include <vector>
#include<algorithm>
#include<math.h>
using namespace std;

const int MAX_N =1000;
int dp[MAX_N][MAX_N];

int n = 4;
int W = 5;
int w[MAX_N], v[MAX_N];
int rec(int i, int j){
    int res;
    if(dp[i][j] >= 0){
        return dp[i][j];
    }
    if(i == n){
        res = 0;
    }
    else if(i < n && j + w[i] > W){
        res = rec(i+1,j);
    }else{
        res = max(rec(i+1,j), rec(i,j-w[i]) + v[i]);
    }
    return dp[i][j] = res;
    
}
int main(){
    memset(dp,-1,sizeof(dp));
    printf("%d\n",rec(0,W));
}