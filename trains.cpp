#include <bits/stdc++.h>
using namespace std;
#define int long long
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL); 
#define pi pair<int,int> 
#define pii pair<int,pi>
int A[10005], dp[10005], n;

main(){
    speed
    int n;
    cin >> n;
    A[0] = 1e9;
    for (int i = 1; i <= n; i++) cin >> A[i];
    A[n + 1] = 0;
    fill(dp, dp + n + 2, 1e9 + 1);
    dp[0] = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[j] < A[i]) continue;
            else {
                dp[i] = min(dp[i], dp[j] + (i - j) * (i - j));
            }
        }
    }
    cout << dp[n + 1];
}
