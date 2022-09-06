// O()
#include<bits/stdc++.h>
#include<fstream>
using namespace std;


struct info{
    string name, type, sex, nick, enneagram, id;
    float data[8], distance;
}friends[1010];


class Node
{
    public:
        int point;
        float distance;
        Node *next;
        Node *prev;
};


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
    void arrange_node(int i)
    {
        Node* newnode = new Node;
        newnode->point = i;
        newnode->distance = friends[i].distance;
        newnode->next = NULL;
        newnode->prev = NULL;

        if (head == NULL) 
        {
            head = newnode;
            tail = newnode;
            fence = newnode;
        }
        else
        {
            if (newnode->distance < head->distance)
            {
                newnode->next = head;
                head->prev = newnode;
                head = newnode;
                fence = head;
            }
            else
            {
                fence = head;
                while (fence->next != NULL)
                {
                    if (newnode->distance < fence->next->distance)
                    {
                        newnode->next = fence->next;
                        fence->next->prev = newnode;
                        fence->next = newnode;
                        newnode->prev = fence;
                        return;
                    }
                    fence = fence->next;
                }
                fence->next = newnode;
                newnode->prev = fence;
                tail = newnode;
            }
        }
    }
    void show(int k)
    {
        char tyype[4];
        for(int j = 0; j < 4; j++)
        {
            int check[160] = {}, mx = INT_MIN;
            fence = (head->distance == 0)?head->next : head;
            for(int i = 0; i < k; i++)
            {
                if(++check[friends[fence->point].type[j]] > mx && friends[fence->point].type[j] != '\0')
                {
                //cout << check[friends[i].type[j]] << " " << friends[i].type[j] << endl ;
                mx = check[friends[fence->point].type[j]];
                tyype[j] = friends[fence->point].type[j];
                }
                fence = fence->next;
            }
        }
        cout << k << " peoples nearest you : ";
        fence = (head->distance == 0)?head->next : head;
        for(int i = 0; i < k; i++)
        {
            cout << endl << friends[fence->point].nick << "\t(" << friends[fence->point].type << ")" ;
            fence = fence->next;
        }
        cout << "\nYour type with KNN : " << tyype;
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
        data.arrange_node(i);//push to linked list
    }
    data.show(k);
}

//  INPUT  26.4 24.6 24 30 30 24 23 25 
//  INPUT  3

//  OUTPUT ESTJ


