#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    string a;
    scanf("%d", &n);
    vector<int> num;
    vector<char> index;

    for (size_t i = 0; i < n - 1; i++)
    {
        int temp;
        char tempIndex;
        scanf("%d %c", &temp, &tempIndex);
        num.push_back(temp);
        index.push_back(tempIndex);
    }
    int temp;
    scanf("%d", &temp);
    num.push_back(temp);
    vector<int> result;

    for (int i = 0; i < index.size() - 1; i++)
    {
        vector<int> tempresult;
        while ((index[i] == '+' || index[i] == '-') && (index[i + 1] != '*') && (index[i + 1] != '/'))
        {
            tempresult.push_back(num[i++]);
        }
        tempresult.push_back(num[i++]);
        sort(tempresult.begin(), tempresult.end());
        result.insert(result.end(), tempresult.begin(), tempresult.end());
        tempresult.clear();
        while ((index[i] == '*') && (index[i + 1] != '+' || index[i + 1] != '-'))
        {
            tempresult.push_back(num[i++]);
        }
        tempresult.push_back(num[i++]);
        sort(tempresult.begin(), tempresult.end());
        result.insert(result.end(), tempresult.begin(), tempresult.end());
    }
    vector<int> tempresult;
    tempresult.push_back(num[index.size() - 1]);
    sort(tempresult.begin(), tempresult.end());
    result.insert(result.end(), tempresult.begin(), tempresult.end());
    
    for (size_t i = 0; i < index.size(); i++)
    {
        cout << result[i] << " " << index[i] << " ";
    }
    cout << result[n - 1];
}