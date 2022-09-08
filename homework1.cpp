// O(n)
#include<bits/stdc++.h>
#include<fstream>
using namespace std;


struct info
{
    string name, type, sex, nick, enneagram, id;
    float data[8], distance;
};


class Node
{
    public:
        string name, type, sex, nick, enneagram, id;
        float data[8], distance;
        Node *next;
        Node *prev;
};


class arrange
{
    public:
        Node *head;
        Node *tail;
        Node *fence;
        bool check = false;
    public:
        arrange()
        { 
            head = NULL;
            tail = NULL;
        }


    void insert(Node* curr, info Info)
    {
        curr->distance = Info.distance;
        curr->next = NULL;
        curr->prev = NULL;
        for(int i = 0; i < 8; i++)
        {
            curr->data[i] = Info.data[i];
        }
        curr->enneagram = Info.enneagram;
        curr->id = Info.id;
        curr->name = Info.name;
        curr->nick = Info.nick;
        curr->sex = Info.sex;
        curr->type = Info.type;
    }


    void arrange_node(int k, info Info)
    {
        Node* newnode = new Node;

        if(head == NULL)
        {
            insert(newnode, Info);
            head = newnode;
            tail = newnode;
            fence = head;
        }
        else
        {
            if(Info.distance < head->distance)
            {
                insert(newnode, Info);
                newnode->next = head;
                head->prev = newnode;
                head = newnode;
                if(check){tail = tail->prev;}
            }
            else
            {
                fence = head;
                for(int i = 0; i < k; i++)
                {
                    if(fence->next == NULL)
                    {
                        insert(newnode, Info);
                        fence->next = newnode;
                        newnode->prev = fence->next;
                        tail = newnode;
                        return;
                    }
                    else if(Info.distance < fence->next->distance)
                    {
                        check = true;
                        insert(newnode, Info);
                        newnode->next = fence->next;
                        newnode->prev = fence;
                        fence->next->prev = newnode;
                        fence->next = newnode;
                        fence = tail;
                        tail = fence->prev;
                        //tail->next->prev = NULL;
                        //tail->next = NULL;
                        return ;
                    }
                    fence = fence->next;
                }
                tail = fence;
            }
        }
    }


    void show(int k)
    {
        cout << k << " peoples nearest you : \n";
        fence = (head->distance == 0) ? head->next : head;
        //cout << " XXX  " << fence->type[1] <<endl;
        for(int j = 0; j < k; j++)
            {
                cout << j + 1 << ". (" << fence->type << ")  " << fence->nick << " " <<endl;
                fence = fence->next;
            }

        char ans[4];
        for(int i = 0; i < 4; i++)
        {
            fence = (head->distance == 0) ? head->next : head;
            int check[200] = {}, mx = INT_MIN;
            for(int j = 0; j < k; j++)
            {
                if(++check[fence->type[i]] > mx)
                {
                    mx = check[fence->type[i]];
                    ans[i] = fence->type[i];
                    
                }
                fence = fence->next;
            }
        }
        cout << "Query type is " << ans;
    }
};


int main()
{
    int k, numofstd = 0;
    info Info, me;
    queue <info> q;
    
    arrange data;
    
    fstream fs;
    string temp;
    
    float sum = 0;
    fs.open("MBTI.csv"); //insert data of all students
    if (fs.is_open())
    {
        int column = 0, i = 0;
        while(getline(fs, temp, ','))
        {   
            if(temp.empty()){(column == 13)?column = 0:column++; sum = 0;continue;}
            cout << temp << " ";
            if(column == 0)
                Info.id = temp;
            else if(column == 1)
                Info.name = temp;
            else if(column == 2)
                Info.sex = temp;
            else if(column > 2 && column < 11)
            {
                Info.data[column - 3] = stoi(temp);
                //sum = pow((Info.data[column - 3] - me.data[column - 3]), 2);
            }
            else if(column == 11) 
                Info.type = temp;
            else if(column == 12) 
                Info.enneagram = temp;
            if(column == 13) 
            {
                Info.nick = temp;
                i++; column = 0; numofstd++;
                //float dis = sqrt(sum);
                //sum = 0;
                //data.arrange_node(dis, k, Info);
                q.push(Info);
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


    cout << "Query\nNe, Ni, Te, Ti, Se, Si, Fe, Fi\n"; 
    for(int i = 0; i < 8; i++)
    {
        cin >> me.data[i];    // input query data
    }
    cout << "Enter K of Nearest Neighbors : ";
    cin >> k;

    for(int i = 0; i < numofstd; i++)
    {
        int dis = 0;
        info Inf = q.front();
        q.pop();
        for (int j = 0; j < 8; j++)
        {
            dis += pow(me.data[j] - Inf.data[j], 2);
        }
        Inf.distance = sqrt(dis);
        //cout << Info.nick << "\t(" << Inf.type << ") " << endl;
        
        data.arrange_node(k, Inf);
    }

    data.show(k);
}

//  INPUT  26.4 24.6 24 30 30 24 23 25 
//  INPUT  3

//  OUTPUT ESTJ











/*// O(n log n)
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
        cout << endl << friends[i].nick << "\t(" << friends[i].type << ") " << friends[i].distance ;
    }

    query.type = tyype;
    cout << "\nYour type with KNN : " << query.type;

}

//  INPUT  26.4 24.6 24 30 30 24 23 25 
//  INPUT  3

//  OUTPUT ESTJ
*/

