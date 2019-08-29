#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

const int MAX_N = 1000;

int countCharacters(vector<string> &words, string chars)
{
    const int length = chars.size();

    bool used[MAX_N];

    for (size_t i = 0; i < MAX_N; i++)
    {
        used[i] = false;
    }
    int result = 0;
    for (size_t i = 0; i < words.size(); i++)
    {
        bool flag = false;
        for (size_t j = 0; j < words[i].size(); j++)
        {
            bool flag2 = false;
            for (int k = 0; k < chars.size(); k++)
            {
                if (chars[k] == words[i][j] && used[k] == false)
                {
                    used[k] = true;
                    break;
                }
                
                if (k == chars.size() - 1)
                {
                    if(chars[k] != words[i][j] || used[k] == true)
                        flag2 = true;
                }else
                {
                    continue;
                }
            }
            if (flag2)
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            result += words[i].size();
        }
        for (size_t i = 0; i < MAX_N; i++)
        {
            used[i] = false;
        }
    }
    return result;
}

int main()
{
    vector<string> words;
    words.push_back("cat");
    words.push_back("bt");
    words.push_back("hat");
    words.push_back("tree");
    string chars = "atach";
    int result = countCharacters(words, chars);
    cout << result;
    system("pause");
    return 0;
}