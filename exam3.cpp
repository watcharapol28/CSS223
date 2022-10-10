#include<iostream>
#include<string.h>
using namespace std;
/*
int main()
{
    int check[130] = {};
    char str1[10010], str2[10010];
    cout << "Enter Words : ";
    cin >> str1;
    cout << "Find : ";
    cin >> str2;
    for(int i = 0; i < strlen(str1); i++)
    {
        check[str1[i]]++;
    }
    for(int i = 0; i < strlen(str2); i++)
    {
        if(check[str2[i]]-- <= 0){cout << "It's not Kangaroo"; return 0;}
    }
    cout << "It's Kangaroo";
}*/


int main()
{
    char str1[10010], str2[10010];
    cout << "Enter Words : ";
    cin >> str1;
    cout << "Find : ";
    cin >> str2;
    int now = 0;
    for(int i = 0; i < strlen(str1); i++)
    {
        if(str2[now] == str1[i]){now++;}
    }
    (now == strlen(str2)) ? cout << "It's Kangaroo" : cout << "It's not Kangaroo";
}