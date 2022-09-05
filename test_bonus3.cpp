//Credit Miss.Julalak
#include <iostream>
using namespace std;
//Data
class Node
{
    public:
        string name;
        int score;
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
    void arrange_node(string a, int b)
    {
        Node *newnode = new Node();
        newnode->name = a;
        newnode->score = b;
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
            if (head->score < newnode->score)
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
                    if (fence->next->score < newnode->score)
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
        int count = 0;
        fence = head;
        for (;count < 10;)
        {
            cout << "" << fence->name << " " <<
            fence->score << endl;
            fence = fence->next;
            count++;
        }
        if (fence != NULL)
        {
            cout << fence->name << " was removefrom the score board";
        }
    }
};



int main()
{
    string name;
    int n;
    arrange data;
    data.arrange_node("A",90);
    data.arrange_node("B",100);
    data.arrange_node("C",50);
    data.arrange_node("D",33);
    data.arrange_node("E",80);
    data.arrange_node("F",82);
    data.arrange_node("G",94);
    data.arrange_node("H",88);
    data.arrange_node("I",72);
    data.arrange_node("J",75);
    data.show();
    cout << "-----------------" << endl;
    cout << "Input name:";
    cin >> name;
    cout << "Input Score:";
    cin >> n;
    data.arrange_node(name,n);
    data.show();
}