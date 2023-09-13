#include<bits/stdc++.h>
using namespace std;
int combination(int N, int K)
{
    int dp[N + 1][K + 1];
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= min(i, K); j++)
        {
            if (j == 0 || j == i)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }
    return dp[N][K];
}

int main()
{
    int N, K;
    cout << "Nhap N: ";  
            cin >> N;
    cout << "Nhap K: ";  
            cin >>
        K;
    cout << "Tong hop chap " << K << " cua " << N << " la: " << combination(N, K) << endl;  
        return 0;
}
int main()
{
    int n, k;
    cin >> k;
    cin >> n;
    cout << combination(k, n);
    return 0;
}