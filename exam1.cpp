#include<iostream>
using namespace std;


class Node
{
    public:
        int num;
        Node *next;
};

class arrange
{
    public:
        Node *head;
        Node *fence;

    public:
        arrange()
        { 
            head = NULL;
        }

    void less(int n, int num)
    {
        Node* newnode = new Node;
        newnode->num = num;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            if(num < head->num)
            {
                newnode->next = head;
                head = newnode;
            }
            else
            {
                fence = head;
                for(int i = 0; i < n; i++)
                {
                    if(fence->next == NULL)
                    {
                        fence->next = newnode;
                        return;
                    }
                    else if(num < fence->next->num)
                    {
                        newnode->next = fence->next;
                        fence->next = newnode;
                        return ;
                    }
                    fence = fence->next;
                }
            }
        }
    }

    void greater(int n, int num)
    {
        Node* newnode = new Node;
        newnode->num = num;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            if(num > head->num)
            {
                newnode->next = head;
                head = newnode;
            }
            else
            {
                fence = head;
                for(int i = 0; i < n; i++)
                {
                    if(fence->next == NULL)
                    {
                        fence->next = newnode;
                        return;
                    }
                    else if(num > fence->next->num)
                    {
                        newnode->next = fence->next;
                        fence->next = newnode;
                        return ;
                    }
                    fence = fence->next;
                }
            }
        }
    }

    void show(int n)
    {
        fence = head;
        for(int j = 0; j < n; j++)
        {
                cout << fence->num << " ";
                fence = fence->next;
        }
        cout << endl;
    }
};


int main()
{
    arrange data;
    int lst[] = {852,405,849,1000,324,258,267,214,900,
                496,186,599,535,2,150,763,336,121,553,
                829,584,506,621,375,490,727,101,98,731,
                682,624,810,389,782,400,351,688,833,429,
                879,819,226,820,215,828,249,614,441,171,
                201,860,796,568,379,899,844,9,1203};
    int n;
    int N = sizeof(lst) / sizeof(lst[0]);

    cout << "\nlist numbers : ";
    for(int i = 0; i < N; i++)
    {
        cout << lst[i] << " ";
    }
    cout << endl << endl;

    cout << "How many numbers : ";
    cin >> n;

    for(int i = 0; i < N; i++)
    {
        data.less(n, lst[i]);
    }
    cout << "\n" << n << " numbers sorted from least\n";
    data.show(n);

    for(int i = 0; i < N; i++)
    {
        data.greater(n, lst[i]);
    }
    cout << "\n" << n << " numbers sorted from highest\n";
    data.show(n);

    cout << endl;
}