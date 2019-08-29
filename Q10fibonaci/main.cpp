#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

vector<int> result;

int fibonacci(int n){
    if(result.size()>= n){
        return result[n-1];
    }
    result.push_back(fibonacci(n-1)+ fibonacci(n-2));

    return result[n-1];
}
int main(){
    result.push_back(1);
    result.push_back(1);
    cout<<fibonacci(10);
    system("pause");
}