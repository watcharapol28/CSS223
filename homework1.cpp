//homework 1 ??
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio();cin.tie(0);
    int x, y, x2, y2;
    cout << " Input[1] x, y : ";
    cin >> x >> y;
    cout << " Input[2] x, y : ";
    cin >> x2 >> y2;
    cout << "Euclidean distance : "<< sqrt(pow(x - x2, 2) + pow(y - y2, 2));
}