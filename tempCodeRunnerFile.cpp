#include<bits/stdc++.h>
#include<string.h>
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
                cout << fence->name << " removed out scoreboard" << endl;
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
    while (1)
    {
        string name;
        int score;
        string stop ="stop";
        
        cout << "Name : ";
        cin >> name;
        cout << "Score : ";
        cin >> score;
        if (strcmp(name,stop) == 0)
        {
            break;
        }
        data.push_sort(name, score);
    }
    data.show();
}