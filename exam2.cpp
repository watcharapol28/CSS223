#include<iostream>
#include<stack>
using namespace std;


struct Queue {
    stack <int> s1, s2;
    public:
        void to_queue(stack <int> v)
        {
            if(!v.empty())
            {
                s2.push(v.top());
                v.pop();
                to_queue(v);
            }
        }
        void to_stack(stack <int> v)
        {
            if(!v.empty())
            {
                s1.push(v.top());
                v.pop();
                to_stack(v);
            }
        }
        void clear_s2()
        {
            if(!s2.empty())
            {
                s2.pop();
                clear_s2();
            }
        }
        void clear_s1()
        {
            if(!s1.empty())
            {
                s1.pop();
                clear_s1();
            }
        }
    void enQueue(int x)
    {
        s1.push(x);
    }
 
    int deQueue()
    {
        clear_s2();
        to_queue(s1);
        if (s2.empty()) {cout << "Queue empty, Error:";}
        else
        {
            int x = s2.top();
            s2.pop();
            clear_s1();
            to_stack(s2);
            return x;
        }
    }
};

int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(100);
 
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    q.enQueue(300);
    cout << q.deQueue() << '\n';
}