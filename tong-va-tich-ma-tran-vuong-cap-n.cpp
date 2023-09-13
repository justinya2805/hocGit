#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int i, j, k;
    int MaTran1[100][100], MaTran2[100][100], MaTranTong[100][100], MaTranTich[100][100];

    cout << "Nhap cap do cua hai ma tran : ";
    cin >> n;

    cout << "Nhap ma tran 1 :\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << "MaTran1[" << i << "][" << j << "] :";
            cin >> MaTran1[i][j];
        }
    }

    cout << "Nhap ma tran 2 :\n";
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            cout << "MaTran2[" << i << "][" << j << "] :";
            cin >> MaTran2[i][j];
        }

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            MaTranTong[i][j] = MaTran1[i][j] + MaTran2[i][j];
        }

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            int temp = 0;
            for (k = 0; k < n; k++)
            {
                temp += (MaTran1[i][k] * MaTran2[k][j]);
            }
            MaTranTich[i][j] = temp;
        }

    cout << "\nKet qua cua phep cong hai ma tran la: \n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << MaTranTong[i][j] << "\t";
        }
        cout << "\n";
    }

    cout << "\nKet qua cua phep nhan hai ma tran la: \n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << MaTranTich[i][j] << "\t";
        }
        cout << "\n";
    }

    return 0;
}