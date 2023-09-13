#include <bits/stdc++.h>
using namespace std;

struct sinhvien
{
    int MaSV;
    string HoTen;
    int diemToan, diemLy, diemHoa;
};

struct node
{
    sinhvien data;
    node *next;
};

struct List
{
    node *head;
    node *tail;
};

void createList(List &L)
{
    L.head = NULL;
    L.tail = NULL;
}

node *createNode(sinhvien x)
{
    node *p = new node;
    p->next = NULL;
    p->data = x;
    return p;
}

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

void input(List &L, int n)
{
    cout << "Nhap thong tin sinh vien : \n";
    for (int i = 0; i < n; i++)
    {
        sinhvien x;
        cout << "\nMa sinh vien : ", cin >> x.MaSV;
        cout << "Ho va Ten : ", cin.ignore(), getline(cin, x.HoTen);
        cout << "Diem Toan : ", cin >> x.diemToan;
        cout << "Diem Ly : ", cin >> x.diemLy;
        cout << "Diem Hoa : ", cin >> x.diemHoa;
        node *p = createNode(x);
        addTail(L, p);
    }
}

void DuLieuSV(List L, node *p)
{
    cout << setw(10) << left << p->data.MaSV;
    cout << setw(20) << left << p->data.HoTen;
    cout << setw(4) << left << p->data.diemToan;
    cout << setw(4) << left << p->data.diemLy;
    cout << setw(4) << left << p->data.diemHoa;
    cout << setw(4) << left << (float)(p->data.diemHoa + p->data.diemLy + p->data.diemToan) / 3 << "\n";
}

void output(List L)
{
    node *p = L.head;
    while (p != NULL)
    {
        DuLieuSV(L, p);
        p = p->next;
    }
}

void outputThiLai_itNhat1(List L)
{
    node *p = L.head;
    while (p != NULL)
    {
        if (p->data.diemToan < 5 || p->data.diemLy < 5 || p->data.diemHoa < 5)
        {
            DuLieuSV(L, p);
        }
        p = p->next;
    }
}

void outputThiLai_ca3(List L)
{
    node *p = L.head;
    while (p != NULL)
    {
        if (p->data.diemToan < 5 && p->data.diemLy < 5 && p->data.diemHoa < 5)
        {
            DuLieuSV(L, p);
        }
        p = p->next;
    }
}

void timKiemSV(List L)
{
    int target;
    cout << "Nhap ma sinh vien can tim : ", cin >> target;
    node *p = L.head;
    while (p != NULL)
    {
        if (p->data.MaSV == target)
        {
            DuLieuSV(L, p);
            return;
        }
        p = p->next;
    }
}

int diemTBmax(List L)
{
    int x = (float)(L.head->data.diemHoa + L.head->data.diemLy + L.head->data.diemToan) / 3;
    node *p = L.head->next;
    while (p != NULL)
    {
        if ((float)(p->data.diemHoa + p->data.diemLy + p->data.diemToan) / 3 > x)
            x = (float)(p->data.diemHoa + p->data.diemLy + p->data.diemToan) / 3;
        p = p->next;
    }
    return x;
}

void outputTBmax(List L)
{
    int x = diemTBmax(L);
    node *p = L.head;
    while (p != NULL)
    {
        if ((float)(p->data.diemHoa + p->data.diemLy + p->data.diemToan) / 3 == x)
            DuLieuSV(L, p);
        p = p->next;
    }
}

void timkiemsinhvien(List L, int target)
{
    node *p = L.head;
    while (p != NULL)
    {
        if (p->data.MaSV == target)
        {
            DuLieuSV(L, p);
            return;
        }
        p = p->next;
    }
}

int main()
{
    List L;
    createList(L);

    int n;
    cout << "Nhap so sinh vien : ";
    cin >> n;

    input(L, n);

    cout << "Danh sach sinh vien vua nhap : \n";
    output(L);

    // cout << "Danh sach sinh vien thi lai it nhat 1 mon :";
    // outputThiLai_itNhat1(L);

    // cout << "Danh sach sinh vien thi lai ca 3 mon :";
    // outputThiLai_ca3(L);

    // // timKiemSV(L);
    return 0;
}