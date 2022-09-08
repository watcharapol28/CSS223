#include<bits/stdc++.h>
using namespace std;


class Node
{
    public:
        int num, degree;
        Node* next;
};


Node* newNode(int num, int degree)
{
    Node* new_node = new Node();
    new_node->num = num;
    new_node->degree = degree;
    new_node->next = NULL;
    return new_node;
}


void push(Node** head_ref, int num, int degree)
{
    Node* new_node = newNode(num, degree);

    if((*head_ref) == NULL)
    {
        (*head_ref) = new_node;
    }

    else if(new_node->degree > (*head_ref)->degree)
    {
        new_node->next = (*head_ref);
        (*head_ref) = new_node;
    }
    else
    {
        Node* fence = (*head_ref);
        while(fence->next != NULL)
        {
            if(new_node->degree > fence->next->degree)
            {
                new_node->next = fence->next;
                fence->next = new_node;
                return;
            }
            else if(new_node->degree == fence->next->degree)
            {
                fence->next->num += new_node->num;
                return;
            }
            fence = fence->next;
        }
        fence->next = new_node;
    }
}


Node* add(Node* curr1, Node* curr2) // O(n)
{
    Node* ans = NULL;
    while(curr1 != NULL || curr2 != NULL)
    {
        if(curr1 == NULL)
        {
            while(curr2 != NULL)
            {
                push(&ans, curr2->num, curr2->degree);
                curr2 = curr2->next;
            }
        }

        if(curr2 == NULL)
        {
            while(curr1 != NULL)
            {
                push(&ans, curr1->num, curr1->degree);
                curr1 = curr1->next;
            }
        }

        else if(curr1->degree == curr2->degree)
        {
            push(&ans, curr1->num + curr2->num, curr1->degree);
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        else if(curr1->degree > curr2->degree)
        {
            push(&ans, curr1->num, curr1->degree);
            curr1 = curr1->next;
        }
        else
        {
            push(&ans, curr2->num, curr2->degree);
            curr2 = curr2->next;
        }
    }
    return ans;
}


Node* Multiply(Node* curr1, Node* curr2)//O(n^2)
{
    Node* ans = NULL;
    while(curr1 != NULL)
    {
        Node *node2 = curr2;
        while(node2 != NULL)
        {
            push(&ans, node2->num * curr1->num, node2->degree + curr1->degree);
            node2 = node2->next;
        }
        curr1 = curr1->next;
    }
    return ans;
}


void show(Node* curr)
{
    while (curr->next != NULL) {
        (curr->degree == 1)?cout << curr->num << "x + ": cout << curr->num << "x^" << curr->degree << " + ";
        curr = curr->next;
    }
    cout << curr->num; (curr->degree != 0)?cout << "x^" << curr->degree << endl: cout << endl;
}



int main()
{
    Node* n1 = NULL;
    push(&n1, 2, 3);
    push(&n1, 3, 4);
    push(&n1, 4, 2);
    push(&n1, 3, 0);
    push(&n1, 3, 1);
    push(&n1, 3, 5);
    cout << "Solution 1 : ";
    show(n1);

    Node* n2 = NULL;
    push(&n2, 2, 7);
    push(&n2, 3, 4);
    push(&n2, 4, 2);
    push(&n2, 3, 0);
    push(&n2, 6, 1);
    push(&n2, 3, 5);
    cout << "Solution 2 : ";
    show(n2);

    Node* n3 = NULL;
    push(&n3, 2, 2);
    push(&n3, 3, 3);
    push(&n3, 4, 4);
    push(&n3, 3, 5);
    push(&n3, 6, 0);
    cout << "Solution 3 : ";
    show(n3);
    
    Node*ans = add(n1,n2);
    cout << "Addition 1,2 : ";
    show(ans);

    Node*ans2 = add(ans,n3);
    cout << "Addition 1,2,3: ";
    show(ans2);

    Node* ans3 = Multiply(n1, n2);
    cout << "Multiply 1,2 : ";
    show(ans3);

    Node* ans4 = Multiply(n1, n3);
    cout << "Multiply 1,3 : ";
    show(ans4);
}





/*
void add_data(Node *curr, int num, int degree)
{
    Node* newnode = new Node;
    newnode->degree = degree;
    newnode->num = num;
    //cout << newnode->degree << " " << newnode->num << endl;
    newnode->next = NULL;

    if(curr == NULL){
        curr = newnode;
        cout << curr->degree << " " << curr->num << endl;}

    else
    {
        if(newnode->degree > curr->degree)
        {
            newnode->next = curr;
            curr = newnode;
        }
        else
        {
            Node* fence = curr;
            while(fence->next != NULL)
            {
                if(newnode->degree > fence->next->degree)
                {
                    newnode = fence->next;
                    fence->next = newnode;
                    return;
                }
                fence = fence->next;
            }
            fence->next = newnode;
        }
    }
}


void show(Node* curr)
{
    //cout << curr->num << " " << curr->degree;
    Node* newnode = curr;
    while(newnode->next != NULL)
    {
        cout << newnode->num << "x^" << newnode->degree << " + ";
        newnode = newnode->next;
    }
    if(newnode != NULL)
    {cout << newnode->num; (newnode->degree == 0)?cout << "x^" << newnode->degree << endl : cout << endl;}
}


Node* add(Node* curr1, Node* curr2)
{
    Node* ans = new Node;
    Node* head = ans;
    Node* n1 = curr1;
    Node* n2 = curr2;
    while(n1 != NULL && n2 != NULL)
    {
        if(n1 == NULL)
        {
            while(n2 != NULL)
            {
                ans->degree = n2->degree;
                ans->num = n2->num;
                ans = ans->next;
                ans->next = NULL;
                n2 = n2->next;
            }
        }

        else if(n2 == NULL)
        {
            while(n1 != NULL)
            {
                ans->degree = n1->degree;
                ans->num = n1->num;
                ans = ans->next;
                ans->next = NULL;
                n1 = n1->next;
            }
        }

        else if(n1->degree == n2->degree)
        {
            ans->num = n1->num + n2->num;
            ans->degree = n1->degree;
            n1 = n1->next;
            n2 = n2->next;
            ans = ans->next;
            ans->next = NULL;
        }
        else if(n1->degree > n2->degree)
        {
            ans->degree = n1->degree;
            ans->num = n1->num;
            ans = ans->next;
            n1 = n1->next;
            ans->next = NULL;
        }
        else
        {
            ans->degree = n2->degree;
            ans->num = n2->num;
            ans = ans->next;
            n2 = n2->next;
            ans->next = NULL;
        }
    }
    return head;
}

int main()
{
    Node* n1 = new Node; // 3x5 3x4 2x3 4x2 3x1 3
    n1 = NULL;
    /*Node* x = n1;
    Node* newnode = new Node;
    newnode->degree = 5;
    newnode->num = 3;
    x->next = newnode;
    x = x->next;
    x->next->degree = 6;
    cout << x->next->degree << n1->next->degree;*//*
    add_data(n1, 2, 3);
    add_data(n1, 3, 4);
    add_data(n1, 4, 2);
    add_data(n1, 3, 0);
    add_data(n1, 3, 1);
    add_data(n1, 3, 5);
    //show(n1);

    Node* n2 = new Node; // 2x7 3x5 3x4 4x2 6x1 3
    add_data(n2, 2, 7);
    add_data(n2, 3, 4);
    add_data(n2, 4, 2);
    add_data(n2, 3, 0);
    add_data(n2, 6, 1);
    add_data(n2, 3, 5);

    //Node* ans_add = add(n1, n2); // 2x7 6x5 6x4 2x3 8x2 9x1 6
    //show(ans_add);
}*/