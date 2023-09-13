#include<bits/stdc++.h>
using namespace std;

//khai báo stack
stack<int> s;

int main()
{
    //thêm giá trị cho stack
    s.push(5);
    s.push(6);
    s.push(9);
    s.push(3);

    //xoá giá trị cuối của stack
    s.pop();
    s.pop();

    //xuất ra kích cỡ của stack
    cout << s.size() << "\n";

    //xuất ra giá trị trên cùng của stack
    cout << s.top() << "\n";
    
    if(s.empty()) cout << "Stack rong!";
    else cout << "Stack co gia tri";
}