#include<bits/stdc++.h>
using namespace std;

char sb[3];

struct multi{
    int No, a, b, c;
} mul[15];


bool sort_by(multi const &x, multi const &y)
{
    if(sb[0] == 'A')
    {
        if(x.a == y.a)
        {
            if(sb[1] == 'B')
            {
                if(x.b == y.b)
                {
                    return x.c < y.c;
                }
                return x.b < y.b;
            }
            else
            {
                if(x.c == y.c)
                {
                    return x.b < y.b;
                }
                return x.c < y.c;
            }
        }
        return x.a < y.a;
    }
    else if(sb[0] == 'B')
    {
        if(x.b == y.b)
        {
            if(sb[1] == 'A')
            {
                if(x.a == y.a)
                {
                    return x.c < y.c;
                }
                return x.a < y.a;
            }
            else
            {
                if(x.c == y.c)
                {
                    return x.a < y.a;
                }
                return x.c < y.c;
            }
        }
        return x.b < y.b;
    }
    else
    {
        if(x.c == y.c)
        {
            if(sb[1] == 'B')
            {
                if(x.b == y.b)
                {
                    return x.a < y.a;
                }
                return x.b < y.b;
            }
            else
            {
                if(x.a == y.a)
                {
                    return x.b < y.b;
                }
                return x.a < y.a;
            }
        }
        return x.c < y.c;
    }
}


int main()
{
    cout << "A B C\n";
    for(int i = 0; i < 14; i++)
    {
        mul[i].No = i + 1;
        cin >> mul[i].a >> mul[i].b >> mul[i].c;
    }
    cout << "Sort by (ex. BAC) : ";
    cin >> sb;
    sort(mul, mul + 14, sort_by);
    cout << "\nNo.\tA B C\n";
    for(int i = 0; i < 14; i++)
    {
        cout << mul[i].No << "\t" << mul[i].a << " " << mul[i].b << " " << mul[i].c << endl;
    }
}
/*
1 1 4
3 1 1
4 4 4
2 4 4
3 5 3
4 3 3
1 3 3
2 4 3
3 3 5
1 5 3
1 1 4
4 1 1
5 2 3
3 5 2
ABC
*/