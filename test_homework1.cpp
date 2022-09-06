//test KNN test
#include<iostream>
#include<fstream>
using namespace std;

/*
struct dataofpoint{
    char name;
    float x, y, d;
    bool operator < (const dataofpoint &b) const
    {
        return d < b.d;
    }
}p[1100];

char knn(int n, int k)
{
    int check[129] = {}, now = 0;
    char ans;

    for(int i = 0; i < k; i++)
    {
        if(++check[p[i].name] > now)
        {
            now = check[p[i].name];
            ans = p[i].name;
        }
    }
    return ans;
}

int main()
{
    int n, k;
    float x, y;
    cout << "Enter your point (x,y) : ";
    cin >> x >> y;
    cout << "How many points? : ";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cout << "x, y and name of point(" << i + 1 << "): ";
        cin >> p[i].x >> p[i].y >> p[i].name;
        p[i].d = sqrt(pow(x - p[i].x, 2) + pow(y - p[i].y, 2));
    }
    cout << "Enter K : ";
    cin >> k;
    sort(p, p + n);
    cout << "Name of " << k << " points closest to your point : " << knn(n, k);
}
*/

/*

INPUT

5 4
10
1 2 A
1 3 A
3 5 A
2 3 B
3 3 B
1 4 C
5 2 B
1 4 C
5 5 B
6 5 C
3


OUTPUT

Enter your point (x,y) : 5 4
How many points? : 10
x, y and name of point(1): 1 2 1
x, y and name of point(2): 1 3 1
x, y and name of point(3): 3 5 1
x, y and name of point(4): 2 3 2
x, y and name of point(5): 3 3 2
x, y and name of point(6): 1 4 3
x, y and name of point(7): 5 2 2
x, y and name of point(8): 1 4 3
x, y and name of point(9): 5 5 2
x, y and name of point(10): 6 5 3
Enter K : 3
Name of 3 points closest to your point : 2

*/

struct info{
    string name, type, sex, nick, enneagram, id;
    float data[8], distance;
}friends;


class Node
{
    public:
        string name, type, sex, nick, enneagram, id;
        float data[8], distance;
        Node *next;
        Node *prev;
};

//arrange
class arrange
{
    public:
        Node *head;
        Node *tail;
        Node *fence;
    public:
        arrange()
        { 
            head = NULL;
            tail = NULL;
        }
    void arrange_node()
    {
        Node* newnode = new Node;
        newnode->id = friends.id;
        newnode->name = friends.name;
        newnode->nick = friends.nick;
        newnode->sex = friends.sex;
        newnode->type = friends.type;
        newnode->enneagram = friends.enneagram;
        for(int i = 0; i < 8; i++)
        {
            newnode->data[i] = friends.data[i];
        }
    }
};



int main()
{
    fstream fs;
    string temp;
    int numofstd = 0;
    arrange data;
    fs.open("MBTI.csv"); //insert data of all students
    if (fs.is_open())
    {
        int column = 0, i = 0;
        while(getline(fs, temp, ','))
        {   
            if(temp.empty()){(column == 13)?column = 0:column++; continue;}
            cout << temp << " ";
            if(column == 0)
                friends.id = temp;
            else if(column == 1)
                friends.name = temp;
            else if(column == 2)
                friends.sex = temp;
            else if(column > 2 && column < 11)
            {
                friends.data[column - 3] = stoi(temp);
            }
            else if(column == 11) 
                friends.type = temp;
            else if(column == 12) 
                friends.enneagram = temp;
            if(column == 13) 
            {
                friends.nick = temp;
                i++; numofstd++; column = 0;
                data.arrange_node();
            }
            else
            {
                column++;
            }  
        }
        cout << "\nOperation successfully performed\n";
        fs.close();
    }
}