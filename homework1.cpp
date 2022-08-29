/*// O(n log n)
#include<bits/stdc++.h>
#include<fstream>
using namespace std;


struct info{
    string name, type, sex, nick, enneagram, id;
    float data[8], distance;
}friends[1010];


int main()
{
    fstream fs;
    string temp;
    int numofstd = 0;

    fs.open("MBTI.csv"); //insert data of all students
    if (fs.is_open())
    {
        int column = 0, i = 0;
        while(getline(fs, temp, ','))
        {   
            if(temp.empty()){(column == 13)?column = 0:column++; continue;}
            cout << temp << " ";
            if(column == 0)
                friends[i].id = temp;
            else if(column == 1)
                friends[i].name = temp;
            else if(column == 2)
                friends[i].sex = temp;
            else if(column > 2 && column < 11)
            {
                friends[i].data[column - 3] = stoi(temp);
            }
            else if(column == 11) 
                friends[i].type = temp;
            else if(column == 12) 
                friends[i].enneagram = temp;
            if(column == 13) 
            {
                friends[i].nick = temp;
                i++; numofstd++; column = 0;
            }
            else
            {
                column++;
            }  
        }
        cout << "\nOperation successfully performed\n";
        fs.close();
    }
    else{cout<<"Error with open file \n";return 0;}
    

    struct info query;  //create query
    int k;
    cout << "\nQuery\nNe, Ni, Te, Ti, Se, Si, Fe, Fi\n";     

    for(int i = 0; i < 8; i++)
    {
        cin >> query.data[i];    // input query data
    }

    cout << "Enter K of Nearest Neighbors : ";
    cin >> k;
    
    int arr[k + 1];

    for(int i = 0; i < numofstd; i++)    //find distance with query and friends
    {
        int dist = 0;
        for(int j = 0; j < 8; j++)
        {
            dist += pow(query.data[j] - friends[i].data[j], 2);
        }
        friends[i].distance = sqrt(dist);
        if(i < 3)
        {
            arr[i] = friends[i].distance;
        }
        else
        {
            for(int i)
        }
        //cout << friends[i].nick << " " << friends[i].distance << endl;
    }

    sort(friends, friends + numofstd);
    char tyype[4];
    for(int j = 0; j < 4; j++)
    {
        int check[160] = {}, mx = INT_MIN;
        for(int i = 1; i < k + 1; i++)
        {
            if(++check[friends[i].type[j]] > mx && friends[i].type[j] != '\0')
            {
                //cout << check[friends[i].type[j]] << " " << friends[i].type[j] << endl ;
                mx = check[friends[i].type[j]];
                tyype[j] = friends[i].type[j];
            }
        }
    }
    cout << k << " peoples nearest you : ";
    for(int i = 1; i < k + 1; i++)
    {
        cout << endl << friends[i].nick << "\t(" << friends[i].type << ")" ;
    }

    query.type = tyype;
    cout << "\nYour type with KNN : " << query.type;

}*/


// O(n log n)
#include<bits/stdc++.h>
#include<fstream>
using namespace std;


struct info{
    string name, type, sex, nick, enneagram, id;
    float data[8], distance;
    bool operator < (const info b) const
    {
        return distance < b.distance;
    }
}friends[1010];


int main()
{
    fstream fs;
    string temp;
    int numofstd = 0;

    fs.open("MBTI.csv"); //insert data of all students
    if (fs.is_open())
    {
        int column = 0, i = 0;
        while(getline(fs, temp, ','))
        {   
            if(temp.empty()){(column == 13)?column = 0:column++; continue;}
            cout << temp << " ";
            if(column == 0)
                friends[i].id = temp;
            else if(column == 1)
                friends[i].name = temp;
            else if(column == 2)
                friends[i].sex = temp;
            else if(column > 2 && column < 11)
            {
                friends[i].data[column - 3] = stoi(temp);
            }
            else if(column == 11) 
                friends[i].type = temp;
            else if(column == 12) 
                friends[i].enneagram = temp;
            if(column == 13) 
            {
                friends[i].nick = temp;
                i++; numofstd++; column = 0;
            }
            else
            {
                column++;
            }  
        }
        cout << "\nOperation successfully performed\n";
        fs.close();
    }
    else{cout<<"Error with open file \n";return 0;}
    

    struct info query;  //create query
    int k;
    cout << "\nQuery\nNe, Ni, Te, Ti, Se, Si, Fe, Fi\n";     

    for(int i = 0; i < 8; i++)
    {
        cin >> query.data[i];    // input query data
    }

    cout << "Enter K of Nearest Neighbors : ";
    cin >> k;

    for(int i = 0; i < numofstd; i++)    //find distance with query and friends
    {
        int dist = 0;
        for(int j = 0; j < 8; j++)
        {
            dist += pow(query.data[j] - friends[i].data[j], 2);
        }
        friends[i].distance = sqrt(dist);
        //cout << friends[i].nick << " " << friends[i].distance << endl;
    }

    sort(friends, friends + numofstd);
    char tyype[4];
    for(int j = 0; j < 4; j++)
    {
        int check[160] = {}, mx = INT_MIN;
        for(int i = 1; i < k + 1; i++)
        {
            if(++check[friends[i].type[j]] > mx && friends[i].type[j] != '\0')
            {
                //cout << check[friends[i].type[j]] << " " << friends[i].type[j] << endl ;
                mx = check[friends[i].type[j]];
                tyype[j] = friends[i].type[j];
            }
        }
    }
    cout << k << " peoples nearest you : ";
    for(int i = 1; i < k + 1; i++)
    {
        cout << endl << friends[i].nick << "\t(" << friends[i].type << ")" ;
    }

    query.type = tyype;
    cout << "\nYour type with KNN : " << query.type;

}

//  INPUT  26.4 24.6 24 30 30 24 23 25 
//  INPUT  3

//  OUTPUT ESTJ




/*
// test O(n log n)
#include<bits/stdc++.h>
using namespace std;

struct info{
    char name[10], type[4];
    float data[8], distance;
    bool operator < (const info &b) const
    {
        return distance < b.distance;
    }
};

int main()
{
    struct info d[15], query;
    for(int i = 0; i < 15; i++)
    {
        cout << "Name : ";
        cin >> d[i].name;
        cout << "Ne Ni TE Ti Se Si Fe Fi  Type\n";
        for(int j = 0; j < 8; j++)
        {
            cin >> d[i].data[j];
        }
        cin >> d[i].type;
    }
    cout << "\nQuery Name : ";
    cin >> query.name;
    cout << "Ne Ni TE Ti Se Si Fe Fi\n";
    for(int j = 0; j < 8; j++)
    {
        cin >> query.data[j];
    }
    for(int i = 0; i < 15; i++)
    {
        int dis = 0;
        for(int j = 0; j < 8; j++)
        {
            dis += pow(query.data[j] - d[i].data[j], 2);   // O(CN)
        }
        d[i].distance = sqrt(dis);
    }

    sort(d, d + 15);    // O(NlogN)

    int k;
    char Type_query[4];
    cout << "\nEnter K Nearest Neighbors : ";
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
    cout << "\nType : " << Type_query;
}
*/
