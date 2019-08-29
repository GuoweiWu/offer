#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int day1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int day2[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dayOfYear(string date)
{
    int year = (date[0] -'0') * 1000 +  (date[1] -'0')  * 100 +  (date[2] -'0')  * 10 +  (date[3] -'0') ;
    int month = (date[5] -'0')  * 10 +  (date[6] -'0');
    int day = (date[8] - '0') * 10 +  (date[9] -'0');  
    int days = 0;
    if(year % 400 == 0 ||(year % 4 == 0 && year % 100 != 0)){
        for(int i = 0 ; i < month-1; i++){
            days +=day2[i];
        }
        days +=day;
    }
    else{
        for(int i = 0 ; i < month-1; i++){
            days +=day1[i];
        }
        days +=day;
    }
    return day;
}
int main()
{
    cout<< dayOfYear("2019-02-10");
    system("pause");
}