#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

struct LIST
{
    node *head;
    node *tail;
};

node *createNode(int x)
{
    node *temp = new node;
    temp->next = NULL;
    temp->data = x;
    return temp;
}

void createList(LIST &L)
{
    L.head = NULL;
    L.tail = NULL;
}

void addHead(LIST &L, node *p)
{
    if (L.head == NULL)
        L.head = L.tail = p;
    else
    {
        p->next = L.head;
        L.head = p;
    }
}

void Input(LIST &L)
{
    int n;
    cout << "Nhap so phan tu cua danh sach : "; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        node *p = createNode(x);
        addHead(L, p);
    }
}

void Output(LIST L)
{
    node *p = L.head;
    while (p != NULL)
    {
        cout << p->data << "\t";
        p = p->next;
    }
}

bool checkPrime(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i <= x/2; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int countPrime(LIST L)
{
    int count = 0;
    node *p = L.head;
    while (p != NULL)
    {
        if (checkPrime(p->data))
            count++;
        p = p->next;
    }
    return count;
}

void addXafterFirstOdd(LIST &L)
{
    int x;
    cout << "\nNhap gia tri can them : ";
    cin >> x;
    node *m = createNode(x);
    if(L.head->data % 2 == 1)
    {
        m->next = L.head;
        L.head = m;
        return;
    }
    node *p = L.head->next;
    while (p != NULL)
    {
        if (p->data % 2 == 1)
        {
            m->next = p->next;
            p->next = m;
            return;
        }
        p = p->next;
    }
}

int main()
{
    LIST L;
    createList(L);
    Input(L);
    cout << "\nDanh sach da nhap: ";
    Output(L);
    cout << "\nSo luong so nguyen to trong danh sach : " << countPrime(L);
    addXafterFirstOdd(L);
    cout << "\nDanh sach sau khi them : ";
    Output(L);
    return 0;
}