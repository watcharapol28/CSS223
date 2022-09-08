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
