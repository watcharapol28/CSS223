#include<bits/stdc++.h>
using namespace std;

struct info
{
    int x, y, num;
};

int main()
{
    ios_base::sync_with_stdio();cin.tie(0);
    cout << fixed << setprecision(2);
    int Mybirth = 6, last_id = 1, last2_id = 2, tabel[12][12] = {};     //Birthday : Friday ,  ID : 64090500421
    struct info tree, hero, monster;
    
    srand (time(NULL));
    tree.x = rand() % 9 + 1; tree.y = rand() % 9 + 1; tree.num = 1;
    hero.x = Mybirth; hero.y = last_id; hero.num = 2;
    monster.x = 10 - Mybirth; monster.y = last2_id; monster.num = 3;
    
    tabel[tree.y - 1][tree.x - 1] = tree.num;
    tabel[hero.y - 1][hero.x - 1] = hero.num;
    tabel[monster.y - 1][monster.x - 1] = monster.num;

    cout << "\tInfo\nBirth day : Friday (6)\nID : 64090500421\nTree : " << tree.x << "," << tree.y << " \nHero : " << hero.x << "," << hero.y << "\nMonster : " << monster.x << "," << monster.y;
    cout << "\n   *** tabel! *** \n";
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cout << tabel[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Euclidean distance : " << sqrt(pow(hero.x - monster.x, 2) + pow(hero.y - monster.y, 2)) << endl;
    cout << "Manhattan distance : " << abs(hero.x - monster.x) + abs(hero.y - monster.y) << endl; 
    cout << "Chebychev distance : " << max(abs(hero.x - monster.x), abs(hero.y - monster.y)) << endl;
}


// Output
/*
    Info
Birth day : Friday (6)
ID : 64090500421
Tree : 6,9
Hero : 6,1
Monster : 4,2
   *** table! ***
0 0 0 0 0 2 0 0 0 0
0 0 0 3 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0 0 0
Euclidean distance : 2.24
Manhattan distance : 3
Chebychev distance : 2
*/