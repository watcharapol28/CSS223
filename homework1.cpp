#include<bits/stdc++.h>
using namespace std;

struct info{
    char name[10], type[5];
    float data[9], distance;
    bool operator < (const info &b) const
    {
        return distance < b.distance;
    }
};

int main()
{
    struct info d[17], query;
    for(int i = 0; i < 15; i++)
    {
        cout << "Name : ";
        cin >> d[i].name;
        cout << "Ne Ni TE Ti Se Si Fe Fi  type\n";
        for(int j = 0; j < 8; j++)
        {
            cin >> d[i].data[j];
        }
        cin >> d[i].type;
    }
    cout << "Query Name : ";
    cin >> query.name;
    cout << "Ne Ni TE Ti Se Si Fe Fi  type\n";
    for(int j = 0; j < 8; j++)
    {
        cin >> query.data[j];
    }
    for(int i = 0; i < 15; i++)
    {
        int dis = 0;
        for(int j = 0; j < 8; j++)
        {
            dis += pow(query.data[j] - d[i].data[j], 2);
        }
        d[i].distance = sqrt(dis);
    }

    sort(d, d + 15);

    int k;
    char Type_query[5];
    cout << "Enter K Nearest Neighbors : ";
    cin >> k;

    for(int j = 0; j < 4; j++)
    {
        int check[150] = {}, now = INT_MIN;
        for(int i = 0; i < k; i++)
        {
            if(++check[d[i].type[j]] > now)
            {
                now = check[d[i].type[j]];
                Type_query[j] = d[i].type[j];
            }
        }
    }
    cout << "Type : " << Type_query;
}

/*
Kuuga 
35.4 31 33 30 38 31 34 31 ENTP
Agito 
26 31 33 30 26 33 30 24 INTJ
Ryuki 
24.4 30.2 31 34 28 36 22 17 ISTJ
Blade 
22.2 25.8 36 37 29 36 34 22 ENTJ
Hibiki 
43.2 34 36 36 39 38 40 35 INTP
Kabuto 
32.4 27 35 34 27 23 31 19 ENFP
Den-O 
28.4 25.6 33 35 32 30 24 26 ESTP
Kiva 
30.2 31.4 35 33 36 33 36 34 ENTJ
Decade 
19.4 12 25 28 25 23 23 22 ESTJ
Fourze 
33.4 38.6 29 29 26 37 24 25 INTJ
Gaim 
30 29.6 34 32 38 28 33 22 ENTP
Ex-Aid 
29 22.8 40 28 27 31 29 19 ENTJ
Zi-O 
25.5 33 28 34 37 27 28 24 INFJ
Saber 
29.8 26.4 28 36 29 30 33 28 INTJ
Revice 
18.4 15 30 33 33 31 26 23 ESTJ
Query
32 32 27 36 29 31 28 23
*/