#include <bits/stdc++.h>
using namespace std;
int K[305], T[305], S[305];
int memo[305][305][1001];
int n;
int dp(int idx, int completed, int t){
    if (t == 0 || idx == n || completed < S[idx]) return 0;
    if (memo[idx][completed][t] != -1) return memo[idx][completed][t];
    int ans = -1e9;
    if (t >= T[idx]) ans = max(ans, dp(idx+1, completed+1, t-T[idx]) + K[idx]);
    ans = max(ans, dp(idx+1, completed, t));
    return memo[idx][completed][t] = ans;
}
int32_t main()
{   
    memset(memo, -1, sizeof memo);
    int m; cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> K[i] >> T[i] >> S[i];
    }
    cout << max(0, dp(0, 0, m)) << endl;
}
