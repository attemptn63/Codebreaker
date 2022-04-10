#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SPEED ios_base::sync_with_stdio(0);cin.tie(NULL);
int A[200010],memo[200010][2],n;
int dp(int x, int taken){
    if (memo[x][taken] != -1) return memo[x][taken];
    if (taken){
        if (x + 2 < n) return memo[x][taken] = max(dp(x + 2, 0), dp(x + 2, 1) + A[x + 2]);
    } else {
        if (x + 1 < n) return memo[x][taken] = max(dp(x + 1, 0), dp(x + 1, 1) + A[x + 1]);
    }
    return memo[x][taken] = 0;
}
int32_t main(){
	SPEED
	cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    memset(memo, -1, sizeof memo);
    cout << max(dp(0, 1) + A[0], dp(0, 0));
}
