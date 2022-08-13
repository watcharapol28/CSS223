#include<bits/stdc++.h>
using namespace std;


struct data{
    int x, y, value;
};

int ans = INT_MAX;
int Ans[10];

void walk(int table[][10],int x, int y, int count,int htg[])
{
    if(table[x][y] == 3)
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
    if(table[x][y] == 0)
    {
        table[x][y] = 1;
        if(x - 1 > -1){htg[count] = 1;walk(table, x-1, y, count+1,htg);}//left
        if(y - 1 > -1){htg[count] = 2;walk(table, x, y-1, count+1,htg);}//down
        if(x + 1 < 10){htg[count] = 3;walk(table, x+1, y, count+1,htg);}//right
        if(y + 1 < 10){htg[count] = 4;walk(table, x, y+1, count+1,htg);}//up
    }
}

int main()
{
    ios_base::sync_with_stdio();cin.tie(0);
    cout << "=====================" << endl;
    int table[10][10] = {};
    struct data tree, hero, monster;
    int htg[100];
    tree.x = rand() % 9; tree.y = rand() % 9; tree.value = 1;
    hero.x = 6; hero.y = 1; hero.value = 2;
    monster.x = 4; monster.y = 2; monster.value = 3;
    table[tree.x][tree.y] = tree.value;
    table[hero.x][hero.y] = 0;
    table[monster.x][monster.y] = monster.value;

    walk(table, hero.x, hero.y, 0, htg);
    cout << "Tree point : " << tree.x << " " << tree.y << endl;
    cout << "Hero point : " << hero.x << " " << hero.y << endl;
    cout << "Monster point : " << monster.x << " " << monster.y << endl;
    cout << "Distance : "<< ans << " blocks" << endl;
    cout << " \" This table \"" << endl;
    memset(table, 0, sizeof(table));
    table[tree.x][tree.y] = tree.value;
    table[hero.x][hero.y] = hero.value;
    table[monster.x][monster.y] = monster.value;

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cout << table[i][j] << " ";
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