#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

struct customStack
{
    node *top;
    int count;
};

void createStack(customStack &s)
{
    s.top = NULL;
    s.count = 0;
}

void push(customStack &s, int x)
{
    node *newNode = new node;
    newNode->data = x;
    newNode->next = s.top;
    s.top = newNode;
    s.count++;
}

void pop(customStack &s)
{
    if (s.top == NULL)
    {
        cout << "Stack rong." << endl;
        return;
    }
    node *temp = s.top;
    s.top = s.top->next;
    delete temp;
    s.count--;
}

int size(customStack s)
{
    return s.count;
}

bool isEmpty(customStack s)
{
    return s.top == NULL;
}

int top(customStack s)
{
    return s.top->data;
}

int main()
{
    customStack s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);

    pop(s);
    pop(s);
    pop(s);

    if (isEmpty(s)) cout << "Stack rong." << endl;
    else cout << "Stack co gia tri." << endl;

    cout << "So phan tu cua stack: " << size(s) << endl; // Output: 4
    return 0;
}