#include<bits/stdc++.h>
using namespace std;


struct data{
    int x, y, value;
};

int ans = INT_MAX;
int Ans[10];

void walk(int tabel[][10],int x, int y, int count,int htg[])
{
    if(tabel[x][y] == 3)
    {
        //cout << "\"3\" : "<< x<<" "<<y <<" "<< count<<endl;
        if(ans > count){ans = count;
            for(int i = 0; i < ans; i++)
            {
                Ans[i] = htg[i];
                //cout << " " << Ans[i];
            }
            //cout<<endl;
        }
        
    }
    if(tabel[x][y] == 0)
    {
        tabel[x][y] = 1;
        if(x - 1 > -1){htg[count] = 1;walk(tabel, x-1, y, count+1,htg);}//left
        if(y - 1 > -1){htg[count] = 2;walk(tabel, x, y-1, count+1,htg);}//down
        if(x + 1 < 10){htg[count] = 3;walk(tabel, x+1, y, count+1,htg);}//right
        if(y + 1 < 10){htg[count] = 4;walk(tabel, x, y+1, count+1,htg);}//up
    }
}

int main()
{
    ios_base::sync_with_stdio();cin.tie(0);
    cout << "=====================" << endl;
    int tabel[10][10] = {};
    struct data tree, hero, monster;
    int htg[100];
    tree.x = rand() % 9; tree.y = rand() % 9; tree.value = 1;
    hero.x = 6; hero.y = 1; hero.value = 2;
    monster.x = 4; monster.y = 2; monster.value = 3;
    tabel[tree.x][tree.y] = tree.value;
    tabel[hero.x][hero.y] = 0;
    tabel[monster.x][monster.y] = monster.value;

    walk(tabel, hero.x, hero.y, 0, htg);
    cout << "Tree point : " << tree.x << " " << tree.y << endl;
    cout << "Hero point : " << hero.x << " " << hero.y << endl;
    cout << "Monster point : " << monster.x << " " << monster.y << endl;
    cout << "Distance : "<< ans << " blocks" << endl;
    cout << " \" This tabel \"" << endl;
    memset(tabel, 0, sizeof(tabel));
    tabel[tree.x][tree.y] = tree.value;
    tabel[hero.x][hero.y] = hero.value;
    tabel[monster.x][monster.y] = monster.value;

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cout << tabel[i][j] << " ";
        }
        cout << endl;
    }
    cout << "how to go? : ";
    for(int i = 0; i < ans; i++)
    {
        if(Ans[i] == 1) cout << "left ";
        else if(Ans[i] == 2) cout << "down ";
        else if(Ans[i] == 3) cout << "right ";
        else if(Ans[i] == 4) cout << "up ";
    }


    cout << endl << "=====================";
}
/*
#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> vec[100100];
int c[10010];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    for(int i = 0; i < m; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        vec[a].push_back({c,b});
        vec[b].push_back({c,a});
    }
    for(int i = 0; i < m; i++)
    {
        sort(vec[i].begin(), vec[i].end());
    }
    for(int i = 0; i < q; i++)
    {
        int a,b;
        cin >> a >> b;
        int base = c[a-1] + c[b-1];
        (vec[a][0].first + vec[b][0].first > base)?cout << base << " 2" <<endl :cout << vec[a][0].first + vec[b][0].first<< " 4"<<endl;
    }
}*/