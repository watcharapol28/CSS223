#include<bits/stdc++.h>
using namespace std;


class Node
{
    public:
        int num, degree;
        Node* next;
};

class Polynomial
{
    public:
        Node* head;
        Node* fence;
    
    public:
        Polynomial()
        {
            head = NULL;
        }
    
    void arrange_node(int num, int degree)
    {
        Node* newnode = new Node;
        newnode->num = num;
        newnode->degree = degree;
        newnode->next = NULL;
        if(head == NULL)
        {
            head = newnode;
            fence = head;
        }
        else
        {
            if(newnode->degree > head->degree)
            {
                newnode->next = head;
                head = newnode;
                fence = head;
            }
            else
            {
                fence = head;
                while(fence != NULL)
                {
                    if(newnode->degree > fence->next->degree)
                    {
                        newnode->next = fence->next;
                        fence->next = newnode;
                        return;
                    }
                    fence = fence->next;
                }
                fence->next = newnode;
            }
        }
    }
    
    
};


int main()
{
    int n;
    cout << "How many Polynomial :";
    cin >> n;
    Node *newnode = new Node;
}