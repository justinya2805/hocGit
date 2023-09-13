#include <bits/stdc++.h>
using namespace std;

// định nghĩa node
struct node
{
    int data;
    node *next;
};

// định nghĩa danh sách
struct List
{
    node *head;
    node *tail;
};

// tạo danh sách
void createList(List &L)
{
    L.head = NULL;
    L.tail = NULL;
}

// tạo node với data là x
node *createNode(int x)
{
    node *temp = new node;
    temp->next = NULL;
    temp->data = x;
    return temp;
}

// thêm node vào đầu
void addHead(List &L, node *p)
{
    if (L.head == NULL)
        L.head = L.tail = p;
    else
    {
        p->next = L.head;
        L.head = p;
    }
}

// thêm node vào cuối
void addTail(List &L, node *p)
{
    if (L.head == NULL)
        L.head = L.tail = p;
    else
    {
        L.tail->next = p;
        L.tail = p;
    }
}

// nhập danh sách
void input(List &L)
{
    int x;
    int number;
    cout << "Nhap so phan tu cua danh sach : ";
    cin >> number;
    cout << "\nNhap danh sach :\n";
    for (int i = 0; i < number; i++)
    {
        cin >> x;
        node *p = createNode(x);
        addTail(L, p);
        // or addHead(L, p); (based on circumstances)
    }
}

// xuất danh sách
void output(List L)
{
    node *p = new node;
    p = L.head;
    while (p != NULL)
    {
        cout << p->data << "\t";
        p = p->next;
    }
}

// xuất ra các số chẵn trong danh sách
void outputEven(List L)
{
    node *p = new node;
    p = L.head;
    while (p != NULL)
    {
        if (p->data % 2 == 0)
            cout << p->data << "\t";
        p = p->next;
    }
}

// tìm giá trị nhỏ nhất trong danh sách
int dataMin(List L)
{
    int temp = L.head->data;
    node *p = new node;
    p = L.head;
    while (p->next != NULL)
    {
        p = p->next;
        if (p->data < temp)
            temp = p->data;
    }
    return temp;
}

// kiểm tra tính nguyên tố
bool checkPrime(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i <= sqrt((float)x); i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

// đếm số nguyên tố trong danh sách
int countPrime(List L)
{
    int number = 0;
    node *p = new node;
    p = L.head;
    while (p != NULL)
    {
        if (checkPrime(p->data))
            number++;
        p = p->next;
    }
    return number;
}

// thêm giá trị x vào trước số chẵn đầu tiên
void addXBeforeFirstEven(List &L)
{
    int x;
    cout << "\nNhap gia tri can them : ";
    cin >> x;

    node *add = createNode(x);
    node *left = L.head;
    node *right = new node;
    right = left->next;

    if(L.head->data % 2 == 0)
    {
        addHead(L, add);
        return;
    }

    while(right != NULL)
    {
        if(right->data % 2 == 0)
        {
            left->next = add;
            add->next = right;
            return;
        }
        left = right;
        right = right->next;
    }
}

// thêm giá trị x vào sau giá trị lẻ cuối cùng
void addXafterLastOdd(List &L)
{
    int x;
    cout << "\nNhap gia tri can them : ";
    cin >> x;

    node *add = createNode(x);

    if(L.tail->data % 2 == 1)
    {
        addTail(L, add);
        return;
    }

    int count = 0;
    int locate = 0;
    node *p = L.head;
    while(p != nullptr)
    {
        count++;
        if(p->data % 2 == 1) locate = count;
        p = p->next;
    }

    p = L.head;
    for(int i = 1; i < locate; i++)
    {
        p = p->next;
    }
    add->next = p->next;
    p->next = add;
}

void deleteHead(List &L)
{
    node *p = L.head;
    L.head = L.head->next;
    p->next = NULL;
    delete p;
}

// xoá 1 node có giá trị bằng x
void deleteX(List &L, int x)
{
    if (L.head->data == x)
    {
        deleteHead(L);
        return;
    }

    node *left = new node;
    for (node *right = L.head; right != NULL; right = right->next)
    {
        if (right->data == x)
        {
            left->next = right->next;
            delete right;
            return;
        }
        left = right;
    }
}

// xoá tất cả node có giá trị bằng x
void deleteAllX(List &L, int x)
{
    while (L.head->data == x)
        deleteHead(L);

    node *left = new node;
    for (node *right = L.head; right != NULL; right = right->next)
    {
        if (right->data == x)
        {
            left->next = right->next;
            delete right;
        }
        left = right;
    }
}

// xoá danh sách
void deleteList(List &L)
{
    for (node *check = L.head; check != NULL; check = check->next)
    {
        node *del = L.head;
        L.head = del->next;
        delete del;
    }
    L.tail = NULL;
}

void cutList(List L, List &Prime, List &Normal)
{
    node *check = new node;
    check = L.head;
    node *p = new node;
    while (check != NULL)
    {
        p = createNode(check->data);
        if (checkPrime(check->data))
            addTail(Prime, p);
        else
            addTail(Normal, p);
        check = check->next;
    }
}

int main()
{
    List L;
    createList(L);

    input(L);

    cout << "\nDanh sach vua nhap : ";
    output(L);

    // cout << "\nCac so chan co trong danh sach : ";
    // outputEven(L);

    // cout << "\nGia tri nho nhat trong danh sach : " << dataMin(L);

    // cout << "\nDanh sach co " << countPrime(L) << " so nguyen to";

    addXBeforeFirstEven(L);
    cout << "\nDanh sach sau khi them x : ";
    output(L);

    addXafterLastOdd(L);
    cout << "\nDanh sach sau khi them x : ";
    output(L);

    // deleteHead(L);
    // cout << "\nDanh sach sau khi xoa phan tu dau : ";
    // output(L);

    // int x;
    // cout << "\nNhap x can xoa : ", cin >> x;
    // deleteX(L, x);
    // cout << "\nDanh sach sau khi xoa x la : ";
    // output(L);

    // List Prime, Normal;
    // createList(Prime), createList(Normal);
    // cutList(L, Prime, Normal);
    // cout << "\nSau khi tach, ta duoc 2 danh sach sau :";
    // cout << "\nCac phan tu nguyen to : ", output(Prime);
    // cout << "\nCac phan tu con lai : ", output(Normal);

    return 0;
}
