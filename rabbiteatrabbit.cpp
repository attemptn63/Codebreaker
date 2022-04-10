#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> rabbits;
int memo[4010][4010];
int dp(int pos, int k){
    if (k == 0 || pos > rabbits.size() - 1) return 0;
    if (memo[pos][k] != -1) return memo[pos][k];
    return memo[pos][k] = max(dp(pos + 1, k), dp(pos + 2, k - 1) + rabbits[pos]);
}
main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(memo, -1, sizeof memo);
    int n, k; cin >> n >> k;
    if (n == 1){
        int g; cin >> g; 
        if (g > 0) cout << g << endl;
        else cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++){
        int g; cin >> g;
        rabbits.push_back(g);
    }
    ans = dp(0, k);
    int g; cin >> g; rabbits.push_back(g);
    memset(memo, -1, sizeof memo);
    ans = max(ans, dp(1, k));
    cout << ans << endl;
}
