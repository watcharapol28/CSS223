#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        string name;
        int score;
        Node* next;
        Node* prev;
};

class arrange
{
    public:
        Node* head;
        Node* tail;
        Node* fence;
    public:
        arrange()
        {
            head = NULL;
            tail = NULL;
        }
    void push_sort(string name, int score)
    {
        Node* newnode = new Node;
        newnode->name = name;
        newnode->score = score;
        newnode->next = NULL;
        newnode->prev = NULL;
        if(head == NULL)
        {
            head = newnode;
            tail = newnode;
            fence = head;
        }
        else
        {
            if(newnode->score > head->score)
            {
                head->prev = newnode;
                newnode->next = head;
                head = newnode;
                fence = head;
            }
            else
            {
                fence = head;
                while(fence->next != NULL)
                {
                    if(fence->next->score < newnode->score)
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
    void show()
    {
        fence = head;
        int i = 0;
        while(fence != NULL)
        {
            if(i < 10)
            {
                i++;
                cout << "[" << i << "]\t" << fence->name << "  Score : " << fence->score << endl;
            }
            else
            {
                cout << fence->name << " was removefrom the score board" << endl;
            }
            fence = fence->next;
        }
    }
};


int main()
{
    arrange data;
    int n;
    cout << "How many student : ";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string name;
        int score;
        cout << "Name : ";
        cin >> name;
        cout << "Score : ";
        cin >> score;
        data.push_sort(name, score);
    }
    data.show();
}


/*
11
H 
9
A 
10
J 
12
D 
14
C 
15
I 
16
E 
19
B 
20
F 
22
G 
30
K 
36
*/